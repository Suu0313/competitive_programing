namespace geometry{
  constexpr double eps = 1e-10;
  bool eq(double a, double b){ return fabs(a - b) < eps; }
  template<typename T>  bool eq(T a, T b){ return a == b; }
  bool is_zero(double a){ return fabs(a) < eps; }
  template<typename T> bool is_zero(T a){ return a == 0; }
  bool le(double a, double b){ return a <= b + eps; }
  template<typename T> bool le(T a, T b){ return a <= b; }
  bool lt(double a, double b){ return a < b - eps; }
  template<typename T> bool lt(T a, T b){ return a < b; }
  int sgn(double a){ return is_zero(a) ? 0 : ((a < 0) ? -1 : 1); }
  template<typename T> int sgn(T a){ return (a<0) ? -1 : ((a > 0) ? 1 : 0); }
  template<typename T> double psqrt(T a){ return sqrt(max(T(0), a)); }

  enum Dir{ BAC = -2, CW, ACB, CCW, ABC };
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
  bool operator!=(const Point &b) const {
    return !(geometry::eq(x, b.x) && geometry::eq(y, b.y));
  }
  bool operator<(const Point &b) const { 
    if(geometry::eq(x, b.x)) return y < b.y;
    return x < b.x;
  }
  T norm() const { return x * x + y * y; }
  double abs() const { return hypot<double>(x, y); }
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

  T cross(const Point &p) const { return x * p.y - y * p.x; }
  T cross(const Point &p, const Point &q) const { return (p - (*this)).cross(q - (*this)) ; }

  T dot(const Point &p) const { return x * p.x + y * p.y; }
  T dot(const Point &p, const Point &q) const { return (p - (*this)).dot(q - (*this)) ; }

  
};

template<typename T> Point<T> Polar(const T& rho, const T& theta = 0){
  return Point<T>(rho * cos(theta), rho * sin(theta));
}

template<typename T> using Polygon = vector<Point<T>>;

