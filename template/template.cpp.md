---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: math/integer/ceil.cpp
    title: math/integer/ceil.cpp
  - icon: ':warning:'
    path: math/integer/floor.cpp
    title: math/integer/floor.cpp
  - icon: ':warning:'
    path: math/integer/floor_kth_root.cpp
    title: math/integer/floor_kth_root.cpp
  - icon: ':warning:'
    path: math/integer/ipow.cpp
    title: math/integer/ipow.cpp
  - icon: ':warning:'
    path: math/integer/isqrt.cpp
    title: math/integer/isqrt.cpp
  - icon: ':warning:'
    path: math/integer/popcount.cpp
    title: math/integer/popcount.cpp
  - icon: ':warning:'
    path: template/template_constants.cpp
    title: template/template_constants.cpp
  - icon: ':warning:'
    path: template/template_defines.cpp
    title: template/template_defines.cpp
  - icon: ':warning:'
    path: template/template_functions.cpp
    title: template/template_functions.cpp
  - icon: ':warning:'
    path: template/template_integers.cpp
    title: template/template_integers.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"template/template.cpp\"\n#include <bits/stdc++.h>\nusing\
    \ namespace std;\n\n#line 2 \"template/template_defines.cpp\"\n\r\ntypedef long\
    \ long LL;\r\ntypedef pair<int, int> PII; typedef pair<LL,LL> PLL;\r\ntypedef\
    \ vector<int> VI; typedef vector<VI> VVI;\r\ntypedef vector<LL> VLL; typedef vector<VLL>\
    \ VVLL;\r\ntypedef vector<bool> VB; typedef vector<VB> VVB;\r\ntypedef vector<double>\
    \ VD; typedef vector<VD> VVD;\r\ntypedef vector<string> VS; typedef vector<VS>\
    \ VVS;\r\ntypedef vector<char> VC; typedef vector<VC> VVC;\r\ntypedef vector<PII>\
    \ VPII; typedef vector<PLL> VPLL;\r\n\r\n#define LB lower_bound\r\n#define UB\
    \ upper_bound\r\n#define FI first\r\n#define SE second\r\n#define EF emplace_front\r\
    \n#define EB emplace_back\r\n#define PF push_front\r\n#define PB push_back\r\n\
    #define POF pop_front\r\n#define POB pop_back\r\n#define MP make_pair\r\n#define\
    \ MT make_tuple\r\n#define ALL(a)  begin(a), end(a)\r\n#define RALL(a) rbegin(a),\
    \ rend(a)\r\n#define SORT(c) sort(begin(c), end(c))\r\n#define SORTR(c) sort(rbegin(c),\
    \ rend(c))\r\n\r\n#define FOR(i,a,b) for(decay_t<decltype(b)> i=(a), i##_r=(b);\
    \ i<i##_r; i++)\r\n#define REP(i,n) FOR(i,0,n)\r\n#define FORR(i,a,b) for(decay_t<decltype(b)>\
    \ i=(b)-1, i##_l=(a); i>=i##_l; i--)\r\n#define REPR(i,n) FORR(i,0,n)\r\n#define\
    \ CFOR(i,a,b) for(decay_t<decltype(b)> i=(a), i##_r=(b); i<=i##_r; i++)\r\n#define\
    \ CREP(i,n) CFOR(i,0,n)\r\n#define SREP(i,n) CFOR(i,1,n)\r\n#define CFORR(i,a,b)\
    \ for(decay_t<decltype(b)> i=(b), i##_l=(a); i>=i##_l; i--)\r\n#define CREPR(i,n)\
    \ CFORR(i,0,n)\r\n#define SREPR(i,n) CFORR(i,1,n)\r\n#define BFOR(bit,a,b) for(long\
    \ long bit=(a); bit<(1ll<<(b)); bit++)\r\n#define BREP(bit,n) BFOR(bit,0,n)\r\n\
    \r\n#define OVERLOAD4(a,b,c,d,name,...) name\r\n#define EACH1(a, v) for(auto&&a\
    \ : v)\r\n#define EACH2(a,b, v) for(auto&&[a,b] : v)\r\n#define EACH3(a,b,c, v)\
    \ for(auto&&[a,b,c] : v)\r\n#define EACH(...) OVERLOAD4(__VA_ARGS__, EACH3, EACH2,\
    \ EACH1)(__VA_ARGS__)\r\n\r\n#define elif else if\r\n#define unless(a) if(!(a))\r\
    \n#line 5 \"template/template.cpp\"\n\n#line 2 \"template/template_constants.cpp\"\
    \n\r\nconstexpr double EPS = 1e-10;\r\nconstexpr double PI  = 3.141592653589793238462643383279;\r\
    \nconstexpr int INF = numeric_limits<int>::max()/2;\r\nconstexpr long long LINF\
    \ = numeric_limits<long long>::max()/3;\r\nconstexpr long long MOD1 = 1e9+7;\r\
    \nconstexpr long long MOD2 = 998244353;\r\nconstexpr long long TEN(int n) { return\
    \ n? 10*TEN(n-1) : 1; }\r\n\r\nconstexpr int dx[] = {1,0,-1,0,1,1,-1,-1}, dy[]\
    \ = {0,1,0,-1,1,-1,1,-1};\r\n#line 7 \"template/template.cpp\"\n\n#line 2 \"template/template_functions.cpp\"\
    \n\r\ntemplate<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1;\
    \ } return 0; }\r\ntemplate<class T>bool chmin(T &a, const T &b) { if (b<a) {\
    \ a=b; return 1; } return 0; }\r\n\r\ntemplate<typename T> T accumulate(const\
    \ vector<T> &v){ return accumulate(begin(v), end(v), T(0)); }\r\ntemplate<typename\
    \ T>\r\nT gcd(const vector<T> &v){ return accumulate(begin(v), end(v),T(0),[](auto&&a,\
    \ auto&&b){ return gcd(a,b); }); }\r\ntemplate<typename T>\r\nT lcm(const vector<T>\
    \ &v){ return accumulate(begin(v), end(v),T(1),[](auto&&a, auto&&b){ return lcm(a,b);\
    \ }); }\r\ntemplate<typename T> T max(const vector<T> &v){ return *max_element(begin(v),\
    \ end(v)); }\r\ntemplate<typename T> T min(const vector<T> &v){ return *min_element(begin(v),\
    \ end(v)); }\r\n\r\ntemplate<class T> vector<T> &operator++(vector<T> &v){ for(auto&&e\
    \ : v){ ++e; } return v; }\r\ntemplate<class T> vector<T> &operator--(vector<T>\
    \ &v){ for(auto&&e : v){ --e; } return v; }\r\ntemplate<class T1, class T2> pair<T1,T2>\
    \ &operator++(pair<T1, T2> &p){ ++p.first, ++p.second; return p; }\r\ntemplate<class\
    \ T1, class T2> pair<T1,T2> &operator--(pair<T1, T2> &p){ --p.first, --p.second;\
    \ return p; }\r\n\r\ntemplate<typename T> vector<T> make_v(size_t a,T b){ return\
    \ vector<T>(a, b); }\r\ntemplate<typename... Ts> auto make_v(size_t a,Ts... ts){\
    \ return vector(a,make_v(ts...)); }\r\n\r\ntemplate<typename T = int> vector<T>\
    \ stov(const string &s, char c = '0'){\r\n  vector<T> res(s.size());\r\n  for(size_t\
    \ i = 0; i < s.size(); ++i) res[i] = s[i] - c;\r\n  return res;\r\n}\r\n\r\nvector<int>\
    \ iota(int s, int t, int d){\r\n  vector<int> idx;\r\n  for(int i = s; (s <= i\
    \ && i < t) || (t < i && i <= s); i += d) idx.push_back(i);\r\n  return idx;\r\
    \n}\r\ntemplate<typename T = int> vector<T> iota(int n, T e = 0){ vector<T> v(n);\
    \ iota(begin(v), end(v), e); return v; }\r\ntemplate<typename Container> constexpr\
    \ int isz(const Container &c){ return size(c); }\r\ntemplate<typename Container>\
    \ void reverse(Container &c){ reverse(begin(c), end(c));}\r\ntemplate<typename\
    \ Container> Container reversed(Container c){ reverse(c); return c; }\r\ntemplate<typename\
    \ Container> void sort(Container &c){ sort(begin(c), end(c)); }\r\ntemplate<typename\
    \ Container> Container sorted(Container c){ sort(c); return c; }\r\ntemplate<typename\
    \ Container, class Compair> void sort(Container &c, const Compair &cmp){ sort(begin(c),\
    \ end(c), cmp); }\r\ntemplate<typename Container, class Compair> Container sorted(Container\
    \ c, const Compair &cmp){ sort(c, cmp); return c; }\r\ntemplate<typename T>\r\n\
    vector<T> subvec(const vector<T> &v,  size_t pos = 0, size_t n = string::npos){\r\
    \n  assert(pos <= v.size()); n = min(n, v.size() - pos);\r\n  return vector<T>(v.begin()+pos,\
    \ v.begin()+pos+n);\r\n}\r\ntemplate<typename Container> Container unique(Container\
    \ c){ c.erase(unique(begin(c), end(c)), end(c)); return c; }\r\ntemplate<typename\
    \ T>\r\nvector<T> concat(const vector<T> &a, const vector<T> &b){\r\n  vector<T>\
    \ res = a; res.reserve(a.size() + b.size());\r\n  res.insert(end(res), begin(b),\
    \ end(b));\r\n  return res;\r\n}\r\ntemplate<typename T, class Compair = less<T>>\r\
    \nvector<int> sorted_idx(const vector<T> &a, vector<int> idx, const Compair &cmp\
    \ = Compair{}){\r\n  sort(begin(idx), end(idx), [&](int i, int j){ return cmp(a[i],\
    \ a[j]); });\r\n  return idx;\r\n}\r\ntemplate<typename T, class Compair = less<T>>\r\
    \nvector<int> sorted_idx(const vector<T> &a, const Compair &cmp = Compair{}){\r\
    \n  vector<int> idx(a.size()); iota(begin(idx), end(idx), 0);\r\n  return sorted_idx<T,\
    \ Compair>(a, idx, cmp);\r\n}\r\ntemplate<typename T>\r\nvector<T> re_order(const\
    \ vector<T> &a, const vector<int> &idx){\r\n  int n = int(a.size());\r\n  vector<T>\
    \ res(n); for(int i = 0; i < n; ++i) res[i] = a[idx[i]];\r\n  return res;\r\n\
    }\r\ntemplate<typename... Ts>\r\nstring format(const string &fmt, Ts... ts){\r\
    \n  size_t len = snprintf(nullptr, 0, fmt.c_str(), ts...);\r\n  vector<char> buf(len\
    \ + 1);\r\n  snprintf(&buf[0], len + 1, fmt.c_str(), ts...);\r\n  return string(buf.begin(),\
    \ buf.end()-1);\r\n}\r\ntemplate<typename Container>\r\nstring join(const Container&v,\
    \ const string &sep = \"\", const string &en = \"\"){\r\n  stringstream s;\r\n\
    \  for(size_t i = 0; i < size(v); i++) s << v[i] << (i+1 != size(v) ? sep : en);\r\
    \n  return s.str();\r\n}\r\ntemplate<typename T>\r\nvector<T> preffix_sum(const\
    \ vector<T> &v){\r\n  int n = int(v.size());\r\n  vector<T> ps(n + 1, 0);\r\n\
    \  for(int i = 0; i < n; ++i) ps[i + 1] = ps[i] + v[i];\r\n  return ps;\r\n}\r\
    \ntemplate<typename T>\r\nvector<T> get_pow_vector(int n, T p){\r\n  vector<T>\
    \ res(n + 1, 1);\r\n  for(int i = 0; i < n; ++i) res[i + 1] = res[i] * p;\r\n\
    \  return res;\r\n}\r\n\r\n\r\nbool cYN(bool fl=true,bool fl2=false){cout << (fl?\"\
    Yes\":\"No\") << '\\n'; if(fl2){ exit(0); } return fl; }\r\nbool CYN(bool fl=true,bool\
    \ fl2=false){cout << (fl?\"YES\":\"NO\") << '\\n'; if(fl2){ exit(0); } return\
    \ fl; }\r\ntemplate<typename T = int> void error(T t=-1,bool fl=true){cout <<\
    \ t << '\\n'; if(fl){ exit(0); } }\r\nvoid COUT(){ cout << \"\\n\"; }\r\ntemplate<class\
    \ T> void COUT(T&& t){ cout << t << '\\n'; }\r\ntemplate<class T,class... Ts>\
    \ void COUT(T&& t,Ts&&... ts){ cout << t << \" \"; COUT(ts...); }\r\ntemplate<class...\
    \ Ts> void CIN(Ts&&... ts){ (cin >> ... >> ts); }\r\n#define INPUT(T, ...) T __VA_ARGS__;\
    \ CIN(__VA_ARGS__)\r\n\r\n\r\ntemplate< typename T1, typename T2 > istream &operator>>(istream\
    \ &is, pair<T1, T2> &p) {\r\n  is >> p.first >> p.second; return is;\r\n}\r\n\
    template< typename T1, typename T2 > ostream &operator<<(ostream &os, const pair<T1,\
    \ T2>& p) {\r\n  os << p.first << \" \" << p.second; return os;\r\n}\r\ntemplate<\
    \ typename T > istream &operator>>(istream &is, vector<T> &v) {\r\n  for(auto&&in\
    \ : v){ is >> in; } return is;\r\n}\r\ntemplate< typename T > ostream &operator<<(ostream\
    \ &os, const vector<T> &v) {\r\n  for(size_t i = 0; i < v.size(); i++) os << v[i]\
    \ << (i + 1 != v.size() ? \" \" : \"\");\r\n  return os;\r\n}\r\n\r\ntemplate<typename...\
    \ Ts, size_t... Is>\r\nostream &tuple_output_impl(ostream &os, const tuple<Ts...>\
    \ &tp, index_sequence<Is...>){\r\n  [[maybe_unused]] bool a[] = {(os << get<Is>(tp)\
    \ << \" \", false)...};\r\n  return os << get<tuple_size<tuple<Ts...>>::value-1>(tp);\r\
    \n}\r\n\r\ntemplate<typename... Ts>\r\nostream &operator<<(ostream &os, const\
    \ tuple<Ts...> &tp){\r\n  return tuple_output_impl(os, tp, make_index_sequence<tuple_size<tuple<Ts...>>::value-1>());\r\
    \n}\r\n\r\nvoid Vcin([[maybe_unused]] size_t i) {}\r\ntemplate<class T, class...\
    \ Ts> void Vcin(size_t i, vector<T> &v, Ts&&... vs){ cin >> v[i]; Vcin(i, vs...);\
    \ }\r\ntemplate<class T, class... Ts>\r\nvoid Vcin(vector<T> &v,Ts&&... vs){ for(size_t\
    \ i = 0; i < v.size(); i++) Vcin(i, v, vs...); }\r\n\r\ntemplate< typename T >\r\
    \nvoid Vcout(const vector<T> &v, const string &sep = \"\\n\", const string &en\
    \ = \"\\n\"){\r\n  for(size_t i = 0; i < v.size(); i++) cout << v[i] << (i+1 !=\
    \ v.size() ? sep : en);\r\n}\r\n#line 9 \"template/template.cpp\"\n\n#line 2 \"\
    math/integer/ceil.cpp\"\n\r\ntemplate<class T> constexpr T ceil(T x, T y) {\r\n\
    \  if(y < 0) x = -x, y = -y;\r\n  if(x >= 0) return (x + y - 1) / y;\r\n  return\
    \ x / y;\r\n}\r\n#line 2 \"template/template_integers.cpp\"\n\r\n#line 2 \"math/integer/floor.cpp\"\
    \n\r\ntemplate<class T> constexpr T floor(T x, T y) {\r\n  if(y < 0) x = -x, y\
    \ = -y;\r\n  if(x >= 0) return x / y;\r\n  return (x - y + 1) / y;\r\n}\r\n#line\
    \ 4 \"template/template_integers.cpp\"\n\r\n#line 2 \"math/integer/floor_kth_root.cpp\"\
    \n\r\nuint64_t floor_kth_root(uint64_t a, int k){\r\n  if(a <= 1 || k <= 1) return\
    \ a;\r\n  if(k >= 64) return 1;\r\n  uint64_t res = 0;\r\n  for(int i = 31; i\
    \ >= 0; --i){\r\n    uint64_t p = 1, x = res | (1u << i);\r\n    bool fl = true;\r\
    \n    for(int j = 0; j < k; ++j){\r\n      if(__builtin_mul_overflow(p, x, &p)){\
    \ fl = false; break;}\r\n    }\r\n    if(fl && p <= a) res |= (1u << i);\r\n \
    \ }\r\n  return res;\r\n}\r\n#line 6 \"template/template_integers.cpp\"\n\r\n\
    #line 2 \"math/integer/isqrt.cpp\"\n\r\nuint64_t isqrt(uint64_t x){\r\n  uint64_t\
    \ res = 0, over = 1;\r\n  while(over*over <= x) over <<= 1;\r\n  while(over-res\
    \ > 1){\r\n    uint64_t wj = res + ((over-res) >> 1);\r\n    ((wj*wj <= x) ? res\
    \ : over) = wj;\r\n  }\r\n  return res;\r\n}\r\n#line 8 \"template/template_integers.cpp\"\
    \n\r\n#line 2 \"math/integer/ipow.cpp\"\n\r\ntemplate<typename T>\r\nT mod_inv(T\
    \ a, T m){\r\n  T b = m, u= 1, v = 0;\r\n  while(b){ T t = a/b; a -= t*b; swap(a,b);\
    \ u -= t*v; swap(u,v); }\r\n  u %= m; if(u<0) u+= m;\r\n  return u;\r\n}\r\n\r\
    \ntemplate<typename T>\r\nT ipow(T a, int64_t n, T m = 0, T e = 1){\r\n  if(n\
    \ < 0){ assert(m != 0); return mod_inv(ipow(a, -n, m, e), m); }\r\n  T res = e;\r\
    \n  while(n > 0){ if(n&1){ res *= a; if(m) res %= m; } a *= a; n >>= 1; if(m)\
    \ a %= m; }\r\n  return res;\r\n}\r\n#line 10 \"template/template_integers.cpp\"\
    \n\r\n#line 2 \"math/integer/popcount.cpp\"\n\r\nconstexpr int popcount(uint64_t\
    \ x){\r\n  x -= ((x>>1)&0x5555555555555555ULL);\r\n  x = (x&0x3333333333333333ULL)\
    \ + ((x&0xCCCCCCCCCCCCCCCCULL)>>2);\r\n  x = (x&0x0F0F0F0F0F0F0F0FULL) + ((x&0xF0F0F0F0F0F0F0F0ULL)>>4);\
    \  \r\n  x *= 0x0101010101010101ULL;\r\n  return x >> 56;\r\n}\r\n#line 11 \"\
    template/template.cpp\"\n"
  code: '#include <bits/stdc++.h>

    using namespace std;


    #include "./template_defines.cpp"


    #include "./template_constants.cpp"


    #include "./template_functions.cpp"


    #include "./template_integers.cpp"'
  dependsOn:
  - template/template_defines.cpp
  - template/template_constants.cpp
  - template/template_functions.cpp
  - template/template_integers.cpp
  - math/integer/ceil.cpp
  - math/integer/floor.cpp
  - math/integer/floor_kth_root.cpp
  - math/integer/isqrt.cpp
  - math/integer/ipow.cpp
  - math/integer/popcount.cpp
  isVerificationFile: false
  path: template/template.cpp
  requiredBy: []
  timestamp: '2023-07-01 17:56:18+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: template/template.cpp
layout: document
redirect_from:
- /library/template/template.cpp
- /library/template/template.cpp.html
title: template/template.cpp
---
