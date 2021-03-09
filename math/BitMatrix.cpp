const int MAX_ROW = 510;
const int MAX_COL = 510;
struct BitMatrix{
  int H,W;
  bitset<MAX_COL> val[MAX_ROW];
  BitMatrix(int h=1,int w=1):H(h),W(w){}
  bitset<MAX_COL>& operator[](int i){return val[i];}
};
int GaussJordan(BitMatrix &A, bool is_extended = false){
  int rank = 0;
  REP(col, A.W){
    if(is_extended && col == A.W-1) break;
    int pivot = -1;
    FOR(row,rank,A.H){
      if(A[row][col]){
        pivot = row;
        break;
      }
    }
    if(pivot == -1) continue;
    swap(A[pivot],A[rank]);
    REP(row, A.H){
      if(row != rank && A[row][col]) A[row] ^= A[rank];
    }
    ++rank;
  }
  return rank;
}
int linear_equation(BitMatrix A, VI b, VI &res){
  int m = A.H, n = A.W;
  BitMatrix M(m, n+1);
  REP(i,m){
    REP(j,n) M[i][j] = A[i][j];
    M[i][n] = b.at(i);
  }
  int rank = GaussJordan(M,true);
  FOR(row, rank, m) if(M[row][n]) return -1;

  res.assign(n,0);
  REP(i,rank) res.at(i) = M[i][n];
  return rank;
}
