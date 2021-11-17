template<typename T>
struct IsomorphismofTree{
  map<vector<int>, int> mp;

  IsomorphismofTree(): mp{} {}

  bool Isomorphism(const Graph<T> &tree1, const Graph<T> &tree2){
    auto cs1 = CenterofTree(tree1), cs2 = CenterofTree(tree2);
    for(auto&c1 : cs1)for(auto&c2 : cs2){
      if(AHUHash(tree1, c1) == AHUHash(tree2, c2)) return true;
    }
    return false;
  }

  bool Isomorphism(const Graph<T> &tree1, int p1, const Graph<T> &tree2, int p2){
    return (AHUHash(tree1, p1) == AHUHash(tree2, p2));
  }

  int AHUHash(const Graph<T> &tree, int v, int p = -1){
    vector<int> res;
    for(auto&e : tree[v]){
      if(e.to == p) continue;
      res.emplace_back(AHUHash(tree, e.to, v));
    }
    sort(begin(res), end(res));
    if(mp.find(res) == mp.end()){
      int h = int(mp.size());
      mp[res] = h;
    }
    return mp[res];
  }

  vector<int> CenterofTree(const Graph<T> &tree, int p = 0){
    int n = int(tree.size());
    vector<int> dist = BFS(tree, p);
    auto it = max_element(begin(dist), end(dist));
    int u = it - begin(dist), dmax = *it;
    dist = BFS(tree, u);
    vector<int> cs;
    for(int i = 0; i < n; ++i){
      if(dist[i] == dmax/2 || dist[i] == (dmax+1)/2) cs.emplace_back(i);
    }

    return cs;
  }

  vector<int> BFS(const Graph<T> &tree, int pp = 0){
    int n = int(tree.size());
    vector<int> dist(n, -1);
    dist[pp] = 0;
    queue<pair<int, int>> qu;
    for(qu.emplace(pp, -1); !qu.empty(); qu.pop()){
      auto[v, p] = qu.front();
      for(auto&e : tree[v]){
        if(e.to == p) continue;
        dist[e.to] = dist[v] + 1;
        qu.emplace(e.to, v);
      }
    }
    return dist;
  }
};
