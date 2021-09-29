
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


namespace FFT{
  template<int mod>
  vector<ModInt<mod>> tovMint(const vector<long long> &a){
    vector<ModInt<mod>> res(a.size());
    for (size_t i = 0; i < a.size(); i++) res[i] = a[i];
    return res;
  }

  vector<long long> multiply(const vector<long long> &a, const vector<long long> &b){
    int n = int(a.size()), m = int(b.size());
    if (!n || !m) return {};

    static constexpr unsigned long long MOD1 = 754974721;
    static constexpr unsigned long long MOD2 = 167772161;
    static constexpr unsigned long long MOD3 = 469762049;
    static constexpr unsigned long long M2M3 = MOD2 * MOD3;
    static constexpr unsigned long long M1M3 = MOD1 * MOD3;
    static constexpr unsigned long long M1M2 = MOD1 * MOD2;
    static constexpr unsigned long long M1M2M3 = MOD1 * MOD2 * MOD3;

    static constexpr unsigned long long i1 = 190329765;
    static constexpr unsigned long long i2 = 58587104;
    static constexpr unsigned long long i3 = 187290749;

    auto c1 = NTT::multiply(tovMint<MOD1>(a), tovMint<MOD1>(b));
    auto c2 = NTT::multiply(tovMint<MOD2>(a), tovMint<MOD2>(b));
    auto c3 = NTT::multiply(tovMint<MOD3>(a), tovMint<MOD3>(b));

    
    
    vector<long long> c(n + m - 1);

    for(int i = 0; i < n+m-1; i++){
      unsigned long long x = 0, x1 = c1[i].x, x2 = c2[i].x, x3 = c3[i].x;
        x += (x1 * i1) % MOD1 * M2M3;
        x += (x2 * i2) % MOD2 * M1M3;
        x += (x3 * i3) % MOD3 * M1M2;
        int diff = (c1[i] - (long long)x).x;
        static constexpr unsigned long long offset[5] = {0, 0, M1M2M3, 2 * M1M2M3, 3 * M1M2M3};
        x -= offset[diff % 5];
        c[i] = x;
    }
    return c;
  }

  template<int mod>
  vector<ModInt<mod>> multiply(const vector<ModInt<mod>> &a, const vector<ModInt<mod>> &b){
    int n = int(a.size()), m = int(b.size());
    if (!n || !m) return {};

    for(int md : {998244353, 2, 167772161, 469762049, 754974721}){
      if(mod == md) return NTT::multiply(a, b);
    }

    static constexpr long long MOD1 = 754974721;
    static constexpr long long MOD2 = 167772161;
    static constexpr long long MOD3 = 469762049;

    static const ModInt<MOD2> i1 = ModInt<MOD2>(MOD1).inverse();
    static const ModInt<MOD3> i2 = ModInt<MOD3>(MOD1 * MOD2).inverse();
    static const ModInt<mod> M12 = MOD1 * MOD2;

    vector<long long> a2(n), b2(m);
    for(int i = 0; i < n; i++) a2[i] = a[i].x;
    for(int i = 0; i < m; i++) b2[i] = b[i].x;

    auto c1 = NTT::multiply(tovMint<MOD1>(a2), tovMint<MOD1>(b2));
    auto c2 = NTT::multiply(tovMint<MOD2>(a2), tovMint<MOD2>(b2));
    auto c3 = NTT::multiply(tovMint<MOD3>(a2), tovMint<MOD3>(b2));

    vector<ModInt<mod>> c(n + m - 1);
    for(int i = 0; i < n+m-1; i++){
      ModInt<MOD2> v1 = (c2[i] - c1[i].x) * i1;
      ModInt<MOD3> v2 = (c3[i] - c1[i].x  - v1.x * MOD1) * i2;
      c[i] = M12 * v2.x + c1[i].x + MOD1 * v1.x;
    }
    return c;
  }
}


template< typename T >
struct Formalpowerseries : vector<T> {
  using vector<T>::vector;
  using vector<T>::operator=;
  using F = Formalpowerseries;
  
  void set(size_t i, const T &x){
    while(i >= this->size()) this->emplace_back(0);
    (*this)[i] = x;
  }

  void shrink(){
    while(this->size() && this->back() == T(0)) this->pop_back();
  }

  T eval(const T &x) const {
    T res = 0, w = 1;
    for(auto &&a : (*this)){
      res += a * w; w *= x;
    }
    return res;
  }
  T operator()(const T &x) const { return eval(x); }

  F operator-() const {
    F res(*this);
    for(auto &&a : res) a = -a;
    return res;
  }

  F &operator+=(const T &c){
    if(this->empty()) this->resize(1);
    (*this)[0] += c;
    return (*this);
  }

  F operator+(const T &c) const {return F(*this) += c; }

