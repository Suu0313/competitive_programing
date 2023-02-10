namespace geometry{
  constexpr double eps = 1e-10;
  bool eq(double a, double b){ return fabs(a - b) < eps; }
  template<typename T>  bool eq(T a, T b){ return a == b; }
  bool is_zero(double a){ return fabs(a) < eps; }
  template<typename T> bool is_zero(T a){ return a == 0; }
  bool le(double a, double b){ return a <= b + eps; }
  template<typename T> bool le(T a, T b){ return a <= b; }
  bool lt(double a, double b){ return a < b - eps; }
  template<typename T> bool lt(T a, T b){ return a < b; }
  int sgn(double a){ return is_zero(a) ? 0 : ((a < 0) ? -1 : 1); }
  template<typename T> int sgn(T a){ return (a<0) ? -1 : ((a > 0) ? 1 : 0); }
  template<typename T> double psqrt(T a){ return sqrt(max(T(0), a)); }

  enum Dir{ BAC = -2, CW, ACB, CCW, ABC };
};

