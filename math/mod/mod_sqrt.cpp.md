---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/mod/mod_sqrt.cpp\"\n\r\ntemplate<typename T>\r\nstruct\
    \ QuadraicField{\r\n  T a, b;\r\n  static T &get_base(){\r\n    static T base\
    \ = T(0);\r\n    return base;\r\n  }\r\n  \r\n  static void set_base(const T &bs){\
    \ get_base() = bs; }\r\n\r\n  QuadraicField() {}\r\n  QuadraicField(const T &a,\
    \ const T &b): a(a), b(b) {}\r\n\r\n  QuadraicField &operator+=(const QuadraicField\
    \ &x){\r\n    a += x.a; b += x.b; return (*this);\r\n  }\r\n  QuadraicField &operator-=(const\
    \ QuadraicField &x){\r\n    a -= x.a; b -= x.b; return (*this);\r\n  }\r\n  QuadraicField\
    \ operator*(const QuadraicField &x) const {\r\n    return QuadraicField(a*x.a\
    \ + b*x.b*get_base(), a*x.b+b*x.a);\r\n  }\r\n  QuadraicField &operator*=(const\
    \ QuadraicField &x){\r\n    return (*this) = (*this) * x;\r\n  }\r\n\r\n  QuadraicField\
    \ pow(int64_t n) const {\r\n    QuadraicField res(1, 0), a(*this);\r\n    while(n){\r\
    \n      if(n & 1) res *= a;\r\n      a *= a; n >>= 1;\r\n    }\r\n    return res;\r\
    \n  }\r\n};\r\n\r\ntemplate<typename T>\r\nT mod_sqrt(const T &a){\r\n  if(T::get_mod()\
    \ == 2) return a;\r\n  if(a == T(0)) return a;\r\n  int p = T::get_mod();\r\n\
    \  if(a.pow((p - 1)/2) != 1) return 0;\r\n  T b = 0;\r\n  while((b*b - a).pow((p\
    \ - 1)/2) == 1) ++b;\r\n  QuadraicField<T>::set_base(b*b - a);\r\n  QuadraicField<T>\
    \ x(b, 1);\r\n  return x.pow((p + 1)/2).a;\r\n}\n"
  code: "#pragma once\r\n\r\ntemplate<typename T>\r\nstruct QuadraicField{\r\n  T\
    \ a, b;\r\n  static T &get_base(){\r\n    static T base = T(0);\r\n    return\
    \ base;\r\n  }\r\n  \r\n  static void set_base(const T &bs){ get_base() = bs;\
    \ }\r\n\r\n  QuadraicField() {}\r\n  QuadraicField(const T &a, const T &b): a(a),\
    \ b(b) {}\r\n\r\n  QuadraicField &operator+=(const QuadraicField &x){\r\n    a\
    \ += x.a; b += x.b; return (*this);\r\n  }\r\n  QuadraicField &operator-=(const\
    \ QuadraicField &x){\r\n    a -= x.a; b -= x.b; return (*this);\r\n  }\r\n  QuadraicField\
    \ operator*(const QuadraicField &x) const {\r\n    return QuadraicField(a*x.a\
    \ + b*x.b*get_base(), a*x.b+b*x.a);\r\n  }\r\n  QuadraicField &operator*=(const\
    \ QuadraicField &x){\r\n    return (*this) = (*this) * x;\r\n  }\r\n\r\n  QuadraicField\
    \ pow(int64_t n) const {\r\n    QuadraicField res(1, 0), a(*this);\r\n    while(n){\r\
    \n      if(n & 1) res *= a;\r\n      a *= a; n >>= 1;\r\n    }\r\n    return res;\r\
    \n  }\r\n};\r\n\r\ntemplate<typename T>\r\nT mod_sqrt(const T &a){\r\n  if(T::get_mod()\
    \ == 2) return a;\r\n  if(a == T(0)) return a;\r\n  int p = T::get_mod();\r\n\
    \  if(a.pow((p - 1)/2) != 1) return 0;\r\n  T b = 0;\r\n  while((b*b - a).pow((p\
    \ - 1)/2) == 1) ++b;\r\n  QuadraicField<T>::set_base(b*b - a);\r\n  QuadraicField<T>\
    \ x(b, 1);\r\n  return x.pow((p + 1)/2).a;\r\n}"
  dependsOn: []
  isVerificationFile: false
  path: math/mod/mod_sqrt.cpp
  requiredBy: []
  timestamp: '2023-02-10 14:54:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/mod/mod_sqrt.cpp
layout: document
redirect_from:
- /library/math/mod/mod_sqrt.cpp
- /library/math/mod/mod_sqrt.cpp.html
title: math/mod/mod_sqrt.cpp
---
