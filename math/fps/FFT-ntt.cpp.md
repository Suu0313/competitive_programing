---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: math/fps/NTT.cpp
    title: math/fps/NTT.cpp
  - icon: ':heavy_check_mark:'
    path: math/mod/ModInt.cpp
    title: math/mod/ModInt.cpp
  _extendedRequiredBy:
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
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/fps/FFT-ntt.cpp\"\n\n#line 2 \"math/mod/ModInt.cpp\"\
    \n\r\ntemplate< int mod >\r\nstruct ModInt {\r\n  int x;\r\n\r\n  constexpr ModInt()\
    \ : x(0) {}\r\n\r\n  constexpr ModInt(int64_t y) : x(y >= 0 ? y % mod : (mod -\
    \ (-y) % mod) % mod) {}\r\n  \r\n  constexpr ModInt &operator+=(const ModInt &p)\
    \ {\r\n    if((x += p.x) >= mod) x -= mod;\r\n    return *this;\r\n  }\r\n  constexpr\
    \ ModInt &operator-=(const ModInt &p) {\r\n    if((x += mod - p.x) >= mod) x -=\
    \ mod;\r\n    return *this;\r\n  }\r\n  constexpr ModInt &operator*=(const ModInt\
    \ &p) {\r\n    x = (int) (1LL * x * p.x % mod);\r\n    return *this;\r\n  }\r\n\
    \  constexpr ModInt &operator/=(const ModInt &p) {\r\n    *this *= p.inverse();\r\
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
    \ >;\r\nusing mint1000000007 = ModInt< 1000000007 >;\r\n#line 2 \"math/fps/NTT.cpp\"\
    \n\r\nnamespace NTT{\r\n\r\n  int bsf(unsigned int n) { return __builtin_ctz(n);\
    \ }\r\n\r\n  long long pow_mod(long long x, long long n, int m) {\r\n    if (m\
    \ == 1) return 0;\r\n    unsigned int _m = (unsigned int)(m);\r\n    unsigned\
    \ long long r = 1;\r\n    x %= m;\r\n    if (x < 0) x += m;\r\n    while (n) {\r\
    \n        if (n & 1) r = (r * x) % _m;\r\n        x = (x * x) % _m;\r\n      \
    \  n >>= 1;\r\n    }\r\n    return r;\r\n  }\r\n\r\n  int primitive_root(int m){\r\
    \n    if (m == 2) return 1;\r\n    if (m == 167772161) return 3;\r\n    if (m\
    \ == 469762049) return 3;\r\n    if (m == 754974721) return 11;\r\n    if (m ==\
    \ 998244353) return 3;\r\n    int divs[20] = {};\r\n    divs[0] = 2;\r\n    int\
    \ cnt = 1;\r\n    int x = (m-1) / 2;\r\n    while(x%2 == 0) x >>= 1;\r\n    for(int\
    \ i=3; (long long)(i)*i <= x; i+=2){\r\n      if(x%i == 0){\r\n        divs[cnt++]\
    \ = i;\r\n        while (x % i == 0) x /= i;\r\n      }\r\n    }\r\n    if(x >\
    \ 1) divs[cnt++] = x;\r\n\r\n    for (int g = 2;; g++) {\r\n        bool ok =\
    \ true;\r\n        for (int i = 0; i < cnt; i++) {\r\n            if (pow_mod(g,\
    \ (m - 1) / divs[i], m) == 1) {\r\n                ok = false;\r\n           \
    \     break;\r\n            }\r\n        }\r\n        if (ok) return g;\r\n  \
    \  }\r\n  }\r\n\r\n  template<typename Mint>\r\n  void butterfly(std::vector<Mint>&\
    \ a){\r\n    static int g = primitive_root(Mint::get_mod());\r\n    int n = int(a.size());\r\
    \n    int h = 0;\r\n    while(n > (1<<h)) h++;\r\n\r\n    static bool first =\
    \ true;\r\n    static Mint sum_e[30];\r\n\r\n    if (first) {\r\n        first\
    \ = false;\r\n        Mint es[30], ies[30];  // es[i]^(2^(2+i)) == 1\r\n     \
    \   int cnt2 = bsf(Mint::get_mod() - 1);\r\n        Mint e = Mint(g).pow((Mint::get_mod()\
    \ - 1) >> cnt2), ie = e.inverse();\r\n        for (int i = cnt2; i >= 2; i--)\
    \ {\r\n            // e^(2^i) == 1\r\n            es[i - 2] = e;\r\n         \
    \   ies[i - 2] = ie;\r\n            e *= e;\r\n            ie *= ie;\r\n     \
    \   }\r\n        Mint now = 1;\r\n        for (int i = 0; i < cnt2 - 2; i++) {\r\
    \n            sum_e[i] = es[i] * now;\r\n            now *= ies[i];\r\n      \
    \  }\r\n    }\r\n    for (int ph = 1; ph <= h; ph++) {\r\n        int w = 1 <<\
    \ (ph - 1), p = 1 << (h - ph);\r\n        Mint now = 1;\r\n        for (int s\
    \ = 0; s < w; s++) {\r\n            int offset = s << (h - ph + 1);\r\n      \
    \      for (int i = 0; i < p; i++) {\r\n                auto l = a[i + offset];\r\
    \n                auto r = a[i + offset + p] * now;\r\n                a[i + offset]\
    \ = l + r;\r\n                a[i + offset + p] = l - r;\r\n            }\r\n\
    \            now *= sum_e[bsf(~(unsigned int)(s))];\r\n        }\r\n    }\r\n\
    \  }\r\n\r\n  template<typename Mint>\r\n  void butterfly_inv(std::vector<Mint>&\
    \ a){\r\n    static int g = primitive_root(Mint::get_mod());\r\n    int n = int(a.size());\r\
    \n    int h = 0;\r\n    while(n > (1<<h)) h++;\r\n\r\n    static bool first =\
    \ true;\r\n    static Mint sum_ie[30];\r\n\r\n    if (first) {\r\n        first\
    \ = false;\r\n        Mint es[30], ies[30];  // es[i]^(2^(2+i)) == 1\r\n     \
    \   int cnt2 = bsf(Mint::get_mod() - 1);\r\n        Mint e = Mint(g).pow((Mint::get_mod()\
    \ - 1) >> cnt2), ie = e.inverse();\r\n        for (int i = cnt2; i >= 2; i--)\
    \ {\r\n            // e^(2^i) == 1\r\n            es[i - 2] = e;\r\n         \
    \   ies[i - 2] = ie;\r\n            e *= e;\r\n            ie *= ie;\r\n     \
    \   }\r\n        Mint now = 1;\r\n        for (int i = 0; i < cnt2 - 2; i++) {\r\
    \n            sum_ie[i] = ies[i] * now;\r\n            now *= es[i];\r\n     \
    \   }\r\n    }\r\n    for (int ph = h; ph >= 1; ph--) {\r\n        int w = 1 <<\
    \ (ph - 1), p = 1 << (h - ph);\r\n        Mint inow = 1;\r\n        for (int s\
    \ = 0; s < w; s++) {\r\n            int offset = s << (h - ph + 1);\r\n      \
    \      for (int i = 0; i < p; i++) {\r\n                auto l = a[i + offset];\r\
    \n                auto r = a[i + offset + p];\r\n                a[i + offset]\
    \ = l + r;\r\n                a[i + offset + p] = (unsigned long long)(Mint::get_mod()\
    \ + l.x - r.x) *\r\n                    inow.x;\r\n            }\r\n         \
    \   inow *= sum_ie[bsf(~(unsigned int)(s))];\r\n        }\r\n    }\r\n  }\r\n\
    \  \r\n  template<typename Mint>\r\n  vector<Mint> multiply(vector<Mint> a, vector<Mint>\
    \ b){\r\n    int n = int(a.size()), m = int(b.size());\r\n    if(min(n,m) <= 60){\r\
    \n      if(n < m){\r\n        swap(n, m); swap(a, b);\r\n      }\r\n      vector<Mint>\
    \ ans(n + m - 1);\r\n      for(int i = 0; i < n; i++){\r\n        for(int j =\
    \ 0; j < m; j++){\r\n          ans[i + j] += a[i] * b[j];\r\n        }\r\n   \
    \   }\r\n      return ans;\r\n    }\r\n    int z = 0;\r\n    while(n+m-1 > (1<<z))\
    \ z++;\r\n    z = 1 << z;\r\n    a.resize(z); butterfly(a);\r\n    b.resize(z);\
    \ butterfly(b);\r\n\r\n    for(int i=0; i<z; i++) a[i] *= b[i];\r\n    butterfly_inv(a);\r\
    \n    a.resize(n + m - 1);\r\n    Mint iz = Mint(z).inverse();\r\n    for (int\
    \ i = 0; i < n + m - 1; i++) a[i] *= iz;\r\n    return a;\r\n  }\r\n}\r\n#line\
    \ 5 \"math/fps/FFT-ntt.cpp\"\n\nnamespace FFT{\n  template<int mod, typename T>\n\
    \  vector<ModInt<mod>> tovMint(const vector<T> &a){\n    vector<ModInt<mod>> res(a.size());\n\
    \    for (size_t i = 0; i < a.size(); i++) res[i] = a[i];\n    return res;\n \
    \ }\n\n  vector<int> multiply(const vector<int> &a, const vector<int> &b){\n \
    \   // must be less than mod\n    int n = int(a.size()), m = int(b.size());\n\
    \    if (!n || !m) return {};\n    static constexpr int MOD1 = 998244353;\n  \
    \  auto c = NTT::multiply(tovMint<MOD1>(a), tovMint<MOD1>(b));\n    vector<int>\
    \ res(n+m-1);\n    for(int i = 0; i < n+m-1; ++i) res[i] = c[i].x;\n    return\
    \ res;\n  }\n\n  vector<long long> multiply(const vector<long long> &a, const\
    \ vector<long long> &b){\n    int n = int(a.size()), m = int(b.size());\n    if\
    \ (!n || !m) return {};\n\n    static constexpr unsigned long long MOD1 = 754974721;\n\
    \    static constexpr unsigned long long MOD2 = 167772161;\n    static constexpr\
    \ unsigned long long MOD3 = 469762049;\n    static constexpr unsigned long long\
    \ M2M3 = MOD2 * MOD3;\n    static constexpr unsigned long long M1M3 = MOD1 * MOD3;\n\
    \    static constexpr unsigned long long M1M2 = MOD1 * MOD2;\n    static constexpr\
    \ unsigned long long M1M2M3 = MOD1 * MOD2 * MOD3;\n\n    static constexpr unsigned\
    \ long long i1 = 190329765;\n    static constexpr unsigned long long i2 = 58587104;\n\
    \    static constexpr unsigned long long i3 = 187290749;\n\n    auto c1 = NTT::multiply(tovMint<MOD1>(a),\
    \ tovMint<MOD1>(b));\n    auto c2 = NTT::multiply(tovMint<MOD2>(a), tovMint<MOD2>(b));\n\
    \    auto c3 = NTT::multiply(tovMint<MOD3>(a), tovMint<MOD3>(b));\n    \n    vector<long\
    \ long> c(n + m - 1);\n\n    for(int i = 0; i < n+m-1; i++){\n      unsigned long\
    \ long x = 0, x1 = c1[i].x, x2 = c2[i].x, x3 = c3[i].x;\n        x += (x1 * i1)\
    \ % MOD1 * M2M3;\n        x += (x2 * i2) % MOD2 * M1M3;\n        x += (x3 * i3)\
    \ % MOD3 * M1M2;\n        int diff = (c1[i] - (long long)x).x;\n        static\
    \ constexpr unsigned long long offset[5] = {0, 0, M1M2M3, 2 * M1M2M3, 3 * M1M2M3};\n\
    \        x -= offset[diff % 5];\n        c[i] = x;\n    }\n    return c;\n  }\n\
    \n  template<int mod>\n  vector<ModInt<mod>> multiply(const vector<ModInt<mod>>\
    \ &a, const vector<ModInt<mod>> &b){\n    int n = int(a.size()), m = int(b.size());\n\
    \    if (!n || !m) return {};\n\n    for(int md : {998244353, 2, 167772161, 469762049,\
    \ 754974721}){\n      if(mod == md) return NTT::multiply(a, b);\n    }\n\n   \
    \ static constexpr long long MOD1 = 754974721;\n    static constexpr long long\
    \ MOD2 = 167772161;\n    static constexpr long long MOD3 = 469762049;\n\n    static\
    \ const ModInt<MOD2> i1 = ModInt<MOD2>(MOD1).inverse();\n    static const ModInt<MOD3>\
    \ i2 = ModInt<MOD3>(MOD1 * MOD2).inverse();\n    static const ModInt<mod> M12\
    \ = MOD1 * MOD2;\n\n    vector<long long> a2(n), b2(m);\n    for(int i = 0; i\
    \ < n; i++) a2[i] = a[i].x;\n    for(int i = 0; i < m; i++) b2[i] = b[i].x;\n\n\
    \    auto c1 = NTT::multiply(tovMint<MOD1>(a2), tovMint<MOD1>(b2));\n    auto\
    \ c2 = NTT::multiply(tovMint<MOD2>(a2), tovMint<MOD2>(b2));\n    auto c3 = NTT::multiply(tovMint<MOD3>(a2),\
    \ tovMint<MOD3>(b2));\n\n    vector<ModInt<mod>> c(n + m - 1);\n    for(int i\
    \ = 0; i < n+m-1; i++){\n      ModInt<MOD2> v1 = (c2[i] - c1[i].x) * i1;\n   \
    \   ModInt<MOD3> v2 = (c3[i] - c1[i].x  - v1.x * MOD1) * i2;\n      c[i] = M12\
    \ * v2.x + c1[i].x + MOD1 * v1.x;\n    }\n    return c;\n  }\n}\n"
  code: "#pragma once\n\n#include \"../mod/ModInt.cpp\"\n#include \"./NTT.cpp\"\n\n\
    namespace FFT{\n  template<int mod, typename T>\n  vector<ModInt<mod>> tovMint(const\
    \ vector<T> &a){\n    vector<ModInt<mod>> res(a.size());\n    for (size_t i =\
    \ 0; i < a.size(); i++) res[i] = a[i];\n    return res;\n  }\n\n  vector<int>\
    \ multiply(const vector<int> &a, const vector<int> &b){\n    // must be less than\
    \ mod\n    int n = int(a.size()), m = int(b.size());\n    if (!n || !m) return\
    \ {};\n    static constexpr int MOD1 = 998244353;\n    auto c = NTT::multiply(tovMint<MOD1>(a),\
    \ tovMint<MOD1>(b));\n    vector<int> res(n+m-1);\n    for(int i = 0; i < n+m-1;\
    \ ++i) res[i] = c[i].x;\n    return res;\n  }\n\n  vector<long long> multiply(const\
    \ vector<long long> &a, const vector<long long> &b){\n    int n = int(a.size()),\
    \ m = int(b.size());\n    if (!n || !m) return {};\n\n    static constexpr unsigned\
    \ long long MOD1 = 754974721;\n    static constexpr unsigned long long MOD2 =\
    \ 167772161;\n    static constexpr unsigned long long MOD3 = 469762049;\n    static\
    \ constexpr unsigned long long M2M3 = MOD2 * MOD3;\n    static constexpr unsigned\
    \ long long M1M3 = MOD1 * MOD3;\n    static constexpr unsigned long long M1M2\
    \ = MOD1 * MOD2;\n    static constexpr unsigned long long M1M2M3 = MOD1 * MOD2\
    \ * MOD3;\n\n    static constexpr unsigned long long i1 = 190329765;\n    static\
    \ constexpr unsigned long long i2 = 58587104;\n    static constexpr unsigned long\
    \ long i3 = 187290749;\n\n    auto c1 = NTT::multiply(tovMint<MOD1>(a), tovMint<MOD1>(b));\n\
    \    auto c2 = NTT::multiply(tovMint<MOD2>(a), tovMint<MOD2>(b));\n    auto c3\
    \ = NTT::multiply(tovMint<MOD3>(a), tovMint<MOD3>(b));\n    \n    vector<long\
    \ long> c(n + m - 1);\n\n    for(int i = 0; i < n+m-1; i++){\n      unsigned long\
    \ long x = 0, x1 = c1[i].x, x2 = c2[i].x, x3 = c3[i].x;\n        x += (x1 * i1)\
    \ % MOD1 * M2M3;\n        x += (x2 * i2) % MOD2 * M1M3;\n        x += (x3 * i3)\
    \ % MOD3 * M1M2;\n        int diff = (c1[i] - (long long)x).x;\n        static\
    \ constexpr unsigned long long offset[5] = {0, 0, M1M2M3, 2 * M1M2M3, 3 * M1M2M3};\n\
    \        x -= offset[diff % 5];\n        c[i] = x;\n    }\n    return c;\n  }\n\
    \n  template<int mod>\n  vector<ModInt<mod>> multiply(const vector<ModInt<mod>>\
    \ &a, const vector<ModInt<mod>> &b){\n    int n = int(a.size()), m = int(b.size());\n\
    \    if (!n || !m) return {};\n\n    for(int md : {998244353, 2, 167772161, 469762049,\
    \ 754974721}){\n      if(mod == md) return NTT::multiply(a, b);\n    }\n\n   \
    \ static constexpr long long MOD1 = 754974721;\n    static constexpr long long\
    \ MOD2 = 167772161;\n    static constexpr long long MOD3 = 469762049;\n\n    static\
    \ const ModInt<MOD2> i1 = ModInt<MOD2>(MOD1).inverse();\n    static const ModInt<MOD3>\
    \ i2 = ModInt<MOD3>(MOD1 * MOD2).inverse();\n    static const ModInt<mod> M12\
    \ = MOD1 * MOD2;\n\n    vector<long long> a2(n), b2(m);\n    for(int i = 0; i\
    \ < n; i++) a2[i] = a[i].x;\n    for(int i = 0; i < m; i++) b2[i] = b[i].x;\n\n\
    \    auto c1 = NTT::multiply(tovMint<MOD1>(a2), tovMint<MOD1>(b2));\n    auto\
    \ c2 = NTT::multiply(tovMint<MOD2>(a2), tovMint<MOD2>(b2));\n    auto c3 = NTT::multiply(tovMint<MOD3>(a2),\
    \ tovMint<MOD3>(b2));\n\n    vector<ModInt<mod>> c(n + m - 1);\n    for(int i\
    \ = 0; i < n+m-1; i++){\n      ModInt<MOD2> v1 = (c2[i] - c1[i].x) * i1;\n   \
    \   ModInt<MOD3> v2 = (c3[i] - c1[i].x  - v1.x * MOD1) * i2;\n      c[i] = M12\
    \ * v2.x + c1[i].x + MOD1 * v1.x;\n    }\n    return c;\n  }\n}\n"
  dependsOn:
  - math/mod/ModInt.cpp
  - math/fps/NTT.cpp
  isVerificationFile: false
  path: math/fps/FFT-ntt.cpp
  requiredBy:
  - math/fps/taylor_shift.cpp
  - math/fps/GeneratingFunction.cpp
  - math/fps/FastKitamasa.cpp
  - math/fps/fps-famous-series/partition_function_table_fps.cpp
  - math/fps/fps-famous-series/stirling_number_of_the_second_kind.cpp
  - math/fps/fps-famous-series/bernoulli_number.cpp
  - math/fps/SemiRelaxedConvolution.cpp
  - math/fps/polynomial_interpolation.cpp
  - math/fps/multipoint_evaluation.cpp
  - math/fps/Formalpowerseries.cpp
  - math/fps/p_subset_sum.cpp
  timestamp: '2023-07-01 17:56:18+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/fps/FFT-ntt.cpp
layout: document
redirect_from:
- /library/math/fps/FFT-ntt.cpp
- /library/math/fps/FFT-ntt.cpp.html
title: math/fps/FFT-ntt.cpp
---
