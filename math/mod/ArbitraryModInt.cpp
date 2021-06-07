struct ArbitraryModInt {
  
  int x;

  ArbitraryModInt() : x(0) {}

  ArbitraryModInt(int64_t y) : x(y >= 0 ? y % get_mod() : (get_mod() - (-y) % get_mod()) % get_mod()) {}
  
  static int &get_mod() {
    static int mod = 0;
    return mod;
  }

  static void set_mod(int md){
    get_mod() = md;
  }

  ArbitraryModInt &operator+=(const ArbitraryModInt &p) {
    if((x += p.x) >= get_mod()) x -= get_mod();
    return *this;
  }
  ArbitraryModInt &operator-=(const ArbitraryModInt &p) {
    if((x += get_mod() - p.x) >= get_mod()) x -= get_mod();
    return *this;
  }
  ArbitraryModInt &operator*=(const ArbitraryModInt &p) {
    x = (int) (1LL * x * p.x % get_mod());
    return *this;
  }
  ArbitraryModInt &operator/=(const ArbitraryModInt &p) {
    *this *= p.inverse();
    return *this;
  }
  ArbitraryModInt operator-() const { return ArbitraryModInt(-x); }
  ArbitraryModInt operator+(const ArbitraryModInt &p) const { return ArbitraryModInt(*this) += p; }
  ArbitraryModInt operator-(const ArbitraryModInt &p) const { return ArbitraryModInt(*this) -= p; }
  ArbitraryModInt operator*(const ArbitraryModInt &p) const { return ArbitraryModInt(*this) *= p; }
  ArbitraryModInt operator/(const ArbitraryModInt &p) const { return ArbitraryModInt(*this) /= p; }
  bool operator==(const ArbitraryModInt &p) const { return x == p.x; }
  bool operator!=(const ArbitraryModInt &p) const { return x != p.x; }
  bool operator<(const ArbitraryModInt &p) const { return x < p.x; }

  ArbitraryModInt& operator++() { (*this).x+=1; return (*this); }
  ArbitraryModInt& operator--() { (*this).x-=1; return (*this); }
  ArbitraryModInt operator++(int) {
    ArbitraryModInt temp(*this); ++(*this);
    return temp;
  }
  ArbitraryModInt operator--(int) {
    ArbitraryModInt temp(*this); --(*this);
    return temp;
  }

  ArbitraryModInt inverse() const {
    int a = x, b = get_mod(), u = 1, v = 0, t;
    while(b > 0) {
      t = a / b;
      swap(a -= t * b, b);
      swap(u -= t * v, v);
    }
    return ArbitraryModInt(u);
  }
  ArbitraryModInt pow(int64_t n) const {
    ArbitraryModInt ret(1), mul(x);
    while(n > 0) {
      if(n & 1) ret *= mul;
      mul *= mul;
      n >>= 1;
    }
    return ret;
  }
  friend ostream &operator<<(ostream &os, const ArbitraryModInt &p) {
    return os << p.x;
  }
  friend istream &operator>>(istream &is, ArbitraryModInt &a) {
    int64_t t;
    is >> t;
    a = ArbitraryModInt(t);
    return (is);
  }
};

using amint = ArbitraryModInt;
using VMA = vector<amint>;
using VVMA = vector<VMA>;
amint operator""_am(unsigned long long x) { return amint(x); }
