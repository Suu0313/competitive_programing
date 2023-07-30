---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: string/LongestCommonPrefixArray.cpp
    title: string/LongestCommonPrefixArray.cpp
  - icon: ':warning:'
    path: string/longest_common_substr_lcp.cpp
    title: string/longest_common_substr_lcp.cpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"string/SuffixArray.cpp\"\n\r\ntemplate<typename Container>\r\
    \nstruct SuffixArray{\r\n  vector<int> sa;\r\n  const Container s;\r\n\r\n  SuffixArray(const\
    \ Container &s): sa(s.size()), s(s) {\r\n    int n = s.size();\r\n    if(n <=\
    \ 1) return;\r\n    if(n == 2){\r\n      if(s[0] < s[1]) sa[1] = 1;\r\n      else\
    \ sa[0] = 1;\r\n      return;\r\n    }\r\n    if(n < 10){ sa_native(); return;\
    \ }\r\n    if(n < 40){ sa_doubling(); return; }\r\n    sa_is(s);\r\n  }\r\n\r\n\
    \  // kth suffix = s[sa[k] : end]\r\n  int operator[](int k) const { return sa[k];\
    \ }\r\n  size_t size() const { return s.size(); }\r\n\r\n  int cmp_substr(const\
    \ Container &t, int ps = 0, int pt = 0) const {\r\n    int n = s.size(), m = t.size();\r\
    \n    for(; ps < n && pt < m; ps++, pt++){\r\n      if(s[ps] < t[pt]) return -1;\r\
    \n      if(s[ps] > t[pt]) return 1;\r\n    }\r\n    return pt < m ? -1 : 0;\r\n\
    \  }\r\n\r\n  int lower_bound(const Container &t) const {\r\n    int low = -1,\
    \ high = s.size();\r\n    while(high-low > 1){\r\n      int mid = (low + high)\
    \ >> 1;\r\n      (cmp_substr(t, sa[mid])<0 ? low : high) = mid;\r\n    }\r\n \
    \   return high;\r\n  }\r\n\r\n  int upper_bound(const Container &t) const {\r\
    \n    int low = -1, high = s.size();\r\n    while(high-low > 1){\r\n      int\
    \ mid = (low + high) >> 1;\r\n      (cmp_substr(t, sa[mid])<=0 ? low : high) =\
    \ mid;\r\n    }\r\n    return high;\r\n  }\r\n\r\n  bool contain(const Container\
    \ &t) const {\r\n    int idx = lower_bound(t);\r\n    return cmp_substr(t, sa[idx])\
    \ == 0;\r\n  }\r\n\r\n  pair<int, int> equal_range(const Container &t) const {\r\
    \n    return {lower_bound(t), upper_bound(t)};\r\n  }\r\n\r\n  void dump() const\
    \ {\r\n    int n = s.size();\r\n    for(int i = 0; i < n; i++){\r\n      cout\
    \ << i << \": \" << sa[i] << \" [ \";\r\n      for(int j = sa[i]; j < n; j++)\
    \ cout << s[j] << \" \";\r\n      cout << \" ]\\n\";\r\n    }\r\n  }\r\n\r\nprivate:\r\
    \n  void sa_native(){\r\n    int n = s.size();\r\n    iota(sa.begin(), sa.end(),\
    \ 0);\r\n    sort(sa.begin(), sa.end(), [&](int i, int j){\r\n      if(i == j)\
    \ return false;\r\n      for(;i < n && j < n; i++, j++) if(s[i] != s[j]) return\
    \ s[i] < s[j];\r\n      return i == n;\r\n    });\r\n  }\r\n\r\n  void sa_doubling(){\r\
    \n    iota(sa.begin(), sa.end(), 0);\r\n    int n = s.size();\r\n    vector<int>\
    \ rank(n), tmp(n);\r\n    for(int i = 0; i < n; i++) rank[i] = s[i];\r\n    auto\
    \ m = *min_element(rank.begin(), rank.end());\r\n\r\n    int k = 1;\r\n    auto\
    \ cmp = [&](int i, int j){\r\n      if(rank[i] != rank[j]) return rank[i] < rank[j];\r\
    \n      return ((i+k < n) ? rank[i+k] : m-1) < ((j+k < n) ? rank[j+k] : m-1);\r\
    \n    };\r\n\r\n    for(; k < n; k <<= 1){\r\n      sort(sa.begin(), sa.end(),\
    \ cmp);\r\n      tmp[sa[0]] = 0;\r\n      for(int i = 0; i < n-1; i++) tmp[sa[i+1]]\
    \ = tmp[sa[i]] + cmp(sa[i], sa[i+1]);\r\n      for(int i = 0; i < n; i++) rank[i]\
    \ = tmp[i];\r\n    }\r\n  }\r\n\r\n  void sa_is(const string &s){\r\n    int n\
    \ = s.size();\r\n    vector<int> v(s.begin(), s.end());\r\n    auto res = sa_is_sub(v,\
    \ 256);\r\n    for(int i = 0; i < n; i++) sa[i] = res[i+1];\r\n  }\r\n\r\n  template<typename\
    \ T>\r\n  void sa_is(const T &s){\r\n    int n = s.size();\r\n\r\n    auto&&[l,r]\
    \ = minmax_element(s.begin(), s.end());\r\n    auto lower = *l; auto upper = *r\
    \ + 1;\r\n    if(upper - lower < n * 20){\r\n      vector<int> v(n);\r\n     \
    \ for(int i = 0; i < n; i++) v[i] = s[i] - lower;\r\n\r\n      auto res = sa_is_sub(v,\
    \ upper - lower);\r\n      for(int i = 0; i < n; i++) sa[i] = res[i+1];\r\n  \
    \    return;\r\n    }\r\n    vector<int> idx(n); iota(idx.begin(), idx.end(),\
    \ 0);\r\n    sort(idx.begin(), idx.end(), [&](int i, int j){ return s[i] < s[j];\
    \ });\r\n    vector<int> rank(n);\r\n    for(int i = 1; i < n; i++) rank[idx[i]]\
    \ = rank[idx[i-1]] + (s[idx[i-1]] < s[idx[i]]);\r\n    auto res = sa_is_sub(rank,\
    \ rank[idx[n-1]] + 1);\r\n    for(int i = 0; i < n; i++) sa[i] = res[i+1];\r\n\
    \  }\r\n\r\n  vector<int> sa_is_sub(const vector<int> &v, int alpha){\r\n    int\
    \ n = v.size();\r\n    if(n == 1) return {0};\r\n    if(n == 2){ if(s[0] < s[1]){\
    \ return {0,1};} return {1,0}; }\r\n\r\n    vector<bool> ls(n + 1, false); ls[n]\
    \ = true;\r\n    for(int i = n-2; i >= 0; i--){\r\n      if(v[i] == v[i+1]) ls[i]\
    \ = ls[i+1];\r\n      else ls[i] = v[i] < v[i+1];\r\n    }\r\n\r\n    auto islms\
    \ = [&](int i){ return i>0 && (!ls[i-1] && ls[i]); };\r\n\r\n    auto chk = [&](int\
    \ i){ if(i >= n){ return 0; } return v[i] + 1; };\r\n\r\n    vector<int> nsa(n\
    \ + 1), lms, rev(n+1), sorted_lms;\r\n    for(int i = 0; i <= n; i++) if(islms(i))\
    \ lms.push_back(i);\r\n    int m = lms.size(); sorted_lms.reserve(m);\r\n    for(int\
    \ i = 0; i < m; i++) rev[lms[i]] = i;\r\n\r\n    auto induced_sort = [&](){\r\n\
    \      vector<int> bin(alpha + 2), cnt(alpha + 1);\r\n      for(int i = 0; i <=\
    \ n; i++) bin[chk(i)+1]++;\r\n      for(int i = 0; i <= alpha; i++) bin[i+1] +=\
    \ bin[i];\r\n\r\n      for(int i = m-1; i >= 0; i--){\r\n        int j = chk(lms[i]);\
    \ nsa[bin[j+1] - (++cnt[j])] = lms[i];\r\n      }\r\n\r\n      fill(cnt.begin(),\
    \ cnt.end(), 0);\r\n      for(auto&&i : nsa) if(i > 0 && !ls[i-1]) nsa[bin[chk(i-1)]\
    \ + (cnt[chk(i-1)]++)] = i - 1;\r\n      \r\n      fill(cnt.begin(), cnt.end(),\
    \ 0);\r\n      for(int i = n; i >= 0; i--) if(nsa[i] > 0 && ls[nsa[i]-1]) {\r\n\
    \        int j = chk(nsa[i] - 1); nsa[bin[j+1] - (++cnt[j])] = nsa[i] - 1;\r\n\
    \      }\r\n    };\r\n\r\n    induced_sort();\r\n    for(int i = 0; i <= n; i++)\
    \ if(islms(nsa[i])) sorted_lms.push_back(nsa[i]);\r\n\r\n    vector<int> rank(m);\
    \ int rmax = 0;\r\n\r\n    for(int i = 0; i < m-1; i++){\r\n      int l = sorted_lms[i],\
    \ r = sorted_lms[i+1];\r\n      auto cmp = [&](){\r\n        for(int pl=l, pr=r;\
    \ pl<=n && pr<=n; pl++, pr++){\r\n          if(chk(pl) != chk(pr)) return true;\r\
    \n          if(pl == l) continue;\r\n          if(islms(pr)) return false;\r\n\
    \          if(islms(pl) && !islms(pl)) return true;\r\n        }\r\n        assert(false);\
    \ return true;\r\n      };\r\n      rmax += cmp(); rank[rev[r]] = rmax;\r\n  \
    \  }\r\n\r\n    if(rmax+1 == (int)rank.size()){\r\n      vector<int> tmp(m); swap(tmp,\
    \ lms);\r\n      for(int i = 0; i < m; i++) lms[rank[i]] = tmp[i];\r\n    }else{\r\
    \n      auto rec_sa = sa_is_sub(rank, rmax+1);\r\n      vector<int> tmp(m); swap(tmp,\
    \ lms);\r\n      for(int i = 0; i < m; i++) lms[i] = tmp[rec_sa[i+1]];\r\n   \
    \ }\r\n\r\n    fill(nsa.begin(), nsa.end(), 0);\r\n    induced_sort();\r\n   \
    \ return nsa;\r\n  }\r\n};\r\n"
  code: "#pragma once\r\n\r\ntemplate<typename Container>\r\nstruct SuffixArray{\r\
    \n  vector<int> sa;\r\n  const Container s;\r\n\r\n  SuffixArray(const Container\
    \ &s): sa(s.size()), s(s) {\r\n    int n = s.size();\r\n    if(n <= 1) return;\r\
    \n    if(n == 2){\r\n      if(s[0] < s[1]) sa[1] = 1;\r\n      else sa[0] = 1;\r\
    \n      return;\r\n    }\r\n    if(n < 10){ sa_native(); return; }\r\n    if(n\
    \ < 40){ sa_doubling(); return; }\r\n    sa_is(s);\r\n  }\r\n\r\n  // kth suffix\
    \ = s[sa[k] : end]\r\n  int operator[](int k) const { return sa[k]; }\r\n  size_t\
    \ size() const { return s.size(); }\r\n\r\n  int cmp_substr(const Container &t,\
    \ int ps = 0, int pt = 0) const {\r\n    int n = s.size(), m = t.size();\r\n \
    \   for(; ps < n && pt < m; ps++, pt++){\r\n      if(s[ps] < t[pt]) return -1;\r\
    \n      if(s[ps] > t[pt]) return 1;\r\n    }\r\n    return pt < m ? -1 : 0;\r\n\
    \  }\r\n\r\n  int lower_bound(const Container &t) const {\r\n    int low = -1,\
    \ high = s.size();\r\n    while(high-low > 1){\r\n      int mid = (low + high)\
    \ >> 1;\r\n      (cmp_substr(t, sa[mid])<0 ? low : high) = mid;\r\n    }\r\n \
    \   return high;\r\n  }\r\n\r\n  int upper_bound(const Container &t) const {\r\
    \n    int low = -1, high = s.size();\r\n    while(high-low > 1){\r\n      int\
    \ mid = (low + high) >> 1;\r\n      (cmp_substr(t, sa[mid])<=0 ? low : high) =\
    \ mid;\r\n    }\r\n    return high;\r\n  }\r\n\r\n  bool contain(const Container\
    \ &t) const {\r\n    int idx = lower_bound(t);\r\n    return cmp_substr(t, sa[idx])\
    \ == 0;\r\n  }\r\n\r\n  pair<int, int> equal_range(const Container &t) const {\r\
    \n    return {lower_bound(t), upper_bound(t)};\r\n  }\r\n\r\n  void dump() const\
    \ {\r\n    int n = s.size();\r\n    for(int i = 0; i < n; i++){\r\n      cout\
    \ << i << \": \" << sa[i] << \" [ \";\r\n      for(int j = sa[i]; j < n; j++)\
    \ cout << s[j] << \" \";\r\n      cout << \" ]\\n\";\r\n    }\r\n  }\r\n\r\nprivate:\r\
    \n  void sa_native(){\r\n    int n = s.size();\r\n    iota(sa.begin(), sa.end(),\
    \ 0);\r\n    sort(sa.begin(), sa.end(), [&](int i, int j){\r\n      if(i == j)\
    \ return false;\r\n      for(;i < n && j < n; i++, j++) if(s[i] != s[j]) return\
    \ s[i] < s[j];\r\n      return i == n;\r\n    });\r\n  }\r\n\r\n  void sa_doubling(){\r\
    \n    iota(sa.begin(), sa.end(), 0);\r\n    int n = s.size();\r\n    vector<int>\
    \ rank(n), tmp(n);\r\n    for(int i = 0; i < n; i++) rank[i] = s[i];\r\n    auto\
    \ m = *min_element(rank.begin(), rank.end());\r\n\r\n    int k = 1;\r\n    auto\
    \ cmp = [&](int i, int j){\r\n      if(rank[i] != rank[j]) return rank[i] < rank[j];\r\
    \n      return ((i+k < n) ? rank[i+k] : m-1) < ((j+k < n) ? rank[j+k] : m-1);\r\
    \n    };\r\n\r\n    for(; k < n; k <<= 1){\r\n      sort(sa.begin(), sa.end(),\
    \ cmp);\r\n      tmp[sa[0]] = 0;\r\n      for(int i = 0; i < n-1; i++) tmp[sa[i+1]]\
    \ = tmp[sa[i]] + cmp(sa[i], sa[i+1]);\r\n      for(int i = 0; i < n; i++) rank[i]\
    \ = tmp[i];\r\n    }\r\n  }\r\n\r\n  void sa_is(const string &s){\r\n    int n\
    \ = s.size();\r\n    vector<int> v(s.begin(), s.end());\r\n    auto res = sa_is_sub(v,\
    \ 256);\r\n    for(int i = 0; i < n; i++) sa[i] = res[i+1];\r\n  }\r\n\r\n  template<typename\
    \ T>\r\n  void sa_is(const T &s){\r\n    int n = s.size();\r\n\r\n    auto&&[l,r]\
    \ = minmax_element(s.begin(), s.end());\r\n    auto lower = *l; auto upper = *r\
    \ + 1;\r\n    if(upper - lower < n * 20){\r\n      vector<int> v(n);\r\n     \
    \ for(int i = 0; i < n; i++) v[i] = s[i] - lower;\r\n\r\n      auto res = sa_is_sub(v,\
    \ upper - lower);\r\n      for(int i = 0; i < n; i++) sa[i] = res[i+1];\r\n  \
    \    return;\r\n    }\r\n    vector<int> idx(n); iota(idx.begin(), idx.end(),\
    \ 0);\r\n    sort(idx.begin(), idx.end(), [&](int i, int j){ return s[i] < s[j];\
    \ });\r\n    vector<int> rank(n);\r\n    for(int i = 1; i < n; i++) rank[idx[i]]\
    \ = rank[idx[i-1]] + (s[idx[i-1]] < s[idx[i]]);\r\n    auto res = sa_is_sub(rank,\
    \ rank[idx[n-1]] + 1);\r\n    for(int i = 0; i < n; i++) sa[i] = res[i+1];\r\n\
    \  }\r\n\r\n  vector<int> sa_is_sub(const vector<int> &v, int alpha){\r\n    int\
    \ n = v.size();\r\n    if(n == 1) return {0};\r\n    if(n == 2){ if(s[0] < s[1]){\
    \ return {0,1};} return {1,0}; }\r\n\r\n    vector<bool> ls(n + 1, false); ls[n]\
    \ = true;\r\n    for(int i = n-2; i >= 0; i--){\r\n      if(v[i] == v[i+1]) ls[i]\
    \ = ls[i+1];\r\n      else ls[i] = v[i] < v[i+1];\r\n    }\r\n\r\n    auto islms\
    \ = [&](int i){ return i>0 && (!ls[i-1] && ls[i]); };\r\n\r\n    auto chk = [&](int\
    \ i){ if(i >= n){ return 0; } return v[i] + 1; };\r\n\r\n    vector<int> nsa(n\
    \ + 1), lms, rev(n+1), sorted_lms;\r\n    for(int i = 0; i <= n; i++) if(islms(i))\
    \ lms.push_back(i);\r\n    int m = lms.size(); sorted_lms.reserve(m);\r\n    for(int\
    \ i = 0; i < m; i++) rev[lms[i]] = i;\r\n\r\n    auto induced_sort = [&](){\r\n\
    \      vector<int> bin(alpha + 2), cnt(alpha + 1);\r\n      for(int i = 0; i <=\
    \ n; i++) bin[chk(i)+1]++;\r\n      for(int i = 0; i <= alpha; i++) bin[i+1] +=\
    \ bin[i];\r\n\r\n      for(int i = m-1; i >= 0; i--){\r\n        int j = chk(lms[i]);\
    \ nsa[bin[j+1] - (++cnt[j])] = lms[i];\r\n      }\r\n\r\n      fill(cnt.begin(),\
    \ cnt.end(), 0);\r\n      for(auto&&i : nsa) if(i > 0 && !ls[i-1]) nsa[bin[chk(i-1)]\
    \ + (cnt[chk(i-1)]++)] = i - 1;\r\n      \r\n      fill(cnt.begin(), cnt.end(),\
    \ 0);\r\n      for(int i = n; i >= 0; i--) if(nsa[i] > 0 && ls[nsa[i]-1]) {\r\n\
    \        int j = chk(nsa[i] - 1); nsa[bin[j+1] - (++cnt[j])] = nsa[i] - 1;\r\n\
    \      }\r\n    };\r\n\r\n    induced_sort();\r\n    for(int i = 0; i <= n; i++)\
    \ if(islms(nsa[i])) sorted_lms.push_back(nsa[i]);\r\n\r\n    vector<int> rank(m);\
    \ int rmax = 0;\r\n\r\n    for(int i = 0; i < m-1; i++){\r\n      int l = sorted_lms[i],\
    \ r = sorted_lms[i+1];\r\n      auto cmp = [&](){\r\n        for(int pl=l, pr=r;\
    \ pl<=n && pr<=n; pl++, pr++){\r\n          if(chk(pl) != chk(pr)) return true;\r\
    \n          if(pl == l) continue;\r\n          if(islms(pr)) return false;\r\n\
    \          if(islms(pl) && !islms(pl)) return true;\r\n        }\r\n        assert(false);\
    \ return true;\r\n      };\r\n      rmax += cmp(); rank[rev[r]] = rmax;\r\n  \
    \  }\r\n\r\n    if(rmax+1 == (int)rank.size()){\r\n      vector<int> tmp(m); swap(tmp,\
    \ lms);\r\n      for(int i = 0; i < m; i++) lms[rank[i]] = tmp[i];\r\n    }else{\r\
    \n      auto rec_sa = sa_is_sub(rank, rmax+1);\r\n      vector<int> tmp(m); swap(tmp,\
    \ lms);\r\n      for(int i = 0; i < m; i++) lms[i] = tmp[rec_sa[i+1]];\r\n   \
    \ }\r\n\r\n    fill(nsa.begin(), nsa.end(), 0);\r\n    induced_sort();\r\n   \
    \ return nsa;\r\n  }\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: string/SuffixArray.cpp
  requiredBy:
  - string/LongestCommonPrefixArray.cpp
  - string/longest_common_substr_lcp.cpp
  timestamp: '2023-02-10 14:54:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: string/SuffixArray.cpp
layout: document
redirect_from:
- /library/string/SuffixArray.cpp
- /library/string/SuffixArray.cpp.html
title: string/SuffixArray.cpp
---
