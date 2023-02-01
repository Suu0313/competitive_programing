template<class Container>
vector<int> manacher(const Container &s){
  int n = int(s.size());
  Container t(n*2 + 1, s[0]);
  for(int i = 0; i < n; ++i) t[i*2 + 1] = s[i];
  n = int(t.size());
  vector<int> dia(n);
  for(int i = 0, j = 0; i < n; ){
    while(i - j >= 0 && i + j < n && t[i - j] == t[i + j]) ++j;
    dia[i] = j;
    int k = 1;
    for( ;i - k >= 0 && i + k < n && k + dia[i - k] < j; ++k){
      dia[i + k] = dia[i - k];
    }
    i += k; j -= k;
  }
  for(auto&e : dia) --e;
  return dia;
}
