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
  bundledCode: "#line 2 \"math/mod/ArbitraryModInt.cpp\"\n\r\n\r\nstruct ArbitraryModInt\
    \ {\r\n  \r\n  int x;\r\n\r\n  ArbitraryModInt() : x(0) {}\r\n\r\n  ArbitraryModInt(int64_t\
    \ y) : x(y >= 0 ? y % get_mod() : (get_mod() - (-y) % get_mod()) % get_mod())\
    \ {}\r\n  \r\n  static int &get_mod() {\r\n    static int mod = 0;\r\n    return\
    \ mod;\r\n  }\r\n\r\n  static void set_mod(int md){\r\n    get_mod() = md;\r\n\
    \  }\r\n\r\n  ArbitraryModInt &operator+=(const ArbitraryModInt &p) {\r\n    if((x\
    \ += p.x) >= get_mod()) x -= get_mod();\r\n    return *this;\r\n  }\r\n  ArbitraryModInt\
    \ &operator-=(const ArbitraryModInt &p) {\r\n    if((x += get_mod() - p.x) >=\
    \ get_mod()) x -= get_mod();\r\n    return *this;\r\n  }\r\n  ArbitraryModInt\
    \ &operator*=(const ArbitraryModInt &p) {\r\n    x = (int) (1LL * x * p.x % get_mod());\r\
    \n    return *this;\r\n  }\r\n  ArbitraryModInt &operator/=(const ArbitraryModInt\
    \ &p) {\r\n    *this *= p.inverse();\r\n    return *this;\r\n  }\r\n  ArbitraryModInt\
    \ operator-() const { return ArbitraryModInt(-x); }\r\n  ArbitraryModInt operator+(const\
    \ ArbitraryModInt &p) const { return ArbitraryModInt(*this) += p; }\r\n  ArbitraryModInt\
    \ operator-(const ArbitraryModInt &p) const { return ArbitraryModInt(*this) -=\
    \ p; }\r\n  ArbitraryModInt operator*(const ArbitraryModInt &p) const { return\
    \ ArbitraryModInt(*this) *= p; }\r\n  ArbitraryModInt operator/(const ArbitraryModInt\
    \ &p) const { return ArbitraryModInt(*this) /= p; }\r\n  bool operator==(const\
    \ ArbitraryModInt &p) const { return x == p.x; }\r\n  bool operator!=(const ArbitraryModInt\
    \ &p) const { return x != p.x; }\r\n  bool operator<(const ArbitraryModInt &p)\
    \ const { return x < p.x; }\r\n\r\n  ArbitraryModInt& operator++() { (*this).x+=1;\
    \ return (*this); }\r\n  ArbitraryModInt& operator--() { (*this).x-=1; return\
    \ (*this); }\r\n  ArbitraryModInt operator++(int) { ArbitraryModInt tmp(*this);\
    \ ++(*this); return tmp; }\r\n  ArbitraryModInt operator--(int) { ArbitraryModInt\
    \ tmp(*this); --(*this); return tmp; }\r\n\r\n  ArbitraryModInt inverse() const\
    \ {\r\n    int a = x, b = get_mod(), u = 1, v = 0, t;\r\n    while(b > 0) {\r\n\
    \      t = a / b;\r\n      swap(a -= t * b, b);\r\n      swap(u -= t * v, v);\r\
    \n    }\r\n    return ArbitraryModInt(u);\r\n  }\r\n  ArbitraryModInt pow(int64_t\
    \ n) const {\r\n    ArbitraryModInt ret(1), mul(x);\r\n    while(n > 0) {\r\n\
    \      if(n & 1) ret *= mul;\r\n      mul *= mul; n >>= 1;\r\n    }\r\n    return\
    \ ret;\r\n  }\r\n  friend ostream &operator<<(ostream &os, const ArbitraryModInt\
    \ &p) {\r\n    return os << p.x;\r\n  }\r\n  friend istream &operator>>(istream\
    \ &is, ArbitraryModInt &a) {\r\n    int64_t t;\r\n    is >> t;\r\n    a = ArbitraryModInt(t);\r\
    \n    return (is);\r\n  }\r\n};\r\nArbitraryModInt operator+(const int64_t &p,\
    \ const ArbitraryModInt &m){ return ArbitraryModInt(p) + m; };\r\nArbitraryModInt\
    \ operator-(const int64_t &p, const ArbitraryModInt &m){ return ArbitraryModInt(p)\
    \ - m; };\r\nArbitraryModInt operator*(const int64_t &p, const ArbitraryModInt\
    \ &m){ return ArbitraryModInt(p) * m; };\r\nArbitraryModInt operator/(const int64_t\
    \ &p, const ArbitraryModInt &m){ return ArbitraryModInt(p) / m; };\r\n\r\nusing\
    \ amint = ArbitraryModInt;\r\nusing VMA = vector<amint>;\r\nusing VVMA = vector<VMA>;\r\
    \n\r\nnamespace amintliteral{ amint operator\"\"_am(unsigned long long x) { return\
    \ amint(x); } }\r\nusing namespace amintliteral;\r\n"
  code: "#pragma once\r\n\r\n\r\nstruct ArbitraryModInt {\r\n  \r\n  int x;\r\n\r\n\
    \  ArbitraryModInt() : x(0) {}\r\n\r\n  ArbitraryModInt(int64_t y) : x(y >= 0\
    \ ? y % get_mod() : (get_mod() - (-y) % get_mod()) % get_mod()) {}\r\n  \r\n \
    \ static int &get_mod() {\r\n    static int mod = 0;\r\n    return mod;\r\n  }\r\
    \n\r\n  static void set_mod(int md){\r\n    get_mod() = md;\r\n  }\r\n\r\n  ArbitraryModInt\
    \ &operator+=(const ArbitraryModInt &p) {\r\n    if((x += p.x) >= get_mod()) x\
    \ -= get_mod();\r\n    return *this;\r\n  }\r\n  ArbitraryModInt &operator-=(const\
    \ ArbitraryModInt &p) {\r\n    if((x += get_mod() - p.x) >= get_mod()) x -= get_mod();\r\
    \n    return *this;\r\n  }\r\n  ArbitraryModInt &operator*=(const ArbitraryModInt\
    \ &p) {\r\n    x = (int) (1LL * x * p.x % get_mod());\r\n    return *this;\r\n\
    \  }\r\n  ArbitraryModInt &operator/=(const ArbitraryModInt &p) {\r\n    *this\
    \ *= p.inverse();\r\n    return *this;\r\n  }\r\n  ArbitraryModInt operator-()\
    \ const { return ArbitraryModInt(-x); }\r\n  ArbitraryModInt operator+(const ArbitraryModInt\
    \ &p) const { return ArbitraryModInt(*this) += p; }\r\n  ArbitraryModInt operator-(const\
    \ ArbitraryModInt &p) const { return ArbitraryModInt(*this) -= p; }\r\n  ArbitraryModInt\
    \ operator*(const ArbitraryModInt &p) const { return ArbitraryModInt(*this) *=\
    \ p; }\r\n  ArbitraryModInt operator/(const ArbitraryModInt &p) const { return\
    \ ArbitraryModInt(*this) /= p; }\r\n  bool operator==(const ArbitraryModInt &p)\
    \ const { return x == p.x; }\r\n  bool operator!=(const ArbitraryModInt &p) const\
    \ { return x != p.x; }\r\n  bool operator<(const ArbitraryModInt &p) const { return\
    \ x < p.x; }\r\n\r\n  ArbitraryModInt& operator++() { (*this).x+=1; return (*this);\
    \ }\r\n  ArbitraryModInt& operator--() { (*this).x-=1; return (*this); }\r\n \
    \ ArbitraryModInt operator++(int) { ArbitraryModInt tmp(*this); ++(*this); return\
    \ tmp; }\r\n  ArbitraryModInt operator--(int) { ArbitraryModInt tmp(*this); --(*this);\
    \ return tmp; }\r\n\r\n  ArbitraryModInt inverse() const {\r\n    int a = x, b\
    \ = get_mod(), u = 1, v = 0, t;\r\n    while(b > 0) {\r\n      t = a / b;\r\n\
    \      swap(a -= t * b, b);\r\n      swap(u -= t * v, v);\r\n    }\r\n    return\
    \ ArbitraryModInt(u);\r\n  }\r\n  ArbitraryModInt pow(int64_t n) const {\r\n \
    \   ArbitraryModInt ret(1), mul(x);\r\n    while(n > 0) {\r\n      if(n & 1) ret\
    \ *= mul;\r\n      mul *= mul; n >>= 1;\r\n    }\r\n    return ret;\r\n  }\r\n\
    \  friend ostream &operator<<(ostream &os, const ArbitraryModInt &p) {\r\n   \
    \ return os << p.x;\r\n  }\r\n  friend istream &operator>>(istream &is, ArbitraryModInt\
    \ &a) {\r\n    int64_t t;\r\n    is >> t;\r\n    a = ArbitraryModInt(t);\r\n \
    \   return (is);\r\n  }\r\n};\r\nArbitraryModInt operator+(const int64_t &p, const\
    \ ArbitraryModInt &m){ return ArbitraryModInt(p) + m; };\r\nArbitraryModInt operator-(const\
    \ int64_t &p, const ArbitraryModInt &m){ return ArbitraryModInt(p) - m; };\r\n\
    ArbitraryModInt operator*(const int64_t &p, const ArbitraryModInt &m){ return\
    \ ArbitraryModInt(p) * m; };\r\nArbitraryModInt operator/(const int64_t &p, const\
    \ ArbitraryModInt &m){ return ArbitraryModInt(p) / m; };\r\n\r\nusing amint =\
    \ ArbitraryModInt;\r\nusing VMA = vector<amint>;\r\nusing VVMA = vector<VMA>;\r\
    \n\r\nnamespace amintliteral{ amint operator\"\"_am(unsigned long long x) { return\
    \ amint(x); } }\r\nusing namespace amintliteral;\r\n"
  dependsOn: []
  isVerificationFile: false
  path: math/mod/ArbitraryModInt.cpp
  requiredBy: []
  timestamp: '2023-02-10 14:54:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/mod/ArbitraryModInt.cpp
layout: document
redirect_from:
- /library/math/mod/ArbitraryModInt.cpp
- /library/math/mod/ArbitraryModInt.cpp.html
title: math/mod/ArbitraryModInt.cpp
---
