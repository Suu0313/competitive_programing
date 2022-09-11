template<typename T>
struct ArithmeticImos{
  int n, k;
  vector<vector<pair<int, T>>> query;

  ArithmeticImos() = default;
  ArithmeticImos(int n, int k): n(n), k(k), query(n + 1) {}

  void add(int l, int r, const T &x){
    query[l].emplace_back(0, x);
    query[r].emplace_back(r - l, -x);
  }

  vector<T> build(vector<T> a, vector<T> c){
    a.resize(n + k);
    for(int i = 0; i < n; ++i){
      for(int j = 0; j < k; ++j){
        a[i + k] += a[i + j] * c[j];
      }
    }

    vector<T> s(k), res(n);
    for(int i = 0; i < n; ++i){
      T t = 0;
      for(int j = 0; j < k; ++j) t += s[j] * c[j];
      s.erase(begin(s)); s.push_back(t);

      for(auto[l, x] : query[i]){
        for(int j = 0; j < k; ++j) s[j] += a[l + j] * x;
      }

      res[i] = s[0];
    }
    return res;
  }
};
