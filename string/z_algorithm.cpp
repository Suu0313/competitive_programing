template<typename Container>
vector<int> z_algorithm(const Container &s){
  int n = int(s.size());
  vector<int> z(n + 1); z[0] = n;
  int i = 1, j = 0;
  
  while(i < n){
    while(i+j < n && s[j] == s[i+j]) ++j;
    z[i] = j;
    if(j==0){i++; continue;}
    
    int k = 1;
    while(k<j && k+z[k] < j){
      z[i+k] = z[k]; ++k;
    }
    i += k; j -= k;
  }
  return z;
}
