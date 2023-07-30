---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: math/geometry/Geometry.cpp
    title: math/geometry/Geometry.cpp
  - icon: ':warning:'
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
  - icon: ':warning:'
    path: test/verify/aoj/gcl_1_a.cpp
    title: test/verify/aoj/gcl_1_a.cpp
  - icon: ':warning:'
    path: test/verify/aoj/gcl_1_b.cpp
    title: test/verify/aoj/gcl_1_b.cpp
  - icon: ':warning:'
    path: test/verify/aoj/gcl_1_c.cpp
    title: test/verify/aoj/gcl_1_c.cpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
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
  - math/geometry/Geometry.cpp
  - math/geometry/closest_pair.cpp
  - math/geometry/manhattan_intersections.cpp
  - math/geometry/convex_diameter.cpp
  - math/geometry/Point.cpp
  - math/geometry/is_contains.cpp
  - math/geometry/convex_hull.cpp
  - math/geometry/clock_hands.cpp
  - math/geometry/bitonicTSP.cpp
  - math/geometry/area.cpp
  - math/geometry/is_congruence.cpp
  - math/geometry/smallest_enclosing_circle.cpp
  - math/geometry/convex_cut.cpp
  - math/geometry/inner_points.cpp
  - math/geometry/is_convex.cpp
  - test/verify/aoj/gcl_1_a.cpp
  - test/verify/aoj/gcl_1_b.cpp
  - test/verify/aoj/gcl_1_c.cpp
  timestamp: '2023-02-10 15:07:37+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/geometry/geometry_base.cpp
layout: document
redirect_from:
- /library/math/geometry/geometry_base.cpp
- /library/math/geometry/geometry_base.cpp.html
title: math/geometry/geometry_base.cpp
---
