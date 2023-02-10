#pragma once

struct Fraction{
  long long a,b;
  constexpr Fraction normalize(){
    if(b < 0){ a = -a; b = -b; }
    long long g = gcd(a, b);
    if(g == 0){
      a = 0; b = 1;
    }else{
      a /= g; b /= g;
    }
    return (*this);
  }
  constexpr Fraction(long long a=0, long long b=1): a(a), b(b) { normalize(); }
  Fraction(string S){
    S += ".0";
    string T;
    vector<string> st;
    stringstream ss{S};
    while(getline(ss,T,'.')) st.emplace_back(T);
    long long A = stoll(st[0]), B = stoll(st[1]), D = 1;
    for(size_t i = 0; i < st[1].size(); i++) D *= 10;
    A = A*D+B; a = A; b = D;
    normalize();
    if(S[0] == '-' && a>0) a = -a;
  }
  constexpr double QtoR() const { return (double)(a) / b; }
  constexpr long long QtoZ() const { return a / b; }

  constexpr Fraction &operator+=(const Fraction &p){
    long long l = lcm(b, p.b);
    a = a*(l/b) + p.a*(l/p.b);
    b = l;
    normalize();
    return *this;
  }
  constexpr Fraction &operator-=(const Fraction &p){
    long long l = lcm(b, p.b);
    a = a*(l/b) - p.a*(l/p.b);
    b = l;
    normalize();
    return *this;
  }
  constexpr Fraction &operator*=(const Fraction &p){
    Fraction x(a, p.b), y(p.a, b);
    a = x.a * y.a;
    b = x.b * y.b;
    normalize();
    return *this;
  }
  constexpr Fraction &operator/=(const Fraction &p){
    return (*this) *= p.inverse();
  }
  constexpr Fraction operator-() const {
    return Fraction(-a, b);
  }
  constexpr Fraction &operator=(long long a){
    return (*this) = Fraction(a, 1);
  }
  constexpr Fraction operator+(const Fraction &p) const {
    return Fraction(*this) += p;
  }
  constexpr Fraction operator-(const Fraction &p) const {
    return Fraction(*this) -= p;
  }
  constexpr Fraction operator*(const Fraction &p) const {
    return Fraction(*this) *= p;
  }
  constexpr Fraction operator/(const Fraction &p) const {
    return Fraction(*this) /= p;
  }
  constexpr bool operator==(const Fraction &p) const {
    return (a==p.a)&&(b==p.b);
  }
  constexpr bool operator!=(const Fraction &p) const {
    return (a!=p.a)||(b!=p.b);
  }

  constexpr Fraction inverse() const {
    return Fraction(b, a);
  }
  constexpr Fraction abs(const Fraction &p){
    Fraction res = p;
    if(res.a < 0) res.a = -res.a;
    return res;
  }

  constexpr bool operator<(const Fraction &p) const {
    return a * p.b < p.a * b;
  }

  friend ostream &operator<<(ostream &os, const Fraction &p) {
    os << p.a;
    if(p.b != 1) os << "/" << p.b;
    return os;
  }
  friend istream &operator>>(istream &is, Fraction &p) {
    string s;
    is >> s;
    p = Fraction(s);
    return (is);
  }
};