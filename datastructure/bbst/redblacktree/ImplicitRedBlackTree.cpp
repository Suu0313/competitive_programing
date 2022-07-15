template<typename T>
struct ImplicitRedBlackTree{
private:
  enum Color{RED, BLACK, NIL};

  struct Node{
    T val;
    Color color;
    size_t sz = 0;
    Node *parentP = nullptr, *leftP = nullptr, *rightP = nullptr, *nextP = nullptr, *prevP = nullptr;

    constexpr Node(): val{}, color(NIL) {}
    constexpr Node(const T &val, Color color): val(val), color(color), sz(1) {}

    constexpr bool is_valid() const { return color != NIL; }
    constexpr bool is_nil() const { return color == NIL; }
    constexpr bool is_red() const { return color == RED; }
    constexpr bool is_black() const { return color != RED; }
    constexpr bool is_left() const { return parentP->leftP == this; }
    constexpr bool is_right() const { return parentP->rightP == this; }
    constexpr bool is_root() const { return parentP->is_nil(); }

    constexpr void flip_color(){
      assert(is_valid());
      if(is_red()) color = BLACK;
      else color = RED;
    }

    constexpr Node *successor() const { return nextP; }
    constexpr Node *predecessor() const { return prevP; }
  };
  using Np = Node*;

  Np nil = new Node{};

  Np root = nil;

  void rotate_left(Np t){
    Np y = t->rightP;
    assert(y->is_valid());

    t->rightP = y->leftP;
    if(y->leftP->is_valid()) y->leftP->parentP = t;
    y->parentP = t->parentP;

    if(t->is_root()) root = y;
    else if(t->is_left()) t->parentP->leftP = y;
    else t->parentP->rightP = y;

    y->leftP = t; t->parentP = y;
    y->sz = t->sz;
    t->sz = t->leftP->sz + t->rightP->sz + 1;
  }

  void rotate_right(Np t){
    Np y = t->leftP;
    assert(y->is_valid());

    t->leftP = y->rightP;
    if(y->rightP->is_valid()) y->rightP->parentP = t;
    y->parentP = t->parentP;

    if(t->is_root()) root = y;
    else if(t->is_left()) t->parentP->leftP = y;
    else t->parentP->rightP = y;

    y->rightP = t; t->parentP = y;
    y->sz = t->sz;
    t->sz = t->leftP->sz + t->rightP->sz + 1;
  }

  void insert_fixup(Np t){
    assert(!!t->parentP);
    while(t->parentP->is_red()){
      if(t->parentP->is_left()){
        Np y = t->parentP->parentP->rightP;
        if(y->is_red()){
          t->parentP->flip_color();
          y->flip_color();
          t->parentP->parentP->flip_color();
          t = t->parentP->parentP;
        }else{
          if(t->is_right()){ t = t->parentP; rotate_left(t); }
          t->parentP->flip_color();
          t->parentP->parentP->flip_color();
          rotate_right(t->parentP->parentP);
        }
      }else{
        Np y = t->parentP->parentP->leftP;
        if(y->is_red()){
          t->parentP->flip_color();
          y->flip_color();
          t->parentP->parentP->flip_color();
          t = t->parentP->parentP;
        }else{
          if(t->is_left()){ t = t->parentP; rotate_right(t); }
          t->parentP->flip_color();
          t->parentP->parentP->flip_color();
          rotate_left(t->parentP->parentP);
        }
      }
    }
    if(root->is_red()) root->flip_color();
  }

  void erase_impl(Np t){
    Np x = nil, y = t;
    Color color = y->color;
    if(t->leftP->is_nil()){
      x = t->rightP;
      transplant(t, t->rightP);
    }else if(t->rightP->is_nil()){
      x = t->leftP;
      transplant(t, t->leftP);
    }else{
      y = y->nextP;
      assert(y->is_valid());
      Np m = y->parentP;
      while(m != t){ m->sz -= 1; m = m->parentP; }
      color = y->color; x = y->rightP;
      if(y->parentP == t) x->parentP = y;
      else{
        transplant(y, y->rightP);
        y->rightP = t->rightP;
        y->rightP->parentP = y;
      }
      transplant(t, y);
      y->leftP = t->leftP;
      y->leftP->parentP = y;
      y->color = t->color;
      y->sz = t->sz;
    }

    if(color == BLACK) erase_fixup(x);
    t->nextP->prevP = t->prevP;
    t->prevP->nextP = t->nextP;
    delete t;
  }

