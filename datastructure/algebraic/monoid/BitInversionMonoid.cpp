template<typename T>
struct BitInversionMonoid{

  BitInversionMonoid() = default;
  BitInversionMonoid(const BitInversionMonoid&) = default;
  BitInversionMonoid(BitInversionMonoid&&) = default;
  BitInversionMonoid &operator=(const BitInversionMonoid&) = default;
  BitInversionMonoid &operator=(BitInversionMonoid&&) = default;

  T zero = 0, one = 0, inv = 0;
  BitInversionMonoid(bool b){
    (b ? one : zero) = 1;
  }

  BitInversionMonoid &operator+=(const BitInversionMonoid &m){
    inv += m.inv + one * m.zero;
    zero += m.zero;
    one += m.one;
    return (*this);
  }

  BitInversionMonoid operator+(const BitInversionMonoid &m){ return BitInversionMonoid(*this) += m; }

  bool operator==(const BitInversionMonoid &m) const { return (zero == m.zero) && (one == m.one) && (inv == m.inv); }
  bool operator!=(const BitInversionMonoid &m) const { return !((*this) == m); }

};
