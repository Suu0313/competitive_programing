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
  bundledCode: "#line 1 \"unuse/switch_macro.cpp\"\n#define MATCH1(a) break; case\
    \ a:\r\n#define MATCH2(a, b) break; case a: case b:\r\n#define MATCH3(a, b, c)\
    \ break; case a: case b: case c:\r\n#define MATCH4(a, b, d) break; case a: case\
    \ b: case c: case d:\r\n#define MATCH(...) OVERLOAD4(__VA_ARGS__, MATCH4, MATCH3,\
    \ MATCH2, MATCH1)(__VA_ARGS__)\r\n#define OW break; default:\r\n\r\n/*\r\nswitch(x){\r\
    \n  MATCH(0){\r\n    COUT(0);\r\n\r\n  }MATCH(1, 2){\r\n    COUT(1);\r\n\r\n \
    \ }OW{\r\n    COUT(2);\r\n\r\n  }\r\n}\r\n//*/\n"
  code: "#define MATCH1(a) break; case a:\r\n#define MATCH2(a, b) break; case a: case\
    \ b:\r\n#define MATCH3(a, b, c) break; case a: case b: case c:\r\n#define MATCH4(a,\
    \ b, d) break; case a: case b: case c: case d:\r\n#define MATCH(...) OVERLOAD4(__VA_ARGS__,\
    \ MATCH4, MATCH3, MATCH2, MATCH1)(__VA_ARGS__)\r\n#define OW break; default:\r\
    \n\r\n/*\r\nswitch(x){\r\n  MATCH(0){\r\n    COUT(0);\r\n\r\n  }MATCH(1, 2){\r\
    \n    COUT(1);\r\n\r\n  }OW{\r\n    COUT(2);\r\n\r\n  }\r\n}\r\n//*/"
  dependsOn: []
  isVerificationFile: false
  path: unuse/switch_macro.cpp
  requiredBy: []
  timestamp: '2022-12-10 03:54:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: unuse/switch_macro.cpp
layout: document
redirect_from:
- /library/unuse/switch_macro.cpp
- /library/unuse/switch_macro.cpp.html
title: unuse/switch_macro.cpp
---
