---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: math/geometry/Geometry.cpp
    title: math/geometry/Geometry.cpp
  - icon: ':heavy_check_mark:'
    path: math/geometry/Point.cpp
    title: math/geometry/Point.cpp
  - icon: ':warning:'
    path: math/geometry/area.cpp
    title: math/geometry/area.cpp
  - icon: ':warning:'
    path: math/geometry/bitonicTSP.cpp
    title: math/geometry/bitonicTSP.cpp
  - icon: ':warning:'
    path: math/geometry/clock_hands.cpp
    title: math/geometry/clock_hands.cpp
  - icon: ':warning:'
    path: math/geometry/closest_pair.cpp
    title: math/geometry/closest_pair.cpp
  - icon: ':warning:'
    path: math/geometry/convex_cut.cpp
    title: math/geometry/convex_cut.cpp
  - icon: ':warning:'
    path: math/geometry/convex_diameter.cpp
    title: math/geometry/convex_diameter.cpp
  - icon: ':warning:'
    path: math/geometry/convex_hull.cpp
    title: math/geometry/convex_hull.cpp
  - icon: ':warning:'
    path: math/geometry/inner_points.cpp
    title: math/geometry/inner_points.cpp
  - icon: ':warning:'
    path: math/geometry/is_congruence.cpp
    title: math/geometry/is_congruence.cpp
  - icon: ':warning:'
    path: math/geometry/is_contains.cpp
    title: math/geometry/is_contains.cpp
  - icon: ':warning:'
    path: math/geometry/is_convex.cpp
    title: math/geometry/is_convex.cpp
  - icon: ':warning:'
    path: math/geometry/manhattan_intersections.cpp
    title: math/geometry/manhattan_intersections.cpp
  - icon: ':warning:'
    path: math/geometry/smallest_enclosing_circle.cpp
    title: math/geometry/smallest_enclosing_circle.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/verify/aoj/gcl_1_a.test.cpp
    title: test/verify/aoj/gcl_1_a.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/verify/aoj/gcl_1_b.test.cpp
    title: test/verify/aoj/gcl_1_b.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/verify/aoj/gcl_1_c.test.cpp
    title: test/verify/aoj/gcl_1_c.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/geometry/geometry_base.cpp\"\n\r\nnamespace geometry{\r\
    \n  constexpr double eps = 1e-10;\r\n  bool eq(double a, double b){ return fabs(a\
    \ - b) < eps; }\r\n  template<typename T>  bool eq(T a, T b){ return a == b; }\r\
    \n  bool is_zero(double a){ return fabs(a) < eps; }\r\n  template<typename T>\
    \ bool is_zero(T a){ return a == 0; }\r\n  bool le(double a, double b){ return\
    \ a <= b + eps; }\r\n  template<typename T> bool le(T a, T b){ return a <= b;\
    \ }\r\n  bool lt(double a, double b){ return a < b - eps; }\r\n  template<typename\
    \ T> bool lt(T a, T b){ return a < b; }\r\n  int sgn(double a){ return is_zero(a)\
    \ ? 0 : ((a < 0) ? -1 : 1); }\r\n  template<typename T> int sgn(T a){ return (a<0)\
    \ ? -1 : ((a > 0) ? 1 : 0); }\r\n  template<typename T> double psqrt(T a){ return\
    \ sqrt(max(T(0), a)); }\r\n\r\n  enum Dir{ BAC = -2, CW, ACB, CCW, ABC };\r\n\
    };\r\n\r\n"
  code: "#pragma once\r\n\r\nnamespace geometry{\r\n  constexpr double eps = 1e-10;\r\
    \n  bool eq(double a, double b){ return fabs(a - b) < eps; }\r\n  template<typename\
    \ T>  bool eq(T a, T b){ return a == b; }\r\n  bool is_zero(double a){ return\
    \ fabs(a) < eps; }\r\n  template<typename T> bool is_zero(T a){ return a == 0;\
    \ }\r\n  bool le(double a, double b){ return a <= b + eps; }\r\n  template<typename\
    \ T> bool le(T a, T b){ return a <= b; }\r\n  bool lt(double a, double b){ return\
    \ a < b - eps; }\r\n  template<typename T> bool lt(T a, T b){ return a < b; }\r\
    \n  int sgn(double a){ return is_zero(a) ? 0 : ((a < 0) ? -1 : 1); }\r\n  template<typename\
    \ T> int sgn(T a){ return (a<0) ? -1 : ((a > 0) ? 1 : 0); }\r\n  template<typename\
    \ T> double psqrt(T a){ return sqrt(max(T(0), a)); }\r\n\r\n  enum Dir{ BAC =\
    \ -2, CW, ACB, CCW, ABC };\r\n};\r\n\r\n"
  dependsOn: []
  isVerificationFile: false
  path: math/geometry/geometry_base.cpp
  requiredBy:
  - math/geometry/smallest_enclosing_circle.cpp
  - math/geometry/manhattan_intersections.cpp
  - math/geometry/bitonicTSP.cpp
  - math/geometry/Point.cpp
  - math/geometry/convex_diameter.cpp
  - math/geometry/clock_hands.cpp
  - math/geometry/convex_cut.cpp
  - math/geometry/inner_points.cpp
  - math/geometry/Geometry.cpp
  - math/geometry/is_congruence.cpp
  - math/geometry/convex_hull.cpp
  - math/geometry/area.cpp
  - math/geometry/is_contains.cpp
  - math/geometry/closest_pair.cpp
  - math/geometry/is_convex.cpp
  timestamp: '2023-02-10 15:07:37+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/verify/aoj/gcl_1_a.test.cpp
  - test/verify/aoj/gcl_1_b.test.cpp
  - test/verify/aoj/gcl_1_c.test.cpp
documentation_of: math/geometry/geometry_base.cpp
layout: document
redirect_from:
- /library/math/geometry/geometry_base.cpp
- /library/math/geometry/geometry_base.cpp.html
title: math/geometry/geometry_base.cpp
---
