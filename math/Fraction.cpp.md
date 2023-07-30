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
  bundledCode: "#line 2 \"math/Fraction.cpp\"\n\r\nstruct Fraction{\r\n  long long\
    \ a,b;\r\n  constexpr Fraction normalize(){\r\n    if(b < 0){ a = -a; b = -b;\
    \ }\r\n    long long g = gcd(a, b);\r\n    if(g == 0){\r\n      a = 0; b = 1;\r\
    \n    }else{\r\n      a /= g; b /= g;\r\n    }\r\n    return (*this);\r\n  }\r\
    \n  constexpr Fraction(long long a=0, long long b=1): a(a), b(b) { normalize();\
    \ }\r\n  Fraction(string S){\r\n    S += \".0\";\r\n    string T;\r\n    vector<string>\
    \ st;\r\n    stringstream ss{S};\r\n    while(getline(ss,T,'.')) st.emplace_back(T);\r\
    \n    long long A = stoll(st[0]), B = stoll(st[1]), D = 1;\r\n    for(size_t i\
    \ = 0; i < st[1].size(); i++) D *= 10;\r\n    A = A*D+B; a = A; b = D;\r\n   \
    \ normalize();\r\n    if(S[0] == '-' && a>0) a = -a;\r\n  }\r\n  constexpr double\
    \ QtoR() const { return (double)(a) / b; }\r\n  constexpr long long QtoZ() const\
    \ { return a / b; }\r\n\r\n  constexpr Fraction &operator+=(const Fraction &p){\r\
    \n    long long l = lcm(b, p.b);\r\n    a = a*(l/b) + p.a*(l/p.b);\r\n    b =\
    \ l;\r\n    normalize();\r\n    return *this;\r\n  }\r\n  constexpr Fraction &operator-=(const\
    \ Fraction &p){\r\n    long long l = lcm(b, p.b);\r\n    a = a*(l/b) - p.a*(l/p.b);\r\
    \n    b = l;\r\n    normalize();\r\n    return *this;\r\n  }\r\n  constexpr Fraction\
    \ &operator*=(const Fraction &p){\r\n    Fraction x(a, p.b), y(p.a, b);\r\n  \
    \  a = x.a * y.a;\r\n    b = x.b * y.b;\r\n    normalize();\r\n    return *this;\r\
    \n  }\r\n  constexpr Fraction &operator/=(const Fraction &p){\r\n    return (*this)\
    \ *= p.inverse();\r\n  }\r\n  constexpr Fraction operator-() const {\r\n    return\
    \ Fraction(-a, b);\r\n  }\r\n  constexpr Fraction &operator=(long long a){\r\n\
    \    return (*this) = Fraction(a, 1);\r\n  }\r\n  constexpr Fraction operator+(const\
    \ Fraction &p) const {\r\n    return Fraction(*this) += p;\r\n  }\r\n  constexpr\
    \ Fraction operator-(const Fraction &p) const {\r\n    return Fraction(*this)\
    \ -= p;\r\n  }\r\n  constexpr Fraction operator*(const Fraction &p) const {\r\n\
    \    return Fraction(*this) *= p;\r\n  }\r\n  constexpr Fraction operator/(const\
    \ Fraction &p) const {\r\n    return Fraction(*this) /= p;\r\n  }\r\n  constexpr\
    \ bool operator==(const Fraction &p) const {\r\n    return (a==p.a)&&(b==p.b);\r\
    \n  }\r\n  constexpr bool operator!=(const Fraction &p) const {\r\n    return\
    \ (a!=p.a)||(b!=p.b);\r\n  }\r\n\r\n  constexpr Fraction inverse() const {\r\n\
    \    return Fraction(b, a);\r\n  }\r\n  constexpr Fraction abs(const Fraction\
    \ &p){\r\n    Fraction res = p;\r\n    if(res.a < 0) res.a = -res.a;\r\n    return\
    \ res;\r\n  }\r\n\r\n  constexpr bool operator<(const Fraction &p) const {\r\n\
    \    return a * p.b < p.a * b;\r\n  }\r\n\r\n  friend ostream &operator<<(ostream\
    \ &os, const Fraction &p) {\r\n    os << p.a;\r\n    if(p.b != 1) os << \"/\"\
    \ << p.b;\r\n    return os;\r\n  }\r\n  friend istream &operator>>(istream &is,\
    \ Fraction &p) {\r\n    string s;\r\n    is >> s;\r\n    p = Fraction(s);\r\n\
    \    return (is);\r\n  }\r\n};\n"
  code: "#pragma once\r\n\r\nstruct Fraction{\r\n  long long a,b;\r\n  constexpr Fraction\
    \ normalize(){\r\n    if(b < 0){ a = -a; b = -b; }\r\n    long long g = gcd(a,\
    \ b);\r\n    if(g == 0){\r\n      a = 0; b = 1;\r\n    }else{\r\n      a /= g;\
    \ b /= g;\r\n    }\r\n    return (*this);\r\n  }\r\n  constexpr Fraction(long\
    \ long a=0, long long b=1): a(a), b(b) { normalize(); }\r\n  Fraction(string S){\r\
    \n    S += \".0\";\r\n    string T;\r\n    vector<string> st;\r\n    stringstream\
    \ ss{S};\r\n    while(getline(ss,T,'.')) st.emplace_back(T);\r\n    long long\
    \ A = stoll(st[0]), B = stoll(st[1]), D = 1;\r\n    for(size_t i = 0; i < st[1].size();\
    \ i++) D *= 10;\r\n    A = A*D+B; a = A; b = D;\r\n    normalize();\r\n    if(S[0]\
    \ == '-' && a>0) a = -a;\r\n  }\r\n  constexpr double QtoR() const { return (double)(a)\
    \ / b; }\r\n  constexpr long long QtoZ() const { return a / b; }\r\n\r\n  constexpr\
    \ Fraction &operator+=(const Fraction &p){\r\n    long long l = lcm(b, p.b);\r\
    \n    a = a*(l/b) + p.a*(l/p.b);\r\n    b = l;\r\n    normalize();\r\n    return\
    \ *this;\r\n  }\r\n  constexpr Fraction &operator-=(const Fraction &p){\r\n  \
    \  long long l = lcm(b, p.b);\r\n    a = a*(l/b) - p.a*(l/p.b);\r\n    b = l;\r\
    \n    normalize();\r\n    return *this;\r\n  }\r\n  constexpr Fraction &operator*=(const\
    \ Fraction &p){\r\n    Fraction x(a, p.b), y(p.a, b);\r\n    a = x.a * y.a;\r\n\
    \    b = x.b * y.b;\r\n    normalize();\r\n    return *this;\r\n  }\r\n  constexpr\
    \ Fraction &operator/=(const Fraction &p){\r\n    return (*this) *= p.inverse();\r\
    \n  }\r\n  constexpr Fraction operator-() const {\r\n    return Fraction(-a, b);\r\
    \n  }\r\n  constexpr Fraction &operator=(long long a){\r\n    return (*this) =\
    \ Fraction(a, 1);\r\n  }\r\n  constexpr Fraction operator+(const Fraction &p)\
    \ const {\r\n    return Fraction(*this) += p;\r\n  }\r\n  constexpr Fraction operator-(const\
    \ Fraction &p) const {\r\n    return Fraction(*this) -= p;\r\n  }\r\n  constexpr\
    \ Fraction operator*(const Fraction &p) const {\r\n    return Fraction(*this)\
    \ *= p;\r\n  }\r\n  constexpr Fraction operator/(const Fraction &p) const {\r\n\
    \    return Fraction(*this) /= p;\r\n  }\r\n  constexpr bool operator==(const\
    \ Fraction &p) const {\r\n    return (a==p.a)&&(b==p.b);\r\n  }\r\n  constexpr\
    \ bool operator!=(const Fraction &p) const {\r\n    return (a!=p.a)||(b!=p.b);\r\
    \n  }\r\n\r\n  constexpr Fraction inverse() const {\r\n    return Fraction(b,\
    \ a);\r\n  }\r\n  constexpr Fraction abs(const Fraction &p){\r\n    Fraction res\
    \ = p;\r\n    if(res.a < 0) res.a = -res.a;\r\n    return res;\r\n  }\r\n\r\n\
    \  constexpr bool operator<(const Fraction &p) const {\r\n    return a * p.b <\
    \ p.a * b;\r\n  }\r\n\r\n  friend ostream &operator<<(ostream &os, const Fraction\
    \ &p) {\r\n    os << p.a;\r\n    if(p.b != 1) os << \"/\" << p.b;\r\n    return\
    \ os;\r\n  }\r\n  friend istream &operator>>(istream &is, Fraction &p) {\r\n \
    \   string s;\r\n    is >> s;\r\n    p = Fraction(s);\r\n    return (is);\r\n\
    \  }\r\n};"
  dependsOn: []
  isVerificationFile: false
  path: math/Fraction.cpp
  requiredBy: []
  timestamp: '2023-02-10 14:54:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/Fraction.cpp
layout: document
redirect_from:
- /library/math/Fraction.cpp
- /library/math/Fraction.cpp.html
title: math/Fraction.cpp
---
