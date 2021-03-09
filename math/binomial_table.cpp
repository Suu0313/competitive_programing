template<typename T>
vector<vector<T>> binomial_table(int N){
  vector<vector<T>> mat(N+1, vector<T>(N+1));
  CREP(i,N)CREP(j,i){
    if(j==0 || j==i) mat.at(i).at(j) = 1;
    else mat.at(i).at(j) = mat.at(i-1).at(j-1) + mat.at(i-1).at(j);
  }
  return mat;
}
