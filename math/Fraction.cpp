struct Fraction{
  LL a,b;
  Fraction normalize(){
    if(b < 0){ a = -a; b = -b;
    }
    LL g = gcd(a, b);
    if(g == 0){
      a = 0; b = 1;
    }else{
      a /= g; b /= g;
    }
    return *this;
  }
  Fraction(LL a=0, LL b=1): a(a),b(b){
    normalize();
  }
  Fraction(string S){
    S += ".0";
    string T;
    vector<string> st;
    stringstream ss{S};
    while(getline(ss,T,'.')) st.PB(T);
    LL A = stoll(st.at(0));
    LL B = stoll(st.at(1));
    int C = SZ(st.at(1));
    LL D = 1;
    REP(i,C) D *= 10;
    A = A*D+B;
    a = A, b = D;
    normalize();
    if(S.at(0) == '-' && a>0) a = -a;
  }
  double QtoR() const {
    return (double)(a) / b;
  }
  LL QtoZ() const {
    return a/b;
  }

  Fraction &operator+=(const Fraction &p){
    LL l = lcm(b, p.b);
    a = a*(l/b) + p.a*(l/p.b);
    b = l;
    normalize();
    return *this;
  }
  Fraction &operator-=(const Fraction &p){
    LL l = lcm(b, p.b);
    a = a*(l/b) - p.a*(l/p.b);
    b = l;
    normalize();
    return *this;
  }
  Fraction &operator*=(const Fraction &p){
    Fraction x(a, p.b), y(p.a, b);
    a = x.a * y.a;
    b = x.b * y.b;
    normalize();
    return *this;
  }
  Fraction &operator/=(const Fraction &p){
    *this *= p.inverse();
    return *this;
  }
  Fraction operator-() const {
    return Fraction(-a, b);
  }
  Fraction &operator=(LL a){
    *this = Fraction(a, 1);
    return *this;
  }
  Fraction operator+(const Fraction &p) const {
    return Fraction(*this) += p;
  }
  Fraction operator-(const Fraction &p) const {
    return Fraction(*this) -= p;
  }
  Fraction operator*(const Fraction &p) const {
    return Fraction(*this) *= p;
  }
  Fraction operator/(const Fraction &p) const {
    return Fraction(*this) /= p;
  }
  bool operator==(const Fraction &p) const {
    return (a==p.a)&&(b==p.b);
  }
  bool operator!=(const Fraction &p) const {
    return (a!=p.a)||(b!=p.b);
  }

  Fraction inverse() const {
    return Fraction(b, a);
  }
  Fraction abs(const Fraction &p){
    Fraction res = p;
    if(res.a < 0) res.a = -res.a;
    return res;
  }

  bool operator<(const Fraction &p) const {
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