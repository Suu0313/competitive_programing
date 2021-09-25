struct UnionFindTree {
  
  vector<int> data, left, right, anc;
  int merge_cnt;
  
  UnionFindTree() {}
  UnionFindTree(int n): data(n,-1), left(n*2-1, -1), right(n*2-1, -1), anc(n*2-1), merge_cnt(n) {
    iota(begin(anc), end(anc), 0);
  }
  
  int find(int x) {
    int root = x;
    while(data[root] >= 0) root = data[root];
    while(data[x] >= 0) tie(data[x], x) = make_pair(root, data[x]);
    return root;
  }

  int ancestor(int x){ return anc[find(x)]; }

  bool unite(int x, int y){
    x = find(x);
    y = find(y);
    if(x == y) return false;

    if(data[x] > data[y]) swap(x,y);
    data[x] += data[y];

    left[merge_cnt] = anc[x];
    right[merge_cnt] = anc[y];
    anc[x] = merge_cnt++;
    data[y] = x;
    return true;
  }

  bool same(int x, int y){
    return find(x) == find(y);
  }
  
  int size(int x){
    return -data[find(x)];
  }
};