  F &operator-=(const T &c){
    if(this->empty()) this->resize(1);
    (*this)[0] -= c;
    return (*this);
  }

  F operator-(const T &c) const {return F(*this) -= c; }

  F &operator*=(const T &c){
    for(auto &&a : (*this)) a *= c;
    return (*this);
  }
  F operator*(const T &c) const { return F(*this) *= c; }

  F &operator/=(const T &c){ return (*this) *= T(1)/c; }
  F operator/(const T &c) const { return F(*this) /= c; }

  F &operator+=(const F &f){
    size_t n = f.size();
    if(this->size() < n) this->resize(f.size());
    for(size_t i = 0; i < n; i++) (*this)[i] += f[i];
    return (*this);
  }
  F operator+(const F &f) const { return F(*this) += f; }

  F &operator-=(const F &f){
    size_t n = f.size();
    if(this->size() < n) this->resize(f.size());
    for(size_t i = 0; i < n; i++) (*this)[i] -= f[i];
    return (*this);
  }
  F operator-(const F &f) const { return F(*this) -= f; }

  F &operator*=(const F &f) {  (*this) = FFT::multiply((*this), f); return (*this); }
  //F &operator*=(const F &f) {  (*this) = NTT::multiply((*this), f); return (*this); }
  F operator*(const F &f) const { return F(*this) *= f; }

  F operator/(const F &f) const {
    if(this->size() < f.size()){ return F{}; }
    size_t n = this->size() - f.size() + 1;
    return (rev().pre(n) * f.rev().inv(n)).pre(n).rev();
  }
  F &operator/=(const F &f){ return (*this) = (*this) / f; }

  F operator%(const F &f) const { return ((*this) - (*this) / f * f).pre(f.size()-1); }
  F &operator%=(const F &f){ return (*this) = (*this) % f; }

  F &operator<<=(size_t d){ this->insert(this->begin(), d, T(0)); return (*this); }
  F operator<<(size_t d) const{ return F(*this) <<= d; }

  F &operator>>=(size_t d){ this->erase(this->begin(), this->begin()+min(this->size(), d)); return (*this); }
  F operator>>(size_t d) const{ return F(*this) >>= d; }

  F operator*(const vector<pair<int, T>> &g) const {
    F res(0);
    for(auto&&[d, c] : g) res += ((*this) * c) << d;
    return res;
  }
  F &operator*=(const vector<pair<int, T>> &g){ return (*this) = (*this) * g; }

  bool operator<(const F &f){ return this->size() < f.size(); }
  bool operator<=(const F &f){ return this->size() <= f.size(); }
  bool operator>(const F &f){ return this->size() > f.size(); }
  bool operator>=(const F &f){ return this->size() >= f.size(); }

  F inv(int d = -1) const {
    if(d == -1) d = this->size();
    if((*this)[0] == T(0)) return F{};
    F res(1, T(1) / (*this)[0]);
    for(int i = 1; i < d; i <<= 1){
      res = (res+res - res*res*pre(i<<1)).pre(i << 1);
    }
    return res.pre(d);
  }

  F rev() const { F res(*this); reverse(res.begin(), res.end()); return res; }

  F pre(size_t d) const { return F(this->begin(), this->begin()+min(this->size(), d)); }

  F dot(const F &f) const {
    F res(min(this->size(), f.size()));
    for(size_t i = 0; i < res.size(); i++) res[i] = (*this)[i] * f[i];
    return res;
  }

  F diff() const {
    int n = this->size();
    F res(max(0, n - 1));
    for(int i = 1; i < n; i++) res[i-1] = (*this)[i] * T(i);
    return res;
  }

  F integral() const {
    int n = this->size();
    F res(n + 1);
    for(int i = 0; i < n; i++) res[i+1] = (*this)[i] / T(i + 1);
    return res;
  }

  F log(int d = -1) const {
    if(d == -1) d = this->size();
    if((*this)[0] != T(1)) return F{};
    return (this->diff() * this->inv(d)).pre(d-1).integral();
  }

  F exp(int d = -1) const {
    if(d == -1) d = this->size();
    if((*this)[0] != T(0)) return F{};
    F res(1, T(1));
    for(int i = 1; i < d; i <<= 1){
      res = res*(pre(i<<1) + T(1) - res.log(i<<1)).pre(i<<1);
    }
    return res.pre(d);
  }

  F pow(int64_t k, int d = -1) const {
    const int n = this->size();
    if(d == -1) d = n;
    for(int i = 0; i < n; ++i){
      if((*this)[i] == T(0)) continue;
      if(i*k > d) return F(d, T(0));
      T inv = T(1) / (*this)[i];
      F res = ((((*this)*inv) >> i).log() * k).exp() * ((*this)[i].pow(k));
      res = (res << (i*k)).pre(d);
      if(int(res.size()) < d) res.resize(d, T(0));
      return res;
    }
    return (*this);
  }
};
