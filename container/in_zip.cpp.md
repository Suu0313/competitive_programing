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
  bundledCode: "#line 2 \"container/in_zip.cpp\"\n\r\ntemplate<class Container> auto\
    \ myref(Container &c, size_t i){ return ref(c[i]); }\r\ntemplate<class Container>\
    \ auto myref(Container &&c, size_t i){ return c[i]; }\r\n\r\ntemplate<class...\
    \ Cs>\r\nauto in_zip_ref(Cs&&... cs){\r\n  vector<tuple<conditional_t<is_lvalue_reference_v<Cs>,\
    \ add_lvalue_reference_t<typename remove_reference_t<Cs>::value_type>, typename\
    \ remove_reference_t<Cs>::value_type>...>> v;\r\n  size_t n = min({size(cs)...});\
    \ v.reserve(n);\r\n  for(size_t i = 0; i < n; i++) v.emplace_back(myref(std::forward<Cs>(cs),\
    \ i)...);\r\n  return v;\r\n}\r\n\r\ntemplate<class... Cs>\r\nauto enumerate_ref(Cs&&...\
    \ cs){\r\n  auto iota_impl = [&]{ vector<int> idx(min({size(cs)...})); iota(begin(idx),\
    \ end(idx), 0); return idx; };\r\n  return inzip(iota_impl(), cs...);\r\n}\r\n\
    \r\ntemplate<class... Cs>\r\nauto in_zip(Cs&&... cs){\r\n  vector<tuple<typename\
    \ remove_reference_t<Cs>::value_type ...>> v;\r\n  size_t n = min({size(cs)...});\
    \ v.reserve(n);\r\n  for(size_t i = 0; i < n; i++) v.emplace_back(cs[i]...);\r\
    \n  return v;\r\n}\r\n\r\ntemplate<class... Cs>\r\nauto enumerate(Cs&&... cs){\r\
    \n  vector<int> idx(min({size(cs)...}));\r\n  iota(begin(idx), end(idx), 0);\r\
    \n  return in_zip(idx, cs...);\r\n}\r\n\r\ntemplate<typename T, size_t... Is>\r\
    \nauto unpack_impl(const vector<T> &v, index_sequence<Is...>){\r\n  tuple<vector<typename\
    \ tuple_element<Is, T>::type>...> res;\r\n  size_t n = v.size();\r\n  for(size_t\
    \ i = 0; i < n; ++i){\r\n    [[maybe_unused]] bool a[] = {(get<Is>(res).push_back(get<Is>(v[i])),\
    \ false)...};\r\n  }\r\n  return res;\r\n}\r\n\r\ntemplate<typename T>\r\nauto\
    \ unpack(const vector<T> &v){\r\n  return unpack_impl(v, make_index_sequence<tuple_size<T>::value>());\r\
    \n}\r\n"
  code: "#pragma once\r\n\r\ntemplate<class Container> auto myref(Container &c, size_t\
    \ i){ return ref(c[i]); }\r\ntemplate<class Container> auto myref(Container &&c,\
    \ size_t i){ return c[i]; }\r\n\r\ntemplate<class... Cs>\r\nauto in_zip_ref(Cs&&...\
    \ cs){\r\n  vector<tuple<conditional_t<is_lvalue_reference_v<Cs>, add_lvalue_reference_t<typename\
    \ remove_reference_t<Cs>::value_type>, typename remove_reference_t<Cs>::value_type>...>>\
    \ v;\r\n  size_t n = min({size(cs)...}); v.reserve(n);\r\n  for(size_t i = 0;\
    \ i < n; i++) v.emplace_back(myref(std::forward<Cs>(cs), i)...);\r\n  return v;\r\
    \n}\r\n\r\ntemplate<class... Cs>\r\nauto enumerate_ref(Cs&&... cs){\r\n  auto\
    \ iota_impl = [&]{ vector<int> idx(min({size(cs)...})); iota(begin(idx), end(idx),\
    \ 0); return idx; };\r\n  return inzip(iota_impl(), cs...);\r\n}\r\n\r\ntemplate<class...\
    \ Cs>\r\nauto in_zip(Cs&&... cs){\r\n  vector<tuple<typename remove_reference_t<Cs>::value_type\
    \ ...>> v;\r\n  size_t n = min({size(cs)...}); v.reserve(n);\r\n  for(size_t i\
    \ = 0; i < n; i++) v.emplace_back(cs[i]...);\r\n  return v;\r\n}\r\n\r\ntemplate<class...\
    \ Cs>\r\nauto enumerate(Cs&&... cs){\r\n  vector<int> idx(min({size(cs)...}));\r\
    \n  iota(begin(idx), end(idx), 0);\r\n  return in_zip(idx, cs...);\r\n}\r\n\r\n\
    template<typename T, size_t... Is>\r\nauto unpack_impl(const vector<T> &v, index_sequence<Is...>){\r\
    \n  tuple<vector<typename tuple_element<Is, T>::type>...> res;\r\n  size_t n =\
    \ v.size();\r\n  for(size_t i = 0; i < n; ++i){\r\n    [[maybe_unused]] bool a[]\
    \ = {(get<Is>(res).push_back(get<Is>(v[i])), false)...};\r\n  }\r\n  return res;\r\
    \n}\r\n\r\ntemplate<typename T>\r\nauto unpack(const vector<T> &v){\r\n  return\
    \ unpack_impl(v, make_index_sequence<tuple_size<T>::value>());\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: container/in_zip.cpp
  requiredBy: []
  timestamp: '2023-02-10 14:54:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: container/in_zip.cpp
layout: document
redirect_from:
- /library/container/in_zip.cpp
- /library/container/in_zip.cpp.html
title: container/in_zip.cpp
---
