---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: datastructure/algebraic/monoid/CompositeMonoid.cpp
    title: datastructure/algebraic/monoid/CompositeMonoid.cpp
  - icon: ':heavy_check_mark:'
    path: datastructure/segtree/SegmentTree.cpp
    title: Segment Tree
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
    PROBLEM: https://judge.yosupo.jp/problem/point_set_range_composite
    links:
    - https://judge.yosupo.jp/problem/point_set_range_composite
  bundledCode: "#line 1 \"test/verify/lc/point_set_range_composite.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/point_set_range_composite\"\n\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n\n#line 2 \"datastructure/segtree/SegmentTree.cpp\"\
    \n\r\ntemplate<class Monoid>\r\nstruct SegmentTree{\r\n  int n;\r\n  vector<Monoid>\
    \ node;\r\n\r\n  SegmentTree() = default;\r\n  SegmentTree(int n): n(n), node(n\
    \ * 2) {}\r\n  SegmentTree(int n, const Monoid &x): n(n), node(n * 2, x){ build();\
    \ }\r\n  template<class Iiter>\r\n  SegmentTree(Iiter first, Iiter last): SegmentTree(int(distance(first,\
    \ last))){\r\n    for(int i = 0; i < n; ++i, ++first) node[i + n] = *first;\r\n\
    \    build();\r\n  }\r\n  template<class Container>\r\n  SegmentTree(const Container\
    \ &c): SegmentTree(begin(c), end(c)) {}\r\n\r\n\r\n  void build(){\r\n    for(int\
    \ k = n - 1; k > 0; --k) node[k] = node[k << 1] + node[k << 1 | 1];\r\n  }\r\n\
    \r\n  void set(int k, const Monoid &x){ node[k + n] = x; }\r\n\r\n  void change(int\
    \ k, const Monoid &x){\r\n    k += n;\r\n    node[k] = x;\r\n    while(k >>= 1)\
    \ node[k] = node[k << 1] + node[k << 1 | 1];\r\n  }\r\n\r\n  void change(int l,\
    \ int r, const Monoid &x){\r\n    for(int k = l; k < r; k++) change(k, x);\r\n\
    \  }\r\n\r\n  template<typename F>\r\n  void update(int k, const F &f){\r\n  \
    \  change(k, f(node[k + n]));\r\n  }\r\n\r\n  template<typename F>\r\n  void update(int\
    \ l, int r, const F &f){\r\n    for(int k = l; k < r; k++) update(k, f);\r\n \
    \ }\r\n\r\n  const Monoid &operator[](int k) const { return node[k + n]; }\r\n\
    \r\n  Monoid query(int l, int r) const {\r\n    Monoid res_l{}, res_r{};\r\n \
    \   for(l += n, r += n; l < r; l >>= 1, r >>= 1){\r\n      if(l & 1) res_l +=\
    \ node[l++];\r\n      if(r & 1) res_r = node[--r] + res_r;\r\n    }\r\n    return\
    \ res_l += res_r;\r\n  }\r\n\r\n  template<typename C>\r\n  int max_right(int\
    \ l, const C &check){\r\n    if(l == n) return n;\r\n    Monoid x{};\r\n    l\
    \ += n;\r\n    int r = n * 2, h = 0;\r\n    for(; l < r; l >>= 1, r >>= 1, ++h){\r\
    \n      if(l & 1){\r\n        if(!check(x + node[l])){\r\n          while(l <\
    \ n){\r\n            l <<= 1;\r\n            if(check(x + node[l])) x += node[l++];\r\
    \n          }\r\n          return l - n;\r\n        }\r\n        x += node[l++];\r\
    \n      }\r\n      if(r & 1) --r;\r\n    }\r\n\r\n    while(r <<= 1, h--){\r\n\
    \      if(((r + 1) << h) <= n * 2) {\r\n        if(!check(x + node[r])){\r\n \
    \         while(r < n){\r\n            r <<= 1;\r\n            if(check(x + node[r]))\
    \ x += node[r++];\r\n          }\r\n          return r - n;\r\n        }\r\n \
    \       x += node[r++];\r\n      }\r\n    }\r\n\r\n    return n;\r\n  }\r\n\r\n\
    \  template<typename C>\r\n  int min_left(int r, const C &check){\r\n    if(r\
    \ == 0) return 0;\r\n    Monoid x{};\r\n    r += n;\r\n    int l = n, h = 0;\r\
    \n    for(; l < r; l >>= 1, r >>= 1, ++h){\r\n      if(l & 1) ++l;\r\n      if(r\
    \ & 1){\r\n        --r;\r\n        if(!check(node[r] + x)){\r\n          while(r\
    \ < n){\r\n            r = 2*r + 1;\r\n            if(check(node[r] + x)) x =\
    \ node[r--] + x;\r\n          }\r\n          return r - n + 1;\r\n        }\r\n\
    \        x = node[r] + x;\r\n      }\r\n    }\r\n\r\n    while(l <<= 1, h--){\r\
    \n      if(((l - 1) << h) >= n){\r\n        --l;\r\n        if(!check(node[l]\
    \ + x)){\r\n          while(l < n){\r\n            l = l * 2 + 1;\r\n        \
    \    if(check(node[l] + x)) x = node[l--] + x;\r\n          }\r\n          return\
    \ l - n + 1;\r\n        }\r\n        x = node[l] + x;\r\n      }\r\n    }\r\n\
    \    \r\n    return 0;\r\n  }\r\n};\r\n#line 7 \"test/verify/lc/point_set_range_composite.test.cpp\"\
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
    \ CompositeMonoid &m) const { return !((*this) == m); }\r\n};\r\n#line 9 \"test/verify/lc/point_set_range_composite.test.cpp\"\
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
    \ 11 \"test/verify/lc/point_set_range_composite.test.cpp\"\n\nint main(){\n  int\
    \ n, q; cin >> n >> q;\n  SegmentTree<CompositeMonoid<mint998244353>> seg(n);\n\
    \  for(int i = 0; i < n; ++i){\n    int a, b; cin >> a >> b;\n    seg.set(i, {a,\
    \ b});\n  }\n\n  seg.build();\n\n  while(q--){\n    int t; cin >> t;\n    if(t\
    \ == 0){\n      int p, c, d; cin >> p >> c >> d;\n      seg.change(p, {c, d});\n\
    \    }else{\n      int l, r, x; cin >> l >> r >> x;\n      auto[a, b] = seg.query(l,\
    \ r);\n      cout << (a * x + b) << \"\\n\";\n    }\n  }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_set_range_composite\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#include \"datastructure/segtree/SegmentTree.cpp\"\
    \n\n#include \"datastructure/algebraic/monoid/CompositeMonoid.cpp\"\n\n#include\
    \ \"math/mod/ModInt.cpp\"\n\nint main(){\n  int n, q; cin >> n >> q;\n  SegmentTree<CompositeMonoid<mint998244353>>\
    \ seg(n);\n  for(int i = 0; i < n; ++i){\n    int a, b; cin >> a >> b;\n    seg.set(i,\
    \ {a, b});\n  }\n\n  seg.build();\n\n  while(q--){\n    int t; cin >> t;\n   \
    \ if(t == 0){\n      int p, c, d; cin >> p >> c >> d;\n      seg.change(p, {c,\
    \ d});\n    }else{\n      int l, r, x; cin >> l >> r >> x;\n      auto[a, b] =\
    \ seg.query(l, r);\n      cout << (a * x + b) << \"\\n\";\n    }\n  }\n}\n"
  dependsOn:
  - datastructure/segtree/SegmentTree.cpp
  - datastructure/algebraic/monoid/CompositeMonoid.cpp
  - math/mod/ModInt.cpp
  isVerificationFile: true
  path: test/verify/lc/point_set_range_composite.test.cpp
  requiredBy: []
  timestamp: '2023-08-01 22:12:46+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/verify/lc/point_set_range_composite.test.cpp
layout: document
redirect_from:
- /verify/test/verify/lc/point_set_range_composite.test.cpp
- /verify/test/verify/lc/point_set_range_composite.test.cpp.html
title: test/verify/lc/point_set_range_composite.test.cpp
---
