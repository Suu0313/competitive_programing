template<typename T>
struct kDtree{ // Don't balanced
  struct Node{
    Point<T> p;
    Node *l, *r;
    int id;
    Node(const Point<T> &p, int id): p(p), l(nullptr), r(nullptr), id(id) {}
  };

  Node *root;
  kDtree(): root(nullptr) {}
  static bool compare(int d, const Point<T> &p, const Point<T> &q){
    return d ? p.x<q.x : p.y<q.y;
  }
  void insert(int id, const Point<T> &p){
    root = insert(root, 0, p, id);
  }
  vector<pair<int,Point<T>>> search(const Point<T> &ld, const Point<T> &ru){
    vector<pair<int,Point<T>>> res;
    search(root, 0, ld, ru, res);
    return res;
  }

private:
  Node *insert(Node *t, int d, const Point<T> &p, int id){
    if(!t) return new Node(p, id);
    if(compare(d, p, t->p)) t->l = insert(t->l, !d, p, id);
    else t->r = insert(t->r, !d, p, id);
    return t;
  }

  void search(Node *t, int d, const Point<T> &ld, const Point<T> &ru, vector<pair<int,Point<T>>> &res){
    if(!t) return;
    const Point<T> &p = t->p;
    if(ld.x<=p.x && p.x<=ru.x && ld.y<=p.y && p.y<=ru.y) res.emplace_back(t->id, p);
    if(!compare(d, p, ld)) search(t->l, !d, ld, ru, res);
    if(!compare(d, ru, p)) search(t->r, !d, ld, ru, res);
  }
};
