#define ADD_OVERFLOW(a, b) __builtin_add_overflow_p (a, b, (decltype(a)) 0)
#define SUB_OVERFLOW(a, b) __builtin_sub_overflow_p (a, b, (decltype(a)) 0)
#define MUL_OVERFLOW(a, b) __builtin_mul_overflow_p (a, b, (decltype(a)) 0)

template<typename T>
T ADD(const T &a, const T &b, const T &lim = numeric_limits<T>::max()){
  if(ADD_OVERFLOW(a,b)){ return lim; } return min(a+b, lim);
}
template<typename T>
T SUB(const T &a, const T &b, const T &lim = numeric_limits<T>::lowest()){
  if(SUB_OVERFLOW(a,b)){ return lim; } return max(a-b, lim);
}
template<typename T>
T MUL(const T &a, const T &b, const T &lim = numeric_limits<T>::max()){
  if(MUL_OVERFLOW(a,b)){ return lim; } return min(a*b, lim);
}
