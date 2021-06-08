template<typename Container>
vector<int> Zalgorithm(const Container &S){
  int N = S.size();
  vector<int> Z(N); Z[0] = N;
  int i = 1, j = 0;
  
  while(i < N){
    while(i+j < N && S[j] == S[i+j]) ++j;
    Z[i] = j;
    if(j==0){i++; continue;}
    
    int k = 1;
    while(k<j && k+Z[k] < j){
      Z[i+k] = Z[k]; ++k;
    }
    i += k; j -= k;
  }
  return Z;
}
