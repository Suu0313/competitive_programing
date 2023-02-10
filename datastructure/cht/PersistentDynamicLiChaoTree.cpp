#pragma once

template<typename T>
struct PersistentDynamicLiChaoTree{
  using Pti = pair<T, int>;
  struct Line{
    T a, b;
    int idx;
    Line(T a, T b, int idx = -1) : a(a), b(b), idx(idx) {}
    inline Pti get(T x) const { return {a*x + b, idx}; }
  };
  struct Node{
    Line f;
    Node *l, *r;
    Node(const Line &f): f(f), l(nullptr), r(nullptr) {}
    Node(const Node *t): f(t->f), l(t->l), r(t->r) {}
  };

  const T low, high, id;

  PersistentDynamicLiChaoTree(const T &low, const T &high, const T &id): low(low), high(high), id(id){}

  static Node *get_root(){ return nullptr; }

  Node *add_line(Node *root, const T &a, const T &b, int idx){
    Line f(a, b, idx);
    return add_line(root, f, low, high, f.get(low), f.get(high));
  }
  Node *add_segment(Node *root, const T &a, const T &b, const T &l, const T &r, int idx){
    Line f(a, b, idx);
    return add_segment(root, f, l, r-1, low, high, f.get(low), f.get(high));
  }

  pair<T, int> query(Node *root, const T &x) const { return query(root, low, high, x); }

private:
  Node *add_line(Node *t, Line &f, const T &l, const T &r, const Pti &f_l, const Pti &f_r){
    if(!t) return new Node(f);
    auto t_l = t->f.get(l), t_r = t->f.get(r);
    if(t_l <= f_l && t_r <= f_r){
      return t;
    }else if(t_l >= f_l && t_r >= f_r){
      Node *p = new Node(t);
      p->f = f; return p;
    }else{
      T m = (l + r)/2;
      if(m == r) --m;
      auto t_m = t->f.get(m), f_m = f.get(m);
      Node *p = new Node(t);
      if(t_m > f_m){
        swap(p->f, f);
        if(f_l >= t_l) p->l = add_line(p->l, f, l, m, t_l, t_m);
        else p->r = add_line(p->r, f, m+1, r, {t_m.first+f.a, t_m.second}, t_r);
      }else{
        if(t_l >= f_l) p->l = add_line(p->l, f, l, m, f_l, f_m);
        else p->r = add_line(p->r, f, m+1, r, {f_m.first+f.a, f_m.second}, f_r);
      }
      return p;
    }
  }

  Node *add_segment(Node *t, Line &f, const T &p, const T &q , const T &l, const T &r, const Pti &f_l, const Pti &f_r){
    if(r < p || q < l) return t;
    if(p <= l && r <= q){
      Line g{f};
      return add_line(t, g, l, r, f_l, f_r);
    }
    if(t){
      auto t_l = t->f.get(l), t_r = t->f.get(r);
      if(t_l <= f_l && t_r <= f_r) return t;
    }
    Node *s = new Node(Line(0, id));
    T m = (l + r)/2;
    auto f_m = f.get(m);
    s->l = add_segment(s->l, f, p, q, l, m, f_l, f_m);
    s->r = add_segment(s->r, f, p, q, m + 1, r, {f_m.first+f.a, f_m.second}, f_r);
    return p;
  }

  pair<T, int>  query(const Node *t, const T &l, const T &r, const T &x) const {
    if(!t) return {id, -1};
    if(l == r) return t->f.get(x);
    T m = (l + r)/2;
    if(m == r) --m;
    if(x <= m) return min(t->f.get(x), query(t->l, l, m, x));
    else return min(t->f.get(x), query(t->r, m+1, r, x));
  }
};
