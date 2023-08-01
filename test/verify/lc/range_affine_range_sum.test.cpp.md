---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: datastructure/algebraic/monoid/CompositeMonoid.cpp
    title: datastructure/algebraic/monoid/CompositeMonoid.cpp
  - icon: ':heavy_check_mark:'
    path: datastructure/algebraic/monoid/LengthMonoid.cpp
    title: datastructure/algebraic/monoid/LengthMonoid.cpp
  - icon: ':heavy_check_mark:'
    path: datastructure/algebraic/operator_monoid/RangeAffineRangeSum.cpp
    title: datastructure/algebraic/operator_monoid/RangeAffineRangeSum.cpp
  - icon: ':heavy_check_mark:'
    path: datastructure/segtree/LazySegTree.cpp
    title: datastructure/segtree/LazySegTree.cpp
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
    PROBLEM: https://judge.yosupo.jp/problem/range_affine_range_sum
    links:
    - https://judge.yosupo.jp/problem/range_affine_range_sum
  bundledCode: "#line 1 \"test/verify/lc/range_affine_range_sum.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/range_affine_range_sum\"\n\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n\n#line 2 \"datastructure/segtree/LazySegTree.cpp\"\
    \n\r\n\r\ntemplate<class Operation>\r\nstruct LazySegTree{\r\n  using Monoid =\
    \ typename Operation::Monoid;\r\n  using OperatorMonoid = typename Operation::OperatorMonoid;\r\
    \n\r\n  int n, height;\r\n  vector<Monoid> node;\r\n  vector<OperatorMonoid> lazy;\r\
    \n  vector<int> sz;\r\n\r\n\r\n  LazySegTree() = default;\r\n  LazySegTree(int\
    \ n): n(n), height(ilog2(n)), node(n * 2), lazy(n) {}\r\n  LazySegTree(int n,\
    \ const Monoid &x): n(n), height(ilog2(n)), node(n * 2, x), lazy(n) { build();\
    \ }\r\n  template<typename Iiter>\r\n  LazySegTree(Iiter first, Iiter last): LazySegTree(int(distance(first,\
    \ last))) {\r\n    for(int i = 0; i < n; ++i, ++first) node[i + n] = *first;\r\
    \n    build();\r\n  }\r\n  template<class Container>\r\n  LazySegTree(const Container\
    \ &c): LazySegTree(begin(c), end(c)) {}\r\n\r\n\r\n  void build(){\r\n    for(int\
    \ k = n-1; k >= 0; k--) propagate(k);\r\n  }\r\n\r\n  void set(int k, const Monoid\
    \ &x){ node[k + n] = x; }\r\n\r\n  void change(int k, const Monoid &x){\r\n  \
    \  k += n;\r\n    resolve(k);\r\n    node[k] = x;\r\n    build(k);\r\n  }\r\n\r\
    \n  void update(int k, const OperatorMonoid &x){\r\n    k += n;\r\n    resolve(k);\
    \ apply(k, x); build(k);\r\n  }\r\n\r\n  void update(int l, int r, const OperatorMonoid\
    \ &x){\r\n    if(l == r) return;\r\n    l += n; r += n;\r\n    int dl = l, dr\
    \ = r;\r\n    resolve(dl); resolve(dr - 1);\r\n\r\n    for(; l < r; l >>= 1, r\
    \ >>= 1){\r\n      if(l & 1) apply(l++, x);\r\n      if(r & 1) apply(--r, x);\r\
    \n    }\r\n\r\n    build(dl); build(dr - 1);\r\n  }\r\n\r\n  Monoid operator[](int\
    \ k){\r\n    resolve(k += n);\r\n    return node[k];\r\n  }\r\n\r\n  Monoid query(int\
    \ l, int r){\r\n    Monoid res_l{}, res_r{};\r\n    if(l == r) return res_l;\r\
    \n    l += n; r += n;\r\n    resolve(l); resolve(r - 1);\r\n\r\n    for(; l <\
    \ r; l >>= 1, r >>= 1){\r\n      if(l & 1) res_l += node[l++];\r\n      if(r &\
    \ 1) res_r = node[--r] + res_r;\r\n    }\r\n    return res_l += res_r;\r\n  }\r\
    \n\r\n  template<typename C>\r\n  int max_right(int l, const C &check){\r\n  \
    \  if(l == n) return n;\r\n    l += n;\r\n    resolve(l);\r\n    Monoid x{};\r\
    \n    int r = n * 2, h = 0;\r\n    for(; l < r; l >>= 1, r >>= 1, ++h){\r\n  \
    \    if(l & 1){\r\n        if(!check(x + node[l])){\r\n          while(l < n){\r\
    \n            l <<= 1;\r\n            if(check(x + node[l])) x += node[l++];\r\
    \n          }\r\n          return l - n;\r\n        }\r\n        x += node[l++];\r\
    \n      }\r\n      if(r & 1) --r;\r\n    }\r\n\r\n    while(r <<= 1, h--){\r\n\
    \      if(((r + 1) << h) <= n * 2) {\r\n        if(!check(x + node[r])){\r\n \
    \         while(r < n){\r\n            r <<= 1;\r\n            if(check(x + node[r]))\
    \ x += node[r++];\r\n          }\r\n          return r - n;\r\n        }\r\n \
    \       x += node[r++];\r\n      }\r\n    }\r\n\r\n    return n;\r\n  }\r\n\r\n\
    \  template<typename C>\r\n  int min_left(int r, const C &check){\r\n    if(r\
    \ == 0) return 0;\r\n    r += n;\r\n    resolve(r - 1);\r\n    Monoid x{};\r\n\
    \    int l = n, h = 0;\r\n    for(; l < r; l >>= 1, r >>= 1, ++h){\r\n      if(l\
    \ & 1) ++l;\r\n      if(r & 1){\r\n        --r;\r\n        if(!check(node[r] +\
    \ x)){\r\n          while(r < n){\r\n            r = 2*r + 1;\r\n            if(check(node[r]\
    \ + x)) x = node[r--] + x;\r\n          }\r\n          return r - n + 1;\r\n \
    \       }\r\n        x = node[r] + x;\r\n      }\r\n    }\r\n\r\n    while(l <<=\
    \ 1, h--){\r\n      if(((l - 1) << h) >= n){\r\n        --l;\r\n        if(!check(node[l]\
    \ + x)){\r\n          while(l < n){\r\n            l = l * 2 + 1;\r\n        \
    \    if(check(node[l] + x)) x = node[l--] + x;\r\n          }\r\n          return\
    \ l - n + 1;\r\n        }\r\n        x = node[l] + x;\r\n      }\r\n    }\r\n\
    \    return 0;\r\n  }\r\n\r\nprivate:\r\n  int ilog2(int m){ return 31 - __builtin_clz(m);\
    \ }\r\n  void propagate(int k){ node[k] = node[k<<1] + node[k<<1 | 1]; }\r\n \
    \ void build(int k){\r\n    while(k){\r\n      k >>= 1;\r\n      propagate(k);\r\
    \n      Operation::act(node[k], lazy[k]);\r\n    }\r\n  }\r\n  void apply(int\
    \ k, const OperatorMonoid &x){\r\n    Operation::act(node[k], x);\r\n    if(k\
    \ < n) lazy[k] += x;\r\n  }\r\n  void resolve(int k){\r\n    OperatorMonoid id{};\r\
    \n    for(int h = height + 2; h > 0; --h){\r\n      int i = k >> h;\r\n      if(lazy[i]\
    \ != id){\r\n        apply(i << 1, lazy[i]);\r\n        apply(i << 1 | 1, lazy[i]);\r\
    \n        lazy[i] = id;\r\n      }\r\n    }\r\n  }\r\n};\r\n#line 7 \"test/verify/lc/range_affine_range_sum.test.cpp\"\
    \n\n#line 2 \"datastructure/algebraic/operator_monoid/RangeAffineRangeSum.cpp\"\
    \n\r\n\r\n#line 2 \"datastructure/algebraic/monoid/LengthMonoid.cpp\"\n\r\ntemplate<typename\
    \ T>\r\nstruct LengthMonoid{\r\n  T x{};\r\n  size_t l = 0;\r\n\r\n  LengthMonoid()\
    \ = default;\r\n  LengthMonoid(const LengthMonoid&) = default;\r\n  LengthMonoid(LengthMonoid&&)\
    \ = default;\r\n\r\n  LengthMonoid(const T &x, size_t l = 1): x(x), l(l) {}\r\n\
    \r\n  LengthMonoid &operator=(const LengthMonoid&) = default;\r\n  LengthMonoid\
    \ &operator=(LengthMonoid&&) = default;\r\n\r\n  LengthMonoid &operator+=(const\
    \ LengthMonoid &m){\r\n    x += m.x; l += m.l;\r\n    return (*this);\r\n  }\r\
    \n  LengthMonoid operator+(const LengthMonoid &m) const {\r\n    return LengthMonoid(*this)\
    \ += m;\r\n  }\r\n\r\n  bool operator==(const LengthMonoid &m) const { return\
    \ x == m.x && l == m.l; }\r\n  bool operator!=(const LengthMonoid &m) const {\
    \ return !((*this) == m); }\r\n};\r\n#line 2 \"datastructure/algebraic/monoid/CompositeMonoid.cpp\"\
    \n\r\ntemplate<typename T>\r\nstruct CompositeMonoid{\r\n  T a = 1, b = 0;\r\n\
    \  CompositeMonoid() = default;\r\n  CompositeMonoid(const CompositeMonoid&) =\
    \ default;\r\n  CompositeMonoid(CompositeMonoid&&) = default;\r\n\r\n  CompositeMonoid(const\
    \ T &a, const T &b): a(a), b(b) {}\r\n\r\n  CompositeMonoid &operator=(const CompositeMonoid&)\
    \ = default;\r\n  CompositeMonoid &operator=(CompositeMonoid&&) = default;\r\n\
    \r\n  CompositeMonoid &operator+=(const CompositeMonoid &m){\r\n    a *= m.a;\r\
    \n    b = b * m.a + m.b;\r\n    return (*this);\r\n  }\r\n  CompositeMonoid operator+(const\
    \ CompositeMonoid &m) const {\r\n    return CompositeMonoid(*this) += m;\r\n \
    \ }\r\n  bool operator==(const CompositeMonoid &m) const { return a == m.a &&\
    \ b == m.b; }\r\n  bool operator!=(const CompositeMonoid &m) const { return !((*this)\
    \ == m); }\r\n};\r\n#line 6 \"datastructure/algebraic/operator_monoid/RangeAffineRangeSum.cpp\"\
    \n\r\ntemplate<typename T>\r\nstruct RangeAffineRangeSum{\r\n  using Monoid =\
    \ LengthMonoid<T>;\r\n  using OperatorMonoid = CompositeMonoid<T>;\r\n\r\n  static\
    \ void act(Monoid &m, const OperatorMonoid &f){\r\n    m = Monoid(f.a * m.x +\
    \ f.b * m.l, m.l);\r\n  }\r\n};\r\n#line 9 \"test/verify/lc/range_affine_range_sum.test.cpp\"\
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
    \ 11 \"test/verify/lc/range_affine_range_sum.test.cpp\"\n\nint main(){\n  int\
    \ n, q; cin >> n >> q;\n  LazySegTree<RangeAffineRangeSum<mint998244353>> seg(n);\n\
    \  for(int i = 0; i < n; ++i){\n    int a; cin >> a;\n    seg.set(i, {a});\n \
    \ }\n  seg.build();\n\n  while(q--){\n    int t; cin >> t;\n    if(t == 0){\n\
    \      int l, r, c, d; cin >> l >> r >> c >> d;\n      seg.update(l, r, {c, d});\n\
    \    }else{\n      int l, r; cin >> l >> r;\n      cout << seg.query(l, r).x <<\
    \ \"\\n\";\n    }\n  }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/range_affine_range_sum\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#include \"datastructure/segtree/LazySegTree.cpp\"\
    \n\n#include \"datastructure/algebraic/operator_monoid/RangeAffineRangeSum.cpp\"\
    \n\n#include \"math/mod/ModInt.cpp\"\n\nint main(){\n  int n, q; cin >> n >> q;\n\
    \  LazySegTree<RangeAffineRangeSum<mint998244353>> seg(n);\n  for(int i = 0; i\
    \ < n; ++i){\n    int a; cin >> a;\n    seg.set(i, {a});\n  }\n  seg.build();\n\
    \n  while(q--){\n    int t; cin >> t;\n    if(t == 0){\n      int l, r, c, d;\
    \ cin >> l >> r >> c >> d;\n      seg.update(l, r, {c, d});\n    }else{\n    \
    \  int l, r; cin >> l >> r;\n      cout << seg.query(l, r).x << \"\\n\";\n   \
    \ }\n  }\n}\n"
  dependsOn:
  - datastructure/segtree/LazySegTree.cpp
  - datastructure/algebraic/operator_monoid/RangeAffineRangeSum.cpp
  - datastructure/algebraic/monoid/LengthMonoid.cpp
  - datastructure/algebraic/monoid/CompositeMonoid.cpp
  - math/mod/ModInt.cpp
  isVerificationFile: true
  path: test/verify/lc/range_affine_range_sum.test.cpp
  requiredBy: []
  timestamp: '2023-08-01 22:12:46+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/verify/lc/range_affine_range_sum.test.cpp
layout: document
redirect_from:
- /verify/test/verify/lc/range_affine_range_sum.test.cpp
- /verify/test/verify/lc/range_affine_range_sum.test.cpp.html
title: test/verify/lc/range_affine_range_sum.test.cpp
---
