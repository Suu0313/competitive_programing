struct HashInt{
  static constexpr uint64_t mod = (1ull << 61) - 1;
  static constexpr uint64_t mask(int k){ return (1ull << k) - 1; }
  static constexpr uint64_t add(uint64_t a, uint64_t b){
    return ((a+=b) >= mod) ? (a - mod) : a;
  }
  static constexpr uint64_t mul(uint64_t a, uint64_t b){
    uint64_t au = a >> 31, ad = a & mask(31);
    uint64_t bu = b >> 31, bd = b & mask(31);
    int64_t mid = ad*bu + au*bd;
    uint64_t mu = mid >> 30, md = mid & mask(30);
    return au*bu*2 + mu + (md << 31) + ad*bd;
  }
  static constexpr uint64_t cal_mod(uint64_t a){
    uint64_t res = (a >> 61) + (a & mask(61));
    return (res>=mod) ? (res-mod) : res;
  }

  uint64_t x;
  HashInt() = default;
  HashInt(uint64_t x): x(cal_mod(x)) {}

  HashInt &operator+=(const HashInt &h){ x = add(x, h.x); return (*this); }
  HashInt &operator*=(const HashInt &h){ x = cal_mod(mul(x, h.x)); return (*this); }
  HashInt operator+(const HashInt &h) const { return HashInt(*this) += h; }
  HashInt operator*(const HashInt &h) const { return HashInt(*this) *= h; }
  friend ostream &operator<<(ostream &os, const HashInt &h){ return os << h.x; }
};