  void erase_fixup(Np t){
    while(!t->is_root() && t->is_black()){
      if(t->is_left()){
        Np y = t->parentP->rightP;
        if(y->is_red()){
          y->flip_color(); t->parentP->flip_color();
          rotate_left(t->parentP);
          y = t->parentP->rightP;
        }
        if(y->leftP->is_black() && y->rightP->is_black()){
          y->flip_color(); t = t->parentP;
        }else{
          if(y->rightP->is_black()){
            y->leftP->flip_color();
            y->flip_color();
            rotate_right(y);
            y = t->parentP->rightP;
          }
          y->color = t->parentP->color;
          t->parentP->color = BLACK;
          y->rightP->color = BLACK;
          rotate_left(t->parentP);
          t = root;
        }
      }else{
        Np y = t->parentP->leftP;
        if(y->is_red()){
          y->flip_color(); t->parentP->flip_color();
          rotate_right(t->parentP);
          y = t->parentP->leftP;
        }
        if(y->leftP->is_black() && y->rightP->is_black()){
          y->flip_color(); t = t->parentP;
        }else{
          if(y->leftP->is_black()){
            y->rightP->flip_color();
            y->flip_color();
            rotate_left(y);
            y = t->parentP->leftP;
          }
          y->color = t->parentP->color;
          t->parentP->color = BLACK;
          y->leftP->color = BLACK;
          rotate_right(t->parentP);
          t = root;
        }
      }
    }
    if(t->is_red()) t->flip_color();
  }

  void transplant(Np u, Np v){
    if(u->is_root()) root = v;
    else if(u->is_left()) u->parentP->leftP = v;
    else u->parentP->rightP = v;
    v->parentP = u->parentP;
  }

  Np select(Np t, size_t k) const {
    assert(!!t);
    size_t r = t->leftP->sz;
    if(k == r) return t;
    else if(k < r) return select(t->leftP, k);
    else return select(t->rightP, k - r - 1);
  }

  void dump(Np t) const {
    if(t->is_nil()) return;
    dump(t->leftP);
    cout << t->val << " ";
    dump(t->rightP);
  }

  size_t rank(Np t) const {
    if(t->is_nil()) return size();
    size_t r = t->leftP->sz;
    Np y = t;
    while(!y->is_root()){
      if(y->is_right()) r += y->parentP->leftP->sz + 1;
      y = y->parentP;
    }
    return r;
  }


public:

  ImplicitRedBlackTree() {
    root->nextP = root->prevP = nil;
  }
  ImplicitRedBlackTree(initializer_list<T> v){
    root->nextP = root->prevP = nil;
    for(auto&e : v) insert(e);
  }

  void push_front(const T &val){
    Np t = new Node(val, RED);
    t->leftP = t->rightP = t->nextP = t->prevP = nil;

    Np x = root, y = nil;
    while(x->is_valid()){
      y = x;
      x = x->leftP;
      y->sz += 1;
    }
    assert(!!y);
    t->parentP = y;
    if(y->is_nil()){ root->nextP = root->prevP = t;  root = t; }
    else{ y->leftP = t; y->prevP->nextP = t; t->nextP = y; t->prevP = y->prevP; y->prevP = t; }

    insert_fixup(t);
  }

  void push_back(const T &val){
    Np t = new Node(val, RED);
    t->leftP = t->rightP = t->nextP = t->prevP = nil;

    Np x = root, y = nil;
    while(x->is_valid()){
      y = x;
      x = x->rightP;
      y->sz += 1;
    }
    assert(!!y);
    t->parentP = y;
    if(y->is_nil()){ root->nextP = root->prevP = t;  root = t; }
    else{ y->rightP = t; y->nextP->prevP = t; t->prevP = y; t->nextP = y->nextP; y->nextP = t; }

    insert_fixup(t);
  }

