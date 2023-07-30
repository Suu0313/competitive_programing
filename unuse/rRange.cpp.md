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
  bundledCode: "#line 1 \"unuse/rRange.cpp\"\ntemplate<typename rbIterator, typename\
    \ reIterator>\r\nstruct rRange{\r\n  rbIterator m_rbegin;\r\n  reIterator m_rend;\r\
    \n  rRange(rbIterator m_rbegin, reIterator m_rend): m_rbegin(m_rbegin), m_rend(m_rend)\
    \ {}\r\n  rbIterator &begin() { return m_rbegin; };\r\n  rbIterator &end() { return\
    \ m_rend; };\r\n};\r\n\r\ntemplate<typename Container>\r\nauto rev(const Container\
    \ &c){ return rRange(rbegin(c), rend(c)); }\r\n"
  code: "template<typename rbIterator, typename reIterator>\r\nstruct rRange{\r\n\
    \  rbIterator m_rbegin;\r\n  reIterator m_rend;\r\n  rRange(rbIterator m_rbegin,\
    \ reIterator m_rend): m_rbegin(m_rbegin), m_rend(m_rend) {}\r\n  rbIterator &begin()\
    \ { return m_rbegin; };\r\n  rbIterator &end() { return m_rend; };\r\n};\r\n\r\
    \ntemplate<typename Container>\r\nauto rev(const Container &c){ return rRange(rbegin(c),\
    \ rend(c)); }\r\n"
  dependsOn: []
  isVerificationFile: false
  path: unuse/rRange.cpp
  requiredBy: []
  timestamp: '2021-09-15 21:46:35+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: unuse/rRange.cpp
layout: document
redirect_from:
- /library/unuse/rRange.cpp
- /library/unuse/rRange.cpp.html
title: unuse/rRange.cpp
---
