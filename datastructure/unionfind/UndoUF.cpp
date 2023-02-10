#pragma once

struct UndoUF {
  vector<int> data;
  stack<pair<int, int>> hist;
  
  UndoUF() {}
  UndoUF(int n): data(n, -1) {}
  void init(int n){
    data.assign(n,-1);
  }

  int find(int x) {
    while(data[x] >= 0) x = data[x];
    return x;
  }

  bool unite(int x, int y){
    x = find(x);
    y = find(y);
    hist.emplace(x,data[x]);
    hist.emplace(y,data[y]);
    if(x == y) return false;

    if(data[x] > data[y]) swap(x,y);
    data[x] += data[y];
    data[y] = x;
    return true;
  }

  bool same(int x, int y){
    return find(x) == find(y);
  }

  int size(int x){
    return -data[find(x)];
  }

  bool undo(){
    if(hist.empty()) return false;
    for(int i = 0; i < 2; i++){
      auto[x,px] = hist.top();
      data[x] = px;
      hist.pop();
    }
    return true;
  }

  void clear(){
    while(!hist.empty()) hist.pop();
  }
  
  void rollback(){
    while(!hist.empty()) undo();
  }
};
