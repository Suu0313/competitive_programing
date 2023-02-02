template<typename T>
struct QuadraicField{
  T a, b;
  static T &get_base(){
    static T base = T(0);
    return base;
  }
  
  static void set_base(const T &bs){ get_base() = bs; }

  QuadraicField() {}
  QuadraicField(const T &a, const T &b): a(a), b(b) {}

  QuadraicField &operator+=(const QuadraicField &x){
    a += x.a; b += x.b; return (*this);
  }
  QuadraicField &operator-=(const QuadraicField &x){
    a -= x.a; b -= x.b; return (*this);
  }
  QuadraicField operator*(const QuadraicField &x) const {
    return QuadraicField(a*x.a + b*x.b*get_base(), a*x.b+b*x.a);
  }
  QuadraicField &operator*=(const QuadraicField &x){
    return (*this) = (*this) * x;
  }

  QuadraicField pow(int64_t n) const {
    QuadraicField res(1, 0), a(*this);
    while(n){
      if(n & 1) res *= a;
      a *= a; n >>= 1;
    }
    return res;
  }
};

template<typename T>
T mod_sqrt(const T &a){
  if(T::get_mod() == 2) return a;
  if(a == T(0)) return a;
  int p = T::get_mod();
  if(a.pow((p - 1)/2) != 1) return 0;
  T b = 0;
  while((b*b - a).pow((p - 1)/2) == 1) ++b;
  QuadraicField<T>::set_base(b*b - a);
  QuadraicField<T> x(b, 1);
  return x.pow((p + 1)/2).a;
}