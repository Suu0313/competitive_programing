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
  bundledCode: "#line 1 \"string/Parsing.cpp\"\nstruct Parsing{\r\n  using State =\
    \ string::const_iterator;\r\n\r\n  void consume(State &pos, char expected){\r\n\
    \    if(*pos == expected) ++pos;\r\n    else{\r\n      cerr << \"expected : '\"\
    \ << expected << \"'\\n\";\r\n      cerr << \"pos : '\" << *pos << \"'\\n\";\r\
    \n\r\n      assert(false);\r\n    }\r\n  }\r\n\r\n  int number(State &pos){\r\n\
    \    int res = 0;\r\n    for(; isdigit(*pos); ++pos){\r\n      res = res*10 +\
    \ *pos-'0';\r\n    }\r\n    return res;\r\n  }\r\n\r\n  int factor(State &pos){\r\
    \n    if(*pos == '('){\r\n      consume(pos, '(');\r\n      int res = expression(pos);\r\
    \n      consume(pos, ')');\r\n      return res;\r\n    }else{\r\n      return\
    \ number(pos);\r\n    }\r\n  }\r\n\r\n  int term(State &pos){\r\n    int res =\
    \ factor(pos);\r\n    while(true){\r\n      if(*pos == '*'){\r\n        consume(pos,\
    \ '*');\r\n        res *= factor(pos);\r\n      }else if(*pos == '/'){\r\n   \
    \     consume(pos, '/');\r\n        res /= factor(pos);\r\n      }else break;\r\
    \n    }\r\n    return res;\r\n  }\r\n\r\n  int expression(State &pos){\r\n   \
    \ int res = term(pos);\r\n    while(true){\r\n      if(*pos == '+'){\r\n     \
    \   consume(pos, '+');\r\n        res += term(pos);\r\n      }else if(*pos ==\
    \ '-'){\r\n        consume(pos, '-');\r\n        res -= term(pos);\r\n      }else\
    \ break;\r\n    }\r\n    return res;\r\n  }\r\n\r\n  int parse(const string &s){\r\
    \n    State pos = s.begin();\r\n    return expression(pos);\r\n  }\r\n};\r\n"
  code: "struct Parsing{\r\n  using State = string::const_iterator;\r\n\r\n  void\
    \ consume(State &pos, char expected){\r\n    if(*pos == expected) ++pos;\r\n \
    \   else{\r\n      cerr << \"expected : '\" << expected << \"'\\n\";\r\n     \
    \ cerr << \"pos : '\" << *pos << \"'\\n\";\r\n\r\n      assert(false);\r\n   \
    \ }\r\n  }\r\n\r\n  int number(State &pos){\r\n    int res = 0;\r\n    for(; isdigit(*pos);\
    \ ++pos){\r\n      res = res*10 + *pos-'0';\r\n    }\r\n    return res;\r\n  }\r\
    \n\r\n  int factor(State &pos){\r\n    if(*pos == '('){\r\n      consume(pos,\
    \ '(');\r\n      int res = expression(pos);\r\n      consume(pos, ')');\r\n  \
    \    return res;\r\n    }else{\r\n      return number(pos);\r\n    }\r\n  }\r\n\
    \r\n  int term(State &pos){\r\n    int res = factor(pos);\r\n    while(true){\r\
    \n      if(*pos == '*'){\r\n        consume(pos, '*');\r\n        res *= factor(pos);\r\
    \n      }else if(*pos == '/'){\r\n        consume(pos, '/');\r\n        res /=\
    \ factor(pos);\r\n      }else break;\r\n    }\r\n    return res;\r\n  }\r\n\r\n\
    \  int expression(State &pos){\r\n    int res = term(pos);\r\n    while(true){\r\
    \n      if(*pos == '+'){\r\n        consume(pos, '+');\r\n        res += term(pos);\r\
    \n      }else if(*pos == '-'){\r\n        consume(pos, '-');\r\n        res -=\
    \ term(pos);\r\n      }else break;\r\n    }\r\n    return res;\r\n  }\r\n\r\n\
    \  int parse(const string &s){\r\n    State pos = s.begin();\r\n    return expression(pos);\r\
    \n  }\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: string/Parsing.cpp
  requiredBy: []
  timestamp: '2021-09-08 20:54:29+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: string/Parsing.cpp
layout: document
redirect_from:
- /library/string/Parsing.cpp
- /library/string/Parsing.cpp.html
title: string/Parsing.cpp
---
