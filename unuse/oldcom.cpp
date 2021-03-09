LL fac[MAX], finv[MAX], inv[MAX];

void ConInit(LL M=MOD) {
  fac[0] = fac[1] = 1;
  finv[0] = finv[1] = 1;
  inv[1] = 1;
  for (int i = 2; i < MAX; i++){
    fac[i] = fac[i - 1] * i % M;
    inv[i] = M - inv[M%i] * (M / i) % M;
    finv[i] = finv[i - 1] * inv[i] % M;
  }
}

LL COM(int n, int k, LL M=MOD){
  if (n < k) return 0;
  if (n < 0 || k < 0) return 0;
  return fac[n] * (finv[k] * finv[n - k] % M) % M;
}

LL PARM(int n, int k, LL M=MOD){
  if (n < k) return 0;
  if (n < 0 || k < 0) return 0;
  return fac[n] *finv[n - k] % M;
}

LL HOM(int n, int k, LL M=MOD){
  if(n < 0 || k < 0) return 0;
  if(k == 0) return 1;
  return COM(n+k-1, k, M);
}