template<typename T>
struct Combination{
  // T は mint の想定です
  int N;
  vector<T> fact_, inv_, finv_;

  Combination(){}
  Combination(int n):N(n+1), fact_(N,1), inv_(N,1), finv_(N,1){
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
    assert(n<N);
    return fact_.at(n);
  }
  T inv(int n){
    if(n < 0) return 0;
    assert(n<N);
    return inv_.at(n);
  }
  T finv(int n){
    if(n < 0) return 0;
    assert(n<N);
    return finv_.at(n);
  }

  T com(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    assert(n<N);
    return fact_.at(n) * finv_.at(k) * finv_.at(n-k);
  }

  T parm(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    assert(n<N);
    return fact_.at(n) *finv_.at(n-k);
  }

  T hom(int n, int k){
    if(n < 0 || k < 0) return 0;
    if(k == 0) return 1;
    assert(n+k-1<N);
    return com(n+k-1, k);
  }
};