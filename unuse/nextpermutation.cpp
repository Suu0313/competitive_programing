template<typename T>
bool NextP(vector<T> &a){
  int n = int(a.size());
  int i = -1;
  for(int d = n-2; d >= 0; d--){
    if(a.at(d)<a.at(d+1)){
      i = d;
      break;
    }
  }
  if(i == -1) return false;
  int j = i;
  for(int d = n-1; d >= 0; d--){
    if(a.at(d)>a.at(i)){
      j = d;
      break;
    }
  }
  swap(a.at(i),a.at(j));
  reverse(a.begin()+i+1,a.end());
  return true;
}