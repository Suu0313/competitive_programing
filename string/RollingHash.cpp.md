---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: graph/tree/AHUHash.cpp
    title: graph/tree/AHUHash.cpp
  - icon: ':warning:'
    path: graph/tree/TreeHash.cpp
    title: graph/tree/TreeHash.cpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"string/RollingHash.cpp\"\n\r\nstruct RollingHash{\r\n  static\
    \ constexpr uint64_t mod = (1ull << 61) - 1;\r\n  static constexpr uint64_t mask(int\
    \ k){ return (1ull << k) - 1; }\r\n  static constexpr uint64_t add(uint64_t a,\
    \ uint64_t b){\r\n    return ((a+=b) >= mod) ? (a - mod) : a;\r\n  }\r\n  static\
    \ constexpr uint64_t mul(uint64_t a, uint64_t b){\r\n    uint64_t au = a >> 31,\
    \ ad = a & mask(31);\r\n    uint64_t bu = b >> 31, bd = b & mask(31);\r\n    int64_t\
    \ mid = ad*bu + au*bd;\r\n    uint64_t mu = mid >> 30, md = mid & mask(30);\r\n\
    \    return au*bu*2 + mu + (md << 31) + ad*bd;\r\n  }\r\n  static constexpr uint64_t\
    \ cal_mod(uint64_t x){\r\n    uint64_t res = (x >> 61) + (x & mask(61));\r\n \
    \   return (res>=mod) ? (res-mod) : res;\r\n  }\r\n\r\n  static inline uint64_t\
    \ generate_base(){\r\n    mt19937_64 mt(random_device{}());\r\n    uniform_int_distribution<uint64_t>\
    \ rand(1, mod-1);\r\n    return rand(mt);\r\n  }\r\n\r\n  inline void expand(size_t\
    \ n){\r\n    if(size_t pn = pow_table.size(); pn < n+1){\r\n      pow_table.resize(n\
    \ + 1);\r\n      for(size_t i = pn-1; i < n; ++i){\r\n        pow_table[i+1] =\
    \ cal_mod(mul(pow_table[i], base));\r\n      }\r\n    }\r\n  }\r\n\r\n  const\
    \ uint64_t base;\r\n  vector<uint64_t> pow_table;\r\n\r\n  RollingHash(uint64_t\
    \ base = generate_base()): base(base), pow_table(1,1) {}\r\n\r\n  vector<uint64_t>\
    \ build(const string &s) const {\r\n    int n = int(s.size());\r\n    vector<uint64_t>\
    \ res(n + 1);\r\n    for(int i = 0; i < n; ++i) res[i+1] = cal_mod(mul(res[i],\
    \ base) + s[i]);\r\n    return res;\r\n  }\r\n\r\n  template<typename T>\r\n \
    \ vector<uint64_t> build(const vector<T> &s) const {\r\n    int n = int(s.size());\r\
    \n    vector<uint64_t> res(n + 1);\r\n    for(int i = 0; i < n; ++i) res[i+1]\
    \ = cal_mod(mul(res[i], base) + s[i]);\r\n    return res;\r\n  }\r\n\r\n  uint64_t\
    \ query(const vector<uint64_t> &s, int l = 0, size_t n = string::npos){\r\n  \
    \  n = min(n, s.size()-1 - l);\r\n    expand(n);\r\n    return cal_mod(s[l+n]\
    \ + mod*4 - mul(s[l], pow_table[n]));\r\n  }\r\n\r\n  uint64_t cat(uint64_t hl,\
    \ uint64_t hr, size_t hr_len){\r\n    expand(hr_len);\r\n    return cal_mod(mul(hl,\
    \ pow_table[hr_len]) + hr);\r\n  }\r\n\r\n  int lcp(const vector<uint64_t> &a,\
    \ int la, int ra, const vector<uint64_t> &b, int lb, int rb){\r\n    int n = min(ra\
    \ - la, rb - lb);\r\n    int l = 0, r = n+1;\r\n    while(r-l > 1){\r\n      int\
    \ m = (l+r) >> 1;\r\n      if(query(a, la, m) == query(b, lb, m)) l = m;\r\n \
    \     else r = m;\r\n    }\r\n    return l;\r\n  }\r\n};\r\n"
  code: "#pragma once\r\n\r\nstruct RollingHash{\r\n  static constexpr uint64_t mod\
    \ = (1ull << 61) - 1;\r\n  static constexpr uint64_t mask(int k){ return (1ull\
    \ << k) - 1; }\r\n  static constexpr uint64_t add(uint64_t a, uint64_t b){\r\n\
    \    return ((a+=b) >= mod) ? (a - mod) : a;\r\n  }\r\n  static constexpr uint64_t\
    \ mul(uint64_t a, uint64_t b){\r\n    uint64_t au = a >> 31, ad = a & mask(31);\r\
    \n    uint64_t bu = b >> 31, bd = b & mask(31);\r\n    int64_t mid = ad*bu + au*bd;\r\
    \n    uint64_t mu = mid >> 30, md = mid & mask(30);\r\n    return au*bu*2 + mu\
    \ + (md << 31) + ad*bd;\r\n  }\r\n  static constexpr uint64_t cal_mod(uint64_t\
    \ x){\r\n    uint64_t res = (x >> 61) + (x & mask(61));\r\n    return (res>=mod)\
    \ ? (res-mod) : res;\r\n  }\r\n\r\n  static inline uint64_t generate_base(){\r\
    \n    mt19937_64 mt(random_device{}());\r\n    uniform_int_distribution<uint64_t>\
    \ rand(1, mod-1);\r\n    return rand(mt);\r\n  }\r\n\r\n  inline void expand(size_t\
    \ n){\r\n    if(size_t pn = pow_table.size(); pn < n+1){\r\n      pow_table.resize(n\
    \ + 1);\r\n      for(size_t i = pn-1; i < n; ++i){\r\n        pow_table[i+1] =\
    \ cal_mod(mul(pow_table[i], base));\r\n      }\r\n    }\r\n  }\r\n\r\n  const\
    \ uint64_t base;\r\n  vector<uint64_t> pow_table;\r\n\r\n  RollingHash(uint64_t\
    \ base = generate_base()): base(base), pow_table(1,1) {}\r\n\r\n  vector<uint64_t>\
    \ build(const string &s) const {\r\n    int n = int(s.size());\r\n    vector<uint64_t>\
    \ res(n + 1);\r\n    for(int i = 0; i < n; ++i) res[i+1] = cal_mod(mul(res[i],\
    \ base) + s[i]);\r\n    return res;\r\n  }\r\n\r\n  template<typename T>\r\n \
    \ vector<uint64_t> build(const vector<T> &s) const {\r\n    int n = int(s.size());\r\
    \n    vector<uint64_t> res(n + 1);\r\n    for(int i = 0; i < n; ++i) res[i+1]\
    \ = cal_mod(mul(res[i], base) + s[i]);\r\n    return res;\r\n  }\r\n\r\n  uint64_t\
    \ query(const vector<uint64_t> &s, int l = 0, size_t n = string::npos){\r\n  \
    \  n = min(n, s.size()-1 - l);\r\n    expand(n);\r\n    return cal_mod(s[l+n]\
    \ + mod*4 - mul(s[l], pow_table[n]));\r\n  }\r\n\r\n  uint64_t cat(uint64_t hl,\
    \ uint64_t hr, size_t hr_len){\r\n    expand(hr_len);\r\n    return cal_mod(mul(hl,\
    \ pow_table[hr_len]) + hr);\r\n  }\r\n\r\n  int lcp(const vector<uint64_t> &a,\
    \ int la, int ra, const vector<uint64_t> &b, int lb, int rb){\r\n    int n = min(ra\
    \ - la, rb - lb);\r\n    int l = 0, r = n+1;\r\n    while(r-l > 1){\r\n      int\
    \ m = (l+r) >> 1;\r\n      if(query(a, la, m) == query(b, lb, m)) l = m;\r\n \
    \     else r = m;\r\n    }\r\n    return l;\r\n  }\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: string/RollingHash.cpp
  requiredBy:
  - graph/tree/TreeHash.cpp
  - graph/tree/AHUHash.cpp
  timestamp: '2023-02-10 14:54:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: string/RollingHash.cpp
layout: document
redirect_from:
- /library/string/RollingHash.cpp
- /library/string/RollingHash.cpp.html
title: string/RollingHash.cpp
---
