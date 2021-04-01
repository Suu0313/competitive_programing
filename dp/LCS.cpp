template <typename T>
T LCS(T s, T t){
  int n = s.size(), m = t.size();
  vector dp(n+1, vector(m+1,0));
  for(int i = 0; i < n; i++)for(int j = 0; j < m; j++){
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
  reverse(res.begin(), res.end());
  return res;
}