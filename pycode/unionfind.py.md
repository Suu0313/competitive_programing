---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: py
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.11.4/x64/lib/python3.11/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.4/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/python.py\"\
    , line 96, in bundle\n    raise NotImplementedError\nNotImplementedError\n"
  code: "class UnionFind:\n    def __init__(self, size):\n        self.data = [-1]\
    \ * size\n    def root(self, x):\n        if self.data[x] < 0:\n            return\
    \ x\n        ans = self.root(self.data[x])\n        self.data[x] = ans\n     \
    \   return ans\n    def unite(self, x, y):\n        x = self.root(x)\n       \
    \ y = self.root(y)\n        if x == y:\n            return False\n        if self.data[x]\
    \ > self.data[y]:\n            x, y = y, x\n        self.data[x] += self.data[y]\n\
    \        self.data[y] = x\n        return True\n    def same(self, x, y):\n  \
    \      return self.root(x) == self.root(y)\n"
  dependsOn: []
  isVerificationFile: false
  path: pycode/unionfind.py
  requiredBy: []
  timestamp: '2021-02-27 18:43:47+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: pycode/unionfind.py
layout: document
redirect_from:
- /library/pycode/unionfind.py
- /library/pycode/unionfind.py.html
title: pycode/unionfind.py
---
