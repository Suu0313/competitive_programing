---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: math/fps/FFT-ntt.cpp
    title: math/fps/FFT-ntt.cpp
  - icon: ':warning:'
    path: math/fps/Formalpowerseries.cpp
    title: math/fps/Formalpowerseries.cpp
  - icon: ':warning:'
    path: math/fps/NTT.cpp
    title: math/fps/NTT.cpp
  - icon: ':warning:'
    path: math/mod/ModInt.cpp
    title: math/mod/ModInt.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/fps/GeneratingFunction.cpp\"\n\r\n#line 2 \"math/fps/Formalpowerseries.cpp\"\
    \n\r\n#line 2 \"math/fps/FFT-ntt.cpp\"\n\n#line 2 \"math/mod/ModInt.cpp\"\n\r\n\
    template< int mod >\r\nstruct ModInt {\r\n  int x;\r\n\r\n  constexpr ModInt()\
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
    \ * v2.x + c1[i].x + MOD1 * v1.x;\n    }\n    return c;\n  }\n}\n#line 4 \"math/fps/Formalpowerseries.cpp\"\
    \n\r\ntemplate< typename T >\r\nstruct Formalpowerseries : vector<T> {\r\n  using\
    \ vector<T>::vector;\r\n  using vector<T>::operator=;\r\n  using F = Formalpowerseries;\r\
    \n  \r\n  Formalpowerseries(const vector<T> &v): vector<T>(v) {}\r\n  Formalpowerseries(vector<T>\
    \ &&v): vector<T>(move(v)) {}\r\n\r\n  void set(size_t i, const T &x){\r\n   \
    \ while(i >= this->size()) this->emplace_back(0);\r\n    (*this)[i] = x;\r\n \
    \ }\r\n\r\n  void shrink(){\r\n    while(this->size() && this->back() == T(0))\
    \ this->pop_back();\r\n  }\r\n\r\n  T eval(const T &x) const {\r\n    T res =\
    \ 0, w = 1;\r\n    for(auto &&a : (*this)){\r\n      res += a * w; w *= x;\r\n\
    \    }\r\n    return res;\r\n  }\r\n  T operator()(const T &x) const { return\
    \ eval(x); }\r\n\r\n  F operator-() const {\r\n    F res(*this);\r\n    for(auto\
    \ &&a : res) a = -a;\r\n    return res;\r\n  }\r\n\r\n  F &operator+=(const T\
    \ &c){\r\n    if(this->empty()) this->resize(1);\r\n    (*this)[0] += c;\r\n \
    \   return (*this);\r\n  }\r\n\r\n  F operator+(const T &c) const {return F(*this)\
    \ += c; }\r\n\r\n  F &operator-=(const T &c){\r\n    if(this->empty()) this->resize(1);\r\
    \n    (*this)[0] -= c;\r\n    return (*this);\r\n  }\r\n\r\n  F operator-(const\
    \ T &c) const {return F(*this) -= c; }\r\n\r\n  F &operator*=(const T &c){\r\n\
    \    for(auto &&a : (*this)) a *= c;\r\n    return (*this);\r\n  }\r\n  F operator*(const\
    \ T &c) const { return F(*this) *= c; }\r\n\r\n  F &operator/=(const T &c){ return\
    \ (*this) *= T(1)/c; }\r\n  F operator/(const T &c) const { return F(*this) /=\
    \ c; }\r\n\r\n  F &operator+=(const F &f){\r\n    size_t n = f.size();\r\n   \
    \ if(this->size() < n) this->resize(f.size());\r\n    for(size_t i = 0; i < n;\
    \ i++) (*this)[i] += f[i];\r\n    return (*this);\r\n  }\r\n  F operator+(const\
    \ F &f) const { return F(*this) += f; }\r\n\r\n  F &operator-=(const F &f){\r\n\
    \    size_t n = f.size();\r\n    if(this->size() < n) this->resize(f.size());\r\
    \n    for(size_t i = 0; i < n; i++) (*this)[i] -= f[i];\r\n    return (*this);\r\
    \n  }\r\n  F operator-(const F &f) const { return F(*this) -= f; }\r\n\r\n  F\
    \ operator*(const F &f) const { return FFT::multiply((*this), f); }\r\n  F &operator*=(const\
    \ F &f) { return (*this) = (*this) * f; }\r\n\r\n  F operator/(const F &f) const\
    \ {\r\n    if(this->size() < f.size()){ return F{}; }\r\n    size_t n = this->size()\
    \ - f.size() + 1;\r\n    return (rev().pre(n) * f.rev().inv(n)).pre(n).rev();\r\
    \n  }\r\n  F &operator/=(const F &f){ return (*this) = (*this) / f; }\r\n\r\n\
    \  F &operator%=(const F &f){ (*this) -= (*this) / f * f; shrink(); return (*this);\
    \ }\r\n  F operator%(const F &f) const { return F(*this) %= f; }\r\n\r\n  pair<F,\
    \ F> divmod(const F &f){ F q = (*this) / f; F r = (*this) - q * f; r.shrink();\
    \ return {q, r}; }\r\n\r\n  F &operator<<=(size_t d){ this->insert(this->begin(),\
    \ d, T(0)); return (*this); }\r\n  F operator<<(size_t d) const{ return F(*this)\
    \ <<= d; }\r\n\r\n  F &operator>>=(size_t d){ this->erase(this->begin(), this->begin()+min(this->size(),\
    \ d)); return (*this); }\r\n  F operator>>(size_t d) const{ return F(*this) >>=\
    \ d; }\r\n\r\n  F operator*(const vector<pair<int, T>> &g) const {\r\n    F res(0);\r\
    \n    for(auto&&[d, c] : g) res += ((*this) * c) << d;\r\n    return res;\r\n\
    \  }\r\n  F &operator*=(const vector<pair<int, T>> &g){ return (*this) = (*this)\
    \ * g; }\r\n\r\n  bool operator<(const F &f){ return this->size() < f.size();\
    \ }\r\n  bool operator<=(const F &f){ return this->size() <= f.size(); }\r\n \
    \ bool operator>(const F &f){ return this->size() > f.size(); }\r\n  bool operator>=(const\
    \ F &f){ return this->size() >= f.size(); }\r\n\r\n  // F inv(int d = -1) const\
    \ {\r\n  //   if(d == -1) d = this->size();\r\n  //   if((*this)[0] == T(0)) return\
    \ F{};\r\n  //   F res(1, T(1) / (*this)[0]);\r\n  //   for(int i = 1; i < d;\
    \ i <<= 1){\r\n  //     res = (res+res - res*res*pre(i << 1)).pre(i << 1);\r\n\
    \  //   }\r\n  //   return res.pre(d);\r\n  // }\r\n\r\n  F inv(int d = -1) const\
    \ {\r\n    if(d == -1) d = this->size();\r\n    if((*this)[0] == T(0)) return\
    \ F{};\r\n    F res(1, T(1) / (*this)[0]);\r\n    for(int i = 1; i < d; i <<=\
    \ 1){\r\n      int n = i << 2;\r\n      F f(n), g(n); f += pre(i << 1); g += res;\r\
    \n      NTT::butterfly(f); NTT::butterfly(g);\r\n      for(int j = 0; j < n; ++j)\
    \ f[j] *= g[j] * g[j];\r\n      NTT::butterfly_inv(f);\r\n      f.resize(i <<\
    \ 1);\r\n      res += res - f * T(n).inverse();\r\n    }\r\n    return res.pre(d);\r\
    \n  }\r\n\r\n  F rev() const { F res(*this); reverse(res.begin(), res.end());\
    \ return res; }\r\n\r\n  F pre(size_t d) const { return F(this->begin(), this->begin()+min(this->size(),\
    \ d)); }\r\n\r\n  F dot(const F &f) const {\r\n    F res(min(this->size(), f.size()));\r\
    \n    for(size_t i = 0; i < res.size(); i++) res[i] = (*this)[i] * f[i];\r\n \
    \   return res;\r\n  }\r\n\r\n  F diff() const {\r\n    int n = this->size();\r\
    \n    F res(max(0, n - 1));\r\n    for(int i = 1; i < n; i++) res[i-1] = (*this)[i]\
    \ * T(i);\r\n    return res;\r\n  }\r\n\r\n  F integral() const {\r\n    int n\
    \ = this->size();\r\n    F res(n + 1);\r\n    static vector<T> invs(2, 1);\r\n\
    \    static int mod = T::get_mod();\r\n    if(int(invs.size()) <= n){\r\n    \
    \  int m = invs.size();\r\n      invs.resize(n + 1);\r\n      for(int i = m; i\
    \ <= n; ++i) invs[i] = -invs[mod%i] * (mod/i);\r\n    }\r\n    for(int i = 0;\
    \ i < n; i++) res[i+1] = (*this)[i] * invs[i + 1];\r\n    return res;\r\n  }\r\
    \n\r\n  F log(int d = -1) const {\r\n    if(d == -1) d = this->size();\r\n   \
    \ if((*this)[0] != T(1)) return F{};\r\n    return (this->diff() * this->inv(d)).pre(d-1).integral();\r\
    \n  }\r\n\r\n  F exp(int d = -1) const {\r\n    if(d == -1) d = this->size();\r\
    \n    if((*this)[0] != T(0)) return F{};\r\n    F res(1, T(1));\r\n    for(int\
    \ i = 1; i < d; i <<= 1){\r\n      res = (res*(pre(i<<1) + T(1) - res.log(i<<1))).pre(i<<1);\r\
    \n    }\r\n    return res.pre(d);\r\n  }\r\n\r\n  F pow(int64_t k, int d = -1)\
    \ const {\r\n    const int n = this->size();\r\n    if(d == -1) d = n;\r\n   \
    \ if(k == 0) return F(d, 0) + 1;\r\n    for(int i = 0; i < n; ++i){\r\n      if((*this)[i]\
    \ == T(0)) continue;\r\n      if(i > d / k) return F(d, T(0));\r\n      T inv\
    \ = T(1) / (*this)[i];\r\n      F res = ((((*this)*inv) >> i).log() * k).exp()\
    \ * ((*this)[i].pow(k));\r\n      res = (res << (i*k)).pre(d);\r\n      if(int(res.size())\
    \ < d) res.resize(d, T(0));\r\n      return res;\r\n    }\r\n    return (*this);\r\
    \n  }\r\n\r\n  F sqrt(const function< T(T) > &get_sqrt, int d = -1) const {\r\n\
    \    const int n = this->size();\r\n    if(d == -1) d = n;\r\n\r\n    if((*this)[0]\
    \ == T(0)){\r\n      if(all_of(begin(*this), end(*this), [](T x){ return x ==\
    \ T(0); })){\r\n        return F(d, 0);\r\n      }\r\n      for(int i = 1; i <\
    \ n; ++i){\r\n        if((*this)[i] != T(0)){\r\n          if(i & 1) return F{};\r\
    \n          if(d - (i>>1) <= 0) return F(d, 0);\r\n          auto res = (*this\
    \ >> i).sqrt(get_sqrt ,d - (i>>1));\r\n          if(res.empty()) return F{};\r\
    \n          res <<= (i >> 1);\r\n          if(int(res.size()) < d) res.resize(d,\
    \ T(0));\r\n          return res;\r\n        }\r\n      }\r\n      return F{};\r\
    \n    }\r\n\r\n    T c = get_sqrt((*this)[0]);\r\n    if(c*c != (*this)[0]) return\
    \ F{};\r\n    T inv2 = T(1) / T(2);\r\n    F res(1, c);\r\n    for(int i = 1;\
    \ i < d; i <<= 1){\r\n      res = (res + pre(i << 1)* res.inv(i << 1)) * inv2;\r\
    \n    }\r\n    return res.pre(d);\r\n  }\r\n};\r\n#line 4 \"math/fps/GeneratingFunction.cpp\"\
    \n\r\ntemplate<typename T>\r\nT GeneratingFunction(Formalpowerseries<T> P, Formalpowerseries<T>\
    \ Q, long long n){\r\n  while(n > 0){\r\n    Formalpowerseries<T> V(Q);\r\n  \r\
    \n    int d = V.size();\r\n    for(int i = 0; i < d; i++) if(i&1) V[i] = -V[i];\r\
    \n  \r\n    auto U = P * V;\r\n    V *= Q;\r\n\r\n    if(n&1){\r\n      d = U.size();\r\
    \n      P.resize(d/2);\r\n      for(int i = 1; i < d; i += 2) P[i/2] = U[i];\r\
    \n    }else{\r\n      d = U.size();\r\n      P.resize((d+1)/2);\r\n      for(int\
    \ i = 0; i < d; i += 2) P[i/2] = U[i];\r\n    }\r\n    d = Q.size();\r\n    for(int\
    \ i = 0; i < d; i++) Q[i] = V[i*2];\r\n    n >>= 1;\r\n  }\r\n  return P[0];\r\
    \n}\r\n"
  code: "#pragma once\r\n\r\n#include \"./Formalpowerseries.cpp\"\r\n\r\ntemplate<typename\
    \ T>\r\nT GeneratingFunction(Formalpowerseries<T> P, Formalpowerseries<T> Q, long\
    \ long n){\r\n  while(n > 0){\r\n    Formalpowerseries<T> V(Q);\r\n  \r\n    int\
    \ d = V.size();\r\n    for(int i = 0; i < d; i++) if(i&1) V[i] = -V[i];\r\n  \r\
    \n    auto U = P * V;\r\n    V *= Q;\r\n\r\n    if(n&1){\r\n      d = U.size();\r\
    \n      P.resize(d/2);\r\n      for(int i = 1; i < d; i += 2) P[i/2] = U[i];\r\
    \n    }else{\r\n      d = U.size();\r\n      P.resize((d+1)/2);\r\n      for(int\
    \ i = 0; i < d; i += 2) P[i/2] = U[i];\r\n    }\r\n    d = Q.size();\r\n    for(int\
    \ i = 0; i < d; i++) Q[i] = V[i*2];\r\n    n >>= 1;\r\n  }\r\n  return P[0];\r\
    \n}\r\n"
  dependsOn:
  - math/fps/Formalpowerseries.cpp
  - math/fps/FFT-ntt.cpp
  - math/mod/ModInt.cpp
  - math/fps/NTT.cpp
  isVerificationFile: false
  path: math/fps/GeneratingFunction.cpp
  requiredBy: []
  timestamp: '2023-07-01 17:56:18+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/fps/GeneratingFunction.cpp
layout: document
redirect_from:
- /library/math/fps/GeneratingFunction.cpp
- /library/math/fps/GeneratingFunction.cpp.html
title: math/fps/GeneratingFunction.cpp
---
