template<int mod>
struct Matrix{
  using Mint = ModInt<mod>;
  vector<vector<Mint>> val;
  Matrix(int n, int m, Mint x=0): val(n,vector<Mint>(m,x)) {}
  Matrix(vector<vector<Mint>> x): val(x) {}
  void init(int n, int m, Mint x=0) {val.assign(n,vector<Mint>(m,x));}
  size_t size() const {return val.size();}
  inline vector<Mint>& operator[] (int i) {return val[i];}
  inline vector<Mint>& at(int i) {return val.at(i);}
};

template<int mod>
Matrix<mod> operator*(Matrix<mod>A, Matrix<mod>B) {
  Matrix<mod> res(SZ(A), SZ(B.at(0)));
  REP(i, SZ(A))REP(j,SZ(B.at(0)))REP(k,SZ(B)){
    res.at(i).at(j) += A.at(i).at(k)*B.at(k).at(j);
  }
  return res;
}

template<int mod>
Matrix<mod> pow(Matrix<mod>A, LL n){
  int m = SZ(A);
  Matrix<mod> res(m, m);
  REP(i,m) res.at(i).at(i) = 1;
  while(n > 0){
    if(n & 1) res = res*A;
    A = A*A;
    n >>= 1;
  }
  return res;
}

template<int mod>
int GaussJordan(Matrix<mod> &A, bool is_extended = false) {
  int m = SZ(A), n = SZ(A.at(0));
  int rank = 0;
  REP(col, n){
    if(is_extended && col==n-1) break;
    int pivot = -1;
    FOR(row, rank, m){
      if(A.at(row).at(col) != 0){
        pivot = row;
        break;
      }
    }
    if(pivot == -1) continue;
    swap(A.at(pivot), A.at(rank));

    auto inv = A.at(rank).at(col).inverse();
    REP(col2,n) A.at(rank).at(col2) *= inv;

    REP(row,m){
      if(row != rank && A.at(row).at(col)!=0){
        auto fac = A.at(row).at(col);
        REP(col2,n){
          A.at(row).at(col2) -= A.at(rank).at(col2)*fac;
        }
      }
    }
    ++rank;
  }
  return rank;
}
template<int mod>
int linear_equation(Matrix<mod> A, vector<ModInt<mod>> b, vector<ModInt<mod>> &res){
  int m = SZ(A), n = SZ(A.at(0));
  Matrix<mod> M(m, n+1);
  REP(i,m){
    REP(j,n) M.at(i).at(j) = A.at(i).at(j);
    M.at(i).at(n) = b.at(i);
  }
  int rank = GaussJordan(M, true);

  FOR(row, rank, m){
    if(M.at(row).at(n) != 0) return -1;
  }

  res.assign(n,0);
  REP(i,rank) res.at(i) = M.at(i).at(n);
  return rank;
}
