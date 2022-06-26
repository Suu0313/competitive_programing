


template<class T> constexpr T Mid(T x, T y) {
  return (x&y) + ((x^y) >> 1);
}

