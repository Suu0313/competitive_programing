template<typename T, class Compair = less<T>>
struct Compress{
  vector<T> a;
  Compair cmp;
  Compress(const vector<T> &a, const Compair &cmp = Compair{}, bool bd = true, int base = 0)
  : a(a), cmp(cmp) { if(bd) build(base); }

  void add(const T &x){ a.emplace_back(x); }
  void add(const vector<T> &xs){ for(auto&&x : xs ) a.emplace_back(x); }

  vector<T> dict;
  vector<int> res;
  void build(int base = 0){
    int n = int(a.size());
    if(n == 0) return;

    vector<int> idx(n); iota(idx.begin(), idx.end(), 0);
    sort(idx.begin(), idx.end(), [&](int i, int j){ return cmp(a[i], a[j]); });
    
    res.assign(n, base); dict.assign(1, a[idx[0]]);
    for(int i = 1; i < n; i++){
      int x = idx[i-1], y = idx[i];
      if(a[x] == a[y]) res[y] = res[x];
      else{
        res[y] = res[x] + 1;
        dict.emplace_back(a[y]);
      }
    }
  }

  int get(const T &x) const {
    return lower_bound(begin(dict), end(dict), x) - begin(dict);
  }
  const int &operator[](int k) const { return res[k]; }

  size_t size() const { return dict.size(); }
};
