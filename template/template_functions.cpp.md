---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: template/template.cpp
    title: template/template.cpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"template/template_functions.cpp\"\n\r\ntemplate<class T>bool\
    \ chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }\r\ntemplate<class\
    \ T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }\r\n\
    \r\ntemplate<typename T> T accumulate(const vector<T> &v){ return accumulate(begin(v),\
    \ end(v), T(0)); }\r\ntemplate<typename T>\r\nT gcd(const vector<T> &v){ return\
    \ accumulate(begin(v), end(v),T(0),[](auto&&a, auto&&b){ return gcd(a,b); });\
    \ }\r\ntemplate<typename T>\r\nT lcm(const vector<T> &v){ return accumulate(begin(v),\
    \ end(v),T(1),[](auto&&a, auto&&b){ return lcm(a,b); }); }\r\ntemplate<typename\
    \ T> T max(const vector<T> &v){ return *max_element(begin(v), end(v)); }\r\ntemplate<typename\
    \ T> T min(const vector<T> &v){ return *min_element(begin(v), end(v)); }\r\n\r\
    \ntemplate<class T> vector<T> &operator++(vector<T> &v){ for(auto&&e : v){ ++e;\
    \ } return v; }\r\ntemplate<class T> vector<T> &operator--(vector<T> &v){ for(auto&&e\
    \ : v){ --e; } return v; }\r\ntemplate<class T1, class T2> pair<T1,T2> &operator++(pair<T1,\
    \ T2> &p){ ++p.first, ++p.second; return p; }\r\ntemplate<class T1, class T2>\
    \ pair<T1,T2> &operator--(pair<T1, T2> &p){ --p.first, --p.second; return p; }\r\
    \n\r\ntemplate<typename T> vector<T> make_v(size_t a,T b){ return vector<T>(a,\
    \ b); }\r\ntemplate<typename... Ts> auto make_v(size_t a,Ts... ts){ return vector(a,make_v(ts...));\
    \ }\r\n\r\ntemplate<typename T = int> vector<T> stov(const string &s, char c =\
    \ '0'){\r\n  vector<T> res(s.size());\r\n  for(size_t i = 0; i < s.size(); ++i)\
    \ res[i] = s[i] - c;\r\n  return res;\r\n}\r\n\r\nvector<int> iota(int s, int\
    \ t, int d){\r\n  vector<int> idx;\r\n  for(int i = s; (s <= i && i < t) || (t\
    \ < i && i <= s); i += d) idx.push_back(i);\r\n  return idx;\r\n}\r\ntemplate<typename\
    \ T = int> vector<T> iota(int n, T e = 0){ vector<T> v(n); iota(begin(v), end(v),\
    \ e); return v; }\r\ntemplate<typename Container> constexpr int isz(const Container\
    \ &c){ return size(c); }\r\ntemplate<typename Container> void reverse(Container\
    \ &c){ reverse(begin(c), end(c));}\r\ntemplate<typename Container> Container reversed(Container\
    \ c){ reverse(c); return c; }\r\ntemplate<typename Container> void sort(Container\
    \ &c){ sort(begin(c), end(c)); }\r\ntemplate<typename Container> Container sorted(Container\
    \ c){ sort(c); return c; }\r\ntemplate<typename Container, class Compair> void\
    \ sort(Container &c, const Compair &cmp){ sort(begin(c), end(c), cmp); }\r\ntemplate<typename\
    \ Container, class Compair> Container sorted(Container c, const Compair &cmp){\
    \ sort(c, cmp); return c; }\r\ntemplate<typename T>\r\nvector<T> subvec(const\
    \ vector<T> &v,  size_t pos = 0, size_t n = string::npos){\r\n  assert(pos <=\
    \ v.size()); n = min(n, v.size() - pos);\r\n  return vector<T>(v.begin()+pos,\
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
    }\r\ntemplate<typename... Ts>\r\nstring cformat(const string &fmt, Ts... ts){\r\
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
    \ v.size() ? sep : en);\r\n}\r\n"
  code: "#pragma once\r\n\r\ntemplate<class T>bool chmax(T &a, const T &b) { if (a<b)\
    \ { a=b; return 1; } return 0; }\r\ntemplate<class T>bool chmin(T &a, const T\
    \ &b) { if (b<a) { a=b; return 1; } return 0; }\r\n\r\ntemplate<typename T> T\
    \ accumulate(const vector<T> &v){ return accumulate(begin(v), end(v), T(0)); }\r\
    \ntemplate<typename T>\r\nT gcd(const vector<T> &v){ return accumulate(begin(v),\
    \ end(v),T(0),[](auto&&a, auto&&b){ return gcd(a,b); }); }\r\ntemplate<typename\
    \ T>\r\nT lcm(const vector<T> &v){ return accumulate(begin(v), end(v),T(1),[](auto&&a,\
    \ auto&&b){ return lcm(a,b); }); }\r\ntemplate<typename T> T max(const vector<T>\
    \ &v){ return *max_element(begin(v), end(v)); }\r\ntemplate<typename T> T min(const\
    \ vector<T> &v){ return *min_element(begin(v), end(v)); }\r\n\r\ntemplate<class\
    \ T> vector<T> &operator++(vector<T> &v){ for(auto&&e : v){ ++e; } return v; }\r\
    \ntemplate<class T> vector<T> &operator--(vector<T> &v){ for(auto&&e : v){ --e;\
    \ } return v; }\r\ntemplate<class T1, class T2> pair<T1,T2> &operator++(pair<T1,\
    \ T2> &p){ ++p.first, ++p.second; return p; }\r\ntemplate<class T1, class T2>\
    \ pair<T1,T2> &operator--(pair<T1, T2> &p){ --p.first, --p.second; return p; }\r\
    \n\r\ntemplate<typename T> vector<T> make_v(size_t a,T b){ return vector<T>(a,\
    \ b); }\r\ntemplate<typename... Ts> auto make_v(size_t a,Ts... ts){ return vector(a,make_v(ts...));\
    \ }\r\n\r\ntemplate<typename T = int> vector<T> stov(const string &s, char c =\
    \ '0'){\r\n  vector<T> res(s.size());\r\n  for(size_t i = 0; i < s.size(); ++i)\
    \ res[i] = s[i] - c;\r\n  return res;\r\n}\r\n\r\nvector<int> iota(int s, int\
    \ t, int d){\r\n  vector<int> idx;\r\n  for(int i = s; (s <= i && i < t) || (t\
    \ < i && i <= s); i += d) idx.push_back(i);\r\n  return idx;\r\n}\r\ntemplate<typename\
    \ T = int> vector<T> iota(int n, T e = 0){ vector<T> v(n); iota(begin(v), end(v),\
    \ e); return v; }\r\ntemplate<typename Container> constexpr int isz(const Container\
    \ &c){ return size(c); }\r\ntemplate<typename Container> void reverse(Container\
    \ &c){ reverse(begin(c), end(c));}\r\ntemplate<typename Container> Container reversed(Container\
    \ c){ reverse(c); return c; }\r\ntemplate<typename Container> void sort(Container\
    \ &c){ sort(begin(c), end(c)); }\r\ntemplate<typename Container> Container sorted(Container\
    \ c){ sort(c); return c; }\r\ntemplate<typename Container, class Compair> void\
    \ sort(Container &c, const Compair &cmp){ sort(begin(c), end(c), cmp); }\r\ntemplate<typename\
    \ Container, class Compair> Container sorted(Container c, const Compair &cmp){\
    \ sort(c, cmp); return c; }\r\ntemplate<typename T>\r\nvector<T> subvec(const\
    \ vector<T> &v,  size_t pos = 0, size_t n = string::npos){\r\n  assert(pos <=\
    \ v.size()); n = min(n, v.size() - pos);\r\n  return vector<T>(v.begin()+pos,\
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
    }\r\ntemplate<typename... Ts>\r\nstring cformat(const string &fmt, Ts... ts){\r\
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
    \ v.size() ? sep : en);\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: template/template_functions.cpp
  requiredBy:
  - template/template.cpp
  timestamp: '2023-08-01 21:17:09+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: template/template_functions.cpp
layout: document
redirect_from:
- /library/template/template_functions.cpp
- /library/template/template_functions.cpp.html
title: template/template_functions.cpp
---
