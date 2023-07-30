---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: math/geometry/Point.cpp
    title: math/geometry/Point.cpp
  - icon: ':warning:'
    path: math/geometry/geometry_base.cpp
    title: math/geometry/geometry_base.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/geometry/is_convex.cpp\"\n\r\n#line 2 \"math/geometry/Point.cpp\"\
    \n\r\n#line 2 \"math/geometry/geometry_base.cpp\"\n\r\nnamespace geometry{\r\n\
    \  constexpr double eps = 1e-10;\r\n  bool eq(double a, double b){ return fabs(a\
    \ - b) < eps; }\r\n  template<typename T>  bool eq(T a, T b){ return a == b; }\r\
    \n  bool is_zero(double a){ return fabs(a) < eps; }\r\n  template<typename T>\
    \ bool is_zero(T a){ return a == 0; }\r\n  bool le(double a, double b){ return\
    \ a <= b + eps; }\r\n  template<typename T> bool le(T a, T b){ return a <= b;\
    \ }\r\n  bool lt(double a, double b){ return a < b - eps; }\r\n  template<typename\
    \ T> bool lt(T a, T b){ return a < b; }\r\n  int sgn(double a){ return is_zero(a)\
    \ ? 0 : ((a < 0) ? -1 : 1); }\r\n  template<typename T> int sgn(T a){ return (a<0)\
    \ ? -1 : ((a > 0) ? 1 : 0); }\r\n  template<typename T> double psqrt(T a){ return\
    \ sqrt(max(T(0), a)); }\r\n\r\n  enum Dir{ BAC = -2, CW, ACB, CCW, ABC };\r\n\
    };\r\n\r\n#line 4 \"math/geometry/Point.cpp\"\n\r\n\r\ntemplate<class T> struct\
    \ Point{\r\n  T x,y;\r\n  Point() = default;\r\n  Point(T x, T y) : x(x), y(y)\
    \ {}\r\n  Point(const pair<T,T> &p) : x(p.first), y(p.second) {}\r\n\r\n  Point\
    \ operator*(const T b) const { return Point(x * b, y * b); }\r\n  Point operator/(const\
    \ T b) const { return Point(x / b, y / b); }\r\n  Point operator+(const Point\
    \ &b) const { return Point(x + b.x, y + b.y); }\r\n  Point operator-(const Point\
    \ &b) const { return Point(x - b.x, y - b.y); }\r\n  Point operator*(const Point\
    \ &b) const { return Point(x*b.x - y*b.y, x*b.y + y*b.x); }\r\n  Point operator/(const\
    \ Point &b) const { return Point(x*b.x + y*b.y, y*b.x - x*b.y)/(b.x*b.x + b.y*b.y);\
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
    \ &ps){\r\n  sort(begin(ps), end(ps), cmp_arg<T>);\r\n}\r\n#line 4 \"math/geometry/is_convex.cpp\"\
    \n\r\n\r\ntemplate<typename T> bool is_convex(const Polygon<T> &ps, bool strict\
    \ = true){\r\n  int n = ps.size();\r\n  for(int i = 0; i < n; i++){\r\n    int\
    \ j = (i+1==n) ? 0 : (i + 1);\r\n    int k = (j+1==n) ? 0 : (j + 1);\r\n    if(strict){\r\
    \n      if(iSP(ps[i], ps[j], ps[k]) != geometry::CCW) return false;\r\n    }else{\r\
    \n      if(iSP(ps[i], ps[j], ps[k]) == geometry::CW) return false;\r\n    }\r\n\
    \  }\r\n  return true;\r\n}\r\n"
  code: "#pragma once\r\n\r\n#include \"./Point.cpp\"\r\n\r\n\r\ntemplate<typename\
    \ T> bool is_convex(const Polygon<T> &ps, bool strict = true){\r\n  int n = ps.size();\r\
    \n  for(int i = 0; i < n; i++){\r\n    int j = (i+1==n) ? 0 : (i + 1);\r\n   \
    \ int k = (j+1==n) ? 0 : (j + 1);\r\n    if(strict){\r\n      if(iSP(ps[i], ps[j],\
    \ ps[k]) != geometry::CCW) return false;\r\n    }else{\r\n      if(iSP(ps[i],\
    \ ps[j], ps[k]) == geometry::CW) return false;\r\n    }\r\n  }\r\n  return true;\r\
    \n}\r\n"
  dependsOn:
  - math/geometry/Point.cpp
  - math/geometry/geometry_base.cpp
  isVerificationFile: false
  path: math/geometry/is_convex.cpp
  requiredBy: []
  timestamp: '2023-07-01 17:56:18+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/geometry/is_convex.cpp
layout: document
redirect_from:
- /library/math/geometry/is_convex.cpp
- /library/math/geometry/is_convex.cpp.html
title: math/geometry/is_convex.cpp
---
