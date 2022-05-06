template<typename T>
struct MatrixTree : Matrix<T>{
  int n;
  MatrixTree() = default;
  MatrixTree(int _n): Matrix<T>(_n - 1), n(_n - 1) {}

  void add_edge(int i, int j, const T &x = 1){
    if(i < n) (*this)[i][i] += x;
    if(j < n) (*this)[j][j] += x;
    if(i < n && j < n) (*this)[i][j] -= x, (*this)[j][i] -= x;
  }

  T solve() const { return determinant((*this)); }
};
