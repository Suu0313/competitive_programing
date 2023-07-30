---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/geometry/Geometry.cpp
    title: math/geometry/Geometry.cpp
  - icon: ':heavy_check_mark:'
    path: math/geometry/Point.cpp
    title: math/geometry/Point.cpp
  - icon: ':heavy_check_mark:'
    path: math/geometry/geometry_base.cpp
    title: math/geometry/geometry_base.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/geometry/manhattan_intersections.cpp\"\n\r\n#line 2\
    \ \"math/geometry/Geometry.cpp\"\n\r\n#line 2 \"math/geometry/geometry_base.cpp\"\
    \n\r\nnamespace geometry{\r\n  constexpr double eps = 1e-10;\r\n  bool eq(double\
    \ a, double b){ return fabs(a - b) < eps; }\r\n  template<typename T>  bool eq(T\
    \ a, T b){ return a == b; }\r\n  bool is_zero(double a){ return fabs(a) < eps;\
    \ }\r\n  template<typename T> bool is_zero(T a){ return a == 0; }\r\n  bool le(double\
    \ a, double b){ return a <= b + eps; }\r\n  template<typename T> bool le(T a,\
    \ T b){ return a <= b; }\r\n  bool lt(double a, double b){ return a < b - eps;\
    \ }\r\n  template<typename T> bool lt(T a, T b){ return a < b; }\r\n  int sgn(double\
    \ a){ return is_zero(a) ? 0 : ((a < 0) ? -1 : 1); }\r\n  template<typename T>\
    \ int sgn(T a){ return (a<0) ? -1 : ((a > 0) ? 1 : 0); }\r\n  template<typename\
    \ T> double psqrt(T a){ return sqrt(max(T(0), a)); }\r\n\r\n  enum Dir{ BAC =\
    \ -2, CW, ACB, CCW, ABC };\r\n};\r\n\r\n#line 2 \"math/geometry/Point.cpp\"\n\r\
    \n#line 4 \"math/geometry/Point.cpp\"\n\r\n\r\ntemplate<class T> struct Point{\r\
    \n  T x,y;\r\n  Point() = default;\r\n  Point(T x, T y) : x(x), y(y) {}\r\n  Point(const\
    \ pair<T,T> &p) : x(p.first), y(p.second) {}\r\n\r\n  Point operator*(const T\
    \ b) const { return Point(x * b, y * b); }\r\n  Point operator/(const T b) const\
    \ { return Point(x / b, y / b); }\r\n  Point operator+(const Point &b) const {\
    \ return Point(x + b.x, y + b.y); }\r\n  Point operator-(const Point &b) const\
    \ { return Point(x - b.x, y - b.y); }\r\n  Point operator*(const Point &b) const\
    \ { return Point(x*b.x - y*b.y, x*b.y + y*b.x); }\r\n  Point operator/(const Point\
    \ &b) const { return Point(x*b.x + y*b.y, y*b.x - x*b.y)/(b.x*b.x + b.y*b.y);\
    \ }\r\n\r\n  Point &operator*=(const T b){ return (*this) = (*this) * b; }\r\n\
    \  Point &operator/=(const T b){ return (*this) = (*this) / b; }\r\n  Point &operator+=(const\
    \ Point &b){ return (*this) = (*this) + b; }\r\n  Point &operator-=(const Point\
    \ &b){ return (*this) = (*this) - b; }\r\n  Point &operator*=(const Point &b){\
    \ return (*this) = (*this) * b; }\r\n  Point &operator/=(const Point &b){ return\
    \ (*this) = (*this) / b; }\r\n  \r\n  bool operator==(const Point &b) const {\r\
    \n    return geometry::eq(x, b.x) && geometry::eq(y, b.y);\r\n  }\r\n  bool operator!=(const\
    \ Point &b) const {\r\n    return !(geometry::eq(x, b.x) && geometry::eq(y, b.y));\r\
    \n  }\r\n  bool operator<(const Point &b) const { \r\n    if(geometry::eq(x, b.x))\
    \ return y < b.y;\r\n    return x < b.x;\r\n  }\r\n  T norm() const { return x\
    \ * x + y * y; }\r\n  double abs() const { return hypot<double>(x, y); }\r\n \
    \ double dist(const Point &b) const { return hypot<double>(x - b.x, y - b.y);\
    \ }\r\n  double arg() const { return atan2<double>(y, x); }\r\n  \r\n  Point ArgVec()\
    \ const {\r\n    if((*this) == Point(0, 0)) return (*this);\r\n    if(geometry::is_zero(x))\
    \ return Point(0, -1);\r\n    return (*this) / gcd(x, y) * (x < 0 ? -1 : 1);\r\
    \n  }\r\n\r\n  int ort() const {\r\n    if(geometry::is_zero(x) && geometry::is_zero(y))\
    \ return 0;\r\n    if(geometry::is_zero(y)) return x > 0 ? 1 : 3;\r\n    if(geometry::is_zero(x))\
    \ return y > 0 ? 2 : 4;\r\n    if (y > 0) return x > 0 ? 1 : 2;\r\n    else return\
    \ x > 0 ? 4 : 3;\r\n  }\r\n  Point rotate90() const { return Point(-y, x);}\r\n\
    \  Point rotate180() const { return Point(-x, -y);}\r\n  Point rotate270() const\
    \ { return Point(y, -x);}\r\n\r\n  Point flip_x(T p = 0) const { return Point(p*2\
    \ - x, y);}\r\n  Point flip_y(T p = 0) const { return Point(x, p*2 - y);}\r\n\r\
    \n  Point rotate(double theta) const {\r\n    return Point(cos(theta)*x - sin(theta)*y,\
    \ sin(theta)*x + cos(theta)*y);\r\n  }\r\n\r\n  Point flip(double theta) const\
    \ {\r\n    return (*this).rotate(-theta).flip_y().rotate(theta);\r\n  }\r\n\r\n\
    \  friend ostream &operator<<(ostream &os, const Point &p) {\r\n    return os\
    \ << p.x << \" \" << p.y;\r\n  }\r\n  friend istream &operator>>(istream &is,\
    \ Point &p) {\r\n    T a, b; is >> a >> b;\r\n    p = Point<T>(a, b);\r\n    return\
    \ (is);\r\n  }\r\n\r\n  T cross(const Point &p) const { return x * p.y - y * p.x;\
    \ }\r\n  T cross(const Point &p, const Point &q) const { return (p - (*this)).cross(q\
    \ - (*this)) ; }\r\n\r\n  T dot(const Point &p) const { return x * p.x + y * p.y;\
    \ }\r\n  T dot(const Point &p, const Point &q) const { return (p - (*this)).dot(q\
    \ - (*this)) ; }\r\n\r\n  \r\n};\r\n\r\ntemplate<typename T> Point<T> Polar(const\
    \ T& rho, const T& theta = 0){\r\n  return Point<T>(rho * cos(theta), rho * sin(theta));\r\
    \n}\r\n\r\ntemplate<typename T> using Polygon = vector<Point<T>>;\r\n\r\ntemplate<class\
    \ T> int iSP(const Point<T> &a, const Point<T> &b, const Point<T> &c){\r\n  T\
    \ fl = a.cross(b, c);\r\n  if(geometry::lt(T(0), fl)) return 1; // CCW\r\n  if(geometry::lt(fl,\
    \ T(0))) return -1; // CW\r\n  if(geometry::lt(b.dot(a, c), T(0))) return 2; //abc\r\
    \n  if(geometry::lt(a.dot(b, c), T(0))) return -2; //bac\r\n  return 0; // acb\r\
    \n}\r\n\r\ntemplate<typename T>\r\nbool cmp_y(const Point<T>& p1, const Point<T>\
    \ &p2){\r\n  if(p1.y == p2.y) return p1.x < p2.x;\r\n  return p1.y < p2.y;\r\n\
    }\r\n\r\ntemplate<typename T>\r\nbool cmp_arg(const Point<T>& p1, const Point<T>\
    \ &p2){\r\n  if(p1.ort() != p2.ort()) return p1.ort() < p2.ort();\r\n  return\
    \ p1.cross(p2) > 0;\r\n}\r\n\r\ntemplate<typename T>\r\nvoid arg_sort(Polygon<T>\
    \ &ps){\r\n  sort(begin(ps), end(ps), cmp_arg<T>);\r\n}\r\n#line 5 \"math/geometry/Geometry.cpp\"\
    \n\r\n\r\ntemplate<class T> struct Line{\r\n  Point<T> a, b;\r\n  Line() {}\r\n\
    \  Line(const Point<T> &a, const Point<T> &b): a(a), b(b) {}\r\n  Line(T A, T\
    \ B, T C){ // Ax + By = C\r\n    if(geometry::is_zero(A)){ a = Point<T>(0, C/B);\
    \ b = Point<T>(1, C/B); }\r\n    else if(geometry::is_zero(B)){ a = Point<T>(C/A,\
    \ 0); b = Point<T>(C/A, 1); }\r\n    else if(geometry::is_zero(C)){ a = Point<T>(0,\
    \ 0); b = Point<T>(1, -A/B); }\r\n    else{ a = Point<T>(0, C/B); b = Point<T>(C/A,\
    \ 0); }\r\n  }\r\n  //Line(const Segment<T> &s): a(s.a), b(s.b) {}\r\n  Point<T>\
    \ projection(const Point<T> &p) const {\r\n    return a + (b - a) * a.dot(p, b)\
    \ / (b - a).norm();\r\n  }\r\n  Point<T> reflection(const Point<T> &p) const {\r\
    \n    return p + (projection(p) - p)*2;\r\n  }\r\n  int angletype(const Line &l)\
    \ const {\r\n    if(geometry::is_zero((b - a).cross(l.b - l.a))) return 1;\r\n\
    \    if(geometry::is_zero((a - b).dot(l.b - l.a))) return -1;\r\n    return 0;\r\
    \n  }\r\n  bool intersect(const Line &l) const {\r\n    return angletype(l) !=\
    \ 1;\r\n  }\r\n  Point<T> cross_point(const Line &l) const {\r\n    if(geometry::is_zero((b\
    \ - a).cross(l.b - l.a))) return l.a;\r\n    return (b - a) * ((l.a - a).cross(l.b\
    \ - l.a)) / ((b - a).cross(l.b - l.a)) + a;\r\n  }\r\n  double dist(const Point<T>\
    \ &p) const {\r\n    return abs(a.cross(p, b)/(b - a).abs());\r\n  }\r\n  double\
    \ dist(const Line &l) const {\r\n    if(intersect(l)) return 0;\r\n    return\
    \ dist(l.a);\r\n  }\r\n};\r\n\r\ntemplate<class T> struct Segment{\r\n  Point<T>\
    \ a, b;\r\n  Segment() {}\r\n  Segment(const Point<T> &a, const Point<T> &b):\
    \ a(a), b(b) {}\r\n\r\n  double length() const { return a.dist(b); }\r\n  bool\
    \ intersect(const Segment &s) const {\r\n    return iSP(a, b, s.a)*iSP(a, b, s.b)\
    \ <= 0 && iSP(s.a, s.b, a)*iSP(s.a, s.b, b) <= 0;\r\n  }\r\n  Point<T> center()\
    \ const { return (a + b) / 2; }\r\n  Line<T> perp_bisector() const {\r\n    Point<T>\
    \ center = this->center();\r\n    return Line<T>((a - center).rotate90() + center,\
    \ center);\r\n  }\r\n  int angletype(const Segment &s) const {\r\n    if(geometry::is_zero((b\
    \ - a).cross(s.b - s.a))) return 1;\r\n    if(geometry::is_zero((a - b).dot(s.b\
    \ - s.a))) return -1;\r\n    return 0;\r\n  }\r\n  Point<T> cross_point(const\
    \ Segment &s) const {\r\n    if(geometry::is_zero((b - a).cross(s.b - s.a))) return\
    \ s.a;\r\n    return (b - a) * ((s.a - a).cross(s.b - s.a)) / ((b - a).cross(s.b\
    \ - s.a)) + a;\r\n  }\r\n  double dist(const Point<T> &p) const {\r\n    if(geometry::lt(a.dot(b,\
    \ p), T(0))) return p.dist(a);\r\n    if(geometry::lt(b.dot(a, p), T(0))) return\
    \ p.dist(b);\r\n    return abs(a.cross(p, b) / (b-a).abs());\r\n  }\r\n  double\
    \ dist(const Segment &s) const {\r\n    if(intersect(s)) return 0;\r\n    return\
    \ min({dist(s.a), dist(s.b), s.dist(a), s.dist(b)});\r\n  }\r\n};\r\n\r\ntemplate<typename\
    \ T>\r\nstruct Triangle{\r\n  Point<T> a, b, c;\r\n  Triangle() {}\r\n  Triangle(const\
    \ Point<T> &a, const Point<T> &b, const Point<T> &c): a(a), b(b), c(c){}\r\n\r\
    \n  double angle_a() const {\r\n    double ab = a.dist(b), bc = b.dist(c), ca\
    \ = c.dist(a);\r\n    return acos((ca*ca + ab*ab - bc*bc)/(2*ca*ab));\r\n  }\r\
    \n  double angle_b() const {\r\n    double ab = a.dist(b), bc = b.dist(c), ca\
    \ = c.dist(a);\r\n    return acos((ab*ab + bc*bc - ca*ca)/(2*ab*bc));\r\n  }\r\
    \n  double angle_c() const {\r\n    double ab = a.dist(b), bc = b.dist(c), ca\
    \ = c.dist(a);\r\n    return acos((bc*bc + ca*ca - ab*ab)/(2*bc*ca));\r\n  }\r\
    \n  Point<T> divpoint(double p, double q, double r) const {\r\n    return (a*p\
    \ + b*q + c*r)/(p + q + r);\r\n  }\r\n\r\n  Point<T> centerofgravity() const {\r\
    \n    return (a + b + c)/3;\r\n  }\r\n  Point<T> circumcenter() const {\r\n  \
    \  Segment<T> s1(a, b), s2(a, c);\r\n    return s1.perp_bisector().cross_point(s2.perp_bisector());\r\
    \n  }\r\n  Point<T> orthocenter() const {\r\n    return centerofgravity()*3 -\
    \ circumcenter()*2;\r\n  }\r\n  Point<T> innercenter() const {\r\n    return divpoint(b.dist(c),\
    \ c.dist(a), a.dist(b));\r\n  }\r\n  Point<T> excenterA() const {\r\n    return\
    \ divpoint(-b.dist(c), c.dist(a), a.dist(b));\r\n  }\r\n  Point<T> excenterB()\
    \ const {\r\n    return divpoint(b.dist(c), -c.dist(a), a.dist(b));\r\n  }\r\n\
    \  Point<T> excenterC() const {\r\n    return divpoint(b.dist(c), c.dist(a), -a.dist(b));\r\
    \n  }\r\n};\r\n\r\ntemplate<class T> struct Circle{\r\n  Point<T> o;\r\n  T r;\r\
    \n  Circle() {}\r\n  Circle(const T &r): o(0, 0), r(r) {}\r\n  Circle(const Point<T>\
    \ &o, const T &r): o(o), r(r) {}\r\n  Circle(const Point<T> &a, const Point<T>\
    \ &b): o((a + b)/2), r(a.dist(b)/2) {}\r\n  Circle(const Point<T> &a, const Point<T>\
    \ &b, const Point<T> &c)\r\n    : o(Triangle(a,b,c).circumcenter()), r(o.dist(a))\
    \ {}\r\n\r\n  int intersect(const Circle&c) const {\r\n    if(r < c.r) return\
    \ c.intersect(*this);\r\n    auto od = (o - c.o).norm();\r\n    auto ra = (r +\
    \ c.r)*(r + c.r), rs = (r - c.r)*(r - c.r);\r\n    if(geometry::lt(ra, od)) return\
    \ 4;\r\n    if(geometry::eq(ra, od)) return 3;\r\n    if(geometry::lt(rs, od))\
    \ return 2;\r\n    if(geometry::eq(rs, od)) return 1;\r\n    return 0;\r\n  }\r\
    \n\r\n  bool is_intersect(const Circle&c) const {\r\n    int k = this->intersect(c);\r\
    \n    return !(k == 0 || k == 4);\r\n  }\r\n\r\n  int intersect(const Line<T>\
    \ &l) const {\r\n    double d = l.dist(o);\r\n    if(geometry::lt<double>(d, r))\
    \ return 2;\r\n    return geometry::eq(d, r);\r\n  }\r\n\r\n  int contains(const\
    \ Point<T> &p) const {\r\n    auto od = (o - p).norm();\r\n    if(geometry::eq(od,\
    \ r*r)) return 1; // on\r\n    return (od > r*r) ? 2 : 0; // out/in\r\n  }\r\n\
    \r\n  Polygon<T> cross_points(const Line<T> &l) const {\r\n    int k = this->intersect(l);\r\
    \n    if(k == 0) return {};\r\n    Point<T> p = l.projection(o);\r\n    if(k ==\
    \ 1) return {p};\r\n    Point<T> d = (l.b - l.a)/l.a.dist(l.b);\r\n    double\
    \ base = geometry::psqrt(r*r - (p - o).norm());\r\n    return {p - d*base, p +\
    \ d*base};\r\n  }\r\n\r\n  Polygon<T> cross_points(const Segment<T> &s) const\
    \ {\r\n    Polygon<T> ps;\r\n    for(const auto &p : this->cross_points(Line<T>(s.a,\
    \ s.b))){\r\n      if((p == s.a) || (p == s.b) || (iSP(s.a, p, s.b) == 2)){\r\n\
    \        ps.push_back(p);\r\n      }\r\n    }\r\n    return ps;\r\n  }\r\n\r\n\
    \  Polygon<T> cross_points(const Circle &c) const {\r\n    int k = this->intersect(c);\r\
    \n    if(k == 0 || k == 4) return {};\r\n    double d = o.dist(c.o), h = (r*r\
    \ - c.r*c.r + d*d) / (d*2);\r\n    Point<T> v = (c.o - o) / d;\r\n    if(k ==\
    \ 1 || k == 3) return {o + v*Point<T>(h, 0) };\r\n    double s = geometry::psqrt(r*r\
    \ - h*h);\r\n    return {o + v*Point<T>(h, s), o + v*Point<T>(h, -s) };\r\n  }\r\
    \n\r\n  Polygon<T> tangent_points(const Point<T> &p) const {\r\n    int t = this->contains(p);\r\
    \n    if(t == 0) return {};\r\n    if(t == 1) return {p};\r\n    double d = p.dist(o),\
    \ h = r*r/d, s = geometry::psqrt(r*r - h*h);\r\n    Point<T> v = (p - o) / d;\r\
    \n    return {o + v*h + v.rotate90()*s, o + v*h + v.rotate270()*s};\r\n  }\r\n\
    \r\n  Polygon<T> tangent_points(const Circle &c) const {\r\n    int k = this->intersect(c);\r\
    \n    if(k == 0) return {};\r\n    Polygon<T> ps; \r\n    Point<T> p = c.o - o;\r\
    \n\r\n    if(k == 1) return { p*r*(r - c.r)/p.norm() + o };\r\n\r\n    double\
    \ d = geometry::psqrt(p.norm() - (r - c.r)*(r - c.r));\r\n    ps.push_back((p*(r\
    \ - c.r) + p.rotate90()*d)*r/p.norm() + o);\r\n    ps.push_back((p*(r - c.r) +\
    \ p.rotate270()*d)*r/p.norm() + o);\r\n    if(k == 2) return ps;\r\n\r\n    if(k\
    \ == 3){\r\n      ps.push_back(p*r*(r + c.r)/p.norm() + o);\r\n      return ps;\r\
    \n    }\r\n\r\n    d = geometry::psqrt(p.norm() - (r + c.r)*(r + c.r));\r\n  \
    \  ps.push_back((p*(r + c.r) + p.rotate90()*d)*r/p.norm() + o);\r\n    ps.push_back((p*(r\
    \ + c.r) + p.rotate270()*d)*r/p.norm() + o);\r\n    \r\n    return ps;\r\n  }\r\
    \n\r\n  double area() const { return r * r * acos(-1.0); }\r\n\r\n  friend ostream\
    \ &operator<<(ostream &os, const Circle &c) {\r\n    return os << c.o << \" \"\
    \ << c.r;\r\n  }\r\n  friend istream &operator>>(istream &is, Circle &c) {\r\n\
    \    Point<T> p; T l; is >> p >> l;\r\n    c = Circle<T>(p, l);\r\n    return\
    \ (is);\r\n  }\r\n};\r\n#line 4 \"math/geometry/manhattan_intersections.cpp\"\n\
    \r\n\r\ntemplate<typename T>\r\nint64_t manhattan_intersections(vector<Segment<T>>\
    \ ss){\r\n  const int n = int(ss.size());\r\n  vector<T> xs(n*2);\r\n  for(int\
    \ i = 0; i < n; ++i) xs[i] = ss[i].a.x, xs[i+n] = ss[i].b.x;\r\n  sort(begin(xs),\
    \ end(xs)); xs.erase(unique(begin(xs), end(xs)), end(xs));\r\n  const int m =\
    \ int(xs.size());\r\n\r\n  auto lb = [&](const T &x){\r\n    return (int)std::distance(begin(xs),\
    \ lower_bound(begin(xs),end(xs), x)); };\r\n  \r\n  vector<tuple<T, int, int>>\
    \ qs;\r\n  for(auto&&[a, b] : ss){\r\n    if(a.y == b.y){\r\n      if(a.x > b.x)\
    \ swap(a, b);\r\n      qs.emplace_back(a.y, lb(a.x), lb(b.x));\r\n    }else{\r\
    \n      if(a.y > b.y) swap(a, b);\r\n      qs.emplace_back(a.y, -1, lb(a.x));\
    \ qs.emplace_back(b.y, m, lb(b.x));\r\n    }\r\n  }\r\n\r\n  sort(begin(qs), end(qs));\r\
    \n  vector<int> fw(m + 1);\r\n  auto add = [&](int x, int c){\r\n    for(int idx\
    \ = x+1; idx <= m; idx += (idx&-idx)) fw[idx] += c;\r\n  };\r\n  auto sum = [&](int\
    \ i){\r\n    int ret = 0;\r\n    for(int idx = i; idx > 0; idx -= (idx & -idx))\
    \ ret += fw[idx];\r\n    return ret;\r\n  };\r\n  int64_t ans = 0;\r\n  for(auto&[y,\
    \ a, b] : qs){\r\n    if(a == -1) add(b, 1);\r\n    else if(a == m) add(b, -1);\r\
    \n    else ans += sum(b+1) - sum(a);\r\n  }\r\n  return ans;\r\n}\r\n"
  code: "#pragma once\r\n\r\n#include \"./Geometry.cpp\"\r\n\r\n\r\ntemplate<typename\
    \ T>\r\nint64_t manhattan_intersections(vector<Segment<T>> ss){\r\n  const int\
    \ n = int(ss.size());\r\n  vector<T> xs(n*2);\r\n  for(int i = 0; i < n; ++i)\
    \ xs[i] = ss[i].a.x, xs[i+n] = ss[i].b.x;\r\n  sort(begin(xs), end(xs)); xs.erase(unique(begin(xs),\
    \ end(xs)), end(xs));\r\n  const int m = int(xs.size());\r\n\r\n  auto lb = [&](const\
    \ T &x){\r\n    return (int)std::distance(begin(xs), lower_bound(begin(xs),end(xs),\
    \ x)); };\r\n  \r\n  vector<tuple<T, int, int>> qs;\r\n  for(auto&&[a, b] : ss){\r\
    \n    if(a.y == b.y){\r\n      if(a.x > b.x) swap(a, b);\r\n      qs.emplace_back(a.y,\
    \ lb(a.x), lb(b.x));\r\n    }else{\r\n      if(a.y > b.y) swap(a, b);\r\n    \
    \  qs.emplace_back(a.y, -1, lb(a.x)); qs.emplace_back(b.y, m, lb(b.x));\r\n  \
    \  }\r\n  }\r\n\r\n  sort(begin(qs), end(qs));\r\n  vector<int> fw(m + 1);\r\n\
    \  auto add = [&](int x, int c){\r\n    for(int idx = x+1; idx <= m; idx += (idx&-idx))\
    \ fw[idx] += c;\r\n  };\r\n  auto sum = [&](int i){\r\n    int ret = 0;\r\n  \
    \  for(int idx = i; idx > 0; idx -= (idx & -idx)) ret += fw[idx];\r\n    return\
    \ ret;\r\n  };\r\n  int64_t ans = 0;\r\n  for(auto&[y, a, b] : qs){\r\n    if(a\
    \ == -1) add(b, 1);\r\n    else if(a == m) add(b, -1);\r\n    else ans += sum(b+1)\
    \ - sum(a);\r\n  }\r\n  return ans;\r\n}\r\n"
  dependsOn:
  - math/geometry/Geometry.cpp
  - math/geometry/geometry_base.cpp
  - math/geometry/Point.cpp
  isVerificationFile: false
  path: math/geometry/manhattan_intersections.cpp
  requiredBy: []
  timestamp: '2023-07-01 17:56:18+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/geometry/manhattan_intersections.cpp
layout: document
redirect_from:
- /library/math/geometry/manhattan_intersections.cpp
- /library/math/geometry/manhattan_intersections.cpp.html
title: math/geometry/manhattan_intersections.cpp
---
