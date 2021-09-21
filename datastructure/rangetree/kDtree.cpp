template<typename T, int D>
struct kDTree{
  struct Node{
    int idx, l, r;
    Node(): idx(-1), l(-1), r(-1) {}
  };

  vector<array<T, D>> ps;
  vector<int> idx;
  vector<Node> ts;
  int root;

  kDTree() {}
  kDTree(int n) { ps.reserve(n); }

  void push(const array<T, D> &p){ ps.push_back(p); }

  void build(){
    int n = int(ps.size());
    idx.resize(n); iota(begin(idx), end(idx), 0);
    ts.resize(n);
    int pos = 0;
    root = build(0, n, 0, pos);
  }

  int build(int l, int r, int d, int &pos){
    if(l >= r) return -1;
    int m = (l + r) >> 1;
    int k = d % D;
    nth_element(begin(idx)+l, begin(idx)+m, begin(idx)+r,
      [&](int i, int j){ return ps[i][k] < ps[j][k]; });
    int cur = pos++;
    ts[cur].idx = idx[m];
    ts[cur].l = build(l, m, d+1, pos);
    ts[cur].r = build(m+1, r, d+1, pos);
    return cur;
  }

  vector<int> find(const array<T, D> &l, const array<T, D> &r) const {
    vector<int> res;
    find(root, 0, l, r, res);
    return res;
  }

  void find(int t, int d, const array<T, D> &l, const array<T, D> &r, vector<int> &res) const {
    if(t == -1 || ts[t].idx == -1) return;
    auto p = ps[ts[t].idx];
    bool fl = true;
    for(int k = 0; k < D; ++k){
      if(p[k] < l[k] || r[k] <= p[k]){ fl = false; break; }
    }
    if(fl) res.push_back(ts[t].idx);
    int k = d % D;
    if(ts[t].l != -1 && l[k] <= p[k]) find(ts[t].l, d+1, l, r, res);
    if(ts[t].r != -1 && p[k] < r[k]) find(ts[t].r, d+1, l, r, res);
  }

  int nnSearch(const array<T, D> &q) const {
    int res = -1;
    T m_norm = numeric_limits<T>::max();
    nnSearch(root, 0, q, res, m_norm);
    return res;
  }

  void nnSearch(int t, int d, const array<T, D> &q, int &guess,T &m_norm) const {
    if(t == -1 || ts[t].idx == -1) return;
    auto p = ps[ts[t].idx];
    T norm = Norm(p, q);
    if(norm < m_norm){ guess = ts[t].idx; m_norm = norm; }
    int k = d % D;
    bool dir = q[k] < p[k];
    nnSearch((dir? ts[t].l : ts[t].r), d+1, q, guess, m_norm);
    
    T diff = (p[k] - q[k])*(p[k] - q[k]);
    if(diff < m_norm) nnSearch((dir? ts[t].r : ts[t].l), d+1, q, guess, m_norm);
  }

  using PPQ = priority_queue<pair<T, int>>;

  vector<int> knnSearch(const array<T, D> &q, int k) const {
    if(k == 0) return {};
    if(k == 1) return { nnSearch(q) };
    PPQ pq;
    knnSearch(root, 0, q, pq, k);
    vector<int> res(pq.size());
    for(int i = int(pq.size())-1; i >= 0; --i){
      res[i] = pq.top().second; pq.pop();
    }
    return res;
  }

  void knnSearch(int t, int d, const array<T, D> &q, PPQ &pq, int k) const {
    if(t == -1 || ts[t].idx == -1) return;
    auto p = ps[ts[t].idx];
    T norm = Norm(p, q);
    pq.emplace(norm, ts[t].idx);
    if(int(pq.size()) > k) pq.pop();

    int axis = d % D;
    bool dir = q[axis] < p[axis];
    knnSearch((dir? ts[t].l : ts[t].r), d+1, q, pq, k);
    
    T diff = (p[axis] - q[axis])*(p[axis] - q[axis]);
    if(int(pq.size()) < k || diff < pq.top().first)
      knnSearch((dir? ts[t].r : ts[t].l), d+1, q, pq, k);
  }

  vector<int> radiusSearch(const array<T, D> &q, const T &norm) const {
    vector<int> res;
    radiusSearch(root, 0, q, norm, res);
    return res;
  }

  void radiusSearch(int t, int d, const array<T, D> &q, const T &norm, vector<int> &res) const {
    if(t == -1 || ts[t].idx == -1) return;
    auto p = ps[ts[t].idx];
    if(!(norm < Norm(p, q))) res.push_back(ts[t].idx);
    int k = d % D;
    bool dir = q[k] < p[k];
    radiusSearch((dir? ts[t].l : ts[t].r), d+1, q, norm, res);
    
    T diff = (p[k] - q[k])*(p[k] - q[k]);
    if(!(norm < diff)) radiusSearch((dir? ts[t].r : ts[t].l), d+1, q, norm, res);
  }

  static T Norm(const array<T, D> &p, const array<T, D> &q){
    T norm = 0;
    for(int k = 0; k < D; ++k) norm += (p[k]-q[k]) * (p[k]-q[k]);
    return norm;
  }
};

template<typename T>
struct twoDTree : kDTree<T, 2> {
  using kDTree<T, 2>::kDTree;
  void push(const T &x, const T &y){ kDTree<T, 2>::push( array<T,2>{x, y} ); }
  vector<int> find(const T &l, const T &r, const T &d, const T &u) const {
    return kDTree<T, 2>::find(array<T,2>{l, d}, array<T,2>{r, u});
  }
  int nnSearch(const T &x, const T &y) const {
    return kDTree<T, 2>::nnSearch( array<T,2>{x, y} );
  }
  vector<int> knnSearch(const T &x, const T &y, int k) const {
    return kDTree<T, 2>::knnSearch( array<T,2>{x, y}, k);
  }
  vector<int> radiusSearch(const T &x, const T &y, const T &norm) const {
    return kDTree<T, 2>::radiusSearch( array<T,2>{x, y}, norm);
  }
};
