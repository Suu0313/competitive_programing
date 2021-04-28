template <typename T = int>
struct PotentializedUF {
  
  vector<int> data;
  vector<T> diff_weight;
  
  PotentializedUF() {}
  
  PotentializedUF(int n):data(n, -1), diff_weight(n) { }
  
  void init(int n) { 
    data.assign(n, -1);
    diff_weight.assign(n,0);
  }
  
  
  int find(int x) {
    if(data[x] < 0) return x;
    int r = find(data[x]);
    diff_weight[x] += diff_weight[data[x]];
    return data[x] = r;
    
  }

  bool unite(int x, int y, T w){
    w += weight(x); w -= weight(y);
    x = find(x); y = find(y);
    if(x == y) return false;

    if(data[x] > data[y]){ swap(x,y); w = -w; }
    data[x] += data[y];
    data[y] = x;
    diff_weight[y] = w;
    return true;
  }

  T weight(int x){
    find(x);
    return diff_weight[x];
  }

  T diff(int x, int y){
    if(same(x,y)){
      return weight(y) - weight(x);
    }
    return T(0);
  }

  bool same(int x, int y){
    return find(x) == find(y);
  }
  
  int size(int x){
    return -data[find(x)];
  }

};
