template<class T> struct Point{
  T x,y;
  Point(){}
  Point(T x, T y) : x(x), y(y) {}
  Point(const pair<T,T> &p) : x(p.first), y(p.second) {}
  
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
  double dist(const Point &b) const { return hypot<double>(x-b.x,y-b.y); }
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
  return iSP(a, b, c)*iSP(a, b, d)<=0 && iSP(c, d, a)*iSP(c, d, b)<=0;
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

template<typename T> T Area(const vector<Point<T>> &ps){
  T res = Cross(ps.back(), ps.front())/2;
  for(int i = 0; i < (int)ps.size()-1; i++){
    res += Cross(ps[i], ps[i+1])/2;
  }
  return res;
}

template<typename T> bool isConvex(vector<Point<T>> ps){
  int n = ps.size();
  ps.emplace_back(ps[0]);
  ps.emplace_back(ps[1]);
  for(int i = 0; i < n; i++){
    if(iSP(ps[i], ps[i+1], ps[i+2]) == -1) return false;
  }
  return true;
}

typedef Point<int> point;
typedef vector<point> polygon;
