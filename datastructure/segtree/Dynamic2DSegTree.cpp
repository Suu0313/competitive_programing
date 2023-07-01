#pragma once

#include "./DynamicSegTree.cpp"

template<typename T>
struct Dynamic2DSegTree{
  using OP = function<T(T,T)>;
  uint64_t h, h0, w, w0;
  const T id;
  const OP op;
  vector<DynamicSegTree<T>> node;

  Dynamic2DSegTree() {}
  Dynamic2DSegTree(uint64_t h0, uint64_t w0, const T &id, const OP &op)
    : h(1), h0(h0), w(1), w0(w0), id(id), op(op){
    while(h < h0) h <<= 1;
    while(w < w0) w <<= 1;
    node.assign(2*h, {w, id, op});
  }

  void add(uint64_t i, uint64_t j, const T &x){
    i += h;
    node[i].change(j, op(node[i].at(j), x));
    while(i >>= 1){
      node[i].change(j, op(node[i].at(j), x));
    }
  }

  T query(uint64_t l, uint64_t r, uint64_t d, uint64_t u){
    T L = id, R = id;
    for(l += h, r += h; l < r; l >>= 1, r >>= 1) {
      if(l & 1) L = op(L, node[l++].query(d, u));
      if(r & 1) R = op(node[--r].query(d, u), R);
    }
    return op(L, R);
  }
};
