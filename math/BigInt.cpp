struct BigInt : vector<uint64_t> {
  using val_type = uint64_t;
  using base_type = vector<val_type>;
  using self = BigInt;
  static constexpr val_type BASE = 100'000'000;
  static constexpr size_t BASE_LEN = 8;

  int sign = 0;
  BigInt(int64_t x = 0): base_type(1, 0){
    if(x > 0) sign = 1;
    if(x < 0) sign = -1, x = -x;
    (*this)[0] = x;
    normalize();
  }

  BigInt(string s): BigInt(0){
    if(s.empty()) return;
    if(s[0] == '-') sign = -1, s = s.substr(1);
    else sign = 1;
    s = string((BASE_LEN - s.size() % BASE_LEN) % BASE_LEN, '0') + s;
    size_t n = s.size() / BASE_LEN;
    this->resize(n);
    for(size_t i = 0; i < n; ++i) (*this)[i] = stoull(s.substr((n - i - 1) * BASE_LEN, BASE_LEN));
    normalize();
  }

  BigInt(const BigInt&) = default;
  BigInt(BigInt&&) = default;
  BigInt &operator=(const BigInt&) = default;
  BigInt &operator=(BigInt&&) = default;

  void normalize(){
    val_type c = 0;
    for(size_t i = 0; ; ++i){
      if(i >= this->size()) this->push_back(0);
      c += (*this)[i];
      (*this)[i] = c % BASE;
      c /= BASE;
      if(c == 0 && i + 1 == this->size()) break;
    }
    while(!this->empty() && this->back() == 0) this->pop_back();
    if(this->empty()) sign = 0, this->push_back(0);
  }

  static self add(self a, const self &b){
    a.resize(max(a.size(), b.size()));
    for(size_t i = 0, l = b.size(); i < l; ++i) a[i] += b[i];
    a.normalize();
    return a;
  }

  static self sub(self a, const self &b){
    a.resize(max(a.size(), b.size()));
    for(size_t i = 0, l = b.size(); i < l; ++i){
      if(a[i] < b[i]){
        size_t j = i + 1;
        while(!a[j]) ++j;
        while(i != j) --a[j], a[--j] += BASE;
      }
      a[i] -= b[i];
    }
    a.normalize();
    return a;
  }

  static self div(self a, self b){
    size_t s = a.size(), t = b.size();
    if(a < b) return 0;

    val_type D = BASE;

    if(t == 1){
      val_type r = 0, d = b[0];
      self w(a);
      for(size_t i = s; i--; ){
        w[i] = (r * D + a[i]) / d;
        r = (r * D + a[i]) % d;
      }
      w.normalize();
      return w;
    }

    val_type n = (t == 1 ? b[t - 1] : (b[t - 1] * D + b[t - 2]));
    val_type d = (n < D ? (D / (n + 1)) : D * D / (n + 1));
    a *= d; b *= d;
    s = a.size(), t = b.size();
    
    self m = self(D).pow(s - t) * b;
    size_t h = m.size();
    val_type mh = m[h - 1], ms = m[h - 2];
    self c(0);
    if(a >= m){ c += 1; a -= m; }
    m.erase(m.begin());

    auto a_at = [&](size_t i){ return (a.size() <= i) ? val_type(0) : a[i]; };

    for(size_t i = 0; i < s - t; ++i){
      c *= D;
      size_t k = a.size();
      val_type xh = a_at(s - 1 - i) * D + a_at(s - 2 - i);
      val_type xs = a_at(s - 3 - i);
      val_type q = min(xh / mh, D - 1);
      while(q * ms > (xh - q * mh) * D + xs) --q;

      if(self mm = m * self(q); a >= mm){
        c += q;
        a -= mm;
      }else if(q){
        while(a < mm && q > 1){ --q; mm -= m; }
        if(q){
          c += q;
          a -= mm;
        }
      }
      m.erase(m.begin());
    }
    return c;
  }

  self operator-() const { self r(*this); r.sign = -r.sign; return r; }

  self abs() const { return (sign == -1) ? -(*this) : (*this); }

  self operator+(const self &a) const {
    if(sign == 0) return a;
    if(a.sign == 0) return (*this);
    if(sign == a.sign) return add((*this), a);
    if(sign == -1) return a - (-(*this));
    return (*this) - (-a);
  }

  self operator-(const self& a) const {
    if(sign == 0) return -a;
    if(a.sign == 0) return (*this);
    if(sign == -1) return -(-(*this) + a);
    if(sign == a.sign){
      if((*this) < a) return -(a - (*this));
      return sub((*this), a);
    }
    if(sign == -1) return (-(*this)) + a;
    return (*this) + (-a);
  }

  self &operator+=(const self &a){ return (*this) = (*this) + a; }
  self &operator-=(const self &a){ return (*this) = (*this) - a; }

  self operator*(const self &a) const {
    int ns = sign * a.sign;
    if(ns == 0) return self(0);
    self r(0); r.sign = ns;

    size_t sl = this->size(), al = a.size();
    r.resize(sl + al);
    for(size_t i = 0; i < sl; ++i){
      for(size_t j = 0; j < al; ++j){
        val_type x = (*this)[i] * a[j] + r[i + j];
        r[i + j] = x % BASE;
        r[i + j + 1] += x / BASE;
      }
    }
    r.normalize();
    return r;
  }
  self &operator*=(const self &a){ return (*this) = (*this) * a; }

  self pow(uint64_t k) const {
    self ret(1), a(*this);
    for(; k; k >>= 1, a *= a){
      if(k & 1) ret *= a;
    }
    return ret;
  }

  self bpow(const self &k) const {
    self r(1);
    for(size_t i = k.size(); i--; ) r = r.pow(BASE) * (*this).pow(k[i]);
    return r;
  }

  self pow_mod(uint64_t k, const self &m) const {
    self ret(1), a(*this);
    for(; k; k >>= 1, a = (a * a) % m){
      if(k & 1) ret = (ret * a) % m;
    }
    return ret;
  }

  self bpow_mod(const self &k, const self &m) const {
    self r(1);
    for(size_t i = k.size(); i--; ) r = (r.pow_mod(BASE, m) * (*this).pow_mod(k[i], m)) % m;
    return r;
  }

  self operator/(const self &a) const {
    assert(a.sign != 0);
    if(sign == 0) return 0;
    if(sign != a.sign) return -(this->abs() / a.abs());
    if(sign == -1) return (this->abs() / a.abs());
    return div(*this, a);
  }

  self &operator/=(const self &a){ return (*this) = (*this) / a; }

  self &operator%=(const self &a){ return (*this) -= (*this) / a * a; }
  self operator%(const self &a) const { return self(*this) %= a; }

  pair<self, self> divmod(const self &m) const {
    self d = (*this) / m;
    return {d, d - (*this) * d};
  }

  int to_int() const { return (*this)[0] * sign; }
  int64_t to_ll() const { return (*this)[0] * sign; }
  uint64_t to_ull() const { return (*this)[0] * sign; }

  string to_string() const {
    if(sign == 0) return "0";
    stringstream ss;
    if(sign == -1) ss << '-';
    size_t i = this->size() - 1;
    ss << (*this)[i];
    while(i--){
      ss.width(BASE_LEN);
      ss.fill('0');
      ss << (*this)[i];
    }
    return ss.str();
  }

  int compair(const self &a) const {
    if(sign != a.sign) return (sign < a.sign) ? -1 : 1;
    if(sign == -1) return -(-(*this)).compair(-a);
    if(this->size() != a.size()) return (this->size() < a.size()) ? -1 : 1;
    for(size_t i = a.size(); i--; ){
      if((*this)[i] != a[i]) return ((*this)[i] < a[i]) ? -1 : 1;
    }
    return 0;
  }

  bool operator<(const self &a) const { return this->compair(a) == -1; }
  bool operator>(const self &a) const { return this->compair(a) == 1; }
  bool operator<=(const self &a) const { return this->compair(a) <= 0; }
  bool operator>=(const self &a) const { return this->compair(a) >= 0; }
  bool operator==(const self &a) const { return this->compair(a) == 0; }
  bool operator!=(const self &a) const { return this->compair(a) != 0; }
  operator bool() const { return sign != 0; }

  friend istream &operator>>(istream &is, self &a){
    string s; is >> s;
    a = self(s);
    return is;
  }
  friend ostream &operator<<(ostream &os, const self &a){
    if(a.sign == 0) return os << 0;
    if(a.sign == -1) os << '-';
    size_t i = a.size() - 1;
    os << a[i];
    while(i--){
      os.width(BASE_LEN);
      os.fill('0');
      os << a[i];
    }
    return os;
  }
};
