template<typename T = long long>
T FloorSum(T n, T m, T a, T b){
  // sum[0,n) \floor((ai+b)/m)
  T res = 0;
  if (a >= m) {
    res += (n - 1) * n / 2 * (a / m);
    a %= m;
  }
  if (b >= m) {
    res += n*(b / m);
    b %= m;
  }

  T last = a * (n-1) + b;
  if(last >= m){
    T l_div = last / m, l_mod = last % m;
    res += l_div + FloorSum(l_div, a, m, l_mod);
  }
  return res;
}
