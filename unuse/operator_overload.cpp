template<typename T1, typename T2>
pair<T1, T2> operator+(const pair<T1, T2> &a, const pair<T1, T2> &b){
  return {a.first + b.first, a.second + b.second};
}
template<typename T1, typename T2>
pair<T1, T2> &operator+=(pair<T1, T2> &a, const pair<T1, T2> &b){
  return a = a+b;
}

template<typename T>
vector<T> &operator++(vector<T> &v){
  for(auto&&e : v){ ++e; } return v;
}
template<typename T>
vector<T> operator++(vector<T> &v, int){
  vector<T> tmp(v); ++v; return tmp;
}
template<typename T>
vector<T> &operator--(vector<T> &v){
  for(auto&&e : v){ --e; } return v;
}
template<typename T>
vector<T> operator--(vector<T> &v, int){
  vector<T> tmp(v); --v; return tmp;
}

template<typename T>
vector<T> &operator+=(vector<T> &v, const T &x){
  for(auto&&e : v){ e += x; } return v;
}
template<typename T>
vector<T> &operator-=(vector<T> &v, const T &x){
  for(auto&&e : v){ e -= x; } return v;
}

template<typename T>
vector<T> operator+(const vector<T> &v, const T &x){
  return vector<T>(v) += x;
}
template<typename T>
vector<T> operator-(const vector<T> &v, const T &x){
  return vector<T>(v) -= x;
}

template<typename... Ts, size_t... Is>
ostream &tuple_output_impl(ostream &os, const tuple<Ts...> &tp, index_sequence<Is...>){
  [[maybe_unused]] bool a[] = {(os << get<Is>(tp) << " ", false)...};
  return os << get<tuple_size<tuple<Ts...>>::value-1>(tp);
}

template<typename... Ts>
ostream &operator<<(ostream &os, const tuple<Ts...> &tp){
  return tuple_output_impl(os, tp, make_index_sequence<tuple_size<tuple<Ts...>>::value-1>());
}
