#include <bits/stdc++.h>
using namespace std;

#include <set>

template<typename T, class Compair = less<T>>
struct RedBlackTree{
private:
  enum Color{RED, BLACK, NIL};

  struct Node{
    T key;
    Color color;
    size_t sz = 0;
    Node *parentP = nullptr, *leftP = nullptr, *rightP = nullptr;

    constexpr Node(): key{}, color(NIL) {}
    constexpr Node(const T &key, Color color): key(key), color(color), sz(1) {}

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
  };
  using Np = Node*;

  static Np get_nil(){
    static Node nil = Node{};
    return &nil;
  }

  Np root = get_nil();
  const Compair cmp;

  void rotate_left(Np t){
    Np y = t->rightP;
    assert(y->is_valid());

    t->rightP = y->leftP;
    if(y->leftP->is_valid()) y->leftP->parentP = t;
    y->parentP = t->parentP;

    if(t->is_root()) root = y;
    else if(t->is_left()) t->parentP->leftP = y;
    else t->parentP->rightP = y;

    y->leftP = t;
    t->parentP = y;

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

    y->rightP = t;
    t->parentP = y;

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
          if(t->is_right()){
            t = t->parentP;
            rotate_left(t);
          }
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
          if(t->is_left()){
            t = t->parentP;
            rotate_right(t);
          }
          t->parentP->flip_color();
          t->parentP->parentP->flip_color();
          rotate_left(t->parentP->parentP);
        }
      }
    }
    if(root->is_red()) root->flip_color();
  }

  void erase_impl(Np t){
    Np x = get_nil(), y = t;
    Color color = y->color;
    if(t->leftP->is_nil()){
      x = t->rightP;
      transplant(t, t->rightP);
    }else if(t->rightP->is_nil()){
      x = t->leftP;
      transplant(t, t->leftP);
    }else{
      y = minimum(y->rightP);
      color = y->color;
      x = y->rightP;
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

  Np minimum(Np t) const {
    while(t->leftP->is_valid()) t = t->leftP;
    return t;
  }

  Np maximum(Np t) const {
    while(t->rightP->is_valid()) t = t->rightP;
    return t;
  }

  Np successor(Np t) const {
    if(t->rightP->is_valid()) return minimum(t->rightP);
    Np y = t->parentP;
    while(y->is_valid() && t->is_right()){
      t = y; y = y->parentP;
    }
    return y;
  }

  Np predecessor(Np t) const {
    if(t->leftP->is_valid()) return maximum(t->leftP);
    Np y = t->parentP;
    while(y->is_valid() && t->is_left()){
      t = y; y = y->parentP;
    }
    return y;
  }

  Np lower_bound(Np t, const T &key) const {
    if(t->is_nil()) return t;
    if(cmp(t->key, key)) return lower_bound(t->rightP, key);
    Np l = lower_bound(t->leftP, key);
    if(l->is_nil()) return t;
    return l;
  }

  Np upper_bound(Np t, const T &key) const {
    if(t->is_nil()) return t;
    if(!cmp(key, t->key)) return upper_bound(t->rightP, key);
    Np l = upper_bound(t->leftP, key);
    if(l->is_nil()) return t;
    return l;
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
    cout << t->key << " ";
    dump(t->rightP);
  }

public:

  RedBlackTree(const Compair &cmp = Compair{}): cmp(cmp) {}
  RedBlackTree(initializer_list<T> v ,const Compair &cmp = Compair{}): cmp(cmp) {
    for(auto&e : v) insert(e);
  }

  Np insert(const T &key){
    Np t = new Node(key, RED);
    t->leftP = t->rightP = get_nil();

    Np x = root, y = get_nil();
    while(x->is_valid()){
      y = x;
      if(cmp(key, x->key)) x = x->leftP;
      else x = x->rightP;
      y->sz += 1;
    }
    assert(!!y);
    t->parentP = y;
    if(y->is_nil()) root = t;
    else if(cmp(key, y->key)) y->leftP = t;
    else y->rightP = t;

    insert_fixup(t);
    return t;
  }

  bool erase(const T &key){
    Np t = find(key);
    if(t->is_nil()) return false;
    assert(t->key == key);
    Np y = t;
    while(y->is_valid()){
      y->sz -= 1;
      y = y->parentP;
    }
    erase_impl(t);
    return true;
  }

  Np find(const T &key) const {
    Np t = root;
    while(t->is_valid() && t->key != key){
      if(cmp(key, t->key)) t = t->leftP;
      else t = t->rightP;
    }
    return t;
  }

  bool exist(const T &key) const {
    return find(key)->is_valid();
  }

  size_t rank(Np t) const {
    size_t r = t->leftP->sz;
    Np y = t;
    while(!y->is_root()){
      if(y->is_right()) r += y->parentP->leftP->sz + 1;
      y = y->parentP;
    }
    return r;
  }

  void dump() const {
    dump(root);
    cout << endl;
  }

  Np lower_bound(const T &key) const { return lower_bound(root, key); }
  Np upper_bound(const T &key) const { return upper_bound(root, key); }

  T at(int k) const {
    if(k < 0) k += (int)size();
    assert(0 <= k && k < (int)size());
    return select(root, k)->key;
  }

  T pop(int k){
    T key = at(k); erase(key); return key;
  }

  size_t size() const { return root->sz; }

  struct itr{
    Np t;
    RedBlackTree<T> &tree;
    bool operator!=(const itr &it) const { return t != it.t; }
    void operator++(){ t = tree.successor(t); }
    void operator--(){
      if(t->is_nil()) t = tree.maximum(root);
      else t = tree.predecessor(t);
    }
    T operator*() const { return t->key; }
  };

  itr begin(){ return {minimum(root), *this}; }
  itr end(){ return {get_nil(), *this}; }
};


int main() {
  RedBlackTree<int> rbt;
  int q; cin >> q;
  while(q--){
    int t, x; cin >> t >> x;
    if(t == 1) rbt.insert(x);
    else cout << rbt.pop(--x) << "\n";
  }
}