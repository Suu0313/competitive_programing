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
  bundledCode: "#line 2 \"datastructure/DequeAggregation.cpp\"\n\r\ntemplate<typename\
    \ Monoid>\r\nstruct DequeAggregation{\r\n  vector<pair<Monoid, Monoid>> st_l,\
    \ st_r;\r\n\r\n  DequeAggregation() = default;\r\n  template<typename Iiter>\r\
    \n  DequeAggregation(Iiter first, Iiter last){\r\n    for(; first != last; ++first)\
    \ push_back(*first);\r\n  }\r\n  template<class Container>\r\n  DequeAggregation(const\
    \ Container &c): DequeAggregation(begin(c), end(c)) {}\r\n\r\n  Monoid prod()\
    \ const { return top(st_l) + top(st_r); }\r\n  void push_back(const Monoid &x){\
    \ st_r.emplace_back(x, top(st_r) + x); }\r\n  void push_front(const Monoid &x){\
    \ st_l.emplace_back(x, x + top(st_l)); }\r\n\r\n  Monoid pop_back(){\r\n    assert(!empty());\r\
    \n    if(!st_r.empty()){\r\n      Monoid val = move(st_r.back().first);\r\n  \
    \    st_r.pop_back();\r\n      return val;\r\n    }\r\n    int sz = int(st_l.size()),\
    \ l = sz >> 1, r = sz - l;\r\n    for(int i = r - 1; i > 0; --i) push_back(move(st_l[i].first));\r\
    \n    Monoid val = move(st_l.front().first);\r\n    st_l.erase(begin(st_l), begin(st_l)\
    \ + r);\r\n    if(l == 0) return val;\r\n    st_l[0].second = st_l[0].first;\r\
    \n    for(int i = 1; i < l; ++i) st_l[i].second = st_l[i].first + st_l[i - 1].second;\r\
    \n    return val;\r\n  }\r\n\r\n  Monoid pop_front(){\r\n    assert(!empty());\r\
    \n    if(!st_l.empty()){\r\n      Monoid val = move(st_l.back().first);\r\n  \
    \    st_l.pop_back();\r\n      return val;\r\n    }\r\n    int sz = int(st_r.size()),\
    \ r = sz >> 1, l = sz - r;\r\n    for(int i = l - 1; i > 0; --i) push_front(move(st_r[i].first));\r\
    \n    Monoid val = move(st_r.front().first);\r\n    st_r.erase(begin(st_r), begin(st_r)\
    \ + l);\r\n    if(r == 0) return val;\r\n    st_r[0].second = st_r[0].first;\r\
    \n    for(int i = 1; i < r; ++i) st_r[i].second = st_r[i - 1].second + st_r[i].first;\r\
    \n    return val;\r\n  }\r\n\r\n  const Monoid &front() const { return st_l.empty()\
    \ ? st_r.front().first : st_l.back().first; }\r\n  const Monoid &back() const\
    \ { return st_r.empty() ? st_l.front().first : st_r.back().first; }\r\n  const\
    \ Monoid &operator[](int k) const {\r\n    if(k < 0) k += size();\r\n    assert(0\
    \ <= k && k < int(size()));\r\n    k -= st_l.size();\r\n    return (k < 0) ? st_l[~k].first\
    \ : st_r[k].first;\r\n  }\r\n  size_t size() const { return st_l.size() + st_r.size();\
    \ }\r\n  void clear(){ st_l.clear(); st_r.clear(); }\r\n  bool empty() const {\
    \ return st_l.empty() && st_r.empty(); }\r\n  operator bool() const { return !empty();\
    \ }\r\n\r\n  Monoid top(const vector<pair<Monoid, Monoid>> &v) const { return\
    \ v.empty() ? Monoid{} : v.back().second; }\r\n};\r\n"
  code: "#pragma once\r\n\r\ntemplate<typename Monoid>\r\nstruct DequeAggregation{\r\
    \n  vector<pair<Monoid, Monoid>> st_l, st_r;\r\n\r\n  DequeAggregation() = default;\r\
    \n  template<typename Iiter>\r\n  DequeAggregation(Iiter first, Iiter last){\r\
    \n    for(; first != last; ++first) push_back(*first);\r\n  }\r\n  template<class\
    \ Container>\r\n  DequeAggregation(const Container &c): DequeAggregation(begin(c),\
    \ end(c)) {}\r\n\r\n  Monoid prod() const { return top(st_l) + top(st_r); }\r\n\
    \  void push_back(const Monoid &x){ st_r.emplace_back(x, top(st_r) + x); }\r\n\
    \  void push_front(const Monoid &x){ st_l.emplace_back(x, x + top(st_l)); }\r\n\
    \r\n  Monoid pop_back(){\r\n    assert(!empty());\r\n    if(!st_r.empty()){\r\n\
    \      Monoid val = move(st_r.back().first);\r\n      st_r.pop_back();\r\n   \
    \   return val;\r\n    }\r\n    int sz = int(st_l.size()), l = sz >> 1, r = sz\
    \ - l;\r\n    for(int i = r - 1; i > 0; --i) push_back(move(st_l[i].first));\r\
    \n    Monoid val = move(st_l.front().first);\r\n    st_l.erase(begin(st_l), begin(st_l)\
    \ + r);\r\n    if(l == 0) return val;\r\n    st_l[0].second = st_l[0].first;\r\
    \n    for(int i = 1; i < l; ++i) st_l[i].second = st_l[i].first + st_l[i - 1].second;\r\
    \n    return val;\r\n  }\r\n\r\n  Monoid pop_front(){\r\n    assert(!empty());\r\
    \n    if(!st_l.empty()){\r\n      Monoid val = move(st_l.back().first);\r\n  \
    \    st_l.pop_back();\r\n      return val;\r\n    }\r\n    int sz = int(st_r.size()),\
    \ r = sz >> 1, l = sz - r;\r\n    for(int i = l - 1; i > 0; --i) push_front(move(st_r[i].first));\r\
    \n    Monoid val = move(st_r.front().first);\r\n    st_r.erase(begin(st_r), begin(st_r)\
    \ + l);\r\n    if(r == 0) return val;\r\n    st_r[0].second = st_r[0].first;\r\
    \n    for(int i = 1; i < r; ++i) st_r[i].second = st_r[i - 1].second + st_r[i].first;\r\
    \n    return val;\r\n  }\r\n\r\n  const Monoid &front() const { return st_l.empty()\
    \ ? st_r.front().first : st_l.back().first; }\r\n  const Monoid &back() const\
    \ { return st_r.empty() ? st_l.front().first : st_r.back().first; }\r\n  const\
    \ Monoid &operator[](int k) const {\r\n    if(k < 0) k += size();\r\n    assert(0\
    \ <= k && k < int(size()));\r\n    k -= st_l.size();\r\n    return (k < 0) ? st_l[~k].first\
    \ : st_r[k].first;\r\n  }\r\n  size_t size() const { return st_l.size() + st_r.size();\
    \ }\r\n  void clear(){ st_l.clear(); st_r.clear(); }\r\n  bool empty() const {\
    \ return st_l.empty() && st_r.empty(); }\r\n  operator bool() const { return !empty();\
    \ }\r\n\r\n  Monoid top(const vector<pair<Monoid, Monoid>> &v) const { return\
    \ v.empty() ? Monoid{} : v.back().second; }\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: datastructure/DequeAggregation.cpp
  requiredBy: []
  timestamp: '2023-02-10 14:54:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: datastructure/DequeAggregation.cpp
layout: document
redirect_from:
- /library/datastructure/DequeAggregation.cpp
- /library/datastructure/DequeAggregation.cpp.html
title: datastructure/DequeAggregation.cpp
---
