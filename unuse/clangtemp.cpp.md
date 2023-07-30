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
  bundledCode: "#line 1 \"unuse/clangtemp.cpp\"\n//include\n//------------------------------------------\n\
    #include <vector>\n#include <list>\n#include <map>\n#include <set>\n#include <deque>\n\
    #include <stack>\n#include <bitset>\n#include <algorithm>\n#include <functional>\n\
    #include <numeric>\n#include <utility>\n#include <sstream>\n#include <iostream>\n\
    #include <iomanip>\n#include <cstdio>\n#include <cmath>\n#include <cstdlib>\n\
    #include <cctype>\n#include <string>\n#include <cstring>\n#include <ctime>\n#include\
    \ <queue>\n#include <fstream>\n#include <tuple>\n\nusing namespace std;\n\n\n\
    //math\n//-------------------------------------------\ntemplate<class T> inline\
    \ T sqr(T x) {return x*x;}\n\n//typedef\n//------------------------------------------\n\
    typedef long long LL;\ntypedef pair<int, int> PII;\ntypedef pair<LL,LL> PLL;\n\
    typedef vector<int> VI;\ntypedef vector<VI> VVI;\ntypedef vector<LL> VLL;\ntypedef\
    \ vector<VLL> VVLL;\ntypedef vector<bool> VB;\ntypedef vector<VB> VVB;\ntypedef\
    \ vector<double> VD;\ntypedef vector<VD> VVD;\ntypedef vector<string> VS;\ntypedef\
    \ vector<VS> VVS;\ntypedef vector<char> VC;\ntypedef vector<VC> VVC;\ntypedef\
    \ vector<PII> VPII;\ntypedef vector<PLL> VPLL;\ntypedef priority_queue<int> PQGI;\
    \ //\u5927\u304D\u3044\u9806\ntypedef priority_queue<int, VI, greater<int>> PQLI;\n\
    typedef priority_queue<PII> PQGP; \ntypedef priority_queue<PII, VPII, greater<int>>\
    \ PQLP;\n\n//container util\n//------------------------------------------\n#define\
    \ ALL(a)  (a).begin(),(a).end()\n#define RALL(a) (a).rbegin(),(a).rend()\n#define\
    \ EB emplace_back\n#define PB push_back\n#define PF push_front\n#define POB pop_back\n\
    #define POF pop_front\n#define MP make_pair\n#define SZ(a) int((a).size())\n#define\
    \ SQ(a) ((a)*(a))\n#define EACH(i,c) for(typeof((c).begin()) i=(c).begin(); i!=(c).end();\
    \ ++i)\n#define EXIST(s,e) ((s).find(e)!=(s).end())\n#define SORT(c) sort((c).begin(),(c).end())\n\
    #define SORTR(c) sort((c).rbegin(), (c).rend())\n#define LB lower_bound\n#define\
    \ UB upper_bound\n#define NEXP next_permutation\n#define FI first\n#define SE\
    \ second\n\n//repetition\n//------------------------------------------\n#define\
    \ FOR(i,a,b) for(int i=(a);i<(b);++i)\n#define REP(i,n)  FOR(i,0,n)\n#define FORR(i,a,b)\
    \ for(int i = (b-1);i>=a;i--)\n#define REPR(i,n) FORR(i,0,n)\n#define BREP(bit,N)\
    \ for(int bit = 0; bit < (1<<N); ++bit)\n\n//constant\n//--------------------------------------------\n\
    const double EPS = 1e-10;\nconst double PI  = acos(-1.0);\nconst LL MOD = 1e9+7;\n\
    const LL MODD = 998244353;\nconst int MAX = 510000;\n\ninline bool Eq(double a,\
    \ double b) { return fabs(b - a) < EPS; }\n\n//other\n//-------------------------------------------\n\
    template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return\
    \ 0; }\ntemplate<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return\
    \ 1; } return 0; }\n\n\n\nint main(){\n  \n  \n  \n  return 0;\n}\n"
  code: "//include\n//------------------------------------------\n#include <vector>\n\
    #include <list>\n#include <map>\n#include <set>\n#include <deque>\n#include <stack>\n\
    #include <bitset>\n#include <algorithm>\n#include <functional>\n#include <numeric>\n\
    #include <utility>\n#include <sstream>\n#include <iostream>\n#include <iomanip>\n\
    #include <cstdio>\n#include <cmath>\n#include <cstdlib>\n#include <cctype>\n#include\
    \ <string>\n#include <cstring>\n#include <ctime>\n#include <queue>\n#include <fstream>\n\
    #include <tuple>\n\nusing namespace std;\n\n\n//math\n//-------------------------------------------\n\
    template<class T> inline T sqr(T x) {return x*x;}\n\n//typedef\n//------------------------------------------\n\
    typedef long long LL;\ntypedef pair<int, int> PII;\ntypedef pair<LL,LL> PLL;\n\
    typedef vector<int> VI;\ntypedef vector<VI> VVI;\ntypedef vector<LL> VLL;\ntypedef\
    \ vector<VLL> VVLL;\ntypedef vector<bool> VB;\ntypedef vector<VB> VVB;\ntypedef\
    \ vector<double> VD;\ntypedef vector<VD> VVD;\ntypedef vector<string> VS;\ntypedef\
    \ vector<VS> VVS;\ntypedef vector<char> VC;\ntypedef vector<VC> VVC;\ntypedef\
    \ vector<PII> VPII;\ntypedef vector<PLL> VPLL;\ntypedef priority_queue<int> PQGI;\
    \ //\u5927\u304D\u3044\u9806\ntypedef priority_queue<int, VI, greater<int>> PQLI;\n\
    typedef priority_queue<PII> PQGP; \ntypedef priority_queue<PII, VPII, greater<int>>\
    \ PQLP;\n\n//container util\n//------------------------------------------\n#define\
    \ ALL(a)  (a).begin(),(a).end()\n#define RALL(a) (a).rbegin(),(a).rend()\n#define\
    \ EB emplace_back\n#define PB push_back\n#define PF push_front\n#define POB pop_back\n\
    #define POF pop_front\n#define MP make_pair\n#define SZ(a) int((a).size())\n#define\
    \ SQ(a) ((a)*(a))\n#define EACH(i,c) for(typeof((c).begin()) i=(c).begin(); i!=(c).end();\
    \ ++i)\n#define EXIST(s,e) ((s).find(e)!=(s).end())\n#define SORT(c) sort((c).begin(),(c).end())\n\
    #define SORTR(c) sort((c).rbegin(), (c).rend())\n#define LB lower_bound\n#define\
    \ UB upper_bound\n#define NEXP next_permutation\n#define FI first\n#define SE\
    \ second\n\n//repetition\n//------------------------------------------\n#define\
    \ FOR(i,a,b) for(int i=(a);i<(b);++i)\n#define REP(i,n)  FOR(i,0,n)\n#define FORR(i,a,b)\
    \ for(int i = (b-1);i>=a;i--)\n#define REPR(i,n) FORR(i,0,n)\n#define BREP(bit,N)\
    \ for(int bit = 0; bit < (1<<N); ++bit)\n\n//constant\n//--------------------------------------------\n\
    const double EPS = 1e-10;\nconst double PI  = acos(-1.0);\nconst LL MOD = 1e9+7;\n\
    const LL MODD = 998244353;\nconst int MAX = 510000;\n\ninline bool Eq(double a,\
    \ double b) { return fabs(b - a) < EPS; }\n\n//other\n//-------------------------------------------\n\
    template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return\
    \ 0; }\ntemplate<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return\
    \ 1; } return 0; }\n\n\n\nint main(){\n  \n  \n  \n  return 0;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: unuse/clangtemp.cpp
  requiredBy: []
  timestamp: '2021-02-27 15:36:36+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: unuse/clangtemp.cpp
layout: document
redirect_from:
- /library/unuse/clangtemp.cpp
- /library/unuse/clangtemp.cpp.html
title: unuse/clangtemp.cpp
---
