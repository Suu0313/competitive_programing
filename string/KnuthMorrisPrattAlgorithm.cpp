vector<int> KnuthMorrisPrattAlgorithm(const string &s){
  int n = int(s.size());
  vector<int> a(n+1, -1);
  for(int i = 0; i < n; ){
    int j = a[i];
    while(j >= 0 && (s[i] != s[j])) j = a[j];
    ++i; ++j;
    if(s[i] == s[j]) a[i] = a[j];
    else a[i] = j;
  }
  return a;
}

template<typename T>
vector<int> KnuthMorrisPrattAlgorithm(const vector<T> &s){
  int n = int(s.size());
  vector<int> a(n+1, -1);
  for(int i = 0; i < n; ){
    int j = a[i];
    while(j >= 0 && (s[i] != s[j])) j = a[j];
    ++i; ++j;
    if(s[i] == s[j]) a[i] = a[j];
    else a[i] = j;
  }
  return a;
}
