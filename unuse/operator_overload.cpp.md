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
  bundledCode: "#line 1 \"unuse/operator_overload.cpp\"\ntemplate<typename T1, typename\
    \ T2>\r\npair<T1, T2> operator+(const pair<T1, T2> &a, const pair<T1, T2> &b){\r\
    \n  return {a.first + b.first, a.second + b.second};\r\n}\r\ntemplate<typename\
    \ T1, typename T2>\r\npair<T1, T2> &operator+=(pair<T1, T2> &a, const pair<T1,\
    \ T2> &b){\r\n  return a = a+b;\r\n}\r\n\r\ntemplate<typename T>\r\nvector<T>\
    \ &operator++(vector<T> &v){\r\n  for(auto&&e : v){ ++e; } return v;\r\n}\r\n\
    template<typename T>\r\nvector<T> operator++(vector<T> &v, int){\r\n  vector<T>\
    \ tmp(v); ++v; return tmp;\r\n}\r\ntemplate<typename T>\r\nvector<T> &operator--(vector<T>\
    \ &v){\r\n  for(auto&&e : v){ --e; } return v;\r\n}\r\ntemplate<typename T>\r\n\
    vector<T> operator--(vector<T> &v, int){\r\n  vector<T> tmp(v); --v; return tmp;\r\
    \n}\r\n\r\ntemplate<typename T>\r\nvector<T> &operator+=(vector<T> &v, const T\
    \ &x){\r\n  for(auto&&e : v){ e += x; } return v;\r\n}\r\ntemplate<typename T>\r\
    \nvector<T> &operator-=(vector<T> &v, const T &x){\r\n  for(auto&&e : v){ e -=\
    \ x; } return v;\r\n}\r\n\r\ntemplate<typename T>\r\nvector<T> operator+(const\
    \ vector<T> &v, const T &x){\r\n  return vector<T>(v) += x;\r\n}\r\ntemplate<typename\
    \ T>\r\nvector<T> operator-(const vector<T> &v, const T &x){\r\n  return vector<T>(v)\
    \ -= x;\r\n}\r\n\r\ntemplate<typename... Ts, size_t... Is>\r\nostream &tuple_output_impl(ostream\
    \ &os, const tuple<Ts...> &tp, index_sequence<Is...>){\r\n  [[maybe_unused]] bool\
    \ a[] = {(os << get<Is>(tp) << \" \", false)...};\r\n  return os << get<tuple_size<tuple<Ts...>>::value-1>(tp);\r\
    \n}\r\n\r\ntemplate<typename... Ts>\r\nostream &operator<<(ostream &os, const\
    \ tuple<Ts...> &tp){\r\n  return tuple_output_impl(os, tp, make_index_sequence<tuple_size<tuple<Ts...>>::value-1>());\r\
    \n}\r\n"
  code: "template<typename T1, typename T2>\r\npair<T1, T2> operator+(const pair<T1,\
    \ T2> &a, const pair<T1, T2> &b){\r\n  return {a.first + b.first, a.second + b.second};\r\
    \n}\r\ntemplate<typename T1, typename T2>\r\npair<T1, T2> &operator+=(pair<T1,\
    \ T2> &a, const pair<T1, T2> &b){\r\n  return a = a+b;\r\n}\r\n\r\ntemplate<typename\
    \ T>\r\nvector<T> &operator++(vector<T> &v){\r\n  for(auto&&e : v){ ++e; } return\
    \ v;\r\n}\r\ntemplate<typename T>\r\nvector<T> operator++(vector<T> &v, int){\r\
    \n  vector<T> tmp(v); ++v; return tmp;\r\n}\r\ntemplate<typename T>\r\nvector<T>\
    \ &operator--(vector<T> &v){\r\n  for(auto&&e : v){ --e; } return v;\r\n}\r\n\
    template<typename T>\r\nvector<T> operator--(vector<T> &v, int){\r\n  vector<T>\
    \ tmp(v); --v; return tmp;\r\n}\r\n\r\ntemplate<typename T>\r\nvector<T> &operator+=(vector<T>\
    \ &v, const T &x){\r\n  for(auto&&e : v){ e += x; } return v;\r\n}\r\ntemplate<typename\
    \ T>\r\nvector<T> &operator-=(vector<T> &v, const T &x){\r\n  for(auto&&e : v){\
    \ e -= x; } return v;\r\n}\r\n\r\ntemplate<typename T>\r\nvector<T> operator+(const\
    \ vector<T> &v, const T &x){\r\n  return vector<T>(v) += x;\r\n}\r\ntemplate<typename\
    \ T>\r\nvector<T> operator-(const vector<T> &v, const T &x){\r\n  return vector<T>(v)\
    \ -= x;\r\n}\r\n\r\ntemplate<typename... Ts, size_t... Is>\r\nostream &tuple_output_impl(ostream\
    \ &os, const tuple<Ts...> &tp, index_sequence<Is...>){\r\n  [[maybe_unused]] bool\
    \ a[] = {(os << get<Is>(tp) << \" \", false)...};\r\n  return os << get<tuple_size<tuple<Ts...>>::value-1>(tp);\r\
    \n}\r\n\r\ntemplate<typename... Ts>\r\nostream &operator<<(ostream &os, const\
    \ tuple<Ts...> &tp){\r\n  return tuple_output_impl(os, tp, make_index_sequence<tuple_size<tuple<Ts...>>::value-1>());\r\
    \n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: unuse/operator_overload.cpp
  requiredBy: []
  timestamp: '2022-04-06 05:01:57+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: unuse/operator_overload.cpp
layout: document
redirect_from:
- /library/unuse/operator_overload.cpp
- /library/unuse/operator_overload.cpp.html
title: unuse/operator_overload.cpp
---
