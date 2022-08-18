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

namespace FFT{
  template<int mod, typename T>
  vector<ModInt<mod>> tovMint(const vector<T> &a){
    vector<ModInt<mod>> res(a.size());
    for (size_t i = 0; i < a.size(); i++) res[i] = a[i];
    return res;
  }

  vector<int> multiply(const vector<int> &a, const vector<int> &b){
    // must be less than mod
    int n = int(a.size()), m = int(b.size());
    if (!n || !m) return {};
    static constexpr int MOD1 = 998244353;
    auto c = NTT::multiply(tovMint<MOD1>(a), tovMint<MOD1>(b));
    vector<int> res(n+m-1);
    for(int i = 0; i < n+m-1; ++i) res[i] = c[i].x;
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
    if(k == 0) return F(d, 0) + 1;
    for(int i = 0; i < n; ++i){
      if((*this)[i] == T(0)) continue;
      if(i > d / k) return F(d, T(0));
      T inv = T(1) / (*this)[i];
      F res = ((((*this)*inv) >> i).log() * k).exp() * ((*this)[i].pow(k));
      res = (res << (i*k)).pre(d);
      if(int(res.size()) < d) res.resize(d, T(0));
      return res;
    }
    return (*this);
  }

  F sqrt(const function< T(T) > &get_sqrt, int d = -1) const {
    const int n = this->size();
    if(d == -1) d = n;

    if((*this)[0] == T(0)){
      if(all_of(begin(*this), end(*this), [](T x){ return x == T(0); })){
        return F(d, 0);
      }
      for(int i = 1; i < n; ++i){
        if((*this)[i] != T(0)){
          if(i & 1) return F{};
          if(d - (i>>1) <= 0) return F(d, 0);
          auto res = (*this >> i).sqrt(get_sqrt ,d - (i>>1));
          if(res.empty()) return F{};
          res <<= (i >> 1);
          if(int(res.size()) < d) res.resize(d, T(0));
          return res;
        }
      }
      return F{};
    }

    T c = get_sqrt((*this)[0]);
    if(c*c != (*this)[0]) return F{};
    T inv2 = T(1) / T(2);
    F res(1, c);
    for(int i = 1; i < d; i <<= 1){
      res = (res + pre(i << 1)* res.inv(i << 1)) * inv2;
    }
    return res.pre(d);
  }
};
