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
  bundledCode: "#line 2 \"math/matrix/BitMatrix.cpp\"\n\r\nconst int MAX_ROW = 510;\r\
    \nconst int MAX_COL = 510;\r\nstruct BitMatrix{\r\n  int H,W;\r\n  bitset<MAX_COL>\
    \ val[MAX_ROW];\r\n  BitMatrix(int h=1,int w=1):H(h),W(w){}\r\n  bitset<MAX_COL>&\
    \ operator[](int i){return val[i];}\r\n};\r\nint GaussJordan(BitMatrix &A, bool\
    \ is_extended = false){\r\n  int rank = 0;\r\n  REP(col, A.W){\r\n    if(is_extended\
    \ && col == A.W-1) break;\r\n    int pivot = -1;\r\n    FOR(row,rank,A.H){\r\n\
    \      if(A[row][col]){\r\n        pivot = row;\r\n        break;\r\n      }\r\
    \n    }\r\n    if(pivot == -1) continue;\r\n    swap(A[pivot],A[rank]);\r\n  \
    \  REP(row, A.H){\r\n      if(row != rank && A[row][col]) A[row] ^= A[rank];\r\
    \n    }\r\n    ++rank;\r\n  }\r\n  return rank;\r\n}\r\nint linear_equation(BitMatrix\
    \ A, VI b, VI &res){\r\n  int m = A.H, n = A.W;\r\n  BitMatrix M(m, n+1);\r\n\
    \  REP(i,m){\r\n    REP(j,n) M[i][j] = A[i][j];\r\n    M[i][n] = b.at(i);\r\n\
    \  }\r\n  int rank = GaussJordan(M,true);\r\n  FOR(row, rank, m) if(M[row][n])\
    \ return -1;\r\n\r\n  res.assign(n,0);\r\n  REP(i,rank) res.at(i) = M[i][n];\r\
    \n  return rank;\r\n}\r\n"
  code: "#pragma once\r\n\r\nconst int MAX_ROW = 510;\r\nconst int MAX_COL = 510;\r\
    \nstruct BitMatrix{\r\n  int H,W;\r\n  bitset<MAX_COL> val[MAX_ROW];\r\n  BitMatrix(int\
    \ h=1,int w=1):H(h),W(w){}\r\n  bitset<MAX_COL>& operator[](int i){return val[i];}\r\
    \n};\r\nint GaussJordan(BitMatrix &A, bool is_extended = false){\r\n  int rank\
    \ = 0;\r\n  REP(col, A.W){\r\n    if(is_extended && col == A.W-1) break;\r\n \
    \   int pivot = -1;\r\n    FOR(row,rank,A.H){\r\n      if(A[row][col]){\r\n  \
    \      pivot = row;\r\n        break;\r\n      }\r\n    }\r\n    if(pivot == -1)\
    \ continue;\r\n    swap(A[pivot],A[rank]);\r\n    REP(row, A.H){\r\n      if(row\
    \ != rank && A[row][col]) A[row] ^= A[rank];\r\n    }\r\n    ++rank;\r\n  }\r\n\
    \  return rank;\r\n}\r\nint linear_equation(BitMatrix A, VI b, VI &res){\r\n \
    \ int m = A.H, n = A.W;\r\n  BitMatrix M(m, n+1);\r\n  REP(i,m){\r\n    REP(j,n)\
    \ M[i][j] = A[i][j];\r\n    M[i][n] = b.at(i);\r\n  }\r\n  int rank = GaussJordan(M,true);\r\
    \n  FOR(row, rank, m) if(M[row][n]) return -1;\r\n\r\n  res.assign(n,0);\r\n \
    \ REP(i,rank) res.at(i) = M[i][n];\r\n  return rank;\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: math/matrix/BitMatrix.cpp
  requiredBy: []
  timestamp: '2023-02-10 14:54:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/matrix/BitMatrix.cpp
layout: document
redirect_from:
- /library/math/matrix/BitMatrix.cpp
- /library/math/matrix/BitMatrix.cpp.html
title: math/matrix/BitMatrix.cpp
---
