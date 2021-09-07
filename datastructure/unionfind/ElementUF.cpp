template<typename T>
struct ElementUF {
  using F = function<void(T&, T&)>;
  
  vector<int> data;
  vector<T> val;
  const F f;
  
  ElementUF() {}
  ElementUF(int n, const F &f, const T &id = T{}): data(n, -1), val(n, id), f(f) {}
  
  int find(int x) {
    int root = x;
    while(data[root] >= 0) root = data[root];
    while(data[x] >= 0) tie(data[x], x) = make_pair(root, data[x]);
    return root;
  }

  bool unite(int x, int y){
    x = find(x);
    y = find(y);
    if(x == y) return false;

    if(data[x] > data[y]) swap(x,y);

    f(val[x], val[y]);
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

  T &operator[](int k){ return val[k]; }
  const T &operator[](int k) const { return val[k]; }

};
