---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: math/convolution/and_sum_01.cpp
    title: c[k] = sum (a[i + k] & b[i])
  - icon: ':warning:'
    path: math/convolution/or_sum_01.cpp
    title: c[k] = sum (a[i + k] | b[i])
  - icon: ':warning:'
    path: math/fps/FFT-ntt.cpp
    title: math/fps/FFT-ntt.cpp
  - icon: ':warning:'
    path: math/fps/FastKitamasa.cpp
    title: math/fps/FastKitamasa.cpp
  - icon: ':warning:'
    path: math/fps/Formalpowerseries.cpp
    title: math/fps/Formalpowerseries.cpp
  - icon: ':warning:'
    path: math/fps/GeneratingFunction.cpp
    title: math/fps/GeneratingFunction.cpp
  - icon: ':warning:'
    path: math/fps/SemiRelaxedConvolution.cpp
    title: math/fps/SemiRelaxedConvolution.cpp
  - icon: ':warning:'
    path: math/fps/fps-famous-series/bernoulli_number.cpp
    title: math/fps/fps-famous-series/bernoulli_number.cpp
  - icon: ':warning:'
    path: math/fps/fps-famous-series/partition_function_table_fps.cpp
    title: math/fps/fps-famous-series/partition_function_table_fps.cpp
  - icon: ':warning:'
    path: math/fps/fps-famous-series/stirling_number_of_the_second_kind.cpp
    title: math/fps/fps-famous-series/stirling_number_of_the_second_kind.cpp
  - icon: ':warning:'
    path: math/fps/multipoint_evaluation.cpp
    title: math/fps/multipoint_evaluation.cpp
  - icon: ':warning:'
    path: math/fps/p_subset_sum.cpp
    title: math/fps/p_subset_sum.cpp
  - icon: ':warning:'
    path: math/fps/polynomial_interpolation.cpp
    title: math/fps/polynomial_interpolation.cpp
  - icon: ':warning:'
    path: math/fps/taylor_shift.cpp
    title: math/fps/taylor_shift.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/verify/lc/point_set_range_composite.test.cpp
    title: test/verify/lc/point_set_range_composite.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/verify/lc/range_affine_point_get.test.cpp
    title: test/verify/lc/range_affine_point_get.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/verify/lc/range_affine_range_sum.test.cpp
    title: test/verify/lc/range_affine_range_sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/mod/ModInt.cpp\"\n\r\ntemplate< int mod >\r\nstruct\
    \ ModInt {\r\n  int x;\r\n\r\n  constexpr ModInt() : x(0) {}\r\n\r\n  constexpr\
    \ ModInt(int64_t y) : x(y >= 0 ? y % mod : (mod - (-y) % mod) % mod) {}\r\n  \r\
    \n  constexpr ModInt &operator+=(const ModInt &p) {\r\n    if((x += p.x) >= mod)\
    \ x -= mod;\r\n    return *this;\r\n  }\r\n  constexpr ModInt &operator-=(const\
    \ ModInt &p) {\r\n    if((x += mod - p.x) >= mod) x -= mod;\r\n    return *this;\r\
    \n  }\r\n  constexpr ModInt &operator*=(const ModInt &p) {\r\n    x = (int) (1LL\
    \ * x * p.x % mod);\r\n    return *this;\r\n  }\r\n  constexpr ModInt &operator/=(const\
    \ ModInt &p) {\r\n    *this *= p.inverse();\r\n    return *this;\r\n  }\r\n  constexpr\
    \ ModInt operator-() const { return ModInt(-x); }\r\n  constexpr ModInt operator+(const\
    \ ModInt &p) const { return ModInt(*this) += p; }\r\n  constexpr ModInt operator-(const\
    \ ModInt &p) const { return ModInt(*this) -= p; }\r\n  constexpr ModInt operator*(const\
    \ ModInt &p) const { return ModInt(*this) *= p; }\r\n  constexpr ModInt operator/(const\
    \ ModInt &p) const { return ModInt(*this) /= p; }\r\n  constexpr bool operator==(const\
    \ ModInt &p) const { return x == p.x; }\r\n  constexpr bool operator!=(const ModInt\
    \ &p) const { return x != p.x; }\r\n  constexpr bool operator<(const ModInt &p)\
    \ const { return x < p.x; }\r\n\r\n  constexpr ModInt& operator++() { (*this).x+=1;\
    \ return (*this); }\r\n  constexpr ModInt& operator--() { (*this).x-=1; return\
    \ (*this); }\r\n  constexpr ModInt operator++(int) { ModInt tmp(*this); ++(*this);\
    \ return tmp; }\r\n  constexpr ModInt operator--(int) { ModInt tmp(*this); --(*this);\
    \ return tmp; }\r\n\r\n  constexpr ModInt inverse() const {\r\n    int a = x,\
    \ b = mod, u = 1, v = 0, t;\r\n    while(b > 0) {\r\n      t = a / b;\r\n    \
    \  swap(a -= t * b, b);\r\n      swap(u -= t * v, v);\r\n    }\r\n    return ModInt(u);\r\
    \n  }\r\n  constexpr ModInt pow(int64_t n) const {\r\n    ModInt ret(1), mul(x);\r\
    \n    while(n > 0) {\r\n      if(n & 1) ret *= mul;\r\n      mul *= mul; n >>=\
    \ 1;\r\n    }\r\n    return ret;\r\n  }\r\n  friend ostream &operator<<(ostream\
    \ &os, const ModInt &p) {\r\n    return os << p.x;\r\n  }\r\n  friend istream\
    \ &operator>>(istream &is, ModInt &a) {\r\n    int64_t t;\r\n    is >> t;\r\n\
    \    a = ModInt< mod >(t);\r\n    return (is);\r\n  }\r\n  constexpr static int\
    \ get_mod() { return mod; }\r\n};\r\ntemplate< int mod >\r\nconstexpr ModInt<mod>\
    \ operator+(const int64_t &p, const ModInt<mod> &m){ return ModInt<mod>(p) + m;\
    \ };\r\ntemplate< int mod >\r\nconstexpr ModInt<mod> operator-(const int64_t &p,\
    \ const ModInt<mod> &m){ return ModInt<mod>(p) - m; };\r\ntemplate< int mod >\r\
    \nconstexpr ModInt<mod> operator*(const int64_t &p, const ModInt<mod> &m){ return\
    \ ModInt<mod>(p) * m; };\r\ntemplate< int mod >\r\nconstexpr ModInt<mod> operator/(const\
    \ int64_t &p, const ModInt<mod> &m){ return ModInt<mod>(p) / m; };\r\n\r\n// constexpr\
    \ int MOD = 1e9 + 7;\r\n//constexpr int MOD = 998244353;\r\n// using mint = ModInt<\
    \ MOD >;\r\n// using VM = vector<mint>;\r\n// using VVM = vector<VM>;\r\n\r\n\
    // namespace mintliteral{ constexpr mint operator\"\"_m(unsigned long long x)\
    \ { return mint(x); } }\r\n// using namespace mintliteral;\r\n\r\nusing mint998244353\
    \ = ModInt< 998244353 >;\r\nusing mint1000000007 = ModInt< 1000000007 >;\r\n"
  code: "#pragma once\r\n\r\ntemplate< int mod >\r\nstruct ModInt {\r\n  int x;\r\n\
    \r\n  constexpr ModInt() : x(0) {}\r\n\r\n  constexpr ModInt(int64_t y) : x(y\
    \ >= 0 ? y % mod : (mod - (-y) % mod) % mod) {}\r\n  \r\n  constexpr ModInt &operator+=(const\
    \ ModInt &p) {\r\n    if((x += p.x) >= mod) x -= mod;\r\n    return *this;\r\n\
    \  }\r\n  constexpr ModInt &operator-=(const ModInt &p) {\r\n    if((x += mod\
    \ - p.x) >= mod) x -= mod;\r\n    return *this;\r\n  }\r\n  constexpr ModInt &operator*=(const\
    \ ModInt &p) {\r\n    x = (int) (1LL * x * p.x % mod);\r\n    return *this;\r\n\
    \  }\r\n  constexpr ModInt &operator/=(const ModInt &p) {\r\n    *this *= p.inverse();\r\
    \n    return *this;\r\n  }\r\n  constexpr ModInt operator-() const { return ModInt(-x);\
    \ }\r\n  constexpr ModInt operator+(const ModInt &p) const { return ModInt(*this)\
    \ += p; }\r\n  constexpr ModInt operator-(const ModInt &p) const { return ModInt(*this)\
    \ -= p; }\r\n  constexpr ModInt operator*(const ModInt &p) const { return ModInt(*this)\
    \ *= p; }\r\n  constexpr ModInt operator/(const ModInt &p) const { return ModInt(*this)\
    \ /= p; }\r\n  constexpr bool operator==(const ModInt &p) const { return x ==\
    \ p.x; }\r\n  constexpr bool operator!=(const ModInt &p) const { return x != p.x;\
    \ }\r\n  constexpr bool operator<(const ModInt &p) const { return x < p.x; }\r\
    \n\r\n  constexpr ModInt& operator++() { (*this).x+=1; return (*this); }\r\n \
    \ constexpr ModInt& operator--() { (*this).x-=1; return (*this); }\r\n  constexpr\
    \ ModInt operator++(int) { ModInt tmp(*this); ++(*this); return tmp; }\r\n  constexpr\
    \ ModInt operator--(int) { ModInt tmp(*this); --(*this); return tmp; }\r\n\r\n\
    \  constexpr ModInt inverse() const {\r\n    int a = x, b = mod, u = 1, v = 0,\
    \ t;\r\n    while(b > 0) {\r\n      t = a / b;\r\n      swap(a -= t * b, b);\r\
    \n      swap(u -= t * v, v);\r\n    }\r\n    return ModInt(u);\r\n  }\r\n  constexpr\
    \ ModInt pow(int64_t n) const {\r\n    ModInt ret(1), mul(x);\r\n    while(n >\
    \ 0) {\r\n      if(n & 1) ret *= mul;\r\n      mul *= mul; n >>= 1;\r\n    }\r\
    \n    return ret;\r\n  }\r\n  friend ostream &operator<<(ostream &os, const ModInt\
    \ &p) {\r\n    return os << p.x;\r\n  }\r\n  friend istream &operator>>(istream\
    \ &is, ModInt &a) {\r\n    int64_t t;\r\n    is >> t;\r\n    a = ModInt< mod >(t);\r\
    \n    return (is);\r\n  }\r\n  constexpr static int get_mod() { return mod; }\r\
    \n};\r\ntemplate< int mod >\r\nconstexpr ModInt<mod> operator+(const int64_t &p,\
    \ const ModInt<mod> &m){ return ModInt<mod>(p) + m; };\r\ntemplate< int mod >\r\
    \nconstexpr ModInt<mod> operator-(const int64_t &p, const ModInt<mod> &m){ return\
    \ ModInt<mod>(p) - m; };\r\ntemplate< int mod >\r\nconstexpr ModInt<mod> operator*(const\
    \ int64_t &p, const ModInt<mod> &m){ return ModInt<mod>(p) * m; };\r\ntemplate<\
    \ int mod >\r\nconstexpr ModInt<mod> operator/(const int64_t &p, const ModInt<mod>\
    \ &m){ return ModInt<mod>(p) / m; };\r\n\r\n// constexpr int MOD = 1e9 + 7;\r\n\
    //constexpr int MOD = 998244353;\r\n// using mint = ModInt< MOD >;\r\n// using\
    \ VM = vector<mint>;\r\n// using VVM = vector<VM>;\r\n\r\n// namespace mintliteral{\
    \ constexpr mint operator\"\"_m(unsigned long long x) { return mint(x); } }\r\n\
    // using namespace mintliteral;\r\n\r\nusing mint998244353 = ModInt< 998244353\
    \ >;\r\nusing mint1000000007 = ModInt< 1000000007 >;\r\n"
  dependsOn: []
  isVerificationFile: false
  path: math/mod/ModInt.cpp
  requiredBy:
  - math/fps/p_subset_sum.cpp
  - math/fps/GeneratingFunction.cpp
  - math/fps/SemiRelaxedConvolution.cpp
  - math/fps/multipoint_evaluation.cpp
  - math/fps/fps-famous-series/partition_function_table_fps.cpp
  - math/fps/fps-famous-series/stirling_number_of_the_second_kind.cpp
  - math/fps/fps-famous-series/bernoulli_number.cpp
  - math/fps/polynomial_interpolation.cpp
  - math/fps/FastKitamasa.cpp
  - math/fps/FFT-ntt.cpp
  - math/fps/Formalpowerseries.cpp
  - math/fps/taylor_shift.cpp
  - math/convolution/or_sum_01.cpp
  - math/convolution/and_sum_01.cpp
  timestamp: '2023-02-10 18:05:26+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/verify/lc/range_affine_point_get.test.cpp
  - test/verify/lc/range_affine_range_sum.test.cpp
  - test/verify/lc/point_set_range_composite.test.cpp
documentation_of: math/mod/ModInt.cpp
layout: document
redirect_from:
- /library/math/mod/ModInt.cpp
- /library/math/mod/ModInt.cpp.html
title: math/mod/ModInt.cpp
---
