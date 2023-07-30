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
  bundledCode: "#line 2 \"datastructure/CumulativeSum.cpp\"\n\ntemplate<typename T>\n\
    struct CumulativeSum{\n  int n, m;\n  bool is_built;\n  vector<vector<T>> sum;\n\
    \  CumulativeSum(int n, int m) : n(n), m(m), is_built(false), sum(n+1, vector<T>(m+1))\
    \ {}\n  CumulativeSum(const vector<vector<T>> &v, bool isbuilt = false){\n   \
    \ is_built = isbuilt;\n    if(!isbuilt){\n      n = v.size(); m = v.at(0).size();\n\
    \      sum.assign(n+1, vector<T>(m+1, 0));\n      for(int i=0; i<n; i++){\n  \
    \      for(int j=0; j<m; j++){\n          sum.at(i+1).at(j+1) = v.at(i).at(j);\n\
    \        }\n      }\n    }else{\n      n = v.size()-1; m = v.at(0).size()-1;\n\
    \      sum = v;\n    }\n  }\n  vector<T> &operator[](int k) { return sum.at(k);\
    \ }\n  const vector<T> &operator[](int k) const { return sum.at(k); }\n  vector<T>\
    \ &at(int k) { return sum.at(k); }\n  const vector<T> &at(int k) const { return\
    \ sum.at(k); }\n\n  void build(){\n    is_built = true;\n    for(int i=0; i<n;\
    \ i++){\n      for(int j=0; j<m; j++){\n        sum.at(i+1).at(j+1) += sum.at(i+1).at(j);\n\
    \      }\n    }\n    for(int j=0; j<m; j++){\n      for(int i=0; i<n; i++){\n\
    \        sum.at(i+1).at(j+1) += sum.at(i).at(j+1);\n      }\n    }\n  }\n  T query(int\
    \ x1, int x2, int y1, int y2){\n    if(!is_built) build();\n    return sum.at(x2).at(y2)-sum.at(x1).at(y2)-sum.at(x2).at(y1)+sum.at(x1).at(y1);\n\
    \  }\n};\n"
  code: "#pragma once\n\ntemplate<typename T>\nstruct CumulativeSum{\n  int n, m;\n\
    \  bool is_built;\n  vector<vector<T>> sum;\n  CumulativeSum(int n, int m) : n(n),\
    \ m(m), is_built(false), sum(n+1, vector<T>(m+1)) {}\n  CumulativeSum(const vector<vector<T>>\
    \ &v, bool isbuilt = false){\n    is_built = isbuilt;\n    if(!isbuilt){\n   \
    \   n = v.size(); m = v.at(0).size();\n      sum.assign(n+1, vector<T>(m+1, 0));\n\
    \      for(int i=0; i<n; i++){\n        for(int j=0; j<m; j++){\n          sum.at(i+1).at(j+1)\
    \ = v.at(i).at(j);\n        }\n      }\n    }else{\n      n = v.size()-1; m =\
    \ v.at(0).size()-1;\n      sum = v;\n    }\n  }\n  vector<T> &operator[](int k)\
    \ { return sum.at(k); }\n  const vector<T> &operator[](int k) const { return sum.at(k);\
    \ }\n  vector<T> &at(int k) { return sum.at(k); }\n  const vector<T> &at(int k)\
    \ const { return sum.at(k); }\n\n  void build(){\n    is_built = true;\n    for(int\
    \ i=0; i<n; i++){\n      for(int j=0; j<m; j++){\n        sum.at(i+1).at(j+1)\
    \ += sum.at(i+1).at(j);\n      }\n    }\n    for(int j=0; j<m; j++){\n      for(int\
    \ i=0; i<n; i++){\n        sum.at(i+1).at(j+1) += sum.at(i).at(j+1);\n      }\n\
    \    }\n  }\n  T query(int x1, int x2, int y1, int y2){\n    if(!is_built) build();\n\
    \    return sum.at(x2).at(y2)-sum.at(x1).at(y2)-sum.at(x2).at(y1)+sum.at(x1).at(y1);\n\
    \  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: datastructure/CumulativeSum.cpp
  requiredBy: []
  timestamp: '2023-02-10 14:54:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: datastructure/CumulativeSum.cpp
layout: document
redirect_from:
- /library/datastructure/CumulativeSum.cpp
- /library/datastructure/CumulativeSum.cpp.html
title: datastructure/CumulativeSum.cpp
---
