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
  code: "class SegmentTree:\n  def __init__(self, v, e, op):\n    self.sz = len(v)\n\
    \    self.e = e\n    self.op = op\n    self.n = 1\n    while self.n < self.sz:\n\
    \      self.n <<= 1\n    self.node = [e]*(self.n*2)\n\n    for i in range(self.sz):\n\
    \      self.node[i+self.n] = v[i]\n    \n    for i in range(self.n-1, -1, -1):\n\
    \      self.node[i] = self.op(self.node[i*2], self.node[i*2+1])\n  \n  def at(self,\
    \ k):\n    return self.node[k+self.n]\n  \n  def change(self, k, x):\n    k +=\
    \ self.n\n    self.node[k] = x\n    while k > 1:\n      k >>= 1\n      self.node[k]\
    \ = self.op(self.node[k*2], self.node[k*2+1])\n\n\n  def query(self, a, b):\n\
    \    l = self.e\n    r = self.e\n    a += self.n\n    b += self.n\n    while a\
    \ < b:\n      if a&1 == 1:\n        l = self.op(l, self.node[a])\n        a +=\
    \ 1\n      if b&1 == 1:\n        b -= 1\n        r = self.op(self.node[b], r)\n\
    \      a >>= 1\n      b >>= 1\n    return self.op(l, r)\n"
  dependsOn: []
  isVerificationFile: false
  path: pycode/segtree.py
  requiredBy: []
  timestamp: '2021-02-27 18:43:19+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: pycode/segtree.py
layout: document
redirect_from:
- /library/pycode/segtree.py
- /library/pycode/segtree.py.html
title: pycode/segtree.py
---
