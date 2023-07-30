---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: datastructure/heap/DoubleEndedPriorityQueue.cpp
    title: datastructure/heap/DoubleEndedPriorityQueue.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/double_ended_priority_queue
    links:
    - https://judge.yosupo.jp/problem/double_ended_priority_queue
  bundledCode: "#line 1 \"test/verify/lc/double_ended_priority_queue.test.cpp\"\n\
    #define PROBLEM \"https://judge.yosupo.jp/problem/double_ended_priority_queue\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#line 2 \"datastructure/heap/DoubleEndedPriorityQueue.cpp\"\
    \n\r\ntemplate<typename T>\r\nstruct DoubleEndedPriorityQueue{\r\n  DoubleEndedPriorityQueue()\
    \ = default;\r\n  DoubleEndedPriorityQueue(const DoubleEndedPriorityQueue&) =\
    \ default;\r\n  DoubleEndedPriorityQueue(DoubleEndedPriorityQueue&&) = default;\r\
    \n  DoubleEndedPriorityQueue &operator=(const DoubleEndedPriorityQueue&) = default;\r\
    \n  DoubleEndedPriorityQueue &operator=(DoubleEndedPriorityQueue&&) = default;\r\
    \n\r\n  vector<T> c;\r\n  DoubleEndedPriorityQueue(const vector<T> &c): c(c) {\
    \ make_heap(); }\r\n  template<class Iiter>\r\n  DoubleEndedPriorityQueue(Iiter\
    \ first, Iiter last): c(first, last) { make_heap(); }\r\n\r\n  void reserve(size_t\
    \ n){ c.reserve(n); }\r\n  size_t size() const { return c.size(); }\r\n  bool\
    \ empty() const { return c.empty(); }\r\n  explicit operator bool() const { return\
    \ !c.empty(); }\r\n\r\n  const T& get_min() const { return c.at(size() > size_t(1));\
    \ }\r\n\r\n  const T& get_max() const { return c.front(); }\r\n\r\n  void push(const\
    \ T &x){\r\n    c.push_back(x);\r\n    lift_up(c.size() - 1);\r\n  }\r\n\r\n \
    \ template <class... Args>\r\n  void emplace_back(Args&&... args){\r\n    c.emplace_back(args...);\r\
    \n    lift_up(c.size() - 1);\r\n  }\r\n\r\n  void pop_min() {\r\n    if(c.size()\
    \ < size_t(3)){\r\n      c.pop_back();\r\n    }else{\r\n      swap(c[1], c.back());\
    \ c.pop_back();\r\n      lift_up(down(1));\r\n    }\r\n  }\r\n\r\n  void pop_max()\
    \ {\r\n    if(c.size() < size_t(2)){\r\n      c.pop_back();\r\n    }else{\r\n\
    \      swap(c.front(), c.back()); c.pop_back();\r\n      lift_up(down(0));\r\n\
    \    }\r\n  }\r\n\r\n\r\n  size_t lift_up(size_t k, size_t root = 1){\r\n    if((k\
    \ | 1) != c.size() && c[k & ~1] < c[k | 1]){\r\n      swap(c[k], c[k ^ 1]); k\
    \ ^= 1;\r\n    }\r\n    \r\n    for(size_t p; root < k && c[p = par(k)] < c[k];\
    \ k = p) swap(c[p], c[k]);\r\n    for(size_t p; root < k && c[k] < c[p = (par(k)|1)]\
    \ ; k = p) swap(c[p], c[k]);\r\n\r\n    return k;\r\n  }\r\n\r\n  size_t down(size_t\
    \ k){\r\n    size_t n = c.size();\r\n    if(k & 1){\r\n      for(size_t i; 2 *\
    \ k + 1 < n; k = i){\r\n        i = 2 * k + 3;\r\n        if(n <= i || c[i - 2]\
    \ < c[i]) i -= 2;\r\n        if(n <= i || !(c[i] < c[k])) break;\r\n        swap(c[i],\
    \ c[k]);\r\n      }\r\n    }else{\r\n      for(size_t i; 2 * k + 2 < n; k = i){\r\
    \n        i = 2 * k + 4;\r\n        if(n <= i ||  c[i] < c[i - 2]) i -= 2;\r\n\
    \        if(n <= i || !(c[k] < c[i])) break;\r\n        swap(c[i], c[k]);\r\n\
    \      }\r\n    }\r\n    return k;\r\n  }\r\n\r\nprivate:\r\n\r\n  constexpr size_t\
    \ par(size_t k) const { return ((k >> 1) - 1) & ~1; }\r\n\r\n  void make_heap(){\r\
    \n    for(size_t k = c.size(); k--; ){\r\n      if(k & 1 && c[k - 1] < c[k]) swap(c[k\
    \ - 1], c[k]);\r\n      lift_up(down(k), k);\r\n    }\r\n  }\r\n};\r\n#line 7\
    \ \"test/verify/lc/double_ended_priority_queue.test.cpp\"\n\nint main(){\n  int\
    \ n, q; cin >> n >> q;\n  vector<int> s(n); for(int &e : s) cin >> e;\n  DoubleEndedPriorityQueue<int>\
    \ pq(s);\n\n  while(q--){\n    int t; cin >> t;\n    if(t == 0){\n      int x;\
    \ cin >> x; pq.push(x);\n    }\n\n    if(t == 1) cout << pq.get_min() << \"\\\
    n\", pq.pop_min();\n    if(t == 2) cout << pq.get_max() << \"\\n\", pq.pop_max();\n\
    \  }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/double_ended_priority_queue\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#include \"datastructure/heap/DoubleEndedPriorityQueue.cpp\"\
    \n\nint main(){\n  int n, q; cin >> n >> q;\n  vector<int> s(n); for(int &e :\
    \ s) cin >> e;\n  DoubleEndedPriorityQueue<int> pq(s);\n\n  while(q--){\n    int\
    \ t; cin >> t;\n    if(t == 0){\n      int x; cin >> x; pq.push(x);\n    }\n\n\
    \    if(t == 1) cout << pq.get_min() << \"\\n\", pq.pop_min();\n    if(t == 2)\
    \ cout << pq.get_max() << \"\\n\", pq.pop_max();\n  }\n}"
  dependsOn:
  - datastructure/heap/DoubleEndedPriorityQueue.cpp
  isVerificationFile: true
  path: test/verify/lc/double_ended_priority_queue.test.cpp
  requiredBy: []
  timestamp: '2023-07-30 22:51:32+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/verify/lc/double_ended_priority_queue.test.cpp
layout: document
redirect_from:
- /verify/test/verify/lc/double_ended_priority_queue.test.cpp
- /verify/test/verify/lc/double_ended_priority_queue.test.cpp.html
title: test/verify/lc/double_ended_priority_queue.test.cpp
---
