template<typename T> T Area(const Polygon<T> &ps, bool harf = true){
  if((int)ps.size() < 3) return 0;
  T res = Cross(ps.back(), ps.front());
  for(int i = 0; i < (int)ps.size()-1; i++){
    res += Cross(ps[i], ps[i+1]);
  }
  if(harf) res /= 2;
  return res;
}
