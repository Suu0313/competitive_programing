namespace NTT{

  int bsf(unsigned int n) { return __builtin_ctz(n); }

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

  template<typename Mint>
  void butterfly(std::vector<Mint>& a){
    static int g = primitive_root(Mint::get_mod());
    int n = int(a.size());
    int h = 0;
    while(n > (1<<h)) h++;

    static bool first = true;
    static Mint sum_e[30];

    if (first) {
        first = false;
        Mint es[30], ies[30];  // es[i]^(2^(2+i)) == 1
        int cnt2 = bsf(Mint::get_mod() - 1);
        Mint e = Mint(g).pow((Mint::get_mod() - 1) >> cnt2), ie = e.inverse();
        for (int i = cnt2; i >= 2; i--) {
            // e^(2^i) == 1
            es[i - 2] = e;
            ies[i - 2] = ie;
            e *= e;
            ie *= ie;
        }
        Mint now = 1;
        for (int i = 0; i < cnt2 - 2; i++) {
            sum_e[i] = es[i] * now;
            now *= ies[i];
        }
    }
    for (int ph = 1; ph <= h; ph++) {
        int w = 1 << (ph - 1), p = 1 << (h - ph);
        Mint now = 1;
        for (int s = 0; s < w; s++) {
            int offset = s << (h - ph + 1);
            for (int i = 0; i < p; i++) {
                auto l = a[i + offset];
                auto r = a[i + offset + p] * now;
                a[i + offset] = l + r;
                a[i + offset + p] = l - r;
            }
            now *= sum_e[bsf(~(unsigned int)(s))];
        }
    }
  }

  template<typename Mint>
  void butterfly_inv(std::vector<Mint>& a){
    static int g = primitive_root(Mint::get_mod());
    int n = int(a.size());
    int h = 0;
    while(n > (1<<h)) h++;

    static bool first = true;
    static Mint sum_ie[30];

    if (first) {
        first = false;
        Mint es[30], ies[30];  // es[i]^(2^(2+i)) == 1
        int cnt2 = bsf(Mint::get_mod() - 1);
        Mint e = Mint(g).pow((Mint::get_mod() - 1) >> cnt2), ie = e.inverse();
        for (int i = cnt2; i >= 2; i--) {
            // e^(2^i) == 1
            es[i - 2] = e;
            ies[i - 2] = ie;
            e *= e;
            ie *= ie;
        }
        Mint now = 1;
        for (int i = 0; i < cnt2 - 2; i++) {
            sum_ie[i] = ies[i] * now;
            now *= es[i];
        }
    }
    for (int ph = h; ph >= 1; ph--) {
        int w = 1 << (ph - 1), p = 1 << (h - ph);
        Mint inow = 1;
        for (int s = 0; s < w; s++) {
            int offset = s << (h - ph + 1);
            for (int i = 0; i < p; i++) {
                auto l = a[i + offset];
                auto r = a[i + offset + p];
                a[i + offset] = l + r;
                a[i + offset + p] = (unsigned long long)(Mint::get_mod() + l.x - r.x) *
                    inow.x;
            }
            inow *= sum_ie[bsf(~(unsigned int)(s))];
        }
    }
  }
  
  template<typename Mint>
  vector<Mint> multiply(vector<Mint> a, vector<Mint> b){
    int n = int(a.size()), m = int(b.size());
    if(min(n,m) <= 60){
      if(n < m){
        swap(n, m); swap(a, b);
      }
      vector<Mint> ans(n + m - 1);
      for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
          ans[i + j] += a[i] * b[j];
        }
      }
      return ans;
    }
    int z = 0;
    while(n+m-1 > (1<<z)) z++;
    z = 1 << z;
    a.resize(z); butterfly(a);
    b.resize(z); butterfly(b);

    for(int i=0; i<z; i++) a[i] *= b[i];
    butterfly_inv(a);
    a.resize(n + m - 1);
    Mint iz = Mint(z).inverse();
    for (int i = 0; i < n + m - 1; i++) a[i] *= iz;
    return a;
  }
}
