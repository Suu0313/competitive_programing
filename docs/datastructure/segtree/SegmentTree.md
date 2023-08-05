---
title: Segment Tree
documentation_of: //datastructure/segtree/SegmentTree.cpp
---

## 概要

非二冪非再帰一点更新区間取得セグメントツリー

以下の条件をみたす構造体 `Monoid` を乗せる

- デフォルトコンストラクタ `Monoid{}` が単位元
- `operator+`, `operator+=`, `opetator=` をもつ
- $(a + b) + c = a + (b + c)$

## 使い方

以下, $a + b$ を $O(1)$ で求められるとする

- `SegmentTree()`: デフォルトコンストラクタ. 要素を持たない空で構築する. $O(1)$
- `SegmentTree(int n)`: $n$ 個の `Monoid{}` で構築. $\Theta(n)$
- `SegmentTree(int n, const Monoid &x)`: $n$ 個の `x` で構築. $\Theta(n)$
- `SegmentTree(Iiter first, Iiter last)`: イレテータ範囲 `[first, last)` を要素としてコピーしてオブジェクトを構築. `distance(first, last)` $= n$ として $\Theta(n)$
- `SegmentTree(const Container &c)`: `SegmentTree(begin(c), end(c))` と等価
- `void build()`: 現在セットされている値でセグ木を構築. $\Theta(n)$
- `void set(int k, const Monoid &x)`: $k$ 番目の値を `x` に変更, 伝播はさせない. $O(1)$
- `void change(int k, const Monoid &x)`: $k$ 番目の値を `x` に変更. $O(\log n)$
- `void change(int l, int r, const Monoid &x)`: $k \in [l, r)$ に対して `change(k, x)` を適用. $O((r - l)\log n)$
- `void update(int k, const F &f)`: `change(k, f(seg[k]))` と等価
- `void update(int l, int r, const F &f)`: $k \in [l, r)$ に対して `update(k, f)` を適用.
- `const Monoid &operator[](int k)`: $k$ 番目の値を取得. $O(1)$
- `Monoid query(int l, int r)`: $\sum _ {l \le k < r}$ `seg[k]` を取得. $O(\log n)$
- `int max_right(int l, const C &check)`: `check(query(l, r))` が `true` となる最大の `r` を取得. `check(Monoid{})` は `true` であること. $O(\log n)$
- `int min_left(int r, const C &check)`: `check(query(l, r))` が `true` となる最小の `l` を取得. `check(Monoid{})` は `true` であること. $O(\log n)$ (verify していない)
