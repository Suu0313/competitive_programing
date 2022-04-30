template<typename T>
struct CentroidDecomposition{
  int n;
  Graph<T> tree;

  vector<int> sz;
  vector<bool> used;

  vector<int> parent;
  vector<int> centroids;

  Graph<int> child;
  int root = -1;

  CentroidDecomposition() = default;
  CentroidDecomposition(int n): n(n), tree(n), sz(n), used(n), parent(n), centroids(), child(n) {}
  CentroidDecomposition(const Graph<T> &tree): n(tree.size()), tree(tree), sz(n), used(n)
  , parent(n), centroids(), child(n) { build(); }
  
  void add_edge(int src, int to, T cost = 1){ tree.add_edge(src, to, cost); }

  void build(){
    root = build(0, n);
  }

  int build(int v, int size){
    auto[c, subtrees] = findCentroid(v, size);
    used[c] = true;

    for(auto&&[e,s] : subtrees){
      child.add_directed_edge(c, build(e, s), s);
    }

    used[c] = false;

    return c;
  }

  vector<int> bfs(int r){
    queue<tuple<int,int,int>> qu;
    qu.emplace(r, 1, -1);
    vector<int> ds;

    while(!qu.empty()){
      auto[v, d, p] = qu.front(); qu.pop();
      ds.push_back(d);
      for(auto&&e : tree[v]){
        if(e == p || used[e]) continue;
        qu.emplace(e, d+1, v);
      }
    }

    return ds;
  }


  pair<int, vector<pair<int,int>> > findCentroid(int root, int size){
    vector<pair<int, int> > subtrees;
    centroids.clear();
    findCentroidRec(root, size);
    int c = centroids[0];
    for (auto&&e : tree[c]) {
        if(used[e]) continue;
        if(e == parent[c]) subtrees.emplace_back(e, size-sz[c]);
        else subtrees.emplace_back(e, sz[e]);
    }
    return {c, subtrees};
  }

  void findCentroidRec(int v, int size, int p = -1){
    sz[v] = 1; parent[v] = p;
    bool isCentroid = true;
    for(auto&&e : tree[v]){
      if(e==p || used[e]) continue;
      findCentroidRec(e, size, v);
      if(sz[e] > size/2) isCentroid = false;
      sz[v] += sz[e];
    }
    if(size-sz[v] > size/2) isCentroid = false;
    if(isCentroid) centroids.push_back(v);
  }
};
