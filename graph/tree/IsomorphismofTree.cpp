#pragma once

#include "..\\Graph.cpp"

template<typename T>
struct IsomorphismofTree{

  IsomorphismofTree() = default;

  static constexpr uint64_t mod = (1ull << 61) - 1;
  static constexpr uint64_t mask(int k){ return (1ull << k) - 1; }
  static constexpr uint64_t add(uint64_t a, uint64_t b){
    return ((a+=b) >= mod) ? (a - mod) : a;
  }
  static constexpr uint64_t mul(uint64_t a, uint64_t b){
    uint64_t au = a >> 31, ad = a & mask(31);
    uint64_t bu = b >> 31, bd = b & mask(31);
    int64_t mid = ad*bu + au*bd;
    uint64_t mu = mid >> 30, md = mid & mask(30);
    return au*bu*2 + mu + (md << 31) + ad*bd;
  }
  static constexpr uint64_t cal_mod(uint64_t x){
    uint64_t res = (x >> 61) + (x & mask(61));
    return (res>=mod) ? (res-mod) : res;
  }

  static inline uint64_t generate_base(){
    static mt19937_64 mt(random_device{}());
    static uniform_int_distribution<uint64_t> rand(1, mod-1);
    return rand(mt);
  }

  vector<uint64_t> rs;

  uint64_t TreeHash(const Graph<T> &tree, int v, int p = -1, size_t d = 0){
    while(rs.size() <= d) rs.push_back(generate_base());
    uint64_t hs = 1;
    for(auto&e : tree[v]){
      if(e.to == p) continue;
      hs = cal_mod(mul(hs, add(TreeHash(tree, e.to, v, d + 1), rs[d])));
    }
    return hs;
  }

  bool Isomorphism(const Graph<T> &tree1, const Graph<T> &tree2){
    auto cs1 = CenterofTree(tree1), cs2 = CenterofTree(tree2);
    assert(int(cs1.size()) <= 2); assert(int(cs2.size()) <= 2);
    for(auto&c1 : cs1)for(auto&c2 : cs2){
      if(TreeHash(tree1, c1) == TreeHash(tree2, c2)) return true;
    }
    return false;
  }

  bool Isomorphism(const Graph<T> &tree1, int p1, const Graph<T> &tree2, int p2){
    return (TreeHash(tree1, p1) == TreeHash(tree2, p2));
  }

  vector<int> CenterofTree(const Graph<T> &tree, int p = 0){
    auto[dist, par]  = bfs(tree, p);
    int u = max_element(begin(dist), end(dist)) - begin(dist);

    tie(dist, par) = bfs(tree, u);
    auto it = max_element(begin(dist), end(dist));
    int dmax = *it, v = it - begin(dist);

    for(int i = 0; i < dmax/2; ++i) v = par[v];

    if(dmax%2 == 0) return {v};
    return {v, par[v]};
  }

  pair<vector<int>, vector<int>> bfs(const Graph<T> &tree, int pp = 0){
    int n = int(tree.size());
    vector<int> dist(n, -1), par(n, -1);
    dist[pp] = 0;
    queue<pair<int, int>> qu;
    for(qu.emplace(pp, -1); !qu.empty(); qu.pop()){
      auto[v, p] = qu.front();
      for(auto&e : tree[v]){
        if(e.to == p) continue;
        par[e.to] = v;
        dist[e.to] = dist[v] + 1;
        qu.emplace(e.to, v);
      }
    }
    return {dist, par};
  }
};
