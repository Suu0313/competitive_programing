VI euler_phi_table(int n) {
  VI euler(n+1);
  CREP(i,n) {
    euler[i] = i;
  }
  CFOR(i,2,n) {
    if(euler[i] == i) {
      for(int j = i; j <= n; j += i) {
        euler[j] = euler[j] / i * (i - 1);
      }
    }
  }
  return euler;
}