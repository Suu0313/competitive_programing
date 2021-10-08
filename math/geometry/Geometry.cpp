namespace geometry{
  constexpr double eps = 1e-9;
  bool eq(double a, double b){ return fabs(a - b) < eps; }
  template<typename T>  bool eq(T a, T b){ return a == b; }
  bool is_zero(double a){ return fabs(a) < eps; }
  template<typename T> bool is_zero(T a){ return a == 0; }
  bool le(double a, double b){ return a <= b + eps; }
  template<typename T> bool le(T a, T b){ return a <= b; }
  bool lt(double a, double b){ return a < b - eps; }
  template<typename T> bool lt(T a, T b){ return a < b; }
};


template<class T> struct Point{
  T x,y;
  Point(){}
  Point(T x, T y) : x(x), y(y) {}
  Point(const pair<T,T> &p) : x(p.first), y(p.second) {}

  Point operator*(const T b) const { return Point(x * b, y * b); }
  Point operator/(const T b) const { return Point(x / b, y / b); }
  Point operator+(const Point &b) const { return Point(x + b.x, y + b.y); }
  Point operator-(const Point &b) const { return Point(x - b.x, y - b.y); }
  Point operator*(const Point &b) const { return Point(x*b.x - y*b.y, x*b.y + y*b.x); }
  Point operator/(const Point &b) const { return Point(x*b.x + y*b.y, y*b.x - x*b.y)/(b.x*b.x + b.y*b.y); }

  Point &operator*=(const T b){ return (*this) = (*this) * b; }
  Point &operator/=(const T b){ return (*this) = (*this) / b; }
  Point &operator+=(const Point &b){ return (*this) = (*this) + b; }
  Point &operator-=(const Point &b){ return (*this) = (*this) - b; }
  Point &operator*=(const Point &b){ return (*this) = (*this) * b; }
  Point &operator/=(const Point &b){ return (*this) = (*this) / b; }
  
  bool operator==(const Point &b) const {
    return geometry::eq(x, b.x) && geometry::eq(y, b.y);
  }
  bool operator<(const Point &b) const { 
    if(geometry::eq(x, b.x)) return y < b.y;
    return x < b.x;
  }
  T Norm() const { return x * x + y * y; }
  double Abs() const { return hypot<double>(x, y); }
  double dist(const Point &b) const { return hypot<double>(x - b.x, y - b.y); }
  double arg() const { return atan2<double>(y, x); }
  
  Point ArgVec() const {
    if((*this) == Point(0, 0)) return (*this);
    if(geometry::is_zero(x)) return Point(0, -1);
    return (*this) / gcd(x, y) * (x < 0 ? -1 : 1);
  }

  int ort() const {
    if(geometry::is_zero(x) && geometry::is_zero(y)) return 0;
    if(geometry::is_zero(y)) return x > 0 ? 1 : 3;
    if(geometry::is_zero(x)) return y > 0 ? 2 : 4;
    if (y > 0) return x > 0 ? 1 : 2;
    else return x > 0 ? 4 : 3;
  }
  Point rotate90() const { return Point(-y, x);}
  Point rotate180() const { return Point(-x, -y);}
  Point rotate270() const { return Point(y, -x);}

  Point flip_x(T p = 0) const { return Point(p*2 - x, y);}
  Point flip_y(T p = 0) const { return Point(x, p*2 - y);}

  Point rotate(double theta) const {
    return Point(cos(theta)*x - sin(theta)*y, sin(theta)*x + cos(theta)*y);
  }

  Point flip(double theta) const {
    return (*this).rotate(-theta).flip_y().rotate(theta);
  }

  friend ostream &operator<<(ostream &os, const Point &p) {
    return os << p.x << " " << p.y;
  }
  friend istream &operator>>(istream &is, Point &p) {
    T a, b; is >> a >> b;
    p = Point<T>(a, b);
    return (is);
  }
};

template<typename T> Point<T> Polar(const T& rho, const T& theta = 0){
  return Point<T>(rho * cos(theta), rho * sin(theta));
}


template<typename T> using Polygon = vector<Point<T>>;

template<class T> T Cross(const Point<T> &a, const Point<T> &b) { return a.x * b.y - a.y * b.x; }

