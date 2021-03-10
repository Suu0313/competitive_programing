template<class T> struct Point{
  T x,y;
  Point(){}
  Point(T x, T y) : x(x), y(y) {}
  Point(pair<T,T> p) : x(p.first), y(p.second) {}
  
  Point operator+(const Point &b) const { return Point(x + b.x, y + b.y); }
  Point operator-(const Point &b) const { return Point(x - b.x, y - b.y); }
  Point operator*(const T b) const { return Point(x * b, y * b); }
  Point operator/(const T b) const { return Point(x / b, y / b); }
  bool operator==(const Point &b) const {
    return (x == b.x && y == b.y);
    //return Eq(x, b.x) && Eq(y, b.y);
  }
  bool operator<(const Point &b) const { 
    if(x==b.x) return y<b.y;
    return x<b.x; }
  T Norm() const { return x * x + y * y; }
  double Abs() const { return hypot<double>(x, y); }
  double dist(const Point &b){ return hypot<double>(x-b.x,y-b.y); }
  double arg() const { return atan2<double>(y, x); }
  
  int ort() const {
    //if (abs(x) < EPS && abs(y) < EPS) return 0;
    if (abs(x) == 0 && abs(y) == 0) return 0;
    if(y==0) return x>0 ? 1 : 3;
    if(x==0) return y>0 ? 2 : 4;
    if (y > 0) return x>0 ? 1 : 2;
    else return x>0 ? 4 : 3;
  }
  Point rotate90() const { return Point(-y, x);}
  Point rotate180() const { return Point(-x, -y);}
  Point rotate270() const { return Point(y, -x);}

  Point flip_x(T p = 0) const { return Point(p*2-x, y);}
  Point flip_y(T p = 0) const { return Point(x, p*2-y);}

  Point rotate(double theta) const {
    return Point(cos(theta)*x-sin(theta)*y, sin(theta)*x+cos(theta)*y);
  }

  Point flip(double theta) const {
    return (*this).rotate(-theta).flip_y().rotate(theta);
  }

  Point operator*(const Point &b) const { return Point(x*b.x-y*b.y,x*b.y+y*b.x); }
  Point operator/(const Point &b) const { return Point(x*b.x+y*b.y,y*b.x-x*b.y)/(b.x*b.x+b.y*b.y); }

  friend ostream &operator<<(ostream &os, const Point &p) {
    return os << p.x << " " << p.y;
  }
  friend istream &operator>>(istream &is, Point &p) {
    T a, b; is >> a >> b;
    p = Point<T>(a, b);
    return (is);
  }
};

template<class T> T Cross(const Point<T> &a, const Point<T> &b) { return a.x * b.y - a.y * b.x; }

template<class T> T Dot(const Point<T> &a, const Point<T> &b) { return a.x * b.x + a.y * b.y; }

template<class T> bool Intersect(const Point<T> &a, const Point<T> &b, const Point<T> &c, const Point<T> &d) {
  if( Cross((c-a),(b-a))>0 != Cross((d-a),(b-a))>0 ){
    if( Cross((a-c),(d-c))>0 != Cross((b-c),(d-c))>0 ){
      return true;
    }
  }
  return false;
}

template<class T> int iSP(const Point<T> &a, const Point<T> &b, const Point<T> &c){
  T fl = Cross(b-a, c-a);
  if(fl > 0) return 1; // CCW
  if(fl < 0) return -1; // CW
  if(Dot(b-a, c-b) > 0) return 2; //abc
  if(Dot(a-b, c-a) > 0) return -2; //bac
  return 0; // acb
}

template<class T> int angletype(const Point<T> &a, const Point<T> &b, const Point<T> &c){
  T v = Dot(a-b, c-a);
  if(v == 0) return 0; // right angle
  if(v > 0) return 1; // acute angle
  return -1; // obtuse angle
}

typedef Point<double> point;
typedef vector<point> polygon;

template<class T> struct Line{
  Point<T> a, b;
  Line() {}
  Line(Point<T> a, Point<T> b): a(a), b(b) {}
  Line(T A, T B, T C){
    a = Point<T>(0, C/B); b = Point<T>(C/A, 0);
  }

  T dist(const Point<T> &p) const {
    return abs(Cross(p-a, b-a)/ (b-a).Abs());
  }
};

template<class T> struct Segment{
  Point<T> a, b;
  Segment() {}
  Segment(Point<T> a, Point<T> b): a(a), b(b) {}

  bool Intersect(const Segment &other) const {
    return ::Intersect(a, b, other.a, other.b);
  }
  Point<T> Center() const { return (a + b) / 2; }
  Line<T> PerpBisector() const {
    Point<T> center = this->Center();
    return Line<T>((a-center).rotate90() + center, center);
  }
};

template<class T> struct Circle{
  Point<T> o;
  T r;
  Circle() {}
  Circle(Point<T> o, T r): o(o), r(r) {}
};
