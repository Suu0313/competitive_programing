template<typename T>
struct Kitamasa{
  const int k;
  const vector<T> a, c;
  const T e, id;
  Kitamasa(const vector<T> &a, const vector<T> &c, const T &e = 1, const T &id = 0): k(a.size()), a(a), c(c), e(e), id(id) {}

  T solve(long long n){
    T res = id;
    auto d = cal(n);
    for(int i = 0; i < k; i++) res += d[i] * a[i];
    return res;
  }

private:
  vector<T> p1(const vector<T> &x){
    vector<T> res(k, id);
    res[0] = x[k-1] * c[0];
    for(int i = 1; i < k; i++){
      res[i] = x[i-1] + (x[k-1] * c[i]);
    }
    return res;
  }

  vector<T> sq(const vector<T> &x){
    vector<T> res(k, id);
    auto d = x;
    for(int i = 0; i < k; i++){
      for(int j = 0; j < k; j++){
        res[j] += x[i] * d[j];
      }
      d = p1(d);
    }
    return res;
  }

  vector<T> cal(long long n){
    vector<T> res(k, id); res[0] = e;
    
    for(int i = 62; i >= 0; i--){
      res = sq(res);
      if(n & (1ll << i)) res = p1(res);
    }
    return res;
  }
};
