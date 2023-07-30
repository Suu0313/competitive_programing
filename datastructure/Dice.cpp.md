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
  bundledCode: "#line 2 \"datastructure/Dice.cpp\"\n\r\nstruct Dice{\r\n  static constexpr\
    \ array<int, 6> dice[24] = { // {u, d, f, b, l, r}\r\n    {1,6,2,5,4,3}, {1,6,3,4,2,5},\
    \ {1,6,4,3,5,2}, {1,6,5,2,3,4},\r\n    {2,5,1,6,3,4}, {2,5,3,4,6,1}, {2,5,4,3,1,6},\
    \ {2,5,6,1,4,3},\r\n    {3,4,1,6,5,2}, {3,4,2,5,1,6}, {3,4,5,2,6,1}, {3,4,6,1,2,5},\r\
    \n    {4,3,1,6,2,5}, {4,3,2,5,6,1}, {4,3,5,2,1,6}, {4,3,6,1,5,2},\r\n    {5,2,1,6,4,3},\
    \ {5,2,3,4,1,6}, {5,2,4,3,6,1}, {5,2,6,1,3,4},\r\n    {6,1,2,5,3,4}, {6,1,3,4,5,2},\
    \ {6,1,4,3,2,5}, {6,1,5,2,4,3}\r\n  };\r\n\r\n  static constexpr int rot[24][6]\
    \ = { // {N, S, E, W, L, R}\r\n    {7, 16, 13, 9, 2, 13}, {11, 12, 5, 17, 0, 5},\
    \ {15, 8, 18, 6, 3, 18}, {19, 4, 10, 14, 1, 10}, \r\n    {3, 20, 8, 12, 5, 8},\
    \ {10, 13, 21, 1, 7, 21}, {14, 9, 2, 22, 4, 2}, {23, 0, 15, 11, 6, 15}, \r\n \
    \   {2, 21, 16, 4, 10, 16}, {6, 17, 0, 20, 8, 0}, {18, 5, 23, 3, 11, 23}, {22,\
    \ 1, 7, 19, 9, 7}, \r\n    {1, 22, 4, 16, 13, 4}, {5, 18, 20, 0, 15, 20}, {17,\
    \ 6, 3, 23, 12, 3}, {21, 2, 19, 7, 14, 19}, \r\n    {0, 23, 12, 8, 18, 12}, {9,\
    \ 14, 1, 21, 16, 1}, {13, 10, 22, 2, 19, 22}, {20, 3, 11, 15, 17, 11}, \r\n  \
    \  {4, 19, 9, 13, 21, 9}, {8, 15, 17, 5, 23, 17}, {12, 11, 6, 18, 20, 6}, {16,\
    \ 7, 14, 10, 22, 14}\r\n  };\r\n\r\n  static constexpr bool check(const array<int,\
    \ 6> &a, const array<int, 6> &b){\r\n    for(int i = 0; i < 6; ++i){\r\n     \
    \ if(!a[i] || !b[i]) continue;\r\n      if(a[i] != b[i]) return false;\r\n   \
    \ }\r\n    return true;\r\n  }\r\n\r\n  int state, x, y;\r\n\r\n  constexpr Dice(const\
    \ array<int, 6> &ds, int x = 0, int y = 0): state(-1), x(x), y(y) {\r\n    for(int\
    \ i = 0; i < 24; ++i){\r\n      if(check(dice[i], ds)){\r\n        state = i;\r\
    \n        break;\r\n      }\r\n    }\r\n    assert(state != -1);\r\n  }\r\n\r\n\
    \  constexpr void rotN(){ state = rot[state][0]; ++y; }\r\n  constexpr void rotS(){\
    \ state = rot[state][1]; --y; }\r\n  constexpr void rotE(){ state = rot[state][2];\
    \ ++x; }\r\n  constexpr void rotW(){ state = rot[state][3]; --x; }\r\n  constexpr\
    \ void rotL(){ state = rot[state][4]; }\r\n  constexpr void rotR(){ state = rot[state][5];\
    \ }\r\n\r\n  constexpr int getU(){ return dice[state][0]; }\r\n  constexpr int\
    \ getD(){ return dice[state][1]; }\r\n  constexpr int getF(){ return dice[state][2];\
    \ }\r\n  constexpr int getB(){ return dice[state][3]; }\r\n  constexpr int getL(){\
    \ return dice[state][4]; }\r\n  constexpr int getR(){ return dice[state][5]; }\r\
    \n};\r\n"
  code: "#pragma once\r\n\r\nstruct Dice{\r\n  static constexpr array<int, 6> dice[24]\
    \ = { // {u, d, f, b, l, r}\r\n    {1,6,2,5,4,3}, {1,6,3,4,2,5}, {1,6,4,3,5,2},\
    \ {1,6,5,2,3,4},\r\n    {2,5,1,6,3,4}, {2,5,3,4,6,1}, {2,5,4,3,1,6}, {2,5,6,1,4,3},\r\
    \n    {3,4,1,6,5,2}, {3,4,2,5,1,6}, {3,4,5,2,6,1}, {3,4,6,1,2,5},\r\n    {4,3,1,6,2,5},\
    \ {4,3,2,5,6,1}, {4,3,5,2,1,6}, {4,3,6,1,5,2},\r\n    {5,2,1,6,4,3}, {5,2,3,4,1,6},\
    \ {5,2,4,3,6,1}, {5,2,6,1,3,4},\r\n    {6,1,2,5,3,4}, {6,1,3,4,5,2}, {6,1,4,3,2,5},\
    \ {6,1,5,2,4,3}\r\n  };\r\n\r\n  static constexpr int rot[24][6] = { // {N, S,\
    \ E, W, L, R}\r\n    {7, 16, 13, 9, 2, 13}, {11, 12, 5, 17, 0, 5}, {15, 8, 18,\
    \ 6, 3, 18}, {19, 4, 10, 14, 1, 10}, \r\n    {3, 20, 8, 12, 5, 8}, {10, 13, 21,\
    \ 1, 7, 21}, {14, 9, 2, 22, 4, 2}, {23, 0, 15, 11, 6, 15}, \r\n    {2, 21, 16,\
    \ 4, 10, 16}, {6, 17, 0, 20, 8, 0}, {18, 5, 23, 3, 11, 23}, {22, 1, 7, 19, 9,\
    \ 7}, \r\n    {1, 22, 4, 16, 13, 4}, {5, 18, 20, 0, 15, 20}, {17, 6, 3, 23, 12,\
    \ 3}, {21, 2, 19, 7, 14, 19}, \r\n    {0, 23, 12, 8, 18, 12}, {9, 14, 1, 21, 16,\
    \ 1}, {13, 10, 22, 2, 19, 22}, {20, 3, 11, 15, 17, 11}, \r\n    {4, 19, 9, 13,\
    \ 21, 9}, {8, 15, 17, 5, 23, 17}, {12, 11, 6, 18, 20, 6}, {16, 7, 14, 10, 22,\
    \ 14}\r\n  };\r\n\r\n  static constexpr bool check(const array<int, 6> &a, const\
    \ array<int, 6> &b){\r\n    for(int i = 0; i < 6; ++i){\r\n      if(!a[i] || !b[i])\
    \ continue;\r\n      if(a[i] != b[i]) return false;\r\n    }\r\n    return true;\r\
    \n  }\r\n\r\n  int state, x, y;\r\n\r\n  constexpr Dice(const array<int, 6> &ds,\
    \ int x = 0, int y = 0): state(-1), x(x), y(y) {\r\n    for(int i = 0; i < 24;\
    \ ++i){\r\n      if(check(dice[i], ds)){\r\n        state = i;\r\n        break;\r\
    \n      }\r\n    }\r\n    assert(state != -1);\r\n  }\r\n\r\n  constexpr void\
    \ rotN(){ state = rot[state][0]; ++y; }\r\n  constexpr void rotS(){ state = rot[state][1];\
    \ --y; }\r\n  constexpr void rotE(){ state = rot[state][2]; ++x; }\r\n  constexpr\
    \ void rotW(){ state = rot[state][3]; --x; }\r\n  constexpr void rotL(){ state\
    \ = rot[state][4]; }\r\n  constexpr void rotR(){ state = rot[state][5]; }\r\n\r\
    \n  constexpr int getU(){ return dice[state][0]; }\r\n  constexpr int getD(){\
    \ return dice[state][1]; }\r\n  constexpr int getF(){ return dice[state][2]; }\r\
    \n  constexpr int getB(){ return dice[state][3]; }\r\n  constexpr int getL(){\
    \ return dice[state][4]; }\r\n  constexpr int getR(){ return dice[state][5]; }\r\
    \n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: datastructure/Dice.cpp
  requiredBy: []
  timestamp: '2023-02-10 14:54:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: datastructure/Dice.cpp
layout: document
redirect_from:
- /library/datastructure/Dice.cpp
- /library/datastructure/Dice.cpp.html
title: datastructure/Dice.cpp
---
