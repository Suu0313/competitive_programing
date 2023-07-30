---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/BigInt.cpp\"\n\r\nstruct BigInt : vector<uint64_t>\
    \ {\r\n  using val_type = uint64_t;\r\n  using base_type = vector<val_type>;\r\
    \n  using self = BigInt;\r\n  static constexpr val_type BASE = 100'000'000;\r\n\
    \  static constexpr size_t BASE_LEN = 8;\r\n\r\n  int sign = 0;\r\n  BigInt(int64_t\
    \ x = 0): base_type(1, 0){\r\n    if(x > 0) sign = 1;\r\n    if(x < 0) sign =\
    \ -1, x = -x;\r\n    (*this)[0] = x;\r\n    normalize();\r\n  }\r\n\r\n  BigInt(string\
    \ s): BigInt(0){\r\n    if(s.empty()) return;\r\n    if(s[0] == '-') sign = -1,\
    \ s = s.substr(1);\r\n    else sign = 1;\r\n    s = string((BASE_LEN - s.size()\
    \ % BASE_LEN) % BASE_LEN, '0') + s;\r\n    size_t n = s.size() / BASE_LEN;\r\n\
    \    this->resize(n);\r\n    for(size_t i = 0; i < n; ++i) (*this)[i] = stoull(s.substr((n\
    \ - i - 1) * BASE_LEN, BASE_LEN));\r\n    normalize();\r\n  }\r\n\r\n  BigInt(const\
    \ BigInt&) = default;\r\n  BigInt(BigInt&&) = default;\r\n  BigInt &operator=(const\
    \ BigInt&) = default;\r\n  BigInt &operator=(BigInt&&) = default;\r\n\r\n  void\
    \ normalize(){\r\n    val_type c = 0;\r\n    for(size_t i = 0; ; ++i){\r\n   \
    \   if(i >= this->size()) this->push_back(0);\r\n      c += (*this)[i];\r\n  \
    \    (*this)[i] = c % BASE;\r\n      c /= BASE;\r\n      if(c == 0 && i + 1 ==\
    \ this->size()) break;\r\n    }\r\n    while(!this->empty() && this->back() ==\
    \ 0) this->pop_back();\r\n    if(this->empty()) sign = 0, this->push_back(0);\r\
    \n  }\r\n\r\n  static self add(self a, const self &b){\r\n    a.resize(max(a.size(),\
    \ b.size()));\r\n    for(size_t i = 0, l = b.size(); i < l; ++i) a[i] += b[i];\r\
    \n    a.normalize();\r\n    return a;\r\n  }\r\n\r\n  static self sub(self a,\
    \ const self &b){\r\n    a.resize(max(a.size(), b.size()));\r\n    for(size_t\
    \ i = 0, l = b.size(); i < l; ++i){\r\n      if(a[i] < b[i]){\r\n        size_t\
    \ j = i + 1;\r\n        while(!a[j]) ++j;\r\n        while(i != j) --a[j], a[--j]\
    \ += BASE;\r\n      }\r\n      a[i] -= b[i];\r\n    }\r\n    a.normalize();\r\n\
    \    return a;\r\n  }\r\n\r\n  static self div(self a, self b){\r\n    size_t\
    \ s = a.size(), t = b.size();\r\n    if(a < b) return 0;\r\n\r\n    val_type D\
    \ = BASE;\r\n\r\n    if(t == 1){\r\n      val_type r = 0, d = b[0];\r\n      self\
    \ w(a);\r\n      for(size_t i = s; i--; ){\r\n        w[i] = (r * D + a[i]) /\
    \ d;\r\n        r = (r * D + a[i]) % d;\r\n      }\r\n      w.normalize();\r\n\
    \      return w;\r\n    }\r\n\r\n    val_type n = (t == 1 ? b[t - 1] : (b[t -\
    \ 1] * D + b[t - 2]));\r\n    val_type d = (n < D ? (D / (n + 1)) : D * D / (n\
    \ + 1));\r\n    a *= d; b *= d;\r\n    s = a.size(), t = b.size();\r\n    \r\n\
    \    self m = self(D).pow(s - t) * b;\r\n    size_t h = m.size();\r\n    val_type\
    \ mh = m[h - 1], ms = m[h - 2];\r\n    self c(0);\r\n    if(a >= m){ c += 1; a\
    \ -= m; }\r\n    m.erase(m.begin());\r\n\r\n    auto a_at = [&](size_t i){ return\
    \ (a.size() <= i) ? val_type(0) : a[i]; };\r\n\r\n    for(size_t i = 0; i < s\
    \ - t; ++i){\r\n      c *= D;\r\n      val_type xh = a_at(s - 1 - i) * D + a_at(s\
    \ - 2 - i);\r\n      val_type xs = a_at(s - 3 - i);\r\n      val_type q = min(xh\
    \ / mh, D - 1);\r\n      while(q * ms > (xh - q * mh) * D + xs) --q;\r\n\r\n \
    \     if(self mm = m * self(q); a >= mm){\r\n        c += q;\r\n        a -= mm;\r\
    \n      }else if(q){\r\n        while(a < mm && q > 1){ --q; mm -= m; }\r\n  \
    \      if(q){\r\n          c += q;\r\n          a -= mm;\r\n        }\r\n    \
    \  }\r\n      m.erase(m.begin());\r\n    }\r\n    return c;\r\n  }\r\n\r\n  self\
    \ operator-() const { self r(*this); r.sign = -r.sign; return r; }\r\n\r\n  self\
    \ abs() const { return (sign == -1) ? -(*this) : (*this); }\r\n\r\n  self operator+(const\
    \ self &a) const {\r\n    if(sign == 0) return a;\r\n    if(a.sign == 0) return\
    \ (*this);\r\n    if(sign == a.sign) return add((*this), a);\r\n    if(sign ==\
    \ -1) return a - (-(*this));\r\n    return (*this) - (-a);\r\n  }\r\n\r\n  self\
    \ operator-(const self& a) const {\r\n    if(sign == 0) return -a;\r\n    if(a.sign\
    \ == 0) return (*this);\r\n    if(sign == -1) return -(-(*this) + a);\r\n    if(sign\
    \ == a.sign){\r\n      if((*this) < a) return -(a - (*this));\r\n      return\
    \ sub((*this), a);\r\n    }\r\n    if(sign == -1) return (-(*this)) + a;\r\n \
    \   return (*this) + (-a);\r\n  }\r\n\r\n  self &operator+=(const self &a){ return\
    \ (*this) = (*this) + a; }\r\n  self &operator-=(const self &a){ return (*this)\
    \ = (*this) - a; }\r\n\r\n  self operator*(const self &a) const {\r\n    int ns\
    \ = sign * a.sign;\r\n    if(ns == 0) return self(0);\r\n    self r(0); r.sign\
    \ = ns;\r\n\r\n    size_t sl = this->size(), al = a.size();\r\n    r.resize(sl\
    \ + al);\r\n    for(size_t i = 0; i < sl; ++i){\r\n      for(size_t j = 0; j <\
    \ al; ++j){\r\n        val_type x = (*this)[i] * a[j] + r[i + j];\r\n        r[i\
    \ + j] = x % BASE;\r\n        r[i + j + 1] += x / BASE;\r\n      }\r\n    }\r\n\
    \    r.normalize();\r\n    return r;\r\n  }\r\n  self &operator*=(const self &a){\
    \ return (*this) = (*this) * a; }\r\n\r\n  self pow(uint64_t k) const {\r\n  \
    \  self ret(1), a(*this);\r\n    for(; k; k >>= 1, a *= a){\r\n      if(k & 1)\
    \ ret *= a;\r\n    }\r\n    return ret;\r\n  }\r\n\r\n  self bpow(const self &k)\
    \ const {\r\n    self r(1);\r\n    for(size_t i = k.size(); i--; ) r = r.pow(BASE)\
    \ * (*this).pow(k[i]);\r\n    return r;\r\n  }\r\n\r\n  self pow_mod(uint64_t\
    \ k, const self &m) const {\r\n    self ret(1), a(*this);\r\n    for(; k; k >>=\
    \ 1, a = (a * a) % m){\r\n      if(k & 1) ret = (ret * a) % m;\r\n    }\r\n  \
    \  return ret;\r\n  }\r\n\r\n  self bpow_mod(const self &k, const self &m) const\
    \ {\r\n    self r(1);\r\n    for(size_t i = k.size(); i--; ) r = (r.pow_mod(BASE,\
    \ m) * (*this).pow_mod(k[i], m)) % m;\r\n    return r;\r\n  }\r\n\r\n  uint64_t\
    \ smod(uint64_t m) const {\r\n    uint64_t r = 0;\r\n    for(size_t i = (*this).size();\
    \ i--; ) r = (r * BASE + (*this)[i]) % m;\r\n    return r;\r\n  }\r\n\r\n  self\
    \ operator/(const self &a) const {\r\n    assert(a.sign != 0);\r\n    if(sign\
    \ == 0) return 0;\r\n    if(sign != a.sign) return -(this->abs() / a.abs());\r\
    \n    if(sign == -1) return (this->abs() / a.abs());\r\n    return div(*this,\
    \ a);\r\n  }\r\n\r\n  self &operator/=(const self &a){ return (*this) = (*this)\
    \ / a; }\r\n\r\n  self &operator%=(const self &a){ return (*this) -= (*this) /\
    \ a * a; }\r\n  self operator%(const self &a) const { return self(*this) %= a;\
    \ }\r\n\r\n  pair<self, self> divmod(const self &m) const {\r\n    self d = (*this)\
    \ / m;\r\n    return {d, d - (*this) * d};\r\n  }\r\n\r\n  int to_int() const\
    \ { return (*this)[0] * sign; }\r\n  int64_t to_ll() const { return (*this)[0]\
    \ * sign; }\r\n  uint64_t to_ull() const { return (*this)[0] * sign; }\r\n\r\n\
    \  string to_string() const {\r\n    if(sign == 0) return \"0\";\r\n    stringstream\
    \ ss;\r\n    if(sign == -1) ss << '-';\r\n    size_t i = this->size() - 1;\r\n\
    \    ss << (*this)[i];\r\n    while(i--){\r\n      ss.width(BASE_LEN);\r\n   \
    \   ss.fill('0');\r\n      ss << (*this)[i];\r\n    }\r\n    return ss.str();\r\
    \n  }\r\n\r\n  int compair(const self &a) const {\r\n    if(sign != a.sign) return\
    \ (sign < a.sign) ? -1 : 1;\r\n    if(sign == -1) return -(-(*this)).compair(-a);\r\
    \n    if(this->size() != a.size()) return (this->size() < a.size()) ? -1 : 1;\r\
    \n    for(size_t i = a.size(); i--; ){\r\n      if((*this)[i] != a[i]) return\
    \ ((*this)[i] < a[i]) ? -1 : 1;\r\n    }\r\n    return 0;\r\n  }\r\n\r\n  bool\
    \ operator<(const self &a) const { return this->compair(a) == -1; }\r\n  bool\
    \ operator>(const self &a) const { return this->compair(a) == 1; }\r\n  bool operator<=(const\
    \ self &a) const { return this->compair(a) <= 0; }\r\n  bool operator>=(const\
    \ self &a) const { return this->compair(a) >= 0; }\r\n  bool operator==(const\
    \ self &a) const { return this->compair(a) == 0; }\r\n  bool operator!=(const\
    \ self &a) const { return this->compair(a) != 0; }\r\n  explicit operator bool()\
    \ const { return sign != 0; }\r\n  bool is_zero() const { return sign == 0; }\r\
    \n\r\n  friend istream &operator>>(istream &is, self &a){\r\n    string s; is\
    \ >> s;\r\n    a = self(s);\r\n    return is;\r\n  }\r\n  friend ostream &operator<<(ostream\
    \ &os, const self &a){\r\n    if(a.sign == 0) return os << 0;\r\n    if(a.sign\
    \ == -1) os << '-';\r\n    size_t i = a.size() - 1;\r\n    os << a[i];\r\n   \
    \ while(i--){\r\n      os.width(BASE_LEN);\r\n      os.fill('0');\r\n      os\
    \ << a[i];\r\n    }\r\n    return os;\r\n  }\r\n};\r\nnamespace bint_literal{\
    \ BigInt operator\"\"_bi(unsigned long long x) { return x; } }\r\nusing namespace\
    \ bint_literal;\r\n"
  code: "#pragma once\r\n\r\nstruct BigInt : vector<uint64_t> {\r\n  using val_type\
    \ = uint64_t;\r\n  using base_type = vector<val_type>;\r\n  using self = BigInt;\r\
    \n  static constexpr val_type BASE = 100'000'000;\r\n  static constexpr size_t\
    \ BASE_LEN = 8;\r\n\r\n  int sign = 0;\r\n  BigInt(int64_t x = 0): base_type(1,\
    \ 0){\r\n    if(x > 0) sign = 1;\r\n    if(x < 0) sign = -1, x = -x;\r\n    (*this)[0]\
    \ = x;\r\n    normalize();\r\n  }\r\n\r\n  BigInt(string s): BigInt(0){\r\n  \
    \  if(s.empty()) return;\r\n    if(s[0] == '-') sign = -1, s = s.substr(1);\r\n\
    \    else sign = 1;\r\n    s = string((BASE_LEN - s.size() % BASE_LEN) % BASE_LEN,\
    \ '0') + s;\r\n    size_t n = s.size() / BASE_LEN;\r\n    this->resize(n);\r\n\
    \    for(size_t i = 0; i < n; ++i) (*this)[i] = stoull(s.substr((n - i - 1) *\
    \ BASE_LEN, BASE_LEN));\r\n    normalize();\r\n  }\r\n\r\n  BigInt(const BigInt&)\
    \ = default;\r\n  BigInt(BigInt&&) = default;\r\n  BigInt &operator=(const BigInt&)\
    \ = default;\r\n  BigInt &operator=(BigInt&&) = default;\r\n\r\n  void normalize(){\r\
    \n    val_type c = 0;\r\n    for(size_t i = 0; ; ++i){\r\n      if(i >= this->size())\
    \ this->push_back(0);\r\n      c += (*this)[i];\r\n      (*this)[i] = c % BASE;\r\
    \n      c /= BASE;\r\n      if(c == 0 && i + 1 == this->size()) break;\r\n   \
    \ }\r\n    while(!this->empty() && this->back() == 0) this->pop_back();\r\n  \
    \  if(this->empty()) sign = 0, this->push_back(0);\r\n  }\r\n\r\n  static self\
    \ add(self a, const self &b){\r\n    a.resize(max(a.size(), b.size()));\r\n  \
    \  for(size_t i = 0, l = b.size(); i < l; ++i) a[i] += b[i];\r\n    a.normalize();\r\
    \n    return a;\r\n  }\r\n\r\n  static self sub(self a, const self &b){\r\n  \
    \  a.resize(max(a.size(), b.size()));\r\n    for(size_t i = 0, l = b.size(); i\
    \ < l; ++i){\r\n      if(a[i] < b[i]){\r\n        size_t j = i + 1;\r\n      \
    \  while(!a[j]) ++j;\r\n        while(i != j) --a[j], a[--j] += BASE;\r\n    \
    \  }\r\n      a[i] -= b[i];\r\n    }\r\n    a.normalize();\r\n    return a;\r\n\
    \  }\r\n\r\n  static self div(self a, self b){\r\n    size_t s = a.size(), t =\
    \ b.size();\r\n    if(a < b) return 0;\r\n\r\n    val_type D = BASE;\r\n\r\n \
    \   if(t == 1){\r\n      val_type r = 0, d = b[0];\r\n      self w(a);\r\n   \
    \   for(size_t i = s; i--; ){\r\n        w[i] = (r * D + a[i]) / d;\r\n      \
    \  r = (r * D + a[i]) % d;\r\n      }\r\n      w.normalize();\r\n      return\
    \ w;\r\n    }\r\n\r\n    val_type n = (t == 1 ? b[t - 1] : (b[t - 1] * D + b[t\
    \ - 2]));\r\n    val_type d = (n < D ? (D / (n + 1)) : D * D / (n + 1));\r\n \
    \   a *= d; b *= d;\r\n    s = a.size(), t = b.size();\r\n    \r\n    self m =\
    \ self(D).pow(s - t) * b;\r\n    size_t h = m.size();\r\n    val_type mh = m[h\
    \ - 1], ms = m[h - 2];\r\n    self c(0);\r\n    if(a >= m){ c += 1; a -= m; }\r\
    \n    m.erase(m.begin());\r\n\r\n    auto a_at = [&](size_t i){ return (a.size()\
    \ <= i) ? val_type(0) : a[i]; };\r\n\r\n    for(size_t i = 0; i < s - t; ++i){\r\
    \n      c *= D;\r\n      val_type xh = a_at(s - 1 - i) * D + a_at(s - 2 - i);\r\
    \n      val_type xs = a_at(s - 3 - i);\r\n      val_type q = min(xh / mh, D -\
    \ 1);\r\n      while(q * ms > (xh - q * mh) * D + xs) --q;\r\n\r\n      if(self\
    \ mm = m * self(q); a >= mm){\r\n        c += q;\r\n        a -= mm;\r\n     \
    \ }else if(q){\r\n        while(a < mm && q > 1){ --q; mm -= m; }\r\n        if(q){\r\
    \n          c += q;\r\n          a -= mm;\r\n        }\r\n      }\r\n      m.erase(m.begin());\r\
    \n    }\r\n    return c;\r\n  }\r\n\r\n  self operator-() const { self r(*this);\
    \ r.sign = -r.sign; return r; }\r\n\r\n  self abs() const { return (sign == -1)\
    \ ? -(*this) : (*this); }\r\n\r\n  self operator+(const self &a) const {\r\n \
    \   if(sign == 0) return a;\r\n    if(a.sign == 0) return (*this);\r\n    if(sign\
    \ == a.sign) return add((*this), a);\r\n    if(sign == -1) return a - (-(*this));\r\
    \n    return (*this) - (-a);\r\n  }\r\n\r\n  self operator-(const self& a) const\
    \ {\r\n    if(sign == 0) return -a;\r\n    if(a.sign == 0) return (*this);\r\n\
    \    if(sign == -1) return -(-(*this) + a);\r\n    if(sign == a.sign){\r\n   \
    \   if((*this) < a) return -(a - (*this));\r\n      return sub((*this), a);\r\n\
    \    }\r\n    if(sign == -1) return (-(*this)) + a;\r\n    return (*this) + (-a);\r\
    \n  }\r\n\r\n  self &operator+=(const self &a){ return (*this) = (*this) + a;\
    \ }\r\n  self &operator-=(const self &a){ return (*this) = (*this) - a; }\r\n\r\
    \n  self operator*(const self &a) const {\r\n    int ns = sign * a.sign;\r\n \
    \   if(ns == 0) return self(0);\r\n    self r(0); r.sign = ns;\r\n\r\n    size_t\
    \ sl = this->size(), al = a.size();\r\n    r.resize(sl + al);\r\n    for(size_t\
    \ i = 0; i < sl; ++i){\r\n      for(size_t j = 0; j < al; ++j){\r\n        val_type\
    \ x = (*this)[i] * a[j] + r[i + j];\r\n        r[i + j] = x % BASE;\r\n      \
    \  r[i + j + 1] += x / BASE;\r\n      }\r\n    }\r\n    r.normalize();\r\n   \
    \ return r;\r\n  }\r\n  self &operator*=(const self &a){ return (*this) = (*this)\
    \ * a; }\r\n\r\n  self pow(uint64_t k) const {\r\n    self ret(1), a(*this);\r\
    \n    for(; k; k >>= 1, a *= a){\r\n      if(k & 1) ret *= a;\r\n    }\r\n   \
    \ return ret;\r\n  }\r\n\r\n  self bpow(const self &k) const {\r\n    self r(1);\r\
    \n    for(size_t i = k.size(); i--; ) r = r.pow(BASE) * (*this).pow(k[i]);\r\n\
    \    return r;\r\n  }\r\n\r\n  self pow_mod(uint64_t k, const self &m) const {\r\
    \n    self ret(1), a(*this);\r\n    for(; k; k >>= 1, a = (a * a) % m){\r\n  \
    \    if(k & 1) ret = (ret * a) % m;\r\n    }\r\n    return ret;\r\n  }\r\n\r\n\
    \  self bpow_mod(const self &k, const self &m) const {\r\n    self r(1);\r\n \
    \   for(size_t i = k.size(); i--; ) r = (r.pow_mod(BASE, m) * (*this).pow_mod(k[i],\
    \ m)) % m;\r\n    return r;\r\n  }\r\n\r\n  uint64_t smod(uint64_t m) const {\r\
    \n    uint64_t r = 0;\r\n    for(size_t i = (*this).size(); i--; ) r = (r * BASE\
    \ + (*this)[i]) % m;\r\n    return r;\r\n  }\r\n\r\n  self operator/(const self\
    \ &a) const {\r\n    assert(a.sign != 0);\r\n    if(sign == 0) return 0;\r\n \
    \   if(sign != a.sign) return -(this->abs() / a.abs());\r\n    if(sign == -1)\
    \ return (this->abs() / a.abs());\r\n    return div(*this, a);\r\n  }\r\n\r\n\
    \  self &operator/=(const self &a){ return (*this) = (*this) / a; }\r\n\r\n  self\
    \ &operator%=(const self &a){ return (*this) -= (*this) / a * a; }\r\n  self operator%(const\
    \ self &a) const { return self(*this) %= a; }\r\n\r\n  pair<self, self> divmod(const\
    \ self &m) const {\r\n    self d = (*this) / m;\r\n    return {d, d - (*this)\
    \ * d};\r\n  }\r\n\r\n  int to_int() const { return (*this)[0] * sign; }\r\n \
    \ int64_t to_ll() const { return (*this)[0] * sign; }\r\n  uint64_t to_ull() const\
    \ { return (*this)[0] * sign; }\r\n\r\n  string to_string() const {\r\n    if(sign\
    \ == 0) return \"0\";\r\n    stringstream ss;\r\n    if(sign == -1) ss << '-';\r\
    \n    size_t i = this->size() - 1;\r\n    ss << (*this)[i];\r\n    while(i--){\r\
    \n      ss.width(BASE_LEN);\r\n      ss.fill('0');\r\n      ss << (*this)[i];\r\
    \n    }\r\n    return ss.str();\r\n  }\r\n\r\n  int compair(const self &a) const\
    \ {\r\n    if(sign != a.sign) return (sign < a.sign) ? -1 : 1;\r\n    if(sign\
    \ == -1) return -(-(*this)).compair(-a);\r\n    if(this->size() != a.size()) return\
    \ (this->size() < a.size()) ? -1 : 1;\r\n    for(size_t i = a.size(); i--; ){\r\
    \n      if((*this)[i] != a[i]) return ((*this)[i] < a[i]) ? -1 : 1;\r\n    }\r\
    \n    return 0;\r\n  }\r\n\r\n  bool operator<(const self &a) const { return this->compair(a)\
    \ == -1; }\r\n  bool operator>(const self &a) const { return this->compair(a)\
    \ == 1; }\r\n  bool operator<=(const self &a) const { return this->compair(a)\
    \ <= 0; }\r\n  bool operator>=(const self &a) const { return this->compair(a)\
    \ >= 0; }\r\n  bool operator==(const self &a) const { return this->compair(a)\
    \ == 0; }\r\n  bool operator!=(const self &a) const { return this->compair(a)\
    \ != 0; }\r\n  explicit operator bool() const { return sign != 0; }\r\n  bool\
    \ is_zero() const { return sign == 0; }\r\n\r\n  friend istream &operator>>(istream\
    \ &is, self &a){\r\n    string s; is >> s;\r\n    a = self(s);\r\n    return is;\r\
    \n  }\r\n  friend ostream &operator<<(ostream &os, const self &a){\r\n    if(a.sign\
    \ == 0) return os << 0;\r\n    if(a.sign == -1) os << '-';\r\n    size_t i = a.size()\
    \ - 1;\r\n    os << a[i];\r\n    while(i--){\r\n      os.width(BASE_LEN);\r\n\
    \      os.fill('0');\r\n      os << a[i];\r\n    }\r\n    return os;\r\n  }\r\n\
    };\r\nnamespace bint_literal{ BigInt operator\"\"_bi(unsigned long long x) { return\
    \ x; } }\r\nusing namespace bint_literal;\r\n"
  dependsOn: []
  isVerificationFile: false
  path: math/BigInt.cpp
  requiredBy: []
  timestamp: '2023-02-10 14:54:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/BigInt.cpp
layout: document
redirect_from:
- /library/math/BigInt.cpp
- /library/math/BigInt.cpp.html
title: math/BigInt.cpp
---
