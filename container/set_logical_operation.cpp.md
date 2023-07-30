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
  bundledCode: "#line 2 \"container/set_logical_operation.cpp\"\n\r\ntemplate<typename\
    \ Container>\r\nContainer SetAnd(const Container &a, const Container &b){\r\n\
    \  Container res;\r\n  std::set_intersection(\r\n    std::begin(a), std::end(a),\r\
    \n    std::begin(b), std::end(b),\r\n    std::inserter(res, std::end(res))\r\n\
    \  );\r\n  return res;\r\n}\r\ntemplate<typename Container>\r\nContainer SetOr(const\
    \ Container &a, const Container &b){\r\n  Container res;\r\n  std::set_union(\r\
    \n    std::begin(a), std::end(a),\r\n    std::begin(b), std::end(b),\r\n    std::inserter(res,\
    \ std::end(res))\r\n  );\r\n  return res;\r\n}\r\ntemplate<typename Container>\r\
    \nContainer SetXor(const Container &a, const Container &b){\r\n  Container res;\r\
    \n  std::set_symmetric_difference(\r\n    std::begin(a), std::end(a),\r\n    std::begin(b),\
    \ std::end(b),\r\n    std::inserter(res, std::end(res))\r\n  );\r\n  return res;\r\
    \n}\r\ntemplate<typename Container>\r\nContainer SetDiff(const Container &a, const\
    \ Container &b){\r\n  Container res;\r\n  std::set_difference(\r\n    std::begin(a),\
    \ std::end(a),\r\n    std::begin(b), std::end(b),\r\n    std::inserter(res, std::end(res))\r\
    \n  );\r\n  return res;\r\n}\n"
  code: "#pragma once\r\n\r\ntemplate<typename Container>\r\nContainer SetAnd(const\
    \ Container &a, const Container &b){\r\n  Container res;\r\n  std::set_intersection(\r\
    \n    std::begin(a), std::end(a),\r\n    std::begin(b), std::end(b),\r\n    std::inserter(res,\
    \ std::end(res))\r\n  );\r\n  return res;\r\n}\r\ntemplate<typename Container>\r\
    \nContainer SetOr(const Container &a, const Container &b){\r\n  Container res;\r\
    \n  std::set_union(\r\n    std::begin(a), std::end(a),\r\n    std::begin(b), std::end(b),\r\
    \n    std::inserter(res, std::end(res))\r\n  );\r\n  return res;\r\n}\r\ntemplate<typename\
    \ Container>\r\nContainer SetXor(const Container &a, const Container &b){\r\n\
    \  Container res;\r\n  std::set_symmetric_difference(\r\n    std::begin(a), std::end(a),\r\
    \n    std::begin(b), std::end(b),\r\n    std::inserter(res, std::end(res))\r\n\
    \  );\r\n  return res;\r\n}\r\ntemplate<typename Container>\r\nContainer SetDiff(const\
    \ Container &a, const Container &b){\r\n  Container res;\r\n  std::set_difference(\r\
    \n    std::begin(a), std::end(a),\r\n    std::begin(b), std::end(b),\r\n    std::inserter(res,\
    \ std::end(res))\r\n  );\r\n  return res;\r\n}"
  dependsOn: []
  isVerificationFile: false
  path: container/set_logical_operation.cpp
  requiredBy: []
  timestamp: '2023-02-10 14:54:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: container/set_logical_operation.cpp
layout: document
redirect_from:
- /library/container/set_logical_operation.cpp
- /library/container/set_logical_operation.cpp.html
title: container/set_logical_operation.cpp
---
