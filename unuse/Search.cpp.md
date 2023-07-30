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
  bundledCode: "#line 1 \"unuse/Search.cpp\"\ntemplate<typename F>\r\npair<double,double>\
    \ Binary(double ok, double ng, const F &isok, int m = 200){\r\n  for(int t = 0;\
    \ t < m; t++){\r\n    double wj = ((ok - ng)/2) + ng;\r\n    (isok(wj)?ok : ng)\
    \ = wj;\r\n  }\r\n  return {ok, ng};\r\n}\r\n\r\ntemplate<typename T, typename\
    \ F>\r\npair<T,T> Binary(T ok, T ng, const F &isok){\r\n  while(abs(ok - ng) >\
    \ 1){\r\n    T wj = ((ok - ng) >> 1) + ng;\r\n    (isok(wj)?ok : ng) = wj;\r\n\
    \  }\r\n  return {ok, ng};\r\n}\r\n\r\ntemplate<typename F>\r\npair<double,double>\
    \ Golden(double l, double r, const F &f, bool maximize = true, int m = 200){\r\
    \n  const double phi =(1 + sqrt(5.0)) / 2;\r\n  double ml = (phi*l + r)/(1 + phi);\r\
    \n  double mr = (l + phi*r)/(1 + phi);\r\n  auto fl = f(ml), fr = f(mr);\r\n \
    \ for(int t = 0; t < m; t++){\r\n    if((fl < fr)^maximize){\r\n      r = mr;\
    \ mr = ml; fr = fl;\r\n      ml = (phi*l + r)/(1 + phi);\r\n      fl = f(ml);\r\
    \n    }else{\r\n      l = ml; ml = mr; fl = fr;\r\n      mr = (l + phi*r)/(1 +\
    \ phi);\r\n      fr = f(mr);\r\n    }\r\n  }\r\n  return {ml, mr};\r\n}\r\n\r\n\
    template<typename T, typename F>\r\nT Golden(T dl, T dr, const F &f, bool maximize\
    \ = true){\r\n  vector<T> fib(2, 1);\r\n  while(fib.back() <= (dr - dl)) fib.push_back(fib.back()\
    \ + fib[fib.size()-2]);\r\n  int d = fib.size()-1;\r\n  T l = dl, r = l + fib[d--];\r\
    \n  T ml = l + fib[d-1], mr = l + fib[d--];\r\n  auto fl = f(ml), fr = f(mr);\r\
    \n\r\n  while(l+2 < r){\r\n    if(mr >= dr){\r\n      r = mr; mr = ml; fr = fl;\r\
    \n      ml = l + fib[--d];\r\n      fl = f(ml);\r\n      continue;\r\n    }\r\n\
    \    if((fl < fr)^maximize){\r\n      r = mr; mr = ml; fr = fl;\r\n      ml =\
    \ l + fib[--d];\r\n      if(ml < dr) fl = f(ml);\r\n    }else{\r\n      l = ml;\
    \ ml = mr; fl = fr;\r\n      mr = l + fib[d--];\r\n      if(mr < dr) fr = f(mr);\r\
    \n    }\r\n  }\r\n  return ++l;\r\n}\r\n"
  code: "template<typename F>\r\npair<double,double> Binary(double ok, double ng,\
    \ const F &isok, int m = 200){\r\n  for(int t = 0; t < m; t++){\r\n    double\
    \ wj = ((ok - ng)/2) + ng;\r\n    (isok(wj)?ok : ng) = wj;\r\n  }\r\n  return\
    \ {ok, ng};\r\n}\r\n\r\ntemplate<typename T, typename F>\r\npair<T,T> Binary(T\
    \ ok, T ng, const F &isok){\r\n  while(abs(ok - ng) > 1){\r\n    T wj = ((ok -\
    \ ng) >> 1) + ng;\r\n    (isok(wj)?ok : ng) = wj;\r\n  }\r\n  return {ok, ng};\r\
    \n}\r\n\r\ntemplate<typename F>\r\npair<double,double> Golden(double l, double\
    \ r, const F &f, bool maximize = true, int m = 200){\r\n  const double phi =(1\
    \ + sqrt(5.0)) / 2;\r\n  double ml = (phi*l + r)/(1 + phi);\r\n  double mr = (l\
    \ + phi*r)/(1 + phi);\r\n  auto fl = f(ml), fr = f(mr);\r\n  for(int t = 0; t\
    \ < m; t++){\r\n    if((fl < fr)^maximize){\r\n      r = mr; mr = ml; fr = fl;\r\
    \n      ml = (phi*l + r)/(1 + phi);\r\n      fl = f(ml);\r\n    }else{\r\n   \
    \   l = ml; ml = mr; fl = fr;\r\n      mr = (l + phi*r)/(1 + phi);\r\n      fr\
    \ = f(mr);\r\n    }\r\n  }\r\n  return {ml, mr};\r\n}\r\n\r\ntemplate<typename\
    \ T, typename F>\r\nT Golden(T dl, T dr, const F &f, bool maximize = true){\r\n\
    \  vector<T> fib(2, 1);\r\n  while(fib.back() <= (dr - dl)) fib.push_back(fib.back()\
    \ + fib[fib.size()-2]);\r\n  int d = fib.size()-1;\r\n  T l = dl, r = l + fib[d--];\r\
    \n  T ml = l + fib[d-1], mr = l + fib[d--];\r\n  auto fl = f(ml), fr = f(mr);\r\
    \n\r\n  while(l+2 < r){\r\n    if(mr >= dr){\r\n      r = mr; mr = ml; fr = fl;\r\
    \n      ml = l + fib[--d];\r\n      fl = f(ml);\r\n      continue;\r\n    }\r\n\
    \    if((fl < fr)^maximize){\r\n      r = mr; mr = ml; fr = fl;\r\n      ml =\
    \ l + fib[--d];\r\n      if(ml < dr) fl = f(ml);\r\n    }else{\r\n      l = ml;\
    \ ml = mr; fl = fr;\r\n      mr = l + fib[d--];\r\n      if(mr < dr) fr = f(mr);\r\
    \n    }\r\n  }\r\n  return ++l;\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: unuse/Search.cpp
  requiredBy: []
  timestamp: '2022-07-28 05:42:13+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: unuse/Search.cpp
layout: document
redirect_from:
- /library/unuse/Search.cpp
- /library/unuse/Search.cpp.html
title: unuse/Search.cpp
---
