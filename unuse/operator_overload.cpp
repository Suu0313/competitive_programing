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
