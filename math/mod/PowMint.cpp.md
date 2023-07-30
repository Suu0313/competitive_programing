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
  bundledCode: "#line 2 \"math/mod/PowMint.cpp\"\n\r\ntemplate<uint32_t mod>\r\nstruct\
    \ PowMint{\r\nprivate:\r\n  static constexpr uint32_t totient(uint32_t m){\r\n\
    \    uint32_t phi = m;\r\n    for(uint32_t i = 2; i * i <= m; ++i){\r\n      if(m\
    \ % i != 0) continue;\r\n      phi = phi / i * (i - 1);\r\n      do m /= i; while(m\
    \ % i == 0);\r\n    }\r\n    if(m != 1) phi = phi / m * (m - 1);\r\n    return\
    \ phi;\r\n  }\r\n\r\n  static constexpr uint32_t pmod(uint64_t x){\r\n    if(x\
    \ < mod * 2) return x;\r\n    return (x % mod) + mod;\r\n  }\r\n\r\n  static uint32_t\
    \ pow(uint32_t a, uint32_t b){\r\n    uint32_t p = 1;\r\n    for(; b; b >>= 1){\r\
    \n      if(b & 1) p = pmod(uint64_t(p) * a);\r\n      a = pmod(uint64_t(a) * a);\r\
    \n    }\r\n    return p;\r\n  }\r\n\r\npublic:\r\n\r\n  uint32_t a;\r\n  PowMint<totient(mod)>\
    \ r;\r\n\r\n  PowMint() = default;\r\n  PowMint(uint64_t x): a(pmod(x)), r(x)\
    \ {}\r\n  PowMint(uint32_t a, PowMint<totient(mod)> r): a(a), r(r) {}\r\n  \r\n\
    \  uint32_t val() const { return (a < mod) ? a : (a - mod); }\r\n  PowMint &operator*=(const\
    \ PowMint &p){\r\n    a = pmod(uint64_t(a) * p.a);\r\n    r *= p.r;\r\n    return\
    \ (*this);\r\n  }\r\n  PowMint &operator+=(const PowMint &p){\r\n    a += p.a;\r\
    \n    if(a >= mod * 2) a -= mod;\r\n    if(a >= mod * 2) a -= mod;\r\n    r +=\
    \ p.r;\r\n    return (*this);\r\n  }\r\n\r\n  PowMint operator*(const PowMint\
    \ &p) const { return PowMint(*this) *= p; }\r\n  PowMint operator+(const PowMint\
    \ &p) const { return PowMint(*this) += p; }\r\n\r\n  PowMint pow(const PowMint\
    \ &p) const { return{pow(a, p.r.a), r.pow(p.r)}; }\r\n  PowMint operator^(const\
    \ PowMint &p) const { return pow(p); }\r\n  PowMint &operator^=(const PowMint\
    \ &p){ return (*this) = pow(p); }\r\n\r\n  friend ostream &operator<<(ostream\
    \ &os, const PowMint &p) {\r\n    return os << p.val();\r\n  }\r\n  friend istream\
    \ &operator>>(istream &is, PowMint &a) {\r\n    uint64_t t;\r\n    is >> t;\r\n\
    \    a = PowMint(t);\r\n    return (is);\r\n  }\r\n};\r\n\r\ntemplate<> struct\
    \ PowMint<1>{\r\n  uint32_t a;\r\n  PowMint() = default;\r\n  PowMint(uint64_t\
    \ x): a(bool(x)) {}\r\n\r\n  uint32_t val() const { return 0; }\r\n  PowMint &operator*=(const\
    \ PowMint &p){ a &= p.a; return (*this); }\r\n  PowMint &operator+=(const PowMint\
    \ &p){ a += p.a; return (*this); }\r\n  PowMint operator*(const PowMint &p) const\
    \ { return PowMint(*this) *= p; }\r\n  PowMint operator+(const PowMint &p) const\
    \ { return PowMint(*this) += p; }\r\n  PowMint pow(const PowMint &p) const { return\
    \ {a || !p.a}; }\r\n  PowMint operator^(const PowMint &p) const { return pow(p);\
    \ }\r\n  PowMint &operator^=(const PowMint &p){ return (*this) = pow(p); }\r\n\
    \r\n  friend ostream &operator<<(ostream &os, const PowMint &p) {\r\n    return\
    \ os << p.val();\r\n  }\r\n  friend istream &operator>>(istream &is, PowMint &a)\
    \ {\r\n    uint64_t t;\r\n    is >> t;\r\n    a = PowMint(t);\r\n    return (is);\r\
    \n  }\r\n};\r\n"
  code: "#pragma once\r\n\r\ntemplate<uint32_t mod>\r\nstruct PowMint{\r\nprivate:\r\
    \n  static constexpr uint32_t totient(uint32_t m){\r\n    uint32_t phi = m;\r\n\
    \    for(uint32_t i = 2; i * i <= m; ++i){\r\n      if(m % i != 0) continue;\r\
    \n      phi = phi / i * (i - 1);\r\n      do m /= i; while(m % i == 0);\r\n  \
    \  }\r\n    if(m != 1) phi = phi / m * (m - 1);\r\n    return phi;\r\n  }\r\n\r\
    \n  static constexpr uint32_t pmod(uint64_t x){\r\n    if(x < mod * 2) return\
    \ x;\r\n    return (x % mod) + mod;\r\n  }\r\n\r\n  static uint32_t pow(uint32_t\
    \ a, uint32_t b){\r\n    uint32_t p = 1;\r\n    for(; b; b >>= 1){\r\n      if(b\
    \ & 1) p = pmod(uint64_t(p) * a);\r\n      a = pmod(uint64_t(a) * a);\r\n    }\r\
    \n    return p;\r\n  }\r\n\r\npublic:\r\n\r\n  uint32_t a;\r\n  PowMint<totient(mod)>\
    \ r;\r\n\r\n  PowMint() = default;\r\n  PowMint(uint64_t x): a(pmod(x)), r(x)\
    \ {}\r\n  PowMint(uint32_t a, PowMint<totient(mod)> r): a(a), r(r) {}\r\n  \r\n\
    \  uint32_t val() const { return (a < mod) ? a : (a - mod); }\r\n  PowMint &operator*=(const\
    \ PowMint &p){\r\n    a = pmod(uint64_t(a) * p.a);\r\n    r *= p.r;\r\n    return\
    \ (*this);\r\n  }\r\n  PowMint &operator+=(const PowMint &p){\r\n    a += p.a;\r\
    \n    if(a >= mod * 2) a -= mod;\r\n    if(a >= mod * 2) a -= mod;\r\n    r +=\
    \ p.r;\r\n    return (*this);\r\n  }\r\n\r\n  PowMint operator*(const PowMint\
    \ &p) const { return PowMint(*this) *= p; }\r\n  PowMint operator+(const PowMint\
    \ &p) const { return PowMint(*this) += p; }\r\n\r\n  PowMint pow(const PowMint\
    \ &p) const { return{pow(a, p.r.a), r.pow(p.r)}; }\r\n  PowMint operator^(const\
    \ PowMint &p) const { return pow(p); }\r\n  PowMint &operator^=(const PowMint\
    \ &p){ return (*this) = pow(p); }\r\n\r\n  friend ostream &operator<<(ostream\
    \ &os, const PowMint &p) {\r\n    return os << p.val();\r\n  }\r\n  friend istream\
    \ &operator>>(istream &is, PowMint &a) {\r\n    uint64_t t;\r\n    is >> t;\r\n\
    \    a = PowMint(t);\r\n    return (is);\r\n  }\r\n};\r\n\r\ntemplate<> struct\
    \ PowMint<1>{\r\n  uint32_t a;\r\n  PowMint() = default;\r\n  PowMint(uint64_t\
    \ x): a(bool(x)) {}\r\n\r\n  uint32_t val() const { return 0; }\r\n  PowMint &operator*=(const\
    \ PowMint &p){ a &= p.a; return (*this); }\r\n  PowMint &operator+=(const PowMint\
    \ &p){ a += p.a; return (*this); }\r\n  PowMint operator*(const PowMint &p) const\
    \ { return PowMint(*this) *= p; }\r\n  PowMint operator+(const PowMint &p) const\
    \ { return PowMint(*this) += p; }\r\n  PowMint pow(const PowMint &p) const { return\
    \ {a || !p.a}; }\r\n  PowMint operator^(const PowMint &p) const { return pow(p);\
    \ }\r\n  PowMint &operator^=(const PowMint &p){ return (*this) = pow(p); }\r\n\
    \r\n  friend ostream &operator<<(ostream &os, const PowMint &p) {\r\n    return\
    \ os << p.val();\r\n  }\r\n  friend istream &operator>>(istream &is, PowMint &a)\
    \ {\r\n    uint64_t t;\r\n    is >> t;\r\n    a = PowMint(t);\r\n    return (is);\r\
    \n  }\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: math/mod/PowMint.cpp
  requiredBy: []
  timestamp: '2023-02-10 14:54:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/mod/PowMint.cpp
layout: document
redirect_from:
- /library/math/mod/PowMint.cpp
- /library/math/mod/PowMint.cpp.html
title: math/mod/PowMint.cpp
---
