vector<int> Zalg(const string &S){
  int N = S.size();
  vector<int> Z(N);
  Z.at(0) = N;
  int i = 1, j = 0;
  
  while(i < N){
    while(i+j < N && S.at(j) == S.at(i+j)) ++j;
    Z.at(i) = j;
    if(j==0){i++; continue;}
    
    int k = 1;
    while(k<j && k+Z.at(k) < j){
      Z.at(i+k) = Z.at(k);
      ++k;
    }
    i += k;
    j -= k;
  }
  return Z;
}