template<class T> int iSP(const Point<T> &a, const Point<T> &b, const Point<T> &c){
  T fl = a.cross(b, c);
  if(geometry::lt(T(0), fl)) return 1; // CCW
  if(geometry::lt(fl, T(0))) return -1; // CW
  if(geometry::lt(b.dot(a, c), T(0))) return 2; //abc
  if(geometry::lt(a.dot(b, c), T(0))) return -2; //bac
  return 0; // acb
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
void arg_sort(Polygon<T> &ps){
  sort(begin(ps), end(ps), cmp_arg<T>);
}

template<class T> struct Line{
  Point<T> a, b;
  Line() {}
  Line(const Point<T> &a, const Point<T> &b): a(a), b(b) {}
  Line(T A, T B, T C){ // Ax + By = C
    if(geometry::is_zero(A)){ a = Point<T>(0, C/B); b = Point<T>(1, C/B); }
    else if(geometry::is_zero(B)){ a = Point<T>(C/A, 0); b = Point<T>(C/A, 1); }
    else if(geometry::is_zero(C)){ a = Point<T>(0, 0); b = Point<T>(1, -A/B); }
    else{ a = Point<T>(0, C/B); b = Point<T>(C/A, 0); }
  }
  //Line(const Segment<T> &s): a(s.a), b(s.b) {}
  Point<T> projection(const Point<T> &p) const {
    return a + (b - a) * a.dot(p, b) / (b - a).norm();
  }
  Point<T> reflection(const Point<T> &p) const {
    return p + (projection(p) - p)*2;
  }
  int angletype(const Line &l) const {
    if(geometry::is_zero((b - a).cross(l.b - l.a))) return 1;
    if(geometry::is_zero((a - b).dot(l.b - l.a))) return -1;
    return 0;
  }
  bool intersect(const Line &l) const {
    return angletype(l) != 1;
  }
  Point<T> cross_point(const Line &l) const {
    if(geometry::is_zero((b - a).cross(l.b - l.a))) return l.a;
    return (b - a) * ((l.a - a).cross(l.b - l.a)) / ((b - a).cross(l.b - l.a)) + a;
  }
  double dist(const Point<T> &p) const {
    return abs(a.cross(p, b)/(b - a).abs());
  }
  double dist(const Line &l) const {
    if(intersect(l)) return 0;
    return dist(l.a);
  }
};

template<class T> struct Segment{
  Point<T> a, b;
  Segment() {}
  Segment(const Point<T> &a, const Point<T> &b): a(a), b(b) {}

  double length() const { return a.dist(b); }
  bool intersect(const Segment &s) const {
    return iSP(a, b, s.a)*iSP(a, b, s.b) <= 0 && iSP(s.a, s.b, a)*iSP(s.a, s.b, b) <= 0;
  }
  Point<T> center() const { return (a + b) / 2; }
  Line<T> perp_bisector() const {
    Point<T> center = this->center();
    return Line<T>((a - center).rotate90() + center, center);
  }
  int angletype(const Segment &s) const {
    if(geometry::is_zero((b - a).cross(s.b - s.a))) return 1;
    if(geometry::is_zero((a - b).dot(s.b - s.a))) return -1;
    return 0;
  }
  Point<T> cross_point(const Segment &s) const {
    if(geometry::is_zero((b - a).cross(s.b - s.a))) return s.a;
    return (b - a) * ((s.a - a).cross(s.b - s.a)) / ((b - a).cross(s.b - s.a)) + a;
  }
  double dist(const Point<T> &p) const {
    if(geometry::lt(a.dot(b, p), T(0))) return p.dist(a);
    if(geometry::lt(b.dot(a, p), T(0))) return p.dist(b);
    return abs(a.cross(p, b) / (b-a).abs());
  }
  double dist(const Segment &s) const {
    if(intersect(s)) return 0;
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
    return s1.perp_bisector().cross_point(s2.perp_bisector());
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
  Circle(const T &r): o(0, 0), r(r) {}
  Circle(const Point<T> &o, const T &r): o(o), r(r) {}
  Circle(const Point<T> &a, const Point<T> &b): o((a + b)/2), r(a.dist(b)/2) {}
  Circle(const Point<T> &a, const Point<T> &b, const Point<T> &c)
    : o(Triangle(a,b,c).circumcenter()), r(o.dist(a)) {}

  int intersect(const Circle&c) const {
    if(r < c.r) return c.intersect(*this);
    auto od = (o - c.o).norm();
    auto ra = (r + c.r)*(r + c.r), rs = (r - c.r)*(r - c.r);
    if(geometry::lt(ra, od)) return 4;
    if(geometry::eq(ra, od)) return 3;
    if(geometry::lt(rs, od)) return 2;
    if(geometry::eq(rs, od)) return 1;
    return 0;
  }

  bool is_intersect(const Circle&c) const {
    int k = this->intersect(c);
    return !(k == 0 || k == 4);
  }

  int intersect(const Line<T> &l) const {
    double d = l.dist(o);
    if(geometry::lt<double>(d, r)) return 2;
    return geometry::eq(d, r);
  }

  int contains(const Point<T> &p) const {
    auto od = (o - p).norm();
    if(geometry::eq(od, r*r)) return 1; // on
    return (od > r*r) ? 2 : 0; // out/in
  }

  Polygon<T> cross_points(const Line<T> &l) const {
    int k = this->intersect(l);
    if(k == 0) return {};
    Point<T> p = l.projection(o);
    if(k == 1) return {p};
    Point<T> d = (l.b - l.a)/l.a.dist(l.b);
    double base = geometry::psqrt(r*r - (p - o).norm());
    return {p - d*base, p + d*base};
  }

  Polygon<T> cross_points(const Segment<T> &s) const {
    Polygon<T> ps;
    for(const auto &p : this->cross_points(Line<T>(s.a, s.b))){
      if((p == s.a) || (p == s.b) || (iSP(s.a, p, s.b) == 2)){
        ps.push_back(p);
      }
    }
    return ps;
  }

  Polygon<T> cross_points(const Circle &c) const {
    int k = this->intersect(c);
    if(k == 0 || k == 4) return {};
    double d = o.dist(c.o), h = (r*r - c.r*c.r + d*d) / (d*2);
    Point<T> v = (c.o - o) / d;
    if(k == 1 || k == 3) return {o + v*Point<T>(h, 0) };
    double s = geometry::psqrt(r*r - h*h);
    return {o + v*Point<T>(h, s), o + v*Point<T>(h, -s) };
  }

  Polygon<T> tangent_points(const Point<T> &p) const {
    int t = this->contains(p);
    if(t == 0) return {};
    if(t == 1) return {p};
    double d = p.dist(o), h = r*r/d, s = geometry::psqrt(r*r - h*h);
    Point<T> v = (p - o) / d;
    return {o + v*h + v.rotate90()*s, o + v*h + v.rotate270()*s};
  }

  Polygon<T> tangent_points(const Circle &c) const {
    int k = this->intersect(c);
    if(k == 0) return {};
    Polygon<T> ps; 
    Point<T> p = c.o - o;

    if(k == 1) return { p*r*(r - c.r)/p.norm() + o };

    double d = geometry::psqrt(p.norm() - (r - c.r)*(r - c.r));
    ps.push_back((p*(r - c.r) + p.rotate90()*d)*r/p.norm() + o);
    ps.push_back((p*(r - c.r) + p.rotate270()*d)*r/p.norm() + o);
    if(k == 2) return ps;

    if(k == 3){
      ps.push_back(p*r*(r + c.r)/p.norm() + o);
      return ps;
    }

    d = geometry::psqrt(p.norm() - (r + c.r)*(r + c.r));
    ps.push_back((p*(r + c.r) + p.rotate90()*d)*r/p.norm() + o);
    ps.push_back((p*(r + c.r) + p.rotate270()*d)*r/p.norm() + o);
    
    return ps;
  }

  double area() const { return r * r * acos(-1.0); }

  friend ostream &operator<<(ostream &os, const Circle &c) {
    return os << c.o << " " << c.r;
  }
  friend istream &operator>>(istream &is, Circle &c) {
    Point<T> p; T l; is >> p >> l;
    c = Circle<T>(p, l);
    return (is);
  }
};
