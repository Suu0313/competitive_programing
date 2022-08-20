template<class modint>
struct NTT{
  static int ps, cnt;
  static modint root, zeta;
  static modint omegas[30], invomegas[30];

  static int bsf(unsigned int n) { return __builtin_ctz(n); }

  static long long pow_mod(long long x, long long n, int m) {
    if (m == 1) return 0;
    unsigned int _m = (unsigned int)(m);
    unsigned long long r = 1;
    x %= m;
    if (x < 0) x += m;
    while (n) {
        if (n & 1) r = (r * x) % _m;
        x = (x * x) % _m; n >>= 1;
    }
    return r;
  }

  static int primitive_root(int m){
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

  static void precalculate(){
    static bool precalculated = false;
    if(precalculated) return;
    precalculated = true;
    int mod = modint::get_mod();
    cnt = bsf(mod - 1);
    ps =  (mod - 1) >> cnt;
    root = primitive_root(mod);
    zeta = root.pow(ps);
    omegas[cnt] = zeta;
    invomegas[cnt] = zeta.inverse();
    for(int i = cnt - 1; i >= 0; --i){
      omegas[i] = omegas[i + 1] * omegas[i + 1];
      invomegas[i] = invomegas[i + 1] * invomegas[i + 1];
    }
  }

  static void ntt(vector<modint> &a, int k){
    int n = 1 << k;
    a.resize(n);
    int i = k - 1;
    if(k & 1){
      modint omega = 1, omega_m = omegas[i + 1];
      for(int j = 0, m = (1 << i); j < m; ++j){
        for(int l = j; l < n; l += m * 2){
          mint u = a[l], t = a[l + m];
          a[l] = u + t; a[l + m] = (u - t) * omega;
        }
        omega *= omega_m;
      }
      --i;
    }
    
    for(; i >= 0; i -= 2){
    modint omega1 = 1, omega_m1 = omegas[i];
    modint omega2 = 1, iomega2 = omegas[2], omega_m2 = omegas[i + 1];
      for(int j = 0, m = (1 << (i - 1)); j < m; ++j){
        for(int l = j; l < n; l += m * 4){
          modint u1 = a[l] + a[l + m * 2], u2 = (a[l] - a[l + m * 2]) * omega2;
          modint t1 = a[l + m] + a[l + m * 3], t2 = (a[l + m] - a[l + m * 3]) * iomega2;

          a[l] = u1 + t1; a[l + m] = (u1 - t1) * omega1;
          a[l + m * 2] = u2 + t2; a[l + m * 3] = (u2 - t2) * omega1;
        }
        omega1 *= omega_m1;
        omega2 *= omega_m2;
        iomega2 *= omega_m2;
      }
    }
  }

  static void invntt(vector<modint> &a, int k){
    int n = 1 << k;
    a.resize(n);

    int i = 0;
    if(k & 1){
      modint omega = 1, omega_m = invomegas[i + 1];
      for(int j = 0, m = (1 << i); j < m; ++j){
        for(int l = j; l < n; l += m * 2){
          modint u = a[l], t = omega * a[l + m];
          a[l] = u + t; a[l + m] = u - t;
        }
        omega *= omega_m;
      }
      ++i;
    }

    for(; i < k; i += 2){
    modint omega1 = 1, omega2 = 1, iomega2 = invomegas[2], omega_m1 = invomegas[i + 1], omega_m2 = invomegas[i + 2];
      for(int j = 0, m = (1 << i); j < m; ++j){
        for(int l = j; l < n; l += m * 4){
          modint u = omega1 * a[l + m], t = omega1 * a[l + m * 3];
          modint u1 = a[l] + u, t1 = a[l] - u;
          modint u2 = a[l + m * 2] + t, t2 = a[l + m * 2] - t;

          a[l] = u1 + (u2 *= omega2); a[l + m * 2] = u1 - u2;
          a[l + m] = t1 + (t2 *= iomega2); a[l + m * 3] = t1 - t2;
        }
        omega1 *= omega_m1;
        omega2 *= omega_m2;
        iomega2 *= omega_m2;
      }
    }
  }

  static vector<modint> multiply(vector<modint> a, vector<modint> b){
    int n = int(a.size()), m = int(b.size());
    if(min(n, m) <= 60){
      vector<modint> ans(n + m - 1);
      for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
          ans[i + j] += a[i] * b[j];
      return ans;
    }
    precalculate();
    int k = 0;
    while((n + m - 1) > (1 << k)) ++k;
    ntt(a, k); ntt(b, k);
    for(int i = 0; i < (1 << k); ++i) a[i] *= b[i];
    invntt(a, k);
    a.resize(n + m - 1);
    modint inv2 = modint(1 << k).inverse();
    for(auto&&e : a) e *= inv2;
    return a;
  }
};

template<class modint> int NTT<modint>::ps = 0;
template<class modint> int NTT<modint>::cnt = 0;
template<class modint> modint NTT<modint>::root = 0;
template<class modint> modint NTT<modint>::zeta = 0;
template<class modint> modint NTT<modint>::omegas[] = {};
template<class modint> modint NTT<modint>::invomegas[] = {};
