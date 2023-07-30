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
  bundledCode: "#line 2 \"other/sort/hilbert_sort.cpp\"\n\r\ntemplate<int pw>\r\n\
    constexpr uint64_t hilbert_length(int x, int y, int rot = 0){\r\n  if constexpr\
    \ (pw == 0) return 0;\r\n  else{\r\n    int mid = 1 << (pw - 1);\r\n    int seg\
    \ = (x < mid) ? ((y < mid) ? 0 : 3) : ((y < mid) ? 1 : 2);\r\n    seg = (seg +\
    \ rot) & 3;\r\n    constexpr int rotd[4] = {3, 0, 0, 1};\r\n    int nx = x & (x\
    \ ^ mid), ny = y & (y ^ mid);\r\n    int nrot = (rot + rotd[seg]) & 3;\r\n   \
    \ uint64_t sqsz = uint64_t(1) << (pw*2 - 2);\r\n    uint64_t ans = seg * sqsz,\
    \ rec = hilbert_length<pw - 1>(nx, ny, nrot);\r\n\r\n    return ans + ((seg ==\
    \ 1 || seg == 2) ? rec : (sqsz - rec - 1));\r\n  }\r\n}\r\n\r\nvector<int> hilbert_sort(const\
    \ vector<int> &l, const vector<int> &r){\r\n  int n = int(l.size());\r\n  vector<uint64_t>\
    \ len(n);\r\n  for(int i = 0; i < n; ++i) len[i] = hilbert_length<30>(l[i], r[i]);\r\
    \n  vector<int> idx(n); iota(begin(idx), end(idx), 0);\r\n  sort(begin(idx), end(idx),\
    \ [&](int i, int j){ return len[i] < len[j]; });\r\n  return idx;\r\n}\r\n"
  code: "#pragma once\r\n\r\ntemplate<int pw>\r\nconstexpr uint64_t hilbert_length(int\
    \ x, int y, int rot = 0){\r\n  if constexpr (pw == 0) return 0;\r\n  else{\r\n\
    \    int mid = 1 << (pw - 1);\r\n    int seg = (x < mid) ? ((y < mid) ? 0 : 3)\
    \ : ((y < mid) ? 1 : 2);\r\n    seg = (seg + rot) & 3;\r\n    constexpr int rotd[4]\
    \ = {3, 0, 0, 1};\r\n    int nx = x & (x ^ mid), ny = y & (y ^ mid);\r\n    int\
    \ nrot = (rot + rotd[seg]) & 3;\r\n    uint64_t sqsz = uint64_t(1) << (pw*2 -\
    \ 2);\r\n    uint64_t ans = seg * sqsz, rec = hilbert_length<pw - 1>(nx, ny, nrot);\r\
    \n\r\n    return ans + ((seg == 1 || seg == 2) ? rec : (sqsz - rec - 1));\r\n\
    \  }\r\n}\r\n\r\nvector<int> hilbert_sort(const vector<int> &l, const vector<int>\
    \ &r){\r\n  int n = int(l.size());\r\n  vector<uint64_t> len(n);\r\n  for(int\
    \ i = 0; i < n; ++i) len[i] = hilbert_length<30>(l[i], r[i]);\r\n  vector<int>\
    \ idx(n); iota(begin(idx), end(idx), 0);\r\n  sort(begin(idx), end(idx), [&](int\
    \ i, int j){ return len[i] < len[j]; });\r\n  return idx;\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: other/sort/hilbert_sort.cpp
  requiredBy: []
  timestamp: '2023-02-10 14:54:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: other/sort/hilbert_sort.cpp
layout: document
redirect_from:
- /library/other/sort/hilbert_sort.cpp
- /library/other/sort/hilbert_sort.cpp.html
title: other/sort/hilbert_sort.cpp
---
