template<typename T = double>
tuple<Point<T>,Point<T>,Point<T>> ClockHands(const T& h, const T& m = 0, const T& s = 0){
  const double PI  = 3.141592653589793238462643383279;
  double ts = 2*PI / 60 * s, tm = 2*PI / 60 * m + ts / 60 ,th = 2*PI / 12 * h + tm / 12;
  return make_tuple(Polar<T>(1, th), Polar<T>(1, tm), Polar<T>(1, ts));
}
