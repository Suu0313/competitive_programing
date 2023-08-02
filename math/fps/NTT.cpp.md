---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: math/convolution/and_sum_01.cpp
    title: c[k] = sum (a[i + k] & b[i])
  - icon: ':warning:'
    path: math/convolution/or_sum_01.cpp
    title: c[k] = sum (a[i + k] | b[i])
  - icon: ':warning:'
    path: math/fps/FFT-ntt.cpp
    title: math/fps/FFT-ntt.cpp
  - icon: ':warning:'
    path: math/fps/FastKitamasa.cpp
    title: math/fps/FastKitamasa.cpp
  - icon: ':warning:'
    path: math/fps/Formalpowerseries.cpp
    title: math/fps/Formalpowerseries.cpp
  - icon: ':warning:'
    path: math/fps/GeneratingFunction.cpp
    title: math/fps/GeneratingFunction.cpp
  - icon: ':warning:'
    path: math/fps/SemiRelaxedConvolution.cpp
    title: math/fps/SemiRelaxedConvolution.cpp
  - icon: ':warning:'
    path: math/fps/fps-famous-series/bernoulli_number.cpp
    title: math/fps/fps-famous-series/bernoulli_number.cpp
  - icon: ':warning:'
    path: math/fps/fps-famous-series/partition_function_table_fps.cpp
    title: math/fps/fps-famous-series/partition_function_table_fps.cpp
  - icon: ':warning:'
    path: math/fps/fps-famous-series/stirling_number_of_the_second_kind.cpp
    title: math/fps/fps-famous-series/stirling_number_of_the_second_kind.cpp
  - icon: ':warning:'
    path: math/fps/multipoint_evaluation.cpp
    title: math/fps/multipoint_evaluation.cpp
  - icon: ':warning:'
    path: math/fps/p_subset_sum.cpp
    title: math/fps/p_subset_sum.cpp
  - icon: ':warning:'
    path: math/fps/polynomial_interpolation.cpp
    title: math/fps/polynomial_interpolation.cpp
  - icon: ':warning:'
    path: math/fps/taylor_shift.cpp
    title: math/fps/taylor_shift.cpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/fps/NTT.cpp\"\n\r\nnamespace NTT{\r\n\r\n  int bsf(unsigned\
    \ int n) { return __builtin_ctz(n); }\r\n\r\n  long long pow_mod(long long x,\
    \ long long n, int m) {\r\n    if (m == 1) return 0;\r\n    unsigned int _m =\
    \ (unsigned int)(m);\r\n    unsigned long long r = 1;\r\n    x %= m;\r\n    if\
    \ (x < 0) x += m;\r\n    while (n) {\r\n        if (n & 1) r = (r * x) % _m;\r\
    \n        x = (x * x) % _m;\r\n        n >>= 1;\r\n    }\r\n    return r;\r\n\
    \  }\r\n\r\n  int primitive_root(int m){\r\n    if (m == 2) return 1;\r\n    if\
    \ (m == 167772161) return 3;\r\n    if (m == 469762049) return 3;\r\n    if (m\
    \ == 754974721) return 11;\r\n    if (m == 998244353) return 3;\r\n    int divs[20]\
    \ = {};\r\n    divs[0] = 2;\r\n    int cnt = 1;\r\n    int x = (m-1) / 2;\r\n\
    \    while(x%2 == 0) x >>= 1;\r\n    for(int i=3; (long long)(i)*i <= x; i+=2){\r\
    \n      if(x%i == 0){\r\n        divs[cnt++] = i;\r\n        while (x % i == 0)\
    \ x /= i;\r\n      }\r\n    }\r\n    if(x > 1) divs[cnt++] = x;\r\n\r\n    for\
    \ (int g = 2;; g++) {\r\n        bool ok = true;\r\n        for (int i = 0; i\
    \ < cnt; i++) {\r\n            if (pow_mod(g, (m - 1) / divs[i], m) == 1) {\r\n\
    \                ok = false;\r\n                break;\r\n            }\r\n  \
    \      }\r\n        if (ok) return g;\r\n    }\r\n  }\r\n\r\n  template<typename\
    \ Mint>\r\n  void butterfly(std::vector<Mint>& a){\r\n    static int g = primitive_root(Mint::get_mod());\r\
    \n    int n = int(a.size());\r\n    int h = 0;\r\n    while(n > (1<<h)) h++;\r\
    \n\r\n    static bool first = true;\r\n    static Mint sum_e[30];\r\n\r\n    if\
    \ (first) {\r\n        first = false;\r\n        Mint es[30], ies[30];  // es[i]^(2^(2+i))\
    \ == 1\r\n        int cnt2 = bsf(Mint::get_mod() - 1);\r\n        Mint e = Mint(g).pow((Mint::get_mod()\
    \ - 1) >> cnt2), ie = e.inverse();\r\n        for (int i = cnt2; i >= 2; i--)\
    \ {\r\n            // e^(2^i) == 1\r\n            es[i - 2] = e;\r\n         \
    \   ies[i - 2] = ie;\r\n            e *= e;\r\n            ie *= ie;\r\n     \
    \   }\r\n        Mint now = 1;\r\n        for (int i = 0; i < cnt2 - 2; i++) {\r\
    \n            sum_e[i] = es[i] * now;\r\n            now *= ies[i];\r\n      \
    \  }\r\n    }\r\n    for (int ph = 1; ph <= h; ph++) {\r\n        int w = 1 <<\
    \ (ph - 1), p = 1 << (h - ph);\r\n        Mint now = 1;\r\n        for (int s\
    \ = 0; s < w; s++) {\r\n            int offset = s << (h - ph + 1);\r\n      \
    \      for (int i = 0; i < p; i++) {\r\n                auto l = a[i + offset];\r\
    \n                auto r = a[i + offset + p] * now;\r\n                a[i + offset]\
    \ = l + r;\r\n                a[i + offset + p] = l - r;\r\n            }\r\n\
    \            now *= sum_e[bsf(~(unsigned int)(s))];\r\n        }\r\n    }\r\n\
    \  }\r\n\r\n  template<typename Mint>\r\n  void butterfly_inv(std::vector<Mint>&\
    \ a){\r\n    static int g = primitive_root(Mint::get_mod());\r\n    int n = int(a.size());\r\
    \n    int h = 0;\r\n    while(n > (1<<h)) h++;\r\n\r\n    static bool first =\
    \ true;\r\n    static Mint sum_ie[30];\r\n\r\n    if (first) {\r\n        first\
    \ = false;\r\n        Mint es[30], ies[30];  // es[i]^(2^(2+i)) == 1\r\n     \
    \   int cnt2 = bsf(Mint::get_mod() - 1);\r\n        Mint e = Mint(g).pow((Mint::get_mod()\
    \ - 1) >> cnt2), ie = e.inverse();\r\n        for (int i = cnt2; i >= 2; i--)\
    \ {\r\n            // e^(2^i) == 1\r\n            es[i - 2] = e;\r\n         \
    \   ies[i - 2] = ie;\r\n            e *= e;\r\n            ie *= ie;\r\n     \
    \   }\r\n        Mint now = 1;\r\n        for (int i = 0; i < cnt2 - 2; i++) {\r\
    \n            sum_ie[i] = ies[i] * now;\r\n            now *= es[i];\r\n     \
    \   }\r\n    }\r\n    for (int ph = h; ph >= 1; ph--) {\r\n        int w = 1 <<\
    \ (ph - 1), p = 1 << (h - ph);\r\n        Mint inow = 1;\r\n        for (int s\
    \ = 0; s < w; s++) {\r\n            int offset = s << (h - ph + 1);\r\n      \
    \      for (int i = 0; i < p; i++) {\r\n                auto l = a[i + offset];\r\
    \n                auto r = a[i + offset + p];\r\n                a[i + offset]\
    \ = l + r;\r\n                a[i + offset + p] = (unsigned long long)(Mint::get_mod()\
    \ + l.x - r.x) *\r\n                    inow.x;\r\n            }\r\n         \
    \   inow *= sum_ie[bsf(~(unsigned int)(s))];\r\n        }\r\n    }\r\n  }\r\n\
    \  \r\n  template<typename Mint>\r\n  vector<Mint> multiply(vector<Mint> a, vector<Mint>\
    \ b){\r\n    int n = int(a.size()), m = int(b.size());\r\n    if(min(n,m) <= 60){\r\
    \n      if(n < m){\r\n        swap(n, m); swap(a, b);\r\n      }\r\n      vector<Mint>\
    \ ans(n + m - 1);\r\n      for(int i = 0; i < n; i++){\r\n        for(int j =\
    \ 0; j < m; j++){\r\n          ans[i + j] += a[i] * b[j];\r\n        }\r\n   \
    \   }\r\n      return ans;\r\n    }\r\n    int z = 0;\r\n    while(n+m-1 > (1<<z))\
    \ z++;\r\n    z = 1 << z;\r\n    a.resize(z); butterfly(a);\r\n    b.resize(z);\
    \ butterfly(b);\r\n\r\n    for(int i=0; i<z; i++) a[i] *= b[i];\r\n    butterfly_inv(a);\r\
    \n    a.resize(n + m - 1);\r\n    Mint iz = Mint(z).inverse();\r\n    for (int\
    \ i = 0; i < n + m - 1; i++) a[i] *= iz;\r\n    return a;\r\n  }\r\n}\r\n"
  code: "#pragma once\r\n\r\nnamespace NTT{\r\n\r\n  int bsf(unsigned int n) { return\
    \ __builtin_ctz(n); }\r\n\r\n  long long pow_mod(long long x, long long n, int\
    \ m) {\r\n    if (m == 1) return 0;\r\n    unsigned int _m = (unsigned int)(m);\r\
    \n    unsigned long long r = 1;\r\n    x %= m;\r\n    if (x < 0) x += m;\r\n \
    \   while (n) {\r\n        if (n & 1) r = (r * x) % _m;\r\n        x = (x * x)\
    \ % _m;\r\n        n >>= 1;\r\n    }\r\n    return r;\r\n  }\r\n\r\n  int primitive_root(int\
    \ m){\r\n    if (m == 2) return 1;\r\n    if (m == 167772161) return 3;\r\n  \
    \  if (m == 469762049) return 3;\r\n    if (m == 754974721) return 11;\r\n   \
    \ if (m == 998244353) return 3;\r\n    int divs[20] = {};\r\n    divs[0] = 2;\r\
    \n    int cnt = 1;\r\n    int x = (m-1) / 2;\r\n    while(x%2 == 0) x >>= 1;\r\
    \n    for(int i=3; (long long)(i)*i <= x; i+=2){\r\n      if(x%i == 0){\r\n  \
    \      divs[cnt++] = i;\r\n        while (x % i == 0) x /= i;\r\n      }\r\n \
    \   }\r\n    if(x > 1) divs[cnt++] = x;\r\n\r\n    for (int g = 2;; g++) {\r\n\
    \        bool ok = true;\r\n        for (int i = 0; i < cnt; i++) {\r\n      \
    \      if (pow_mod(g, (m - 1) / divs[i], m) == 1) {\r\n                ok = false;\r\
    \n                break;\r\n            }\r\n        }\r\n        if (ok) return\
    \ g;\r\n    }\r\n  }\r\n\r\n  template<typename Mint>\r\n  void butterfly(std::vector<Mint>&\
    \ a){\r\n    static int g = primitive_root(Mint::get_mod());\r\n    int n = int(a.size());\r\
    \n    int h = 0;\r\n    while(n > (1<<h)) h++;\r\n\r\n    static bool first =\
    \ true;\r\n    static Mint sum_e[30];\r\n\r\n    if (first) {\r\n        first\
    \ = false;\r\n        Mint es[30], ies[30];  // es[i]^(2^(2+i)) == 1\r\n     \
    \   int cnt2 = bsf(Mint::get_mod() - 1);\r\n        Mint e = Mint(g).pow((Mint::get_mod()\
    \ - 1) >> cnt2), ie = e.inverse();\r\n        for (int i = cnt2; i >= 2; i--)\
    \ {\r\n            // e^(2^i) == 1\r\n            es[i - 2] = e;\r\n         \
    \   ies[i - 2] = ie;\r\n            e *= e;\r\n            ie *= ie;\r\n     \
    \   }\r\n        Mint now = 1;\r\n        for (int i = 0; i < cnt2 - 2; i++) {\r\
    \n            sum_e[i] = es[i] * now;\r\n            now *= ies[i];\r\n      \
    \  }\r\n    }\r\n    for (int ph = 1; ph <= h; ph++) {\r\n        int w = 1 <<\
    \ (ph - 1), p = 1 << (h - ph);\r\n        Mint now = 1;\r\n        for (int s\
    \ = 0; s < w; s++) {\r\n            int offset = s << (h - ph + 1);\r\n      \
    \      for (int i = 0; i < p; i++) {\r\n                auto l = a[i + offset];\r\
    \n                auto r = a[i + offset + p] * now;\r\n                a[i + offset]\
    \ = l + r;\r\n                a[i + offset + p] = l - r;\r\n            }\r\n\
    \            now *= sum_e[bsf(~(unsigned int)(s))];\r\n        }\r\n    }\r\n\
    \  }\r\n\r\n  template<typename Mint>\r\n  void butterfly_inv(std::vector<Mint>&\
    \ a){\r\n    static int g = primitive_root(Mint::get_mod());\r\n    int n = int(a.size());\r\
    \n    int h = 0;\r\n    while(n > (1<<h)) h++;\r\n\r\n    static bool first =\
    \ true;\r\n    static Mint sum_ie[30];\r\n\r\n    if (first) {\r\n        first\
    \ = false;\r\n        Mint es[30], ies[30];  // es[i]^(2^(2+i)) == 1\r\n     \
    \   int cnt2 = bsf(Mint::get_mod() - 1);\r\n        Mint e = Mint(g).pow((Mint::get_mod()\
    \ - 1) >> cnt2), ie = e.inverse();\r\n        for (int i = cnt2; i >= 2; i--)\
    \ {\r\n            // e^(2^i) == 1\r\n            es[i - 2] = e;\r\n         \
    \   ies[i - 2] = ie;\r\n            e *= e;\r\n            ie *= ie;\r\n     \
    \   }\r\n        Mint now = 1;\r\n        for (int i = 0; i < cnt2 - 2; i++) {\r\
    \n            sum_ie[i] = ies[i] * now;\r\n            now *= es[i];\r\n     \
    \   }\r\n    }\r\n    for (int ph = h; ph >= 1; ph--) {\r\n        int w = 1 <<\
    \ (ph - 1), p = 1 << (h - ph);\r\n        Mint inow = 1;\r\n        for (int s\
    \ = 0; s < w; s++) {\r\n            int offset = s << (h - ph + 1);\r\n      \
    \      for (int i = 0; i < p; i++) {\r\n                auto l = a[i + offset];\r\
    \n                auto r = a[i + offset + p];\r\n                a[i + offset]\
    \ = l + r;\r\n                a[i + offset + p] = (unsigned long long)(Mint::get_mod()\
    \ + l.x - r.x) *\r\n                    inow.x;\r\n            }\r\n         \
    \   inow *= sum_ie[bsf(~(unsigned int)(s))];\r\n        }\r\n    }\r\n  }\r\n\
    \  \r\n  template<typename Mint>\r\n  vector<Mint> multiply(vector<Mint> a, vector<Mint>\
    \ b){\r\n    int n = int(a.size()), m = int(b.size());\r\n    if(min(n,m) <= 60){\r\
    \n      if(n < m){\r\n        swap(n, m); swap(a, b);\r\n      }\r\n      vector<Mint>\
    \ ans(n + m - 1);\r\n      for(int i = 0; i < n; i++){\r\n        for(int j =\
    \ 0; j < m; j++){\r\n          ans[i + j] += a[i] * b[j];\r\n        }\r\n   \
    \   }\r\n      return ans;\r\n    }\r\n    int z = 0;\r\n    while(n+m-1 > (1<<z))\
    \ z++;\r\n    z = 1 << z;\r\n    a.resize(z); butterfly(a);\r\n    b.resize(z);\
    \ butterfly(b);\r\n\r\n    for(int i=0; i<z; i++) a[i] *= b[i];\r\n    butterfly_inv(a);\r\
    \n    a.resize(n + m - 1);\r\n    Mint iz = Mint(z).inverse();\r\n    for (int\
    \ i = 0; i < n + m - 1; i++) a[i] *= iz;\r\n    return a;\r\n  }\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: math/fps/NTT.cpp
  requiredBy:
  - math/fps/taylor_shift.cpp
  - math/fps/GeneratingFunction.cpp
  - math/fps/FFT-ntt.cpp
  - math/fps/FastKitamasa.cpp
  - math/fps/fps-famous-series/partition_function_table_fps.cpp
  - math/fps/fps-famous-series/stirling_number_of_the_second_kind.cpp
  - math/fps/fps-famous-series/bernoulli_number.cpp
  - math/fps/SemiRelaxedConvolution.cpp
  - math/fps/polynomial_interpolation.cpp
  - math/fps/multipoint_evaluation.cpp
  - math/fps/Formalpowerseries.cpp
  - math/fps/p_subset_sum.cpp
  - math/convolution/or_sum_01.cpp
  - math/convolution/and_sum_01.cpp
  timestamp: '2023-02-10 14:54:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/fps/NTT.cpp
layout: document
redirect_from:
- /library/math/fps/NTT.cpp
- /library/math/fps/NTT.cpp.html
title: math/fps/NTT.cpp
---
