template<typename Tx, typename Ty>
struct RangeTree{ // memory yabai

  struct Node{
    Tx key;
    Treap<pair<Ty, int>> ps;
    bool operator<(const Node &t) const { return key < t.key; }
    bool operator==(const Node &t) const { return key == t.key; }

    Node() {}
    Node(const Tx &x): key(x), ps() { }
    Node(const Tx &x, const Ty &y, int idx): key(x), ps() {
      ps.insert({y, idx});
    }
  };

  Treap<Node> tree;
  RangeTree() {}

  void add(const Tx &x, const Ty &y, int idx = -1){
    auto t = tree.find(Node(x));
    if(!t) tree.insert(Node(x, y, idx));
    else t->key.ps.insert({y, idx});
  }

  vector<tuple<Tx, Ty, int>> search(const Tx &l, const Tx &r, const Ty &d, const Ty u){
    vector<tuple<Tx, Ty, int>> res;
    auto f = [&](const Node &t){
      auto ps = t.ps.enumerate({d, -1}, {u, -1});
      for(auto&[y,idx] : ps) res.emplace_back(t.key, y, idx);
    };
    tree.enumerate({l}, {r}, f);
    return res;
  };
};
