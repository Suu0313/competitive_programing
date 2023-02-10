#pragma once

template<typename T>
struct DynamicSegTree{

  using OP = function<T(T,T)>;
  uint64_t n, n0;
  T id;
  OP op;

  DynamicSegTree() {}
  DynamicSegTree(uint64_t n_, const T &id, const OP &op) : n(1), n0(n_), id(id),op(op){
    while(n < n_) n<<=1;
  }

  void change(uint64_t k, const T &x){ root = change(root, k, x, 0, n); }
  T query(uint64_t l, uint64_t r) const { return query(root, l, r, 0, n); }
  T all_query() const { return query(0, n); }
  T at(uint64_t k) const { return query(k, k+1); }

private:

  struct Node{
    T val;
    Node *l, *r;
    Node(const T &v): val(v), l(nullptr), r(nullptr) {}
  } *root = nullptr;
  using np = Node*;

  T val(np t) const { return !t ? id : t->val; }

  np change(np t, uint64_t k, const T &x, uint64_t l, uint64_t r){
    if(!t) t = new Node(id);
    if(l+1==r){ t->val = x; return t; }

    uint64_t m = l + ((r-l) >> 1);
    if(k < m) t->l = change(t->l, k, x, l, m);
    else t->r = change(t->r, k, x, m, r);

    t->val = op(val(t->l), val(t->r));
    return t;
  }

  T query(np t, uint64_t ql, uint64_t qr, uint64_t l, uint64_t r) const {
    if(!t || r<=ql || qr<=l) return id;
    if(ql<=l && r<=qr) return t->val;

    uint64_t m = l + ((r-l) >> 1);
    return op(query(t->l, ql, qr, l, m), query(t->r, ql, qr, m, r));
  }
};
