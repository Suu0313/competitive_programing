template<typename T>
struct DynamicLiChaoTree{
  struct Line{
    T a, b;
    Line(T a, T b) : a(a), b(b) {}
    inline T get(T x) const { return a*x + b; }
  };
  struct Node{
    Line f;
    Node *l, *r;
    Node(const Line &f): f(f), l(nullptr), r(nullptr) {}
  };

  Node *root;
  const T low, high, id;

  DynamicLiChaoTree(const T &low, const T &high, const T &id)
    : root(nullptr), low(low), high(high), id(id){}

  void add_line(const T &a, const T &b){
    Line f(a, b);
    root = add_line(root, f, low, high, f.get(low), f.get(high));
  }
  void add_segment(const T &a, const T &b, const T &l, const T &r){
    Line f(a, b);
    root = add_segment(root, f, l, r-1, low, high, f.get(low), f.get(high));
  }

  T query(const T &x) const {
    return query(root, low, high, x);
  }

private:
  Node *add_line(Node *t, Line &f, const T &l, const T &r, const T &f_l, const T &f_r){
    if(!t) return new Node(f);
    T t_l = t->f.get(l), t_r = t->f.get(r);
    if(t_l <= f_l && t_r <= f_r){
      return t;
    }else if(t_l >= f_l && t_r >= f_r){
      t->f = f; return t;
    }else{
      T m = (l + r)/2;
      if(m == r) --m;
      T t_m = t->f.get(m), f_m = f.get(m);
      if(t_m > f_m){
        swap(t->f, f);
        if(f_l >= t_l) t->l = add_line(t->l, f, l, m, t_l, t_m);
        else t->r = add_line(t->r, f, m+1, r, t_m+f.a, t_r);
      }else{
        if(t_l >= f_l) t->l = add_line(t->l, f, l, m, f_l, f_m);
        else t->r = add_line(t->r, f, m+1, r, f_m+f.a, f_r);
      }
      return t;
    }
  }

  Node *add_segment(Node *t, Line &f, const T &p, const T &q , const T &l, const T &r, const T &f_l, const T &f_r){
    if(r < p || q < l) return t;
    if(p <= l && r <= q){
      Line g{f};
      return add_line(t, g, l, r, f_l, f_r);
    }
    if(t){
      T t_l = t->f.get(l), t_r = t->f.get(r);
      if(t_l <= f_l && t_r <= f_r) return t;
    }else{
      t = new Node(Line(0, id));
    }
    T m = (l + r)/2;
    if(m == r) --m;
    T f_m = f.get(m);
    t->l = add_segment(t->l, f, p, q, l, m, f_l, f_m);
    t->r = add_segment(t->r, f, p, q, m + 1, r, f_m + f.a, f_r);
    return t;
  }

  T query(const Node *t, const T &l, const T &r, const T &x) const {
    if(!t) return id;
    if(l == r) return t->f.get(x);
    T m = (l + r)/2;
    if(m == r) --m;
    if(x <= m) return min(t->f.get(x), query(t->l, l, m, x));
    else return min(t->f.get(x), query(t->r, m+1, r, x));
  }
};
