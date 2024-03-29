#pragma once

template<typename T>
struct Combination{
  // T は mint の想定です
  int N;
  vector<T> fact_, inv_, finv_;

  Combination(int n = 10):N(n+1), fact_(N,1), inv_(N,1), finv_(N,1){
    int mod = fact_.at(0).get_mod();

    for (int i = 2; i < N; i++){
      fact_.at(i) = fact_.at(i-1) * i;
      inv_.at(i) = -inv_.at(mod%i) * (mod/i);
      finv_.at(i) = finv_.at(i-1) * inv_.at(i);
    }
  }

  void init(int n) {
    N = n+1;
    fact_.assign(N, 1);
    inv_.assign(N, 1);
    finv_.assign(N, 1);

    int mod = fact_.at(0).get_mod();

    for (int i = 2; i < N; i++){
      fact_.at(i) = fact_.at(i-1) * i;
      inv_.at(i) = -inv_.at(mod%i) * (mod/i);
      finv_.at(i) = finv_.at(i-1) * inv_.at(i);
    }
  }

  T fact(int n){
    if(n < 0) return 0;
    append(n);
    return fact_.at(n);
  }
  T inv(int n){
    if(n < 0) return 0;
    append(n);
    return inv_.at(n);
  }
  T finv(int n){
    if(n < 0) return 0;
    append(n);
    return finv_.at(n);
  }

  T com(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    append(n);
    return fact_.at(n) * finv_.at(k) * finv_.at(n-k);
  }

  T parm(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    append(n);
    return fact_.at(n) *finv_.at(n-k);
  }

  T hom(int n, int k){
    if(n < 0 || k < 0) return 0;
    if(k == 0) return 1;
    append(n+k-1);
    return com(n+k-1, k);
  }

  T catalan(int n){
    return catalan(n, n, 1);
  }

  T catalan(int n, int k){
    return catalan(n, k, 1);
  }

  T catalan(int n, int k, int m){
    if(k < m) return com(n+k, k);
    if(k < n+m-1) return com(n+k, k) - com(n+k, k-m);
    return 0;
  }
  
  T random_walk(int n, int x){
    if(n < abs(x) || n%2 != abs(x)%2) return 0;
    return com(n, (n + x)/2);
  }

  T random_walk(int n, int x, int y){
    return random_walk(n, x+y) * random_walk(n, x-y);
  }

  T mul(std::initializer_list<int> ks){
    int n = accumulate(begin(ks), end(ks), 0);
    T res = fact(n);
    for(int k : ks) res *= finv(k);
    return res;
  }

private:
  void append(int n){
    if(n < N) return;
    fact_.resize(n+1);
    inv_.resize(n+1);
    finv_.resize(n+1);

    int mod = fact_.at(0).get_mod();

    for (int i = N; i < n+1; i++){
      fact_.at(i) = fact_.at(i-1) * i;
      inv_.at(i) = -inv_.at(mod%i) * (mod/i);
      finv_.at(i) = finv_.at(i-1) * inv_.at(i);
    }

    N = n+1;
  }
};
