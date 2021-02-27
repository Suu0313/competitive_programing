template<typename T>
vector<T> make_v(size_t a,T b){return vector<T>(a,b);}

template<typename... Ts>
auto make_v(size_t a,Ts... ts){
  return vector<decltype(make_v(ts...))>(a,make_v(ts...));
}