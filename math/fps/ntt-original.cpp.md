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
  bundledCode: "#line 2 \"math/fps/ntt-original.cpp\"\n\r\ntemplate<class modint>\r\
    \nstruct NTT{\r\n  static int ps, cnt;\r\n  static modint root, zeta;\r\n  static\
    \ modint omegas[30], invomegas[30];\r\n\r\n  static int bsf(unsigned int n) {\
    \ return __builtin_ctz(n); }\r\n\r\n  static constexpr long long pow_mod(long\
    \ long x, long long n, int m) {\r\n    if (m == 1) return 0;\r\n    unsigned int\
    \ _m = (unsigned int)(m);\r\n    unsigned long long r = 1;\r\n    x %= m;\r\n\
    \    if (x < 0) x += m;\r\n    while (n) {\r\n        if (n & 1) r = (r * x) %\
    \ _m;\r\n        x = (x * x) % _m; n >>= 1;\r\n    }\r\n    return r;\r\n  }\r\
    \n\r\n  static constexpr int primitive_root(int m){\r\n    if (m == 2) return\
    \ 1;\r\n    if (m == 167772161) return 3;\r\n    if (m == 469762049) return 3;\r\
    \n    if (m == 754974721) return 11;\r\n    if (m == 998244353) return 3;\r\n\
    \    int divs[20] = {};\r\n    divs[0] = 2;\r\n    int cnt = 1;\r\n    int x =\
    \ (m-1) / 2;\r\n    while(x%2 == 0) x >>= 1;\r\n    for(int i=3; (long long)(i)*i\
    \ <= x; i+=2){\r\n      if(x%i == 0){\r\n        divs[cnt++] = i;\r\n        while\
    \ (x % i == 0) x /= i;\r\n      }\r\n    }\r\n    if(x > 1) divs[cnt++] = x;\r\
    \n\r\n    for (int g = 2;; g++) {\r\n        bool ok = true;\r\n        for (int\
    \ i = 0; i < cnt; i++) {\r\n            if (pow_mod(g, (m - 1) / divs[i], m) ==\
    \ 1) {\r\n                ok = false;\r\n                break;\r\n          \
    \  }\r\n        }\r\n        if (ok) return g;\r\n    }\r\n  }\r\n\r\n  static\
    \ void precalculate(){\r\n    static bool precalculated = false;\r\n    if(precalculated)\
    \ return;\r\n    precalculated = true;\r\n    int mod = modint::get_mod();\r\n\
    \    cnt = bsf(mod - 1);\r\n    ps =  (mod - 1) >> cnt;\r\n    root = primitive_root(mod);\r\
    \n    zeta = root.pow(ps);\r\n    omegas[cnt] = zeta;\r\n    invomegas[cnt] =\
    \ zeta.inverse();\r\n    for(int i = cnt - 1; i >= 0; --i){\r\n      omegas[i]\
    \ = omegas[i + 1] * omegas[i + 1];\r\n      invomegas[i] = invomegas[i + 1] *\
    \ invomegas[i + 1];\r\n    }\r\n  }\r\n\r\n  static void ntt(vector<modint> &a,\
    \ int k){\r\n    int n = 1 << k;\r\n    int i = k - 1;\r\n    if(k & 1){\r\n \
    \     modint omega = 1;\r\n      for(int j = 0, m = (1 << i); j < m; ++j){\r\n\
    \        modint u = a[j], t = a[j + m];\r\n        a[j] = u + t; a[j + m] = (u\
    \ - t) * omega;\r\n        omega *= omegas[i + 1];\r\n      }\r\n      --i;\r\n\
    \    }\r\n    \r\n    for(; i >= 0; i -= 2){\r\n      modint omega1 = 1, omega_m1\
    \ = omegas[i];\r\n      modint omega2 = 1, iomega2 = omegas[2], omega_m2 = omegas[i\
    \ + 1];\r\n      for(int j = 0, m = (1 << (i - 1)); j < m; ++j){\r\n        for(int\
    \ l = j; l < n; l += m * 4){\r\n          modint u1 = a[l] + a[l + m * 2], u2\
    \ = (a[l] - a[l + m * 2]) * omega2;\r\n          modint t1 = a[l + m] + a[l +\
    \ m * 3], t2 = (a[l + m] - a[l + m * 3]) * iomega2;\r\n\r\n          a[l] = u1\
    \ + t1; a[l + m] = (u1 - t1) * omega1;\r\n          a[l + m * 2] = u2 + t2; a[l\
    \ + m * 3] = (u2 - t2) * omega1;\r\n        }\r\n        omega1 *= omega_m1;\r\
    \n        omega2 *= omega_m2;\r\n        iomega2 *= omega_m2;\r\n      }\r\n \
    \   }\r\n  }\r\n\r\n  static void invntt(vector<modint> &a, int k){\r\n    int\
    \ n = 1 << k;\r\n    int i = 0;\r\n    if(k & 1){\r\n      for(int l = 0; l <\
    \ n; l += 2){\r\n        modint u = a[l], t = a[l + 1];\r\n        a[l] = u +\
    \ t; a[l + 1] = u - t;\r\n      }\r\n      ++i;\r\n    }\r\n\r\n    for(; i <\
    \ k; i += 2){\r\n      modint omega1 = 1, omega2 = 1, iomega2 = invomegas[2],\
    \ omega_m1 = invomegas[i + 1], omega_m2 = invomegas[i + 2];\r\n      for(int j\
    \ = 0, m = (1 << i); j < m; ++j){\r\n        for(int l = j; l < n; l += m * 4){\r\
    \n          modint u = omega1 * a[l + m], t = omega1 * a[l + m * 3];\r\n     \
    \     modint u1 = a[l] + u, t1 = a[l] - u;\r\n          modint u2 = a[l + m *\
    \ 2] + t, t2 = a[l + m * 2] - t;\r\n\r\n          a[l] = u1 + (u2 *= omega2);\
    \ a[l + m * 2] = u1 - u2;\r\n          a[l + m] = t1 + (t2 *= iomega2); a[l +\
    \ m * 3] = t1 - t2;\r\n        }\r\n        omega1 *= omega_m1;\r\n        omega2\
    \ *= omega_m2;\r\n        iomega2 *= omega_m2;\r\n      }\r\n    }\r\n  }\r\n\r\
    \n  static vector<modint> multiply_native(const vector<modint> &a, const vector<modint>\
    \ &b){\r\n    int n = int(a.size()), m = int(b.size());\r\n    vector<modint>\
    \ ans(n + m - 1);\r\n    for(int i = 0; i < n; i++)\r\n      for(int j = 0; j\
    \ < m; j++)\r\n        ans[i + j] += a[i] * b[j];\r\n    return ans;\r\n  }\r\n\
    \r\n\r\n  static vector<modint> multiply(vector<modint> a, vector<modint> b){\r\
    \n    int n = int(a.size()), m = int(b.size());\r\n    if(min(n, m) <= 60) return\
    \ multiply_native(a, b);\r\n    precalculate();\r\n    int k = 0;\r\n    while((n\
    \ + m - 1) > (1 << k)) ++k;\r\n    a.resize(1 << k); b.resize(1 << k);\r\n   \
    \ ntt(a, k); ntt(b, k);\r\n    for(int i = 0; i < (1 << k); ++i) a[i] *= b[i];\r\
    \n    invntt(a, k);\r\n    a.resize(n + m - 1);\r\n    modint inv2 = modint(1\
    \ << k).inverse();\r\n    for(auto&&e : a) e *= inv2;\r\n    return a;\r\n  }\r\
    \n};\r\n\r\ntemplate<class modint> int NTT<modint>::ps = 0;\r\ntemplate<class\
    \ modint> int NTT<modint>::cnt = 0;\r\ntemplate<class modint> modint NTT<modint>::root\
    \ = 0;\r\ntemplate<class modint> modint NTT<modint>::zeta = 0;\r\ntemplate<class\
    \ modint> modint NTT<modint>::omegas[] = {};\r\ntemplate<class modint> modint\
    \ NTT<modint>::invomegas[] = {};\r\n"
  code: "#pragma once\r\n\r\ntemplate<class modint>\r\nstruct NTT{\r\n  static int\
    \ ps, cnt;\r\n  static modint root, zeta;\r\n  static modint omegas[30], invomegas[30];\r\
    \n\r\n  static int bsf(unsigned int n) { return __builtin_ctz(n); }\r\n\r\n  static\
    \ constexpr long long pow_mod(long long x, long long n, int m) {\r\n    if (m\
    \ == 1) return 0;\r\n    unsigned int _m = (unsigned int)(m);\r\n    unsigned\
    \ long long r = 1;\r\n    x %= m;\r\n    if (x < 0) x += m;\r\n    while (n) {\r\
    \n        if (n & 1) r = (r * x) % _m;\r\n        x = (x * x) % _m; n >>= 1;\r\
    \n    }\r\n    return r;\r\n  }\r\n\r\n  static constexpr int primitive_root(int\
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
    \ g;\r\n    }\r\n  }\r\n\r\n  static void precalculate(){\r\n    static bool precalculated\
    \ = false;\r\n    if(precalculated) return;\r\n    precalculated = true;\r\n \
    \   int mod = modint::get_mod();\r\n    cnt = bsf(mod - 1);\r\n    ps =  (mod\
    \ - 1) >> cnt;\r\n    root = primitive_root(mod);\r\n    zeta = root.pow(ps);\r\
    \n    omegas[cnt] = zeta;\r\n    invomegas[cnt] = zeta.inverse();\r\n    for(int\
    \ i = cnt - 1; i >= 0; --i){\r\n      omegas[i] = omegas[i + 1] * omegas[i + 1];\r\
    \n      invomegas[i] = invomegas[i + 1] * invomegas[i + 1];\r\n    }\r\n  }\r\n\
    \r\n  static void ntt(vector<modint> &a, int k){\r\n    int n = 1 << k;\r\n  \
    \  int i = k - 1;\r\n    if(k & 1){\r\n      modint omega = 1;\r\n      for(int\
    \ j = 0, m = (1 << i); j < m; ++j){\r\n        modint u = a[j], t = a[j + m];\r\
    \n        a[j] = u + t; a[j + m] = (u - t) * omega;\r\n        omega *= omegas[i\
    \ + 1];\r\n      }\r\n      --i;\r\n    }\r\n    \r\n    for(; i >= 0; i -= 2){\r\
    \n      modint omega1 = 1, omega_m1 = omegas[i];\r\n      modint omega2 = 1, iomega2\
    \ = omegas[2], omega_m2 = omegas[i + 1];\r\n      for(int j = 0, m = (1 << (i\
    \ - 1)); j < m; ++j){\r\n        for(int l = j; l < n; l += m * 4){\r\n      \
    \    modint u1 = a[l] + a[l + m * 2], u2 = (a[l] - a[l + m * 2]) * omega2;\r\n\
    \          modint t1 = a[l + m] + a[l + m * 3], t2 = (a[l + m] - a[l + m * 3])\
    \ * iomega2;\r\n\r\n          a[l] = u1 + t1; a[l + m] = (u1 - t1) * omega1;\r\
    \n          a[l + m * 2] = u2 + t2; a[l + m * 3] = (u2 - t2) * omega1;\r\n   \
    \     }\r\n        omega1 *= omega_m1;\r\n        omega2 *= omega_m2;\r\n    \
    \    iomega2 *= omega_m2;\r\n      }\r\n    }\r\n  }\r\n\r\n  static void invntt(vector<modint>\
    \ &a, int k){\r\n    int n = 1 << k;\r\n    int i = 0;\r\n    if(k & 1){\r\n \
    \     for(int l = 0; l < n; l += 2){\r\n        modint u = a[l], t = a[l + 1];\r\
    \n        a[l] = u + t; a[l + 1] = u - t;\r\n      }\r\n      ++i;\r\n    }\r\n\
    \r\n    for(; i < k; i += 2){\r\n      modint omega1 = 1, omega2 = 1, iomega2\
    \ = invomegas[2], omega_m1 = invomegas[i + 1], omega_m2 = invomegas[i + 2];\r\n\
    \      for(int j = 0, m = (1 << i); j < m; ++j){\r\n        for(int l = j; l <\
    \ n; l += m * 4){\r\n          modint u = omega1 * a[l + m], t = omega1 * a[l\
    \ + m * 3];\r\n          modint u1 = a[l] + u, t1 = a[l] - u;\r\n          modint\
    \ u2 = a[l + m * 2] + t, t2 = a[l + m * 2] - t;\r\n\r\n          a[l] = u1 + (u2\
    \ *= omega2); a[l + m * 2] = u1 - u2;\r\n          a[l + m] = t1 + (t2 *= iomega2);\
    \ a[l + m * 3] = t1 - t2;\r\n        }\r\n        omega1 *= omega_m1;\r\n    \
    \    omega2 *= omega_m2;\r\n        iomega2 *= omega_m2;\r\n      }\r\n    }\r\
    \n  }\r\n\r\n  static vector<modint> multiply_native(const vector<modint> &a,\
    \ const vector<modint> &b){\r\n    int n = int(a.size()), m = int(b.size());\r\
    \n    vector<modint> ans(n + m - 1);\r\n    for(int i = 0; i < n; i++)\r\n   \
    \   for(int j = 0; j < m; j++)\r\n        ans[i + j] += a[i] * b[j];\r\n    return\
    \ ans;\r\n  }\r\n\r\n\r\n  static vector<modint> multiply(vector<modint> a, vector<modint>\
    \ b){\r\n    int n = int(a.size()), m = int(b.size());\r\n    if(min(n, m) <=\
    \ 60) return multiply_native(a, b);\r\n    precalculate();\r\n    int k = 0;\r\
    \n    while((n + m - 1) > (1 << k)) ++k;\r\n    a.resize(1 << k); b.resize(1 <<\
    \ k);\r\n    ntt(a, k); ntt(b, k);\r\n    for(int i = 0; i < (1 << k); ++i) a[i]\
    \ *= b[i];\r\n    invntt(a, k);\r\n    a.resize(n + m - 1);\r\n    modint inv2\
    \ = modint(1 << k).inverse();\r\n    for(auto&&e : a) e *= inv2;\r\n    return\
    \ a;\r\n  }\r\n};\r\n\r\ntemplate<class modint> int NTT<modint>::ps = 0;\r\ntemplate<class\
    \ modint> int NTT<modint>::cnt = 0;\r\ntemplate<class modint> modint NTT<modint>::root\
    \ = 0;\r\ntemplate<class modint> modint NTT<modint>::zeta = 0;\r\ntemplate<class\
    \ modint> modint NTT<modint>::omegas[] = {};\r\ntemplate<class modint> modint\
    \ NTT<modint>::invomegas[] = {};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: math/fps/ntt-original.cpp
  requiredBy: []
  timestamp: '2023-02-10 14:54:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/fps/ntt-original.cpp
layout: document
redirect_from:
- /library/math/fps/ntt-original.cpp
- /library/math/fps/ntt-original.cpp.html
title: math/fps/ntt-original.cpp
---
