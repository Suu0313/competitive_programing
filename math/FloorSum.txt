LL FloorSum(LL n, LL m, LL a, LL b){
  // sum[0,n) \floor((ai+b)/m)
  LL res = 0;
  if (a >= m) {
    res += (n - 1)*n*(a / m)/2;
    a %= m;
  }
  if (b >= m) {
    res += n*(b / m);
    b %= m;
  }

  LL y_max = (a*n + b)/m, x_max = (y_max*m - b);
  if (y_max == 0) return res;
  res += (n - (x_max + a - 1)/a) * y_max;
  res += FloorSum(y_max, a, m, (a - x_max %a) % a);
  return res;
}