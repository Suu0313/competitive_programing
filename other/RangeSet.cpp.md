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
  bundledCode: "#line 2 \"other/RangeSet.cpp\"\n\r\ntemplate<typename T>\r\nstruct\
    \ RangeSet{\r\n  set<pair<T, T>> st;\r\n  RangeSet(){\r\n    st.emplace(numeric_limits<T>::min(),\
    \ numeric_limits<T>::min());\r\n    st.emplace(numeric_limits<T>::max(), numeric_limits<T>::max());\r\
    \n  }\r\n\r\n  bool contains(T x) const {\r\n    auto [l, r] = *prev(st.lower_bound(make_pair(x+1,\
    \ x+1)));\r\n    return l <= x && x <= r;\r\n  }\r\n\r\n  bool contains(T l, T\
    \ r) const {\r\n    auto [nl, nr] = *prev(st.lower_bound(make_pair(l+1, l+1)));\r\
    \n    return nl <= l && r <= nr;\r\n  }\r\n\r\n  bool insert(T x){\r\n    auto\
    \ nit = st.lower_bound(make_pair(x+1,x+1));\r\n    auto it = prev(nit);\r\n  \
    \  auto [l, r] = *it;\r\n    auto [nl, nr] = *nit;\r\n    if(l<=x && x<=r) return\
    \ false;\r\n    if(r == x-1){\r\n      if(x+1 == nl){\r\n        st.erase(it);\r\
    \n        st.erase(nit);\r\n        st.emplace(l,nr);\r\n      }else{\r\n    \
    \    st.erase(it);\r\n        st.emplace(l,x);\r\n      }\r\n    }else{\r\n  \
    \    if(x+1 == nl){\r\n        st.erase(nit);\r\n        st.emplace(x,nr);\r\n\
    \      }else{\r\n        st.emplace(x,x);\r\n      }\r\n    }\r\n    return true;\r\
    \n  }\r\n\r\n  bool insert(T l, T r){\r\n    auto it = prev(st.lower_bound(make_pair(l+1,\
    \ l+1)));\r\n    auto [nl, nr] = *it;\r\n    if(r <= nr) return false;\r\n   \
    \ if(nl <= l && l <= nr+1) l = nl;\r\n    else it++;\r\n    while(it->second <=\
    \ r) it = st.erase(it);\r\n    if(it->first <= r+1){ r = it->second; st.erase(it);\
    \ }\r\n    st.emplace(l, r);\r\n    return true;\r\n  }\r\n\r\n  bool erase(T\
    \ x){\r\n    auto it = prev(st.lower_bound(make_pair(x+1, x+1)));\r\n    auto\
    \ [l, r] = *it;\r\n    if(r < x) return false;\r\n    st.erase(it);\r\n    if(l\
    \ != r){\r\n      if(l == x) st.emplace(l+1, r);\r\n      else if(r == x) st.emplace(l,\
    \ r-1);\r\n      else st.emplace(l, x-1), st.emplace(x+1, r); \r\n    }\r\n  \
    \  return true;\r\n  }\r\n\r\n  bool erase(T l, T r){\r\n    auto it = prev(st.lower_bound(make_pair(l+1,\
    \ l+1)));\r\n    auto [nl, nr] = *it;\r\n    // ToDo\r\n    return true;\r\n \
    \ }\r\n\r\n  int mex(int x=0) const {\r\n    auto [l, r] = *prev(st.lower_bound(make_pair(x+1,\
    \ x+1)));\r\n    if(l<=x && x<=r) return r+1;\r\n    return x;\r\n  }\r\n\r\n\
    \  int cnt() const {\r\n    return (int)st.size() - 2;\r\n  }\r\n};\r\n"
  code: "#pragma once\r\n\r\ntemplate<typename T>\r\nstruct RangeSet{\r\n  set<pair<T,\
    \ T>> st;\r\n  RangeSet(){\r\n    st.emplace(numeric_limits<T>::min(), numeric_limits<T>::min());\r\
    \n    st.emplace(numeric_limits<T>::max(), numeric_limits<T>::max());\r\n  }\r\
    \n\r\n  bool contains(T x) const {\r\n    auto [l, r] = *prev(st.lower_bound(make_pair(x+1,\
    \ x+1)));\r\n    return l <= x && x <= r;\r\n  }\r\n\r\n  bool contains(T l, T\
    \ r) const {\r\n    auto [nl, nr] = *prev(st.lower_bound(make_pair(l+1, l+1)));\r\
    \n    return nl <= l && r <= nr;\r\n  }\r\n\r\n  bool insert(T x){\r\n    auto\
    \ nit = st.lower_bound(make_pair(x+1,x+1));\r\n    auto it = prev(nit);\r\n  \
    \  auto [l, r] = *it;\r\n    auto [nl, nr] = *nit;\r\n    if(l<=x && x<=r) return\
    \ false;\r\n    if(r == x-1){\r\n      if(x+1 == nl){\r\n        st.erase(it);\r\
    \n        st.erase(nit);\r\n        st.emplace(l,nr);\r\n      }else{\r\n    \
    \    st.erase(it);\r\n        st.emplace(l,x);\r\n      }\r\n    }else{\r\n  \
    \    if(x+1 == nl){\r\n        st.erase(nit);\r\n        st.emplace(x,nr);\r\n\
    \      }else{\r\n        st.emplace(x,x);\r\n      }\r\n    }\r\n    return true;\r\
    \n  }\r\n\r\n  bool insert(T l, T r){\r\n    auto it = prev(st.lower_bound(make_pair(l+1,\
    \ l+1)));\r\n    auto [nl, nr] = *it;\r\n    if(r <= nr) return false;\r\n   \
    \ if(nl <= l && l <= nr+1) l = nl;\r\n    else it++;\r\n    while(it->second <=\
    \ r) it = st.erase(it);\r\n    if(it->first <= r+1){ r = it->second; st.erase(it);\
    \ }\r\n    st.emplace(l, r);\r\n    return true;\r\n  }\r\n\r\n  bool erase(T\
    \ x){\r\n    auto it = prev(st.lower_bound(make_pair(x+1, x+1)));\r\n    auto\
    \ [l, r] = *it;\r\n    if(r < x) return false;\r\n    st.erase(it);\r\n    if(l\
    \ != r){\r\n      if(l == x) st.emplace(l+1, r);\r\n      else if(r == x) st.emplace(l,\
    \ r-1);\r\n      else st.emplace(l, x-1), st.emplace(x+1, r); \r\n    }\r\n  \
    \  return true;\r\n  }\r\n\r\n  bool erase(T l, T r){\r\n    auto it = prev(st.lower_bound(make_pair(l+1,\
    \ l+1)));\r\n    auto [nl, nr] = *it;\r\n    // ToDo\r\n    return true;\r\n \
    \ }\r\n\r\n  int mex(int x=0) const {\r\n    auto [l, r] = *prev(st.lower_bound(make_pair(x+1,\
    \ x+1)));\r\n    if(l<=x && x<=r) return r+1;\r\n    return x;\r\n  }\r\n\r\n\
    \  int cnt() const {\r\n    return (int)st.size() - 2;\r\n  }\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: other/RangeSet.cpp
  requiredBy: []
  timestamp: '2023-02-10 14:54:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: other/RangeSet.cpp
layout: document
redirect_from:
- /library/other/RangeSet.cpp
- /library/other/RangeSet.cpp.html
title: other/RangeSet.cpp
---
