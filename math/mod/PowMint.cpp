#pragma once

template<uint32_t mod>
struct PowMint{
private:
  static constexpr uint32_t totient(uint32_t m){
    uint32_t phi = m;
    for(uint32_t i = 2; i * i <= m; ++i){
      if(m % i != 0) continue;
      phi = phi / i * (i - 1);
      do m /= i; while(m % i == 0);
    }
    if(m != 1) phi = phi / m * (m - 1);
    return phi;
  }

  static constexpr uint32_t pmod(uint64_t x){
    if(x < mod * 2) return x;
    return (x % mod) + mod;
  }

  static uint32_t pow(uint32_t a, uint32_t b){
    uint32_t p = 1;
    for(; b; b >>= 1){
      if(b & 1) p = pmod(uint64_t(p) * a);
      a = pmod(uint64_t(a) * a);
    }
    return p;
  }

public:

  uint32_t a;
  PowMint<totient(mod)> r;

  PowMint() = default;
  PowMint(uint64_t x): a(pmod(x)), r(x) {}
  PowMint(uint32_t a, PowMint<totient(mod)> r): a(a), r(r) {}
  
  uint32_t val() const { return (a < mod) ? a : (a - mod); }
  PowMint &operator*=(const PowMint &p){
    a = pmod(uint64_t(a) * p.a);
    r *= p.r;
    return (*this);
  }
  PowMint &operator+=(const PowMint &p){
    a += p.a;
    if(a >= mod * 2) a -= mod;
    if(a >= mod * 2) a -= mod;
    r += p.r;
    return (*this);
  }

  PowMint operator*(const PowMint &p) const { return PowMint(*this) *= p; }
  PowMint operator+(const PowMint &p) const { return PowMint(*this) += p; }

  PowMint pow(const PowMint &p) const { return{pow(a, p.r.a), r.pow(p.r)}; }
  PowMint operator^(const PowMint &p) const { return pow(p); }
  PowMint &operator^=(const PowMint &p){ return (*this) = pow(p); }

  friend ostream &operator<<(ostream &os, const PowMint &p) {
    return os << p.val();
  }
  friend istream &operator>>(istream &is, PowMint &a) {
    uint64_t t;
    is >> t;
    a = PowMint(t);
    return (is);
  }
};

template<> struct PowMint<1>{
  uint32_t a;
  PowMint() = default;
  PowMint(uint64_t x): a(bool(x)) {}

  uint32_t val() const { return 0; }
  PowMint &operator*=(const PowMint &p){ a &= p.a; return (*this); }
  PowMint &operator+=(const PowMint &p){ a += p.a; return (*this); }
  PowMint operator*(const PowMint &p) const { return PowMint(*this) *= p; }
  PowMint operator+(const PowMint &p) const { return PowMint(*this) += p; }
  PowMint pow(const PowMint &p) const { return {a || !p.a}; }
  PowMint operator^(const PowMint &p) const { return pow(p); }
  PowMint &operator^=(const PowMint &p){ return (*this) = pow(p); }

  friend ostream &operator<<(ostream &os, const PowMint &p) {
    return os << p.val();
  }
  friend istream &operator>>(istream &is, PowMint &a) {
    uint64_t t;
    is >> t;
    a = PowMint(t);
    return (is);
  }
};
