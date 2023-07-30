---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: template/template.cpp
    title: template/template.cpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"template/template_defines.cpp\"\n\r\ntypedef long long LL;\r\
    \ntypedef pair<int, int> PII; typedef pair<LL,LL> PLL;\r\ntypedef vector<int>\
    \ VI; typedef vector<VI> VVI;\r\ntypedef vector<LL> VLL; typedef vector<VLL> VVLL;\r\
    \ntypedef vector<bool> VB; typedef vector<VB> VVB;\r\ntypedef vector<double> VD;\
    \ typedef vector<VD> VVD;\r\ntypedef vector<string> VS; typedef vector<VS> VVS;\r\
    \ntypedef vector<char> VC; typedef vector<VC> VVC;\r\ntypedef vector<PII> VPII;\
    \ typedef vector<PLL> VPLL;\r\n\r\n#define LB lower_bound\r\n#define UB upper_bound\r\
    \n#define FI first\r\n#define SE second\r\n#define EF emplace_front\r\n#define\
    \ EB emplace_back\r\n#define PF push_front\r\n#define PB push_back\r\n#define\
    \ POF pop_front\r\n#define POB pop_back\r\n#define MP make_pair\r\n#define MT\
    \ make_tuple\r\n#define ALL(a)  begin(a), end(a)\r\n#define RALL(a) rbegin(a),\
    \ rend(a)\r\n#define SORT(c) sort(begin(c), end(c))\r\n#define SORTR(c) sort(rbegin(c),\
    \ rend(c))\r\n\r\n#define FOR(i,a,b) for(decay_t<decltype(b)> i=(a), i##_r=(b);\
    \ i<i##_r; i++)\r\n#define REP(i,n) FOR(i,0,n)\r\n#define FORR(i,a,b) for(decay_t<decltype(b)>\
    \ i=(b)-1, i##_l=(a); i>=i##_l; i--)\r\n#define REPR(i,n) FORR(i,0,n)\r\n#define\
    \ CFOR(i,a,b) for(decay_t<decltype(b)> i=(a), i##_r=(b); i<=i##_r; i++)\r\n#define\
    \ CREP(i,n) CFOR(i,0,n)\r\n#define SREP(i,n) CFOR(i,1,n)\r\n#define CFORR(i,a,b)\
    \ for(decay_t<decltype(b)> i=(b), i##_l=(a); i>=i##_l; i--)\r\n#define CREPR(i,n)\
    \ CFORR(i,0,n)\r\n#define SREPR(i,n) CFORR(i,1,n)\r\n#define BFOR(bit,a,b) for(long\
    \ long bit=(a); bit<(1ll<<(b)); bit++)\r\n#define BREP(bit,n) BFOR(bit,0,n)\r\n\
    \r\n#define OVERLOAD4(a,b,c,d,name,...) name\r\n#define EACH1(a, v) for(auto&&a\
    \ : v)\r\n#define EACH2(a,b, v) for(auto&&[a,b] : v)\r\n#define EACH3(a,b,c, v)\
    \ for(auto&&[a,b,c] : v)\r\n#define EACH(...) OVERLOAD4(__VA_ARGS__, EACH3, EACH2,\
    \ EACH1)(__VA_ARGS__)\r\n\r\n#define elif else if\r\n#define unless(a) if(!(a))\r\
    \n"
  code: "#pragma once\r\n\r\ntypedef long long LL;\r\ntypedef pair<int, int> PII;\
    \ typedef pair<LL,LL> PLL;\r\ntypedef vector<int> VI; typedef vector<VI> VVI;\r\
    \ntypedef vector<LL> VLL; typedef vector<VLL> VVLL;\r\ntypedef vector<bool> VB;\
    \ typedef vector<VB> VVB;\r\ntypedef vector<double> VD; typedef vector<VD> VVD;\r\
    \ntypedef vector<string> VS; typedef vector<VS> VVS;\r\ntypedef vector<char> VC;\
    \ typedef vector<VC> VVC;\r\ntypedef vector<PII> VPII; typedef vector<PLL> VPLL;\r\
    \n\r\n#define LB lower_bound\r\n#define UB upper_bound\r\n#define FI first\r\n\
    #define SE second\r\n#define EF emplace_front\r\n#define EB emplace_back\r\n#define\
    \ PF push_front\r\n#define PB push_back\r\n#define POF pop_front\r\n#define POB\
    \ pop_back\r\n#define MP make_pair\r\n#define MT make_tuple\r\n#define ALL(a)\
    \  begin(a), end(a)\r\n#define RALL(a) rbegin(a), rend(a)\r\n#define SORT(c) sort(begin(c),\
    \ end(c))\r\n#define SORTR(c) sort(rbegin(c), rend(c))\r\n\r\n#define FOR(i,a,b)\
    \ for(decay_t<decltype(b)> i=(a), i##_r=(b); i<i##_r; i++)\r\n#define REP(i,n)\
    \ FOR(i,0,n)\r\n#define FORR(i,a,b) for(decay_t<decltype(b)> i=(b)-1, i##_l=(a);\
    \ i>=i##_l; i--)\r\n#define REPR(i,n) FORR(i,0,n)\r\n#define CFOR(i,a,b) for(decay_t<decltype(b)>\
    \ i=(a), i##_r=(b); i<=i##_r; i++)\r\n#define CREP(i,n) CFOR(i,0,n)\r\n#define\
    \ SREP(i,n) CFOR(i,1,n)\r\n#define CFORR(i,a,b) for(decay_t<decltype(b)> i=(b),\
    \ i##_l=(a); i>=i##_l; i--)\r\n#define CREPR(i,n) CFORR(i,0,n)\r\n#define SREPR(i,n)\
    \ CFORR(i,1,n)\r\n#define BFOR(bit,a,b) for(long long bit=(a); bit<(1ll<<(b));\
    \ bit++)\r\n#define BREP(bit,n) BFOR(bit,0,n)\r\n\r\n#define OVERLOAD4(a,b,c,d,name,...)\
    \ name\r\n#define EACH1(a, v) for(auto&&a : v)\r\n#define EACH2(a,b, v) for(auto&&[a,b]\
    \ : v)\r\n#define EACH3(a,b,c, v) for(auto&&[a,b,c] : v)\r\n#define EACH(...)\
    \ OVERLOAD4(__VA_ARGS__, EACH3, EACH2, EACH1)(__VA_ARGS__)\r\n\r\n#define elif\
    \ else if\r\n#define unless(a) if(!(a))\r\n"
  dependsOn: []
  isVerificationFile: false
  path: template/template_defines.cpp
  requiredBy:
  - template/template.cpp
  timestamp: '2023-02-10 14:54:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: template/template_defines.cpp
layout: document
redirect_from:
- /library/template/template_defines.cpp
- /library/template/template_defines.cpp.html
title: template/template_defines.cpp
---
