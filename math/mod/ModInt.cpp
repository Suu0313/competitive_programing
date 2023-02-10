#pragma once

template< int mod >
struct ModInt {
  int x;

  constexpr ModInt() : x(0) {}

  constexpr ModInt(int64_t y) : x(y >= 0 ? y % mod : (mod - (-y) % mod) % mod) {}
  
  constexpr ModInt &operator+=(const ModInt &p) {
    if((x += p.x) >= mod) x -= mod;
    return *this;
  }
  constexpr ModInt &operator-=(const ModInt &p) {
    if((x += mod - p.x) >= mod) x -= mod;
    return *this;
  }
  constexpr ModInt &operator*=(const ModInt &p) {
    x = (int) (1LL * x * p.x % mod);
    return *this;
  }
  constexpr ModInt &operator/=(const ModInt &p) {
    *this *= p.inverse();
    return *this;
  }
  constexpr ModInt operator-() const { return ModInt(-x); }
  constexpr ModInt operator+(const ModInt &p) const { return ModInt(*this) += p; }
  constexpr ModInt operator-(const ModInt &p) const { return ModInt(*this) -= p; }
  constexpr ModInt operator*(const ModInt &p) const { return ModInt(*this) *= p; }
  constexpr ModInt operator/(const ModInt &p) const { return ModInt(*this) /= p; }
  constexpr bool operator==(const ModInt &p) const { return x == p.x; }
  constexpr bool operator!=(const ModInt &p) const { return x != p.x; }
  constexpr bool operator<(const ModInt &p) const { return x < p.x; }

  constexpr ModInt& operator++() { (*this).x+=1; return (*this); }
  constexpr ModInt& operator--() { (*this).x-=1; return (*this); }
  constexpr ModInt operator++(int) { ModInt tmp(*this); ++(*this); return tmp; }
  constexpr ModInt operator--(int) { ModInt tmp(*this); --(*this); return tmp; }

  constexpr ModInt inverse() const {
    int a = x, b = mod, u = 1, v = 0, t;
    while(b > 0) {
      t = a / b;
      swap(a -= t * b, b);
      swap(u -= t * v, v);
    }
    return ModInt(u);
  }
  constexpr ModInt pow(int64_t n) const {
    ModInt ret(1), mul(x);
    while(n > 0) {
      if(n & 1) ret *= mul;
      mul *= mul; n >>= 1;
    }
    return ret;
  }
  friend ostream &operator<<(ostream &os, const ModInt &p) {
    return os << p.x;
  }
  friend istream &operator>>(istream &is, ModInt &a) {
    int64_t t;
    is >> t;
    a = ModInt< mod >(t);
    return (is);
  }
  constexpr static int get_mod() { return mod; }
};
template< int mod >
constexpr ModInt<mod> operator+(const int64_t &p, const ModInt<mod> &m){ return ModInt<mod>(p) + m; };
template< int mod >
constexpr ModInt<mod> operator-(const int64_t &p, const ModInt<mod> &m){ return ModInt<mod>(p) - m; };
template< int mod >
constexpr ModInt<mod> operator*(const int64_t &p, const ModInt<mod> &m){ return ModInt<mod>(p) * m; };
template< int mod >
constexpr ModInt<mod> operator/(const int64_t &p, const ModInt<mod> &m){ return ModInt<mod>(p) / m; };

//constexpr int MOD = 1e9 + 7;
//constexpr int MOD = 998244353;
// using mint = ModInt< MOD >;
// using VM = vector<mint>;
// using VVM = vector<VM>;

// namespace mintliteral{ constexpr mint operator""_m(unsigned long long x) { return mint(x); } }
// using namespace mintliteral;
