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
  bundledCode: "#line 2 \"container/Vpress.cpp\"\n\r\ntemplate <typename T>\r\nvector<T>\
    \ Vpress(vector<T> &x) {\r\n    vector<T> vs = x;\r\n    sort(begin(vs), end(vs));\r\
    \n    vs.erase(unique(begin(vs), end(vs)), end(vs));\r\n    for(auto&e : x) e\
    \ = lower_bound(begin(vs), end(vs), e) - begin(vs);\r\n    return vs;\r\n}\r\n\
    \r\ntemplate <typename T>\r\nvector<T> Vpress(vector<T> &C1, vector<T> &C2, T\
    \ sp = 1) {\r\n    vector<T> vals;\r\n    for(size_t i = 0; i < C1.size(); i++){\r\
    \n        for (T d = 0; d < sp; d++) {  \r\n            T tc1 = C1[i] + d;\r\n\
    \            T tc2 = C2[i] + d;\r\n            vals.push_back(tc1);\r\n      \
    \      vals.push_back(tc2);\r\n        }\r\n    }\r\n    sort(vals.begin(), vals.end());\r\
    \n    vals.erase(unique(vals.begin(), vals.end()), vals.end());\r\n\r\n    for(size_t\
    \ i = 0; i < C1.size(); i++){\r\n        C1[i] = lower_bound(vals.begin(), vals.end(),\
    \ C1[i]) - vals.begin();\r\n        C2[i] = lower_bound(vals.begin(), vals.end(),\
    \ C2[i]) - vals.begin();\r\n    }\r\n    return vals;\r\n}\r\n"
  code: "#pragma once\r\n\r\ntemplate <typename T>\r\nvector<T> Vpress(vector<T> &x)\
    \ {\r\n    vector<T> vs = x;\r\n    sort(begin(vs), end(vs));\r\n    vs.erase(unique(begin(vs),\
    \ end(vs)), end(vs));\r\n    for(auto&e : x) e = lower_bound(begin(vs), end(vs),\
    \ e) - begin(vs);\r\n    return vs;\r\n}\r\n\r\ntemplate <typename T>\r\nvector<T>\
    \ Vpress(vector<T> &C1, vector<T> &C2, T sp = 1) {\r\n    vector<T> vals;\r\n\
    \    for(size_t i = 0; i < C1.size(); i++){\r\n        for (T d = 0; d < sp; d++)\
    \ {  \r\n            T tc1 = C1[i] + d;\r\n            T tc2 = C2[i] + d;\r\n\
    \            vals.push_back(tc1);\r\n            vals.push_back(tc2);\r\n    \
    \    }\r\n    }\r\n    sort(vals.begin(), vals.end());\r\n    vals.erase(unique(vals.begin(),\
    \ vals.end()), vals.end());\r\n\r\n    for(size_t i = 0; i < C1.size(); i++){\r\
    \n        C1[i] = lower_bound(vals.begin(), vals.end(), C1[i]) - vals.begin();\r\
    \n        C2[i] = lower_bound(vals.begin(), vals.end(), C2[i]) - vals.begin();\r\
    \n    }\r\n    return vals;\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: container/Vpress.cpp
  requiredBy: []
  timestamp: '2023-02-10 14:54:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: container/Vpress.cpp
layout: document
redirect_from:
- /library/container/Vpress.cpp
- /library/container/Vpress.cpp.html
title: container/Vpress.cpp
---
