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

  // F &operator*=(const F &f) {  (*this) = FFT::multiply((*this), f); return (*this); }
  F &operator*=(const F &f) {  (*this) = NTT::multiply((*this), f); return (*this); }
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