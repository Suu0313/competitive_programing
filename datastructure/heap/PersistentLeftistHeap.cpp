template<typename T, class Compair = less<T>>
struct PersistentLeftistHeap{
  struct Node;
  using Np = shared_ptr<Node>;
  template<class... Args>
  static Np make_np(Args&&... args){
      return make_shared<Node>(forward<Args>(args)...);
  }

  struct Node{
    T val;
    Np l = nullptr, r = nullptr;
    size_t s = 1;
    Node() = default;
    Node(const T &val): val(val) {}
    Node(const Node&) = default;
    Node(Node&&) = default;
    Node &operator=(const Node&) = default;
    Node &operator=(Node&&) = default;
  };

  static Np make_root(){ return nullptr; }
  static Np make_clone(Np t){ return t ? make_np(*t) : nullptr; }
  static size_t get_s(Np t){ return t ? t->s : 0; }

  Compair cmp;
  
  PersistentLeftistHeap(const Compair &cmp = Compair{}): cmp(cmp) {}

  Np meld(Np a, Np b){
    if(!b) return make_clone(a);
    if(!a) return make_clone(b);
    a = make_clone(a); b = make_clone(b);
    if(cmp(b->val, a->val)) a.swap(b);

    a->r = meld(a->r, b);
    if(!a->l || a->l->s < a->r->s) a->l.swap(a->r);
    a->s = get_s(a->r) + 1;
    return a;
  }
  Np push(Np t, const T &x){ return meld(t, make_np(x)); }
  Np pop(Np t){ return meld(t->l, t->r); }
};
