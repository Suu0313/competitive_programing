#pragma once

template<class Monoid>
struct ElementUF {
  
  vector<int> data;
  vector<Monoid> val;
  
  ElementUF() = default;
  ElementUF(int n): data(n, -1), val(n) {}
  template<typename Iiter>
  ElementUF(Iiter first, Iiter last): ElementUF(distance(first, last)) {
    for(int i = 0; first != last; ++i, ++first) val[i] = *first;
  }
  template<typename T>
  ElementUF(const vector<T> &x): ElementUF(x.begin(), x.end()) {}
  
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

    if(data[x] > data[y]) swap(x, y);

    val[x] += val[y];
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

  Monoid &operator[](int k){ return val[k]; }
  const Monoid &operator[](int k) const { return val[k]; }
};
