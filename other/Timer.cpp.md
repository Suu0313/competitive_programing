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
  bundledCode: "#line 2 \"other/Timer.cpp\"\n\r\nstruct Timer {\r\n  chrono::high_resolution_clock::time_point\
    \ st;\r\n\r\n  Timer() { reset(); }\r\n\r\n  void reset() {\r\n    st = chrono::high_resolution_clock::now();\r\
    \n  }\r\n\r\n  chrono::milliseconds::rep elapsed() {\r\n    auto ed = chrono::high_resolution_clock::now();\r\
    \n    return chrono::duration_cast< chrono::milliseconds >(ed - st).count();\r\
    \n  }\r\n};\n"
  code: "#pragma once\r\n\r\nstruct Timer {\r\n  chrono::high_resolution_clock::time_point\
    \ st;\r\n\r\n  Timer() { reset(); }\r\n\r\n  void reset() {\r\n    st = chrono::high_resolution_clock::now();\r\
    \n  }\r\n\r\n  chrono::milliseconds::rep elapsed() {\r\n    auto ed = chrono::high_resolution_clock::now();\r\
    \n    return chrono::duration_cast< chrono::milliseconds >(ed - st).count();\r\
    \n  }\r\n};"
  dependsOn: []
  isVerificationFile: false
  path: other/Timer.cpp
  requiredBy: []
  timestamp: '2023-02-10 14:54:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: other/Timer.cpp
layout: document
redirect_from:
- /library/other/Timer.cpp
- /library/other/Timer.cpp.html
title: other/Timer.cpp
---
