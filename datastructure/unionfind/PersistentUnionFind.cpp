#pragma once

#include ".\\PersistentArray.cpp"

struct PersistentUnionFind{
  
  PersistentArray<int, 20> data;
  using Np = PersistentArray<int, 20>::Np;

  PersistentUnionFind() = default;
  PersistentUnionFind(int n): data(vector<int>(n, -1)) {}

  Np &get_root(){ return data.root; }
  
  int find(const Np &t, int k) const {
    int x = data.get(t, k);
    return (x >= 0) ? find(t, x) : k;
  }

  pair<bool, Np> unite(const Np &t, int u, int v){
    u = find(t, u);
    v = find(t, v);
    if(u == v) return {false, t};

    if(data.get(t, u) > data.get(t, v)) swap(u, v);
    
    int x = data.get(t, u), y = data.get(t, v);
    return {true, data.update(data.update(t, u, x + y), v, u)};
  }

  bool same(const Np &t, int u, int v){
    return find(t, u) == find(t, v);
  }
  
  int size(const Np &t, int v){
    return -data.get(t, find(t, v));;
  }
};
