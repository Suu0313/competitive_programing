#pragma once

struct UnionFind {
  
  vector<int> data;
  int cnt,n,smax;
  
  UnionFind() = default;
  UnionFind(int n_): data(n_,-1),cnt(n_),n(n_),smax(1) {}
  
  void init(int n_) {
    data.assign(n_,-1);
    cnt = n_;
    n = n_;
    smax = 1;
  }
  
  int find(int x) {
    int root = x;
    while(data[root] >= 0) root = data[root];
    while(data[x] >= 0) x = exchange(data[x], root);
    return root;
  }

  bool unite(int x, int y){
    x = find(x);
    y = find(y);
    if(x == y) return false;
    cnt--;

    if(data[x] > data[y]) swap(x,y);
    data[x] += data[y];
    smax = max(smax, -data[x]);
    data[y] = x;
    return true;
  }

  bool same(int x, int y){
    return find(x) == find(y);
  }
  
  int size(int x){
    return -data[find(x)];
  }


  vector<vector<int>> groups() {
    vector<int> leader_buf(n), group_size(n);
    for(int i=0; i<n; i++){
      leader_buf.at(i) = find(i);
      group_size.at(leader_buf.at(i))++;
    }
    vector<vector<int>> result(n);
    for(int i=0; i<n; i++){
      result.at(i).reserve(group_size.at(i));
    }
    for(int i=0; i<n; i++){
      result.at(leader_buf.at(i)).emplace_back(i);
    }
    result.erase(
      remove_if(
        result.begin(), result.end(),
        [&](const vector<int>& v) { return v.empty(); }
      ),
      result.end()
    );
    return result;
  }

};