  size_t insert(int k, const T &val){
    if(k < 0) k += (int)size();
    assert(0 <= k && k <= (int)size());
    
    Np t = new Node(val, RED);
    t->leftP = t->rightP = t->nextP = t->prevP = nil;

    Np x = root, y = nil;
    int dir = -1;
    while(x->is_valid()){
      y = x;
      int sz = ((x->leftP->is_nil()) ? 0 : int(x->leftP->sz));
      if(k <= sz) x = x->leftP, dir = 0;
      else x = x->rightP, k -= sz + 1, dir = 1;
      y->sz += 1;
    }
    assert(!!y);
    t->parentP = y;
    if(y->is_nil()){ root->nextP = root->prevP = t;  root = t; }
    else if(dir == 0){ y->leftP = t; y->prevP->nextP = t; t->nextP = y; t->prevP = y->prevP; y->prevP = t; }
    else{ y->rightP = t; y->nextP->prevP = t; t->prevP = y; t->nextP = y->nextP; y->nextP = t; }

    insert_fixup(t);
    return rank(t);
  }

  T pop_front(){
    assert(!this->empty());
    itr it = this->begin();
    T res = *it;
    erase(it);
    return res;
  }

  T pop_back(){
    assert(!this->empty());
    ritr it = this->rbegin();
    T res = *it;
    erase(it);
    return res;
  }

  T erase(int k){
    if(k < 0) k += (int)size();
    assert(0 <= k && k < (int)size());
    Np t = select(root, k), y = t;
    T res = t->val;
    while(y->is_valid()){ y->sz -= 1; y = y->parentP; }
    erase_impl(t);
    return res;
  };

  void dump() const {
    dump(root);
    cout << endl;
  }

  T at(int k) const {
    if(k < 0) k += (int)size();
    assert(0 <= k && k < (int)size());
    return select(root, k)->val;
  }

  T operator[](int k) const {
    if(k < 0) k += (int)size();
    assert(0 <= k && k < (int)size());
    return select(root, k)->val;
  }

  T pop(int k){ T val = at(k); erase(val); return val; }

  size_t size() const { return root->sz; }

  bool empty() const { return size() == 0; }
  operator bool() const { return !empty(); }

  struct itr{
    Np t;
    bool operator!=(const itr &it) const { return t != it.t; }
    void operator++(){ t = t->successor(); }
    void operator--(){ t = t->predecessor(); }
    T operator*() const { return t->val; }
    itr &operator=(const itr &it){ t = it.t; return (*this); }
  };

  struct ritr{
    Np t;
    bool operator!=(const ritr &it) const { return t != it.t; }
    void operator++(){ t = t->predecessor(); }
    void operator--(){ t = t->successor(); }
    T operator*() const { return t->val; }
    ritr &operator=(const ritr &it){ t = it.t; return (*this); }
  };

  itr begin() const { return {nil->nextP}; }
  itr end() const { return {nil}; }
  ritr rbegin() const { return {nil->prevP}; }
  ritr rend() const { return {nil}; }

  itr erase(itr it){
    Np t = it.t, y = t;
    assert(t->is_valid());
    itr res = it; ++res;
    while(y->is_valid()){ y->sz -= 1; y = y->parentP; }
    erase_impl(t);
    return res;
  }

  ritr erase(ritr it){
    Np t = it.t, y = t;
    assert(t->is_valid());
    ritr res = it; ++res;
    while(y->is_valid()){ y->sz -= 1; y = y->parentP; }
    erase_impl(t);
    return res;
  }

  void swap(ImplicitRedBlackTree &tree){
    Np tmp = this->root;
    this->root = tree.root;
    tree.root = tmp;
    tmp = this->nil;
    this->nil = tree.nil;
    tree.nil = tmp;
  }
};
