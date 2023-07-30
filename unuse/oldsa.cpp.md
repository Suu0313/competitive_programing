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
  bundledCode: "#line 1 \"unuse/oldsa.cpp\"\nstruct SuffixArray{ // O(Nlog^2N)\r\n\
    \  vector<int> sa;\r\n  const string s;\r\n\r\n  SuffixArray(const string &s):\
    \ sa(s.size()), s(s) {\r\n    iota(sa.begin(), sa.end(), 0);\r\n\r\n    int n\
    \ = s.size();\r\n    vector<int> rank(n), tmp(n);\r\n    for(int i = 0; i < n;\
    \ i++) rank[i] = s[i];\r\n\r\n    int k = 1;\r\n    auto cmp = [&](int i, int\
    \ j){\r\n      if(rank[i] != rank[j]) return rank[i] < rank[j];\r\n      int ni\
    \ = (i+k < n) ? rank[i+k] : -1;\r\n      int nj = (j+k < n) ? rank[j+k] : -1;\r\
    \n      return ni < nj;\r\n    };\r\n\r\n    for(; k < n; k <<= 1){\r\n      sort(sa.begin(),\
    \ sa.end(), cmp);\r\n      tmp[sa[0]] = 0;\r\n      for(int i = 0; i < n-1; i++)\
    \ tmp[sa[i+1]] = tmp[sa[i]] + cmp(sa[i], sa[i+1]);\r\n      for(int i = 0; i <\
    \ n; i++) rank[i] = tmp[i];\r\n    }\r\n  }\r\n\r\n  int operator[](int k) const\
    \ { return sa[k]; }\r\n  size_t size() const { return s.size(); }\r\n\r\n  int\
    \ cmp_substr(const string &t, int ps = 0, int pt = 0) const {\r\n    int n = s.size(),\
    \ m = t.size();\r\n    for(; ps < n && pt < m; ps++, pt++){\r\n      if(s[ps]\
    \ < t[pt]) return -1;\r\n      if(s[ps] > t[pt]) return 1;\r\n    }\r\n    return\
    \ pt < m ? -1 : 0;\r\n  }\r\n\r\n  int lower_bound(const string &t) const {\r\n\
    \    int low = -1, high = s.size();\r\n    while(high-low > 1){\r\n      int mid\
    \ = (low + high) >> 1;\r\n      (cmp_substr(t, sa[mid])<0 ? low : high) = mid;\r\
    \n    }\r\n    return high;\r\n  }\r\n\r\n  int upper_bound(const string &t) const\
    \ {\r\n    int low = -1, high = s.size();\r\n    while(high-low > 1){\r\n    \
    \  int mid = (low + high) >> 1;\r\n      (cmp_substr(t, sa[mid])<=0 ? low : high)\
    \ = mid;\r\n    }\r\n    return high;\r\n  }\r\n\r\n  bool contain(const string\
    \ &t) const {\r\n    int idx = lower_bound(t);\r\n    return cmp_substr(t, idx)\
    \ == 0;\r\n  }\r\n\r\n  pair<int, int> equal_range(const string &t) const {\r\n\
    \    return {lower_bound(t), upper_bound(t)};\r\n  }\r\n\r\n  void dump() const\
    \ {\r\n    int n = s.size();\r\n    for(int i = 0; i < n; i++){\r\n      cout\
    \ << i << \": \" << s.substr(sa[i]) << '\\n';\r\n    }\r\n  }\r\n};\r\n\r\n\r\n\
    struct SuffixArray{ // O(NlogN)\r\n  vector<int> sa;\r\n  const string s;\r\n\r\
    \n  SuffixArray(const string &s): sa(s.size()), s(s) {\r\n    iota(sa.begin(),\
    \ sa.end(), 0);\r\n    sort(sa.begin(), sa.end(), [&](int i, int j){ return s[i]\
    \ < s[j]; });\r\n\r\n    int n = s.size(), k = 0;\r\n    vector<int> rank(n),\
    \ tmp(n), nsa(n);\r\n\r\n    tmp[sa[0]] = 0;\r\n    for(int i = 0; i < n-1; i++)\
    \ tmp[sa[i+1]] = tmp[sa[i]] + (s[sa[i]] < s[sa[i+1]]);\r\n    swap(rank, tmp);\r\
    \n\r\n    auto nr = [&](int i){ return (i+k < n) ? rank[i+k] : -1; };\r\n\r\n\
    \    auto cmp = [&](int i, int j){\r\n      if(rank[i] != rank[j]) return rank[i]\
    \ < rank[j];\r\n      return nr(i) < nr(j);\r\n    };\r\n    \r\n    auto binsort2\
    \ = [&](){\r\n      vector<int> cnt(n+1);\r\n      for(int i = 0; i < n; i++)\
    \ cnt[nr(i)+1]++;\r\n      for(int i = 0; i < n; i++) cnt[i+1] += cnt[i];\r\n\
    \      for(int i = 0; i < n; i++) nsa[--cnt[nr(i)+1]] = i;\r\n    };\r\n\r\n \
    \   auto binsort = [&](){\r\n      binsort2();\r\n      vector<int> cnt(n);\r\n\
    \      for(int i = 0; i < n; i++) cnt[rank[i]]++;\r\n      for(int i = 0; i <\
    \ n-1; i++) cnt[i+1] += cnt[i];\r\n      for(int i = n-1; i >= 0; i--) sa[--cnt[rank[nsa[i]]]]\
    \ = nsa[i];\r\n    };\r\n\r\n    for(k = 1; k < n; k <<= 1){\r\n      binsort();\
    \ tmp[sa[0]] = 0;\r\n      for(int i = 0; i < n-1; i++) tmp[sa[i+1]] = tmp[sa[i]]\
    \ + cmp(sa[i], sa[i+1]);\r\n      swap(rank, tmp);\r\n    }\r\n  }\r\n\r\n  int\
    \ operator[](int k) const { return sa[k]; }\r\n  size_t size() const { return\
    \ s.size(); }\r\n\r\n  int cmp_substr(const string &t, int ps = 0) const {\r\n\
    \    auto ls = s.substr(ps, t.size());\r\n    return ls<t ? -1 : (ls==t ? 0 :\
    \ 1);\r\n  }\r\n\r\n  int lower_bound(const string &t) const {\r\n    int low\
    \ = -1, high = s.size();\r\n    while(high-low > 1){\r\n      int mid = (low +\
    \ high) >> 1;\r\n      (cmp_substr(t, sa[mid])<0 ? low : high) = mid;\r\n    }\r\
    \n    return high;\r\n  }\r\n\r\n  int upper_bound(const string &t) const {\r\n\
    \    int low = -1, high = s.size();\r\n    while(high-low > 1){\r\n      int mid\
    \ = (low + high) >> 1;\r\n      (cmp_substr(t, sa[mid])<=0 ? low : high) = mid;\r\
    \n    }\r\n    return high;\r\n  }\r\n\r\n  bool contain(const string &t) const\
    \ {\r\n    int idx = lower_bound(t);\r\n    return cmp_substr(t, idx) == 0;\r\n\
    \  }\r\n\r\n  pair<int, int> equal_range(const string &t) const {\r\n    return\
    \ {lower_bound(t), upper_bound(t)};\r\n  }\r\n\r\n  void dump() const {\r\n  \
    \  int n = s.size();\r\n    for(int i = 0; i < n; i++){\r\n      cout << i <<\
    \ \": \" << s.substr(sa[i]) << endl;\r\n    }\r\n  }\r\n};\r\n"
  code: "struct SuffixArray{ // O(Nlog^2N)\r\n  vector<int> sa;\r\n  const string\
    \ s;\r\n\r\n  SuffixArray(const string &s): sa(s.size()), s(s) {\r\n    iota(sa.begin(),\
    \ sa.end(), 0);\r\n\r\n    int n = s.size();\r\n    vector<int> rank(n), tmp(n);\r\
    \n    for(int i = 0; i < n; i++) rank[i] = s[i];\r\n\r\n    int k = 1;\r\n   \
    \ auto cmp = [&](int i, int j){\r\n      if(rank[i] != rank[j]) return rank[i]\
    \ < rank[j];\r\n      int ni = (i+k < n) ? rank[i+k] : -1;\r\n      int nj = (j+k\
    \ < n) ? rank[j+k] : -1;\r\n      return ni < nj;\r\n    };\r\n\r\n    for(; k\
    \ < n; k <<= 1){\r\n      sort(sa.begin(), sa.end(), cmp);\r\n      tmp[sa[0]]\
    \ = 0;\r\n      for(int i = 0; i < n-1; i++) tmp[sa[i+1]] = tmp[sa[i]] + cmp(sa[i],\
    \ sa[i+1]);\r\n      for(int i = 0; i < n; i++) rank[i] = tmp[i];\r\n    }\r\n\
    \  }\r\n\r\n  int operator[](int k) const { return sa[k]; }\r\n  size_t size()\
    \ const { return s.size(); }\r\n\r\n  int cmp_substr(const string &t, int ps =\
    \ 0, int pt = 0) const {\r\n    int n = s.size(), m = t.size();\r\n    for(; ps\
    \ < n && pt < m; ps++, pt++){\r\n      if(s[ps] < t[pt]) return -1;\r\n      if(s[ps]\
    \ > t[pt]) return 1;\r\n    }\r\n    return pt < m ? -1 : 0;\r\n  }\r\n\r\n  int\
    \ lower_bound(const string &t) const {\r\n    int low = -1, high = s.size();\r\
    \n    while(high-low > 1){\r\n      int mid = (low + high) >> 1;\r\n      (cmp_substr(t,\
    \ sa[mid])<0 ? low : high) = mid;\r\n    }\r\n    return high;\r\n  }\r\n\r\n\
    \  int upper_bound(const string &t) const {\r\n    int low = -1, high = s.size();\r\
    \n    while(high-low > 1){\r\n      int mid = (low + high) >> 1;\r\n      (cmp_substr(t,\
    \ sa[mid])<=0 ? low : high) = mid;\r\n    }\r\n    return high;\r\n  }\r\n\r\n\
    \  bool contain(const string &t) const {\r\n    int idx = lower_bound(t);\r\n\
    \    return cmp_substr(t, idx) == 0;\r\n  }\r\n\r\n  pair<int, int> equal_range(const\
    \ string &t) const {\r\n    return {lower_bound(t), upper_bound(t)};\r\n  }\r\n\
    \r\n  void dump() const {\r\n    int n = s.size();\r\n    for(int i = 0; i < n;\
    \ i++){\r\n      cout << i << \": \" << s.substr(sa[i]) << '\\n';\r\n    }\r\n\
    \  }\r\n};\r\n\r\n\r\nstruct SuffixArray{ // O(NlogN)\r\n  vector<int> sa;\r\n\
    \  const string s;\r\n\r\n  SuffixArray(const string &s): sa(s.size()), s(s) {\r\
    \n    iota(sa.begin(), sa.end(), 0);\r\n    sort(sa.begin(), sa.end(), [&](int\
    \ i, int j){ return s[i] < s[j]; });\r\n\r\n    int n = s.size(), k = 0;\r\n \
    \   vector<int> rank(n), tmp(n), nsa(n);\r\n\r\n    tmp[sa[0]] = 0;\r\n    for(int\
    \ i = 0; i < n-1; i++) tmp[sa[i+1]] = tmp[sa[i]] + (s[sa[i]] < s[sa[i+1]]);\r\n\
    \    swap(rank, tmp);\r\n\r\n    auto nr = [&](int i){ return (i+k < n) ? rank[i+k]\
    \ : -1; };\r\n\r\n    auto cmp = [&](int i, int j){\r\n      if(rank[i] != rank[j])\
    \ return rank[i] < rank[j];\r\n      return nr(i) < nr(j);\r\n    };\r\n    \r\
    \n    auto binsort2 = [&](){\r\n      vector<int> cnt(n+1);\r\n      for(int i\
    \ = 0; i < n; i++) cnt[nr(i)+1]++;\r\n      for(int i = 0; i < n; i++) cnt[i+1]\
    \ += cnt[i];\r\n      for(int i = 0; i < n; i++) nsa[--cnt[nr(i)+1]] = i;\r\n\
    \    };\r\n\r\n    auto binsort = [&](){\r\n      binsort2();\r\n      vector<int>\
    \ cnt(n);\r\n      for(int i = 0; i < n; i++) cnt[rank[i]]++;\r\n      for(int\
    \ i = 0; i < n-1; i++) cnt[i+1] += cnt[i];\r\n      for(int i = n-1; i >= 0; i--)\
    \ sa[--cnt[rank[nsa[i]]]] = nsa[i];\r\n    };\r\n\r\n    for(k = 1; k < n; k <<=\
    \ 1){\r\n      binsort(); tmp[sa[0]] = 0;\r\n      for(int i = 0; i < n-1; i++)\
    \ tmp[sa[i+1]] = tmp[sa[i]] + cmp(sa[i], sa[i+1]);\r\n      swap(rank, tmp);\r\
    \n    }\r\n  }\r\n\r\n  int operator[](int k) const { return sa[k]; }\r\n  size_t\
    \ size() const { return s.size(); }\r\n\r\n  int cmp_substr(const string &t, int\
    \ ps = 0) const {\r\n    auto ls = s.substr(ps, t.size());\r\n    return ls<t\
    \ ? -1 : (ls==t ? 0 : 1);\r\n  }\r\n\r\n  int lower_bound(const string &t) const\
    \ {\r\n    int low = -1, high = s.size();\r\n    while(high-low > 1){\r\n    \
    \  int mid = (low + high) >> 1;\r\n      (cmp_substr(t, sa[mid])<0 ? low : high)\
    \ = mid;\r\n    }\r\n    return high;\r\n  }\r\n\r\n  int upper_bound(const string\
    \ &t) const {\r\n    int low = -1, high = s.size();\r\n    while(high-low > 1){\r\
    \n      int mid = (low + high) >> 1;\r\n      (cmp_substr(t, sa[mid])<=0 ? low\
    \ : high) = mid;\r\n    }\r\n    return high;\r\n  }\r\n\r\n  bool contain(const\
    \ string &t) const {\r\n    int idx = lower_bound(t);\r\n    return cmp_substr(t,\
    \ idx) == 0;\r\n  }\r\n\r\n  pair<int, int> equal_range(const string &t) const\
    \ {\r\n    return {lower_bound(t), upper_bound(t)};\r\n  }\r\n\r\n  void dump()\
    \ const {\r\n    int n = s.size();\r\n    for(int i = 0; i < n; i++){\r\n    \
    \  cout << i << \": \" << s.substr(sa[i]) << endl;\r\n    }\r\n  }\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: unuse/oldsa.cpp
  requiredBy: []
  timestamp: '2021-05-11 10:10:42+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: unuse/oldsa.cpp
layout: document
redirect_from:
- /library/unuse/oldsa.cpp
- /library/unuse/oldsa.cpp.html
title: unuse/oldsa.cpp
---
