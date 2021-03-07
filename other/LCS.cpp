template <typename T>
T LCS(T s, T t){
  int n = SZ(s), m = SZ(t);
  VVI dp(n+1,VI(m+1,0));
  REP(i,n)REP(j,m){
    if(s.at(i)==t.at(j)){
      dp.at(i+1).at(j+1)=dp.at(i).at(j)+1;
    }else{
      dp.at(i+1).at(j+1)=max(dp.at(i+1).at(j),dp.at(i).at(j+1));
    }
  }
  T res;

  for(int i=n,j=m;i>0&&j>0;){
    if(dp.at(i).at(j)==dp.at(i-1).at(j))i--;
    else if(dp.at(i).at(j)==dp.at(i).at(j-1))j--;
    else{
      i--;j--;
      res.push_back(s.at(i));
    }
  }
  reverse(ALL(res));
  return res;
}