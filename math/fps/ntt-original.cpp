namespace NTT{

  vector<int> bit_rev_perm(int k){
    int n = 1 << k;
    vector<int> a(n);
    for(int i = 0, l = 1; i < k; ++i, l <<= 1){
      n >>= 1;
      for(int j = 0; j < l; ++j){
        a[l + j] = a[j] + n;
      }
    }
    return a;
  }

  long long pow_mod(long long x, long long n, int m) {
    if (m == 1) return 0;
    unsigned int _m = (unsigned int)(m);
    unsigned long long r = 1;
    x %= m;
    if (x < 0) x += m;
    while (n) {
        if (n & 1) r = (r * x) % _m;
        x = (x * x) % _m;
        n >>= 1;
    }
    return r;
  }

  int primitive_root(int m){
      if (m == 2) return 1;
      if (m == 167772161) return 3;
      if (m == 469762049) return 3;
      if (m == 754974721) return 11;
      if (m == 998244353) return 3;
      int divs[20] = {};
      divs[0] = 2;
      int cnt = 1;
      int x = (m-1) / 2;
      while(x%2 == 0) x >>= 1;
      for(int i=3; (long long)(i)*i <= x; i+=2){
        if(x%i == 0){
          divs[cnt++] = i;
          while (x % i == 0) x /= i;
        }
      }
      if(x > 1) divs[cnt++] = x;

      for (int g = 2;; g++) {
          bool ok = true;
          for (int i = 0; i < cnt; i++) {
              if (pow_mod(g, (m - 1) / divs[i], m) == 1) {
                  ok = false;
                  break;
              }
          }
          if (ok) return g;
      }
    }

  int bsf(unsigned int n) { return __builtin_ctz(n); }

  template<class modint>
  void ntt(vector<modint> &a, modint zeta, int k, const vector<int> &rev){
    int n = 1 << k;
    a.resize(n);
    vector<modint> omegas(k);
    omegas[k - 1] = zeta;
    for(int i = k-2; i >= 0; --i) omegas[i] = omegas[i + 1] * omegas[i + 1];
    for(int i = 0; i < n; ++i) if(i > rev[i]) swap(a[i], a[rev[i]]);

    for(int i = 0; i < k; ++i){
    modint omega = 1, omega_m = omegas[i];
      for(int j = 0, m = (1 << i); j < m; ++j){
        for(int k = j; k < n; k += m * 2){
          modint u = a[k], t = omega * a[k + m];
          a[k] = u + t; a[k + m] = u - t;
        }
        omega *= omega_m;
      }
    }
  }

  template<class modint>
  vector<modint> multiply(vector<modint> a, vector<modint> b){
    int n = int(a.size()), m = int(b.size());
    if(min(n, m) <= 60){
      vector<modint> ans(n + m - 1);
      for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
          ans[i + j] += a[i] * b[j];
      return ans;
    }

    int k = 0;
    while((n + m - 1) > (1 << k)) ++k;
    int mod = modint::get_mod(), ps = mod - 1, cnt = bsf(ps);
    ps >>= cnt;
    assert(cnt >= k);
    modint root = primitive_root(mod), zeta = root.pow(ps);
    for(int i = 0; i < cnt - k; ++i) zeta *= zeta;
    vector<int> rev = bit_rev_perm(k);
    ntt(a, zeta, k, rev); ntt(b, zeta, k, rev);
    for(int i = 0; i < (1 << k); ++i) a[i] *= b[i];
    ntt(a, zeta.inverse(), k, rev);
    a.resize(n + m - 1);
    modint inv2 = modint(1 << k).inverse();
    for(auto&&e : a) e *= inv2;
    return a;
  }
}
