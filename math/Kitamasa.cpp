template<typename T>
struct Kitamasa{
  const int k;
  const vector<T> a, c;
  Kitamasa(const vector<T> &a, const vector<T> &c): k(a.size()), a(a), c(c) {}

  T solve(long long n){
    T res = 0;
    auto d = cal(n);
    for(int i = 0; i < k; i++) res += d[i] * a[i];
    return res;
  }

private:
  vector<T> p1(const vector<T> &x){
    /*
    a_n = sum(x_i * a_i)
    のとき、
    a_n+1 = sum(y_i * a_i)
    となるyを求める
    a_n+1 
    = sum(x_i * a_i+1)
    = sum(x_i * a_i+1) + x_k-1*a_k
    = sum(x_i * a_i+1) + x_k-1*sum(c_i * a_i)
    //*/
    vector<T> res(k);
    res[0] = x[k-1] * c[0];
    for(int i = 1; i < k; i++){
      res[i] = x[i-1] + (x[k-1] * c[i]);
    }
    return res;
  }

  vector<T> sq(const vector<T> &x){
    /*
    a_n = sum(x_i * a_i)
    のとき、
    a_2n = sum(y_i * a_i)
    となるyを求める
    a_2n = sum(x_i * a_n+i)
    
    ここで、
    f(n) = x, f(n+1) = p1(f(n)), ... , f(n+k-1)
    が列挙できたとすると
    a_n+i = sum(f(n+i)_j * a_j)
    となる よって、
    a_2n = sum(x_i*sum(f(n+i)_j * a_j))
    //*/
    vector<T> res(k);
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
    vector<T> res(k); res[0] = 1;
    
    for(int i = 62; i >= 0; i--){
      res = sq(res);
      if(n & (1ll << i)) res = p1(res);
    }
    return res;
  }
};
