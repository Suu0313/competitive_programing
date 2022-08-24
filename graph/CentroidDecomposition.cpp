template<typename T>
struct CentroidDecomposition : Graph<T>{
  using base_t = Graph<T>;
  using base_t::base_t;
  CentroidDecomposition() = default;
  CentroidDecomposition(size_t n):
    base_t(n), used(n), sz(n), parent(n), centroids() {}
  vector<bool> used;
  vector<size_t> sz;
  vector<int> parent, centroids;

  pair<Graph<int>, int> decomposition(){
    Graph<int> decomposition_tree(base_t::size());
    int root = decomposition(0, base_t::size(), decomposition_tree);
    return {decomposition_tree, root};
  }

  int decomposition(int tmp, size_t size, Graph<int> &decomposition_tree){
    auto[centroid, subtrees] = findCentroid(tmp, size);
    used[centroid] = true;

    for(auto&&[sub_c, sub_sz] : subtrees){
      decomposition_tree.add_directed_edge(
        centroid, decomposition(sub_c, sub_sz, decomposition_tree), sub_sz);
    }

    used[centroid] = false;

    return centroid;
  }

  pair<int, vector<pair<int,int>> > findCentroid(int root, int size){
    vector<pair<int, int> > subtrees;
    centroids.clear();
    findCentroidRec(root, size);
    int c = centroids[0];
    for (auto&&e : base_t::operator[](c)) {
        if(used[e]) continue;
        if(e.to == parent[c]) subtrees.emplace_back(e, size-sz[c]);
        else subtrees.emplace_back(e, sz[e]);
    }
    return {c, subtrees};
  }

  void findCentroidRec(int v, int size, int p = -1){
    sz[v] = 1; parent[v] = p;
    bool isCentroid = true;
    for(auto&&e : base_t::operator[](v)){
      if(e.to == p || used[e]) continue;
      findCentroidRec(e, size, v);
      if(sz[e] > size/2) isCentroid = false;
      sz[v] += sz[e];
    }
    if(size-sz[v] > size/2) isCentroid = false;
    if(isCentroid) centroids.push_back(v);
  }
};
