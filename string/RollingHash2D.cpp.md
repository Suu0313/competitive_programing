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
  bundledCode: "#line 2 \"string/RollingHash2D.cpp\"\n\r\nstruct RollingHash2D{\r\n\
    \  static constexpr uint64_t mod = (1ull << 61) - 1;\r\n  static constexpr uint64_t\
    \ mask(int k){ return (1ull << k) - 1; }\r\n  static constexpr uint64_t add(uint64_t\
    \ a, uint64_t b){\r\n    return ((a+=b) >= mod) ? (a - mod) : a;\r\n  }\r\n  static\
    \ constexpr uint64_t mul(uint64_t a, uint64_t b){\r\n    uint64_t au = a >> 31,\
    \ ad = a & mask(31);\r\n    uint64_t bu = b >> 31, bd = b & mask(31);\r\n    int64_t\
    \ mid = ad*bu + au*bd;\r\n    uint64_t mu = mid >> 30, md = mid & mask(30);\r\n\
    \    return au*bu*2 + mu + (md << 31) + ad*bd;\r\n  }\r\n  static constexpr uint64_t\
    \ cal_mod(uint64_t x){\r\n    uint64_t res = (x >> 61) + (x & mask(61));\r\n \
    \   return (res>=mod) ? (res-mod) : res;\r\n  }\r\n\r\n  static inline uint64_t\
    \ generate_base(){\r\n    mt19937_64 mt(random_device{}());\r\n    uniform_int_distribution<uint64_t>\
    \ rand(1, mod-1);\r\n    return rand(mt);\r\n  }\r\n\r\n  inline void expand1(size_t\
    \ n){\r\n    if(size_t pn = pow_table1.size(); pn < n+1){\r\n      pow_table1.resize(n\
    \ + 1);\r\n      for(size_t i = pn-1; i < n; ++i){\r\n        pow_table1[i+1]\
    \ = cal_mod(mul(pow_table1[i], base1));\r\n      }\r\n    }\r\n  }\r\n\r\n  inline\
    \ void expand2(size_t n){\r\n    if(size_t pn = pow_table2.size(); pn < n+1){\r\
    \n      pow_table2.resize(n + 1);\r\n      for(size_t i = pn-1; i < n; ++i){\r\
    \n        pow_table2[i+1] = cal_mod(mul(pow_table2[i], base2));\r\n      }\r\n\
    \    }\r\n  }\r\n\r\n  const uint64_t base1, base2;\r\n  vector<uint64_t> pow_table1,\
    \ pow_table2;\r\n\r\n  RollingHash2D(uint64_t base1 = generate_base(), uint64_t\
    \ base2 = generate_base())\r\n  : base1(base1), base2(base2), pow_table1(1,1),\
    \ pow_table2(1,1) {}\r\n\r\n  vector<vector<uint64_t>> build(const vector<string>\
    \ &s) const {\r\n    int n = int(s.size()), m = int(s[0].size());\r\n    vector<vector<uint64_t>>\
    \ res(n + 1, vector<uint64_t>(m + 1));\r\n    for(int i = 0; i < n; ++i){\r\n\
    \      for(int j = 0; j < m; ++j){\r\n        res[i+1][j+1] = cal_mod(mul(res[i+1][j],\
    \ base2) + s[i][j]);\r\n      }\r\n    }\r\n    for(int j = 0; j < m; ++j){\r\n\
    \      for(int i = 0; i < n; ++i){\r\n        res[i+1][j+1] = cal_mod(mul(res[i][j+1],\
    \ base1) + res[i+1][j+1]);\r\n      }\r\n    }\r\n    return res;\r\n  }\r\n\r\
    \n  template<typename T>\r\n  vector<vector<uint64_t>> build(const vector<vector<T>>\
    \ &s) const {\r\n    int n = int(s.size()), m = int(s[0].size());\r\n    vector<vector<uint64_t>>\
    \ res(n + 1, vector<uint64_t>(m + 1));\r\n    for(int i = 0; i < n; ++i){\r\n\
    \      for(int j = 0; j < m; ++j){\r\n        res[i+1][j+1] = cal_mod(mul(res[i+1][j],\
    \ base2) + s[i][j]);\r\n      }\r\n    }\r\n    for(int j = 0; j < m; ++j){\r\n\
    \      for(int i = 0; i < n; ++i){\r\n        res[i+1][j+1] = cal_mod(mul(res[i][j+1],\
    \ base1) + res[i+1][j+1]);\r\n      }\r\n    }\r\n    return res;\r\n  }\r\n\r\
    \n  uint64_t query(const vector<vector<uint64_t>> &s, int l, int r, int d, int\
    \ u){\r\n    expand1(r - l);\r\n    expand2(u - d);\r\n    uint64_t p1 = pow_table1[r-l],\
    \ p2 = pow_table2[u-d];\r\n    \r\n    return cal_mod(cal_mod(s[r][u] + mod*4\
    \ - cal_mod(mul(s[r][d], p2)))\r\n      + cal_mod(mul(s[l][d], cal_mod(mul(p1,\
    \ p2))) + mod*4 - cal_mod(mul(s[l][u], p1)))\r\n      );\r\n  }\r\n};\r\n"
  code: "#pragma once\r\n\r\nstruct RollingHash2D{\r\n  static constexpr uint64_t\
    \ mod = (1ull << 61) - 1;\r\n  static constexpr uint64_t mask(int k){ return (1ull\
    \ << k) - 1; }\r\n  static constexpr uint64_t add(uint64_t a, uint64_t b){\r\n\
    \    return ((a+=b) >= mod) ? (a - mod) : a;\r\n  }\r\n  static constexpr uint64_t\
    \ mul(uint64_t a, uint64_t b){\r\n    uint64_t au = a >> 31, ad = a & mask(31);\r\
    \n    uint64_t bu = b >> 31, bd = b & mask(31);\r\n    int64_t mid = ad*bu + au*bd;\r\
    \n    uint64_t mu = mid >> 30, md = mid & mask(30);\r\n    return au*bu*2 + mu\
    \ + (md << 31) + ad*bd;\r\n  }\r\n  static constexpr uint64_t cal_mod(uint64_t\
    \ x){\r\n    uint64_t res = (x >> 61) + (x & mask(61));\r\n    return (res>=mod)\
    \ ? (res-mod) : res;\r\n  }\r\n\r\n  static inline uint64_t generate_base(){\r\
    \n    mt19937_64 mt(random_device{}());\r\n    uniform_int_distribution<uint64_t>\
    \ rand(1, mod-1);\r\n    return rand(mt);\r\n  }\r\n\r\n  inline void expand1(size_t\
    \ n){\r\n    if(size_t pn = pow_table1.size(); pn < n+1){\r\n      pow_table1.resize(n\
    \ + 1);\r\n      for(size_t i = pn-1; i < n; ++i){\r\n        pow_table1[i+1]\
    \ = cal_mod(mul(pow_table1[i], base1));\r\n      }\r\n    }\r\n  }\r\n\r\n  inline\
    \ void expand2(size_t n){\r\n    if(size_t pn = pow_table2.size(); pn < n+1){\r\
    \n      pow_table2.resize(n + 1);\r\n      for(size_t i = pn-1; i < n; ++i){\r\
    \n        pow_table2[i+1] = cal_mod(mul(pow_table2[i], base2));\r\n      }\r\n\
    \    }\r\n  }\r\n\r\n  const uint64_t base1, base2;\r\n  vector<uint64_t> pow_table1,\
    \ pow_table2;\r\n\r\n  RollingHash2D(uint64_t base1 = generate_base(), uint64_t\
    \ base2 = generate_base())\r\n  : base1(base1), base2(base2), pow_table1(1,1),\
    \ pow_table2(1,1) {}\r\n\r\n  vector<vector<uint64_t>> build(const vector<string>\
    \ &s) const {\r\n    int n = int(s.size()), m = int(s[0].size());\r\n    vector<vector<uint64_t>>\
    \ res(n + 1, vector<uint64_t>(m + 1));\r\n    for(int i = 0; i < n; ++i){\r\n\
    \      for(int j = 0; j < m; ++j){\r\n        res[i+1][j+1] = cal_mod(mul(res[i+1][j],\
    \ base2) + s[i][j]);\r\n      }\r\n    }\r\n    for(int j = 0; j < m; ++j){\r\n\
    \      for(int i = 0; i < n; ++i){\r\n        res[i+1][j+1] = cal_mod(mul(res[i][j+1],\
    \ base1) + res[i+1][j+1]);\r\n      }\r\n    }\r\n    return res;\r\n  }\r\n\r\
    \n  template<typename T>\r\n  vector<vector<uint64_t>> build(const vector<vector<T>>\
    \ &s) const {\r\n    int n = int(s.size()), m = int(s[0].size());\r\n    vector<vector<uint64_t>>\
    \ res(n + 1, vector<uint64_t>(m + 1));\r\n    for(int i = 0; i < n; ++i){\r\n\
    \      for(int j = 0; j < m; ++j){\r\n        res[i+1][j+1] = cal_mod(mul(res[i+1][j],\
    \ base2) + s[i][j]);\r\n      }\r\n    }\r\n    for(int j = 0; j < m; ++j){\r\n\
    \      for(int i = 0; i < n; ++i){\r\n        res[i+1][j+1] = cal_mod(mul(res[i][j+1],\
    \ base1) + res[i+1][j+1]);\r\n      }\r\n    }\r\n    return res;\r\n  }\r\n\r\
    \n  uint64_t query(const vector<vector<uint64_t>> &s, int l, int r, int d, int\
    \ u){\r\n    expand1(r - l);\r\n    expand2(u - d);\r\n    uint64_t p1 = pow_table1[r-l],\
    \ p2 = pow_table2[u-d];\r\n    \r\n    return cal_mod(cal_mod(s[r][u] + mod*4\
    \ - cal_mod(mul(s[r][d], p2)))\r\n      + cal_mod(mul(s[l][d], cal_mod(mul(p1,\
    \ p2))) + mod*4 - cal_mod(mul(s[l][u], p1)))\r\n      );\r\n  }\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: string/RollingHash2D.cpp
  requiredBy: []
  timestamp: '2023-02-10 14:54:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: string/RollingHash2D.cpp
layout: document
redirect_from:
- /library/string/RollingHash2D.cpp
- /library/string/RollingHash2D.cpp.html
title: string/RollingHash2D.cpp
---
