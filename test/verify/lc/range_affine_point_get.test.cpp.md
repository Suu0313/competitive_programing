---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: datastructure/algebraic/monoid/CompositeMonoid.cpp
    title: datastructure/algebraic/monoid/CompositeMonoid.cpp
  - icon: ':heavy_check_mark:'
    path: datastructure/segtree/DualSegTree.cpp
    title: datastructure/segtree/DualSegTree.cpp
  - icon: ':heavy_check_mark:'
    path: math/mod/ModInt.cpp
    title: math/mod/ModInt.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/range_affine_point_get
    links:
    - https://judge.yosupo.jp/problem/range_affine_point_get
  bundledCode: "#line 1 \"test/verify/lc/range_affine_point_get.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/range_affine_point_get\"\n\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n\n#line 2 \"datastructure/segtree/DualSegTree.cpp\"\
    \n\r\ntemplate<class Monoid>\r\nstruct DualSegTree{\r\n  int n, height;\r\n  vector<Monoid>\
    \ lazy;\r\n\r\n  DualSegTree() = default;\r\n  DualSegTree(int n): n(n), height(ilog2(n)),\
    \ lazy(n * 2) {}\r\n  DualSegTree(int n, const Monoid &x): n(n), height(ilog2(n)),\
    \ lazy(n * 2) {\r\n    for(int i = 0; i < n; ++i) lazy[i + n] = x;\r\n  }\r\n\
    \  template<typename Iiter>\r\n  DualSegTree(Iiter first, Iiter last): DualSegTree(int(distance(first,\
    \ last))) {\r\n    for(int i = 0; i < n; ++i, ++first) lazy[i + n] = *first;\r\
    \n  }\r\n  template<class Container>\r\n  DualSegTree(const Container &c): DualSegTree(begin(c),\
    \ end(c)) {}\r\n\r\n\r\n  void update(int k, const Monoid &x){\r\n    if(x ==\
    \ Monoid{}) return;\r\n    resolve(k += n);\r\n    lazy[k] += x;\r\n  }\r\n\r\n\
    \  void update(int l, int r, const Monoid &x){\r\n    if(l >= r || x == Monoid{})\
    \ return;\r\n    l += n; r += n;\r\n    resolve(l); resolve(r - 1);\r\n\r\n  \
    \  for(; l < r; l >>= 1, r >>= 1){\r\n      if(l & 1) lazy[l++] += x;\r\n    \
    \  if(r & 1) lazy[--r] += x;\r\n    }\r\n  }\r\n\r\n  const Monoid &operator[](int\
    \ k){\r\n    resolve(k += n);\r\n    return lazy[k];\r\n  }\r\n\r\nprivate:\r\n\
    \  int ilog2(int m){ return 31 - __builtin_clz(m); }\r\n\r\n  void resolve(int\
    \ k){\r\n    Monoid id{};\r\n    for(int h = height + 2; h > 0; --h){\r\n    \
    \  int i = k >> h;\r\n      if(lazy[i] != id){\r\n        lazy[i << 1] += lazy[i];\r\
    \n        lazy[i << 1 | 1] += lazy[i];\r\n        lazy[i] = id;\r\n      }\r\n\
    \    }\r\n  }\r\n};\r\n#line 7 \"test/verify/lc/range_affine_point_get.test.cpp\"\
    \n\n#line 2 \"datastructure/algebraic/monoid/CompositeMonoid.cpp\"\n\r\ntemplate<typename\
    \ T>\r\nstruct CompositeMonoid{\r\n  T a = 1, b = 0;\r\n  CompositeMonoid() =\
    \ default;\r\n  CompositeMonoid(const CompositeMonoid&) = default;\r\n  CompositeMonoid(CompositeMonoid&&)\
    \ = default;\r\n\r\n  CompositeMonoid(const T &a, const T &b): a(a), b(b) {}\r\
    \n\r\n  CompositeMonoid &operator=(const CompositeMonoid&) = default;\r\n  CompositeMonoid\
    \ &operator=(CompositeMonoid&&) = default;\r\n\r\n  CompositeMonoid &operator+=(const\
    \ CompositeMonoid &m){\r\n    a *= m.a;\r\n    b = b * m.a + m.b;\r\n    return\
    \ (*this);\r\n  }\r\n  CompositeMonoid operator+(const CompositeMonoid &m) const\
    \ {\r\n    return CompositeMonoid(*this) += m;\r\n  }\r\n  bool operator==(const\
    \ CompositeMonoid &m) const { return a == m.a && b == m.b; }\r\n  bool operator!=(const\
    \ CompositeMonoid &m) const { return !((*this) == m); }\r\n};\r\n#line 9 \"test/verify/lc/range_affine_point_get.test.cpp\"\
    \n\n#line 2 \"math/mod/ModInt.cpp\"\n\r\ntemplate< int mod >\r\nstruct ModInt\
    \ {\r\n  int x;\r\n\r\n  constexpr ModInt() : x(0) {}\r\n\r\n  constexpr ModInt(int64_t\
    \ y) : x(y >= 0 ? y % mod : (mod - (-y) % mod) % mod) {}\r\n  \r\n  constexpr\
    \ ModInt &operator+=(const ModInt &p) {\r\n    if((x += p.x) >= mod) x -= mod;\r\
    \n    return *this;\r\n  }\r\n  constexpr ModInt &operator-=(const ModInt &p)\
    \ {\r\n    if((x += mod - p.x) >= mod) x -= mod;\r\n    return *this;\r\n  }\r\
    \n  constexpr ModInt &operator*=(const ModInt &p) {\r\n    x = (int) (1LL * x\
    \ * p.x % mod);\r\n    return *this;\r\n  }\r\n  constexpr ModInt &operator/=(const\
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
    \ = ModInt< 998244353 >;\r\nusing mint1000000007 = ModInt< 1000000007 >;\r\n#line\
    \ 11 \"test/verify/lc/range_affine_point_get.test.cpp\"\n\nint main() {\n  int\
    \ n, q; cin >> n >> q;\n  vector<int> x(n); for(auto&&e : x) cin >> e;\n  DualSegTree<CompositeMonoid<mint998244353>>\
    \ seg(n);\n  while(q--){\n    int t; cin >> t;\n    if(t == 0){\n      int l,\
    \ r, b, c; cin >> l >> r >> b >> c;\n      seg.update(l, r, {b, c});\n    }else{\n\
    \      int i; cin >> i;\n      auto[a, b] = seg[i];\n      cout << a * x[i] +\
    \ b << \"\\n\";\n    }\n  }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/range_affine_point_get\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#include \"datastructure/segtree/DualSegTree.cpp\"\
    \n\n#include \"datastructure/algebraic/monoid/CompositeMonoid.cpp\"\n\n#include\
    \ \"math/mod/ModInt.cpp\"\n\nint main() {\n  int n, q; cin >> n >> q;\n  vector<int>\
    \ x(n); for(auto&&e : x) cin >> e;\n  DualSegTree<CompositeMonoid<mint998244353>>\
    \ seg(n);\n  while(q--){\n    int t; cin >> t;\n    if(t == 0){\n      int l,\
    \ r, b, c; cin >> l >> r >> b >> c;\n      seg.update(l, r, {b, c});\n    }else{\n\
    \      int i; cin >> i;\n      auto[a, b] = seg[i];\n      cout << a * x[i] +\
    \ b << \"\\n\";\n    }\n  }\n}\n"
  dependsOn:
  - datastructure/segtree/DualSegTree.cpp
  - datastructure/algebraic/monoid/CompositeMonoid.cpp
  - math/mod/ModInt.cpp
  isVerificationFile: true
  path: test/verify/lc/range_affine_point_get.test.cpp
  requiredBy: []
  timestamp: '2023-08-01 22:12:46+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/verify/lc/range_affine_point_get.test.cpp
layout: document
redirect_from:
- /verify/test/verify/lc/range_affine_point_get.test.cpp
- /verify/test/verify/lc/range_affine_point_get.test.cpp.html
title: test/verify/lc/range_affine_point_get.test.cpp
---