template<class T> T Dot(const Point<T> &a, const Point<T> &b) { return a.x * b.x + a.y * b.y; }

template<class T> bool Intersect(const Point<T> &a, const Point<T> &b, const Point<T> &c, const Point<T> &d) {
  return (iSP(a, b, c)*iSP(a, b, d) <= 0) && (iSP(c, d, a)*iSP(c, d, b) <= 0);
}

template<class T> int iSP(const Point<T> &a, const Point<T> &b, const Point<T> &c){
  T fl = Cross(b-a, c-a);
  if(geometry::lt(T(0), fl)) return 1; // CCW
  if(geometry::lt(fl, T(0))) return -1; // CW
  if(geometry::lt(T(0), Dot(b-a, c-b))) return 2; //abc
  if(geometry::lt(T(0), Dot(a-b, c-a))) return -2; //bac
  return 0; // acb
}

template<class T> int angletype(const Point<T> &a, const Point<T> &b, const Point<T> &c){
  T v = Dot(a-b, c-a);
  if(geometry::is_zero(v)) return 0; // right angle
  if(v > 0) return 1; // acute angle
  return -1; // obtuse angle
}

template<typename T>
bool cmp_y(const Point<T>& p1, const Point<T> &p2){
  if(p1.y == p2.y) return p1.x < p2.x;
  return p1.y < p2.y;
}

template<typename T>
bool cmp_arg(const Point<T>& p1, const Point<T> &p2){
  if(p1.ort() != p2.ort()) return p1.ort() < p2.ort();
  return iSP(Point<T>(0,0), p1, p2) > 0;
}

template<typename T>
void ArgSort(Polygon<T> &ps){
  sort(begin(ps), end(ps), cmp_arg<T>);
}

template<class T> struct Line{
  Point<T> a, b;
  Line() {}
  Line(const Point<T> &a, const Point<T> &b): a(a), b(b) {}
  Line(T A, T B, T C){ // Ax + By = C
    if(A == 0){ a = Point<T>(0, C/B); b = Point<T>(1, C/B); }
    else if(B == 0){ a = Point<T>(C/A, 0); b = Point<T>(C/A, 1); }
    else{ a = Point<T>(0, C/B); b = Point<T>(C/A, 0); }
  }
  //Line(const Segment<T> &s): a(s.a), b(s.b) {}
  Point<T> projection(const Point<T> &p) const {
    return a + (b - a)*Dot(p - a, b - a)/(b - a).Norm();
  }
  Point<T> reflection(const Point<T> &p) const {
    return p + (projection(p) - p)*2;
  }
  int angletype(const Line &l) const {
    if(geometry::is_zero(Cross(b-a, l.b-l.a))) return 1;
    if(geometry::is_zero(Dot(a-b, l.b-l.a))) return -1;
    return 0;
  }
  bool Intersect(const Line &l) const {
    return angletype(l) != 1;
  }
  Point<T> Cross_Point(const Line &l) const {
    if(geometry::is_zero(Cross(b-a,l.b-l.a))) return l.a;
    return (b - a)*Cross(l.a - a, l.b - l.a)/Cross(b - a,l.b - l.a) + a;
  }
  double dist(const Point<T> &p) const {
    return abs(Cross(p - a, b - a)/(b - a).Abs());
  }
  double dist(const Line &l) const {
    if(Intersect(l)) return 0;
    return dist(l.a);
  }
};

template<class T> struct Segment{
  Point<T> a, b;
  Segment() {}
  Segment(const Point<T> &a, const Point<T> &b): a(a), b(b) {}

  double length() const { return a.dist(b); }
  bool Intersect(const Segment &s) const {
    return iSP(a, b, s.a)*iSP(a, b, s.b) <= 0 && iSP(s.a, s.b, a)*iSP(s.a, s.b, b) <= 0;
  }
  Point<T> Center() const { return (a + b) / 2; }
  Line<T> PerpBisector() const {
    Point<T> center = this->Center();
    return Line<T>((a - center).rotate90() + center, center);
  }
  int angletype(const Segment &s) const {
    if(geometry::is_zero(Cross(b-a, s.b-s.a))) return 1;
    if(geometry::is_zero(Dot(a-b, s.b-s.a))) return -1;
    return 0;
  }
  Point<T> Cross_Point(const Segment &s) const {
    if(geometry::is_zero(Cross(b-a,s.b-s.a))) return s.a;
    return (b - a)*Cross(s.a - a, s.b - s.a)/Cross(b - a, s.b - s.a) + a;
  }
  double dist(const Point<T> &p) const {
    if(Dot(b-a, p-a) < 0) return p.dist(a);
    if(Dot(a-b, p-b) < 0) return p.dist(b);
    return abs(Cross(p-a, b-a)/ (b-a).Abs());
  }
  double dist(const Segment &s) const {
    if(Intersect(s)) return 0;
    return min({dist(s.a), dist(s.b), s.dist(a), s.dist(b)});
  }
};

