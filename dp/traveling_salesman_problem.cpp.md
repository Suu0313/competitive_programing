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
  bundledCode: "#line 2 \"dp/traveling_salesman_problem.cpp\"\n\ntemplate <typename\
    \ T>\nT traveling_salesman_problem(const vector<vector<T>> &dist, int s = -1,\
    \ int t = -1, const T &inf = numeric_limits<T>::max()){\n  const int n = dist.size();\n\
    \  vector dp(1<<n, vector(n, inf));\n\n  if(t == -1){\n    if(s >= 0) dp.at(1<<s).at(s)\
    \ = 0;\n    else for(int i=0; i < n; i++) dp.at(1<<i).at(i) = 0;\n  }else{\n \
    \   if(s == t) dp.at(0).at(s) = 0;\n    else if(s >= 0) dp.at(1<<s).at(s) = 0;\n\
    \    else for(int i=0; i < n; i++) dp.at(0).at(i) = 0;\n  }\n\n  for(int bit =\
    \ 0; bit < (1<<n); bit++)\n    for(int i=0; i < n; i++) for(int j=0; j < n; j++)\n\
    \      if((i != j)&&(~bit >> j & 1)&&(dp.at(bit).at(i) != inf))\n        dp.at(bit|(1<<j)).at(j)\n\
    \          = min(dp.at(bit|(1<<j)).at(j), dp.at(bit).at(i) + dist.at(i).at(j));\n\
    \  \n  if(t == -1){\n    return *min_element(begin(dp.at((1<<n)-1)), end(dp.at((1<<n)-1)));\n\
    \  }else{\n    return dp.at((1<<n)-1).at(t);\n  }\n}\n"
  code: "#pragma once\n\ntemplate <typename T>\nT traveling_salesman_problem(const\
    \ vector<vector<T>> &dist, int s = -1, int t = -1, const T &inf = numeric_limits<T>::max()){\n\
    \  const int n = dist.size();\n  vector dp(1<<n, vector(n, inf));\n\n  if(t ==\
    \ -1){\n    if(s >= 0) dp.at(1<<s).at(s) = 0;\n    else for(int i=0; i < n; i++)\
    \ dp.at(1<<i).at(i) = 0;\n  }else{\n    if(s == t) dp.at(0).at(s) = 0;\n    else\
    \ if(s >= 0) dp.at(1<<s).at(s) = 0;\n    else for(int i=0; i < n; i++) dp.at(0).at(i)\
    \ = 0;\n  }\n\n  for(int bit = 0; bit < (1<<n); bit++)\n    for(int i=0; i < n;\
    \ i++) for(int j=0; j < n; j++)\n      if((i != j)&&(~bit >> j & 1)&&(dp.at(bit).at(i)\
    \ != inf))\n        dp.at(bit|(1<<j)).at(j)\n          = min(dp.at(bit|(1<<j)).at(j),\
    \ dp.at(bit).at(i) + dist.at(i).at(j));\n  \n  if(t == -1){\n    return *min_element(begin(dp.at((1<<n)-1)),\
    \ end(dp.at((1<<n)-1)));\n  }else{\n    return dp.at((1<<n)-1).at(t);\n  }\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: dp/traveling_salesman_problem.cpp
  requiredBy: []
  timestamp: '2023-02-10 14:54:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: dp/traveling_salesman_problem.cpp
layout: document
redirect_from:
- /library/dp/traveling_salesman_problem.cpp
- /library/dp/traveling_salesman_problem.cpp.html
title: dp/traveling_salesman_problem.cpp
---
