#pragma once

template<typename key_t, typename val_t, class Compair = less<key_t>>
struct FibonacciHeap{
  struct Node;
  using Np = Node *;
  
  struct Node{
    key_t key;
    val_t val;
    Node() = default;
    Node(const key_t &key, const val_t &val): key(key), val(val) {}

    Np p = nullptr, child = nullptr, left = this, right = this;

    size_t degree = 0;  
    bool mark = false;
  };
private:

  Np root;
  size_t sz;
  Compair cmp;

  void insert(Np &p1, Np &p2){
    Np rr = p1->right;
    p1->right = p2; p2->left = p1;
    p2->right = rr; rr->left = p2;
  }

  void merge(Np &p1, Np &p2){
    Np r1 = p1->right, r2 = p2->left;
    p1->right = p2; p2->left = p1;
    r2->right = r1; r1->left = r2;
  }

  vector<Np> get_Np_list(Np r){
    assert(!!r);
    vector<Np> nps;
    Np w = r;
    do{
      nps.push_back(w);
      w = w->right;
    }while(w != r);
    return nps;
  }

  void consolidate(){
    vector<Np> a, nps = get_Np_list(root);

    for(Np w : nps){
      Np x = w;
      size_t d = x->degree;
      
      while(d < a.size() && !!a[d]){
        Np y = a[d];
        if(cmp(y->key, x->key)) swap(x, y);
        heap_link(y, x);
        a[d] = nullptr;
        ++d;
      }

      if(a.size() <= d) a.resize(d + 1, nullptr);
      a[d] = x;
    }
    root = nullptr;
    for(Np x : a){
      if(!x) continue;
      if(!root){
        x->left = x->right = x;
        root = x;
      }else{
        insert(root, x);
        if(cmp(x->key, root->key)) root = x;
      }
    }
    assert(!!root);
  }

  void heap_link(Np &y, Np &x){
    if(y->right != y) delete_node(y);
    if(!x->child) x->child = y;
    else insert(x->child, y);
    y->p = x;
    x->degree += 1;
    y->mark = false;
  }

  void cascading_cut(Np &y){
    Np z = y->p;
    if(!!z){
      if(!y->mark) y->mark = true;
      else{
        cut(y, z);
        cascading_cut(z);
      }
    }
  }

  void erase(Np &x, const key_t &linf){
    decrease(x, linf);
    pop();
  }

  void delete_node(Np &x){
    Np l = x->left, r = x->right;
    l->right = r; r->left = l;
    x->left = x->right = x;
  }

  void cut(Np &x, Np &y){
    if(x->right == x){
      y->child = nullptr;
    }else{
      y->child = x->right;
      delete_node(x);
    }
    y->degree -= 1;
    insert(root, x);
    x->p = nullptr;
    x->mark = false;
  }

public:
  FibonacciHeap(const Compair &cmp = Compair{}): root(nullptr), sz(0), cmp(cmp) {}
  FibonacciHeap(const FibonacciHeap&) = default;
  FibonacciHeap(FibonacciHeap&&) = default;

  FibonacciHeap &operator=(const FibonacciHeap&) = default;
  FibonacciHeap &operator=(FibonacciHeap&&) = default;

  size_t size() const { return sz; }
  bool empty() const { return !sz; }

  pair<key_t, val_t> top() const {
    assert(!!root);
    return {root->key, root->val};
  }

  Np push(const key_t &key, const val_t &val){
    Np x = new Node(key, val);

    if(!root){
      root = x;
    }else{
      insert(root, x);
      if(cmp(key, root->key)) root = x;
    }

    ++sz;
    return x;
  }

  void merge(FibonacciHeap &h2){
    if(!h2.root) return;
    sz += h2.sz;

    if(!root){
      root = h2.root;
      return;
    }
    merge(root, h2.root);
    if(cmp(h2.root->key, root->key)) root = h2.root;
  }

  pair<key_t, val_t> pop(){
    assert(("can't pop" ,!!root));
    pair<key_t, val_t> res = {root->key, root->val};

    Np c = root->child;

    if(!!c){
      vector<Np> nps = get_Np_list(c);
      for(Np x : nps){
        insert(root, x);
        x->p = nullptr;
      }
    }

    if(root->right == root){
      delete root;
      root = nullptr;
    }else{
      Np z = root;
      root = root->right;
      delete_node(z);
      delete z;
      consolidate();
    }
    --sz;

    return res;
  }

  void decrease(Np &x, const key_t &key){
    assert(!!x);
    assert(!cmp(x->key, key));
    x->key = key;
    Np y = x->p;
    if(!!y && cmp(x->key, y->key)){
      cut(x, y);
      cascading_cut(y);
    }
    if(cmp(x->key, root->key)) root = x;
  }

  static Np get_np() { return nullptr; }
};