template<typename T>
struct Triangle{
  Point<T> a, b, c;
  Triangle() {}
  Triangle(const Point<T> &a, const Point<T> &b, const Point<T> &c): a(a), b(b), c(c){}

  double angle_a() const {
    double ab = a.dist(b), bc = b.dist(c), ca = c.dist(a);
    return acos((ca*ca + ab*ab - bc*bc)/(2*ca*ab));
  }
  double angle_b() const {
    double ab = a.dist(b), bc = b.dist(c), ca = c.dist(a);
    return acos((ab*ab + bc*bc - ca*ca)/(2*ab*bc));
  }
  double angle_c() const {
    double ab = a.dist(b), bc = b.dist(c), ca = c.dist(a);
    return acos((bc*bc + ca*ca - ab*ab)/(2*bc*ca));
  }
  Point<T> divpoint(double p, double q, double r) const {
    return (a*p + b*q + c*r)/(p + q + r);
  }

  Point<T> centerofgravity() const {
    return (a + b + c)/3;
  }
  Point<T> circumcenter() const {
    Segment<T> s1(a, b), s2(a, c);
    return s1.PerpBisector().Cross_Point(s2.PerpBisector());
  }
  Point<T> orthocenter() const {
    return centerofgravity()*3 - circumcenter()*2;
  }
  Point<T> innercenter() const {
    return divpoint(b.dist(c), c.dist(a), a.dist(b));
  }
  Point<T> excenterA() const {
    return divpoint(-b.dist(c), c.dist(a), a.dist(b));
  }
  Point<T> excenterB() const {
    return divpoint(b.dist(c), -c.dist(a), a.dist(b));
  }
  Point<T> excenterC() const {
    return divpoint(b.dist(c), c.dist(a), -a.dist(b));
  }
};

template<class T> struct Circle{
  Point<T> o;
  T r;
  Circle() {}
  Circle(const Point<T> &o, const T &r): o(o), r(r) {}
  Circle(const Point<T> &a, const Point<T> &b): o((a + b)/2), r(a.dist(b)/2) {}
  Circle(const Point<T> &a, const Point<T> &b, const Point<T> &c)
    : o(Triangle(a,b,c).circumcenter()), r(o.dist(a)) {}

  int Intersect(const Circle&c) const {
    if(r < c.r) return c.Intersect(*this);
    auto od = (o - c.o).Norm();
    auto ra = (r + c.r)*(r + c.r), rs = (r - c.r)*(r - c.r);
    if(geometry::lt(ra, od)) return 4;
    if(geometry::eq(ra, od)) return 3;
    if(geometry::lt(rs, od)) return 2;
    if(geometry::eq(rs, od)) return 1;
    return 0;
  }
  int Contains(const Point<T> &p) const {
    auto od = (o - p).Norm();
    if(geometry::eq(od, r*r)) return 1; // on
    return (od > r*r) ? 2 : 0; // out/in
  }
  pair<Point<T>, Point<T>> Cross_Point(const Line<T> &l) const {
    Point<T> p = l.projection(o), d = (l.b - l.a)/l.a.dist(l.b);
    double base = sqrt(r*r - (p - o).Norm());
    return {p + d*base, p - d*base};
  }
  friend ostream &operator<<(ostream &os, const Circle &c) {
    return os << c.o << " " << c.r;
  }
  friend istream &operator>>(istream &is, Circle &c) {
    Point<T> p; T l; is >> p >> l;
    c = Circle<T>(p, l);
    return (is);
  }
};
