---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/verify/lc/counting_primes.test.cpp
    title: test/verify/lc/counting_primes.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/prime/count_primes.cpp\"\n\r\nint64_t count_primes(int64_t\
    \ n){\r\n  int64_t y = pow(n, 0.38);\r\n  if(n < 100) y = 1;\r\n  int64_t iy =\
    \ n / y;\r\n\r\n  vector<int64_t> min_factor(iy + 1, -1), primes;\r\n  for(int64_t\
    \ i = 2; i <= iy; ++i){\r\n    if(min_factor[i] == -1){\r\n      min_factor[i]\
    \ = primes.size();\r\n      primes.push_back(i);\r\n    }\r\n    for(int j = 0;\
    \ j <= min_factor[i]; ++j){\r\n      int64_t p = primes[j];\r\n      if(i * p\
    \ > iy) break;\r\n      min_factor[i * p] = j;\r\n      if(i % p == 0) break;\r\
    \n    }\r\n  }\r\n  int64_t pi_iy = int64_t(primes.size());\r\n  if(n < 100) return\
    \ pi_iy;\r\n\r\n  int64_t pi_y = 0;\r\n  for(auto&p : primes){\r\n    if(p > y)\
    \ break;\r\n    ++pi_y;\r\n  }\r\n\r\n  int64_t ans = pi_y - 1;\r\n\r\n  for(int\
    \ i = pi_y+1, j = pi_iy-1; i < pi_iy; ++i){\r\n    while(i <= j && primes[i-1]*primes[j-1]\
    \ > n) --j;\r\n    if(j < i) break;\r\n    ans -= j - i + 1;\r\n  }\r\n\r\n  vector<tuple<int64_t,\
    \ int, int>> rem;\r\n\r\n  stack<tuple<int64_t, int, int>> st; st.emplace(n, pi_y,\
    \ 1);\r\n  while(!st.empty()){\r\n    auto[m, a, sign] = st.top(); st.pop();\r\
    \n    if(m == 0) continue;\r\n    if(a == 0){ ans += m * sign; continue; }\r\n\
    \    if(m <= iy){ rem.emplace_back(m, a, sign); continue; }\r\n    st.emplace(m,\
    \ a-1, sign);\r\n    st.emplace(m/primes[a-1], a-1, -sign);\r\n  }\r\n  \r\n \
    \ sort(begin(rem), end(rem));\r\n  \r\n  int cur = 2;\r\n  vector<int> fw(pi_iy\
    \ + 1);\r\n  for(auto&&[m, a, sign] : rem){\r\n    for( ; cur <= m; ++cur){\r\n\
    \      for(int idx = min_factor[cur]+1; idx <= pi_iy; idx += (idx & -idx)){\r\n\
    \        fw[idx] += 1;\r\n      }\r\n    }\r\n    int sum = 0;\r\n    for(int\
    \ idx = a; idx > 0; idx -= (idx & -idx)){\r\n      sum += fw[idx];\r\n    }\r\n\
    \    ans += (m - sum) * sign;\r\n  }\r\n  return ans;\r\n};\r\n"
  code: "#pragma once\r\n\r\nint64_t count_primes(int64_t n){\r\n  int64_t y = pow(n,\
    \ 0.38);\r\n  if(n < 100) y = 1;\r\n  int64_t iy = n / y;\r\n\r\n  vector<int64_t>\
    \ min_factor(iy + 1, -1), primes;\r\n  for(int64_t i = 2; i <= iy; ++i){\r\n \
    \   if(min_factor[i] == -1){\r\n      min_factor[i] = primes.size();\r\n     \
    \ primes.push_back(i);\r\n    }\r\n    for(int j = 0; j <= min_factor[i]; ++j){\r\
    \n      int64_t p = primes[j];\r\n      if(i * p > iy) break;\r\n      min_factor[i\
    \ * p] = j;\r\n      if(i % p == 0) break;\r\n    }\r\n  }\r\n  int64_t pi_iy\
    \ = int64_t(primes.size());\r\n  if(n < 100) return pi_iy;\r\n\r\n  int64_t pi_y\
    \ = 0;\r\n  for(auto&p : primes){\r\n    if(p > y) break;\r\n    ++pi_y;\r\n \
    \ }\r\n\r\n  int64_t ans = pi_y - 1;\r\n\r\n  for(int i = pi_y+1, j = pi_iy-1;\
    \ i < pi_iy; ++i){\r\n    while(i <= j && primes[i-1]*primes[j-1] > n) --j;\r\n\
    \    if(j < i) break;\r\n    ans -= j - i + 1;\r\n  }\r\n\r\n  vector<tuple<int64_t,\
    \ int, int>> rem;\r\n\r\n  stack<tuple<int64_t, int, int>> st; st.emplace(n, pi_y,\
    \ 1);\r\n  while(!st.empty()){\r\n    auto[m, a, sign] = st.top(); st.pop();\r\
    \n    if(m == 0) continue;\r\n    if(a == 0){ ans += m * sign; continue; }\r\n\
    \    if(m <= iy){ rem.emplace_back(m, a, sign); continue; }\r\n    st.emplace(m,\
    \ a-1, sign);\r\n    st.emplace(m/primes[a-1], a-1, -sign);\r\n  }\r\n  \r\n \
    \ sort(begin(rem), end(rem));\r\n  \r\n  int cur = 2;\r\n  vector<int> fw(pi_iy\
    \ + 1);\r\n  for(auto&&[m, a, sign] : rem){\r\n    for( ; cur <= m; ++cur){\r\n\
    \      for(int idx = min_factor[cur]+1; idx <= pi_iy; idx += (idx & -idx)){\r\n\
    \        fw[idx] += 1;\r\n      }\r\n    }\r\n    int sum = 0;\r\n    for(int\
    \ idx = a; idx > 0; idx -= (idx & -idx)){\r\n      sum += fw[idx];\r\n    }\r\n\
    \    ans += (m - sum) * sign;\r\n  }\r\n  return ans;\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: math/prime/count_primes.cpp
  requiredBy: []
  timestamp: '2023-02-10 14:54:58+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/verify/lc/counting_primes.test.cpp
documentation_of: math/prime/count_primes.cpp
layout: document
redirect_from:
- /library/math/prime/count_primes.cpp
- /library/math/prime/count_primes.cpp.html
title: math/prime/count_primes.cpp
---
