template<typename T> bool isConvex(const Polygon<T> &ps){
  int n = ps.size();
  for(int i = 0; i < n; i++){
    int j = (i+1==n) ? 0 : (i + 1);
    int k = (j+1==n) ? 0 : (j + 1);
    if(iSP(ps[i], ps[j], ps[k]) == -1) return false;
  }
  return true;
}
