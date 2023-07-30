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
  bundledCode: "#line 2 \"math/mod/HashInt.cpp\"\n\r\nstruct HashInt{\r\n  static\
    \ constexpr uint64_t mod = (1ull << 61) - 1;\r\n  static constexpr uint64_t mask(int\
    \ k){ return (1ull << k) - 1; }\r\n  static constexpr uint64_t add(uint64_t a,\
    \ uint64_t b){\r\n    return ((a+=b) >= mod) ? (a - mod) : a;\r\n  }\r\n  static\
    \ constexpr uint64_t mul(uint64_t a, uint64_t b){\r\n    uint64_t au = a >> 31,\
    \ ad = a & mask(31);\r\n    uint64_t bu = b >> 31, bd = b & mask(31);\r\n    int64_t\
    \ mid = ad*bu + au*bd;\r\n    uint64_t mu = mid >> 30, md = mid & mask(30);\r\n\
    \    return au*bu*2 + mu + (md << 31) + ad*bd;\r\n  }\r\n  static constexpr uint64_t\
    \ cal_mod(uint64_t a){\r\n    uint64_t res = (a >> 61) + (a & mask(61));\r\n \
    \   return (res>=mod) ? (res-mod) : res;\r\n  }\r\n\r\n  uint64_t x;\r\n  HashInt()\
    \ = default;\r\n  HashInt(uint64_t x): x(cal_mod(x)) {}\r\n\r\n  HashInt operator-()\
    \ const { return HashInt(x == 0 ? 0 : mod - x); }\r\n  HashInt &operator+=(const\
    \ HashInt &h){ x = add(x, h.x); return (*this); }\r\n  HashInt &operator-=(const\
    \ HashInt &h){ return (*this) += -h; }\r\n  HashInt &operator*=(const HashInt\
    \ &h){ x = cal_mod(mul(x, h.x)); return (*this); }\r\n  HashInt operator+(const\
    \ HashInt &h) const { return HashInt(*this) += h; }\r\n  HashInt operator-(const\
    \ HashInt &h) const { return HashInt(*this) -= h; }\r\n  HashInt operator*(const\
    \ HashInt &h) const { return HashInt(*this) *= h; }\r\n\r\n  bool operator==(const\
    \ HashInt &h) const { return x == h.x; }\r\n  bool operator!=(const HashInt &h)\
    \ const { return x != h.x; }\r\n\r\n  friend istream &operator>>(istream &is,\
    \ HashInt &h){\r\n    uint64_t x; cin >> x; h = HashInt(x);\r\n    return is;\r\
    \n  }\r\n  friend ostream &operator<<(ostream &os, const HashInt &h){ return os\
    \ << h.x; }\r\n};\r\n"
  code: "#pragma once\r\n\r\nstruct HashInt{\r\n  static constexpr uint64_t mod =\
    \ (1ull << 61) - 1;\r\n  static constexpr uint64_t mask(int k){ return (1ull <<\
    \ k) - 1; }\r\n  static constexpr uint64_t add(uint64_t a, uint64_t b){\r\n  \
    \  return ((a+=b) >= mod) ? (a - mod) : a;\r\n  }\r\n  static constexpr uint64_t\
    \ mul(uint64_t a, uint64_t b){\r\n    uint64_t au = a >> 31, ad = a & mask(31);\r\
    \n    uint64_t bu = b >> 31, bd = b & mask(31);\r\n    int64_t mid = ad*bu + au*bd;\r\
    \n    uint64_t mu = mid >> 30, md = mid & mask(30);\r\n    return au*bu*2 + mu\
    \ + (md << 31) + ad*bd;\r\n  }\r\n  static constexpr uint64_t cal_mod(uint64_t\
    \ a){\r\n    uint64_t res = (a >> 61) + (a & mask(61));\r\n    return (res>=mod)\
    \ ? (res-mod) : res;\r\n  }\r\n\r\n  uint64_t x;\r\n  HashInt() = default;\r\n\
    \  HashInt(uint64_t x): x(cal_mod(x)) {}\r\n\r\n  HashInt operator-() const {\
    \ return HashInt(x == 0 ? 0 : mod - x); }\r\n  HashInt &operator+=(const HashInt\
    \ &h){ x = add(x, h.x); return (*this); }\r\n  HashInt &operator-=(const HashInt\
    \ &h){ return (*this) += -h; }\r\n  HashInt &operator*=(const HashInt &h){ x =\
    \ cal_mod(mul(x, h.x)); return (*this); }\r\n  HashInt operator+(const HashInt\
    \ &h) const { return HashInt(*this) += h; }\r\n  HashInt operator-(const HashInt\
    \ &h) const { return HashInt(*this) -= h; }\r\n  HashInt operator*(const HashInt\
    \ &h) const { return HashInt(*this) *= h; }\r\n\r\n  bool operator==(const HashInt\
    \ &h) const { return x == h.x; }\r\n  bool operator!=(const HashInt &h) const\
    \ { return x != h.x; }\r\n\r\n  friend istream &operator>>(istream &is, HashInt\
    \ &h){\r\n    uint64_t x; cin >> x; h = HashInt(x);\r\n    return is;\r\n  }\r\
    \n  friend ostream &operator<<(ostream &os, const HashInt &h){ return os << h.x;\
    \ }\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: math/mod/HashInt.cpp
  requiredBy: []
  timestamp: '2023-02-10 14:54:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/mod/HashInt.cpp
layout: document
redirect_from:
- /library/math/mod/HashInt.cpp
- /library/math/mod/HashInt.cpp.html
title: math/mod/HashInt.cpp
---
