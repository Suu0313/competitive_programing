---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/prime/count_primes.cpp
    title: math/prime/count_primes.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/counting_primes
    links:
    - https://judge.yosupo.jp/problem/counting_primes
  bundledCode: "#line 1 \"test/verify/lc/counting_primes.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/counting_primes\"\n\n#include <bits/stdc++.h>\n\
    using namespace std;\n\n#line 2 \"math/prime/count_primes.cpp\"\n\r\nint64_t count_primes(int64_t\
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
    \    ans += (m - sum) * sign;\r\n  }\r\n  return ans;\r\n};\r\n#line 7 \"test/verify/lc/counting_primes.test.cpp\"\
    \n\nint main(){\n  int64_t n; cin >> n;\n  cout << count_primes(n) << \"\\n\"\
    ;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/counting_primes\"\n\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n\n#include \"math/prime/count_primes.cpp\"\
    \n\nint main(){\n  int64_t n; cin >> n;\n  cout << count_primes(n) << \"\\n\"\
    ;\n}"
  dependsOn:
  - math/prime/count_primes.cpp
  isVerificationFile: true
  path: test/verify/lc/counting_primes.test.cpp
  requiredBy: []
  timestamp: '2023-08-02 21:16:16+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/verify/lc/counting_primes.test.cpp
layout: document
redirect_from:
- /verify/test/verify/lc/counting_primes.test.cpp
- /verify/test/verify/lc/counting_primes.test.cpp.html
title: test/verify/lc/counting_primes.test.cpp
---
