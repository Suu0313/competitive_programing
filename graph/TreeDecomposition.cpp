struct TreeDecomposition{
  int n;
  using T = int;
  Graph<T> tree;

  vector<int> sz;
  vector<bool> used;

  vector<int> parent;
  vector<int> centroids;

  TreeDecomposition() {}

  void solve(){
    solve(0, n);
    
  }

  void solve(int v, int size){
    auto[c, subtrees] = findCentroid(v, size);
    used[c] = true;

    for(auto&&[e,s] : subtrees) solve(e, s);

    // がんばる
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
