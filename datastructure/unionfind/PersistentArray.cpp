#pragma once

template<typename T, size_t M = 20>
struct PersistentArray{
  struct Node;
  using Np = shared_ptr<Node>;

  struct Node{
    T x;
    array<Np, M> child = {};

    Node() = default;
    Node(const T &x): x(x) {}
  };

  Np root = Np{};

  PersistentArray() = default;
  template<class Iiter>
  PersistentArray(Iiter first, Iiter last){
    size_t n = distance(first, last);
    for(size_t i = 0; i != n; ++i, ++first) set(root, i, *first);
  }
  template<class Container>
  PersistentArray(const Container &c): PersistentArray(begin(c), end(c)) {}

  void set(Np &t, size_t k, const T &x){
    if(!t) t = Np(new Node());
    if(!k) t->x = x;
    else set(t->child[k % M], k / M, x);
  }

  void set(size_t k, const T &x){ set(root, k, x); }

  Np update(const Np &t, size_t k, const T &x){
    Np res(new Node());

    if(t){
      copy(begin(t->child), end(t->child), begin(res->child));
      res->x = t->x;
    }

    if(!k) res->x = x;
    else res->child[k % M] = update(res->child[k % M], k / M, x);

    return res;
  }

  Np update(size_t k, const T &x){ return update(root, k, x); }

  T get(const Np &t, size_t k) const {
    assert(!!t);
    if(!k) return t->x;
    return get(t->child[k % M], k / M);
  }

  T get(size_t k) const { return get(root, k); }
};
