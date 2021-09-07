template<typename T> bool isConvex(const Polygon<T> &ps){
  int n = ps.size();
  for(int i = 0; i < n; i++){
    if(iSP(ps[i], ps[(i+1)%n], ps[(i+2)%n]) == -1) return false;
  }
  return true;
}
