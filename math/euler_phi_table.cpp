vector<int> euler_phi_table(int n) {
  vector<int> euler(n+1);
  iota(euler.begin(), euler.end(), 0);
  
  for(int i = 2; i <= n; i++){
    if(euler[i] == i) {
      for(int j = i; j <= n; j += i) {
        euler[j] = euler[j] / i * (i - 1);
      }
    }
  }
  return euler;
}