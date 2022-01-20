vector<int> RestPath(int s, int g, vector<vector<int>> &v, vector<vector<int>> &u){
  //  vをﾜｼｬってuにしたときsからgへのpath
  int n = v.size();
  vector<int> res;
  int cur = s;
  while(s != g){
    for(int i = 0; i < n; i++){
      if(i==cur)continue;
      if(v.at(cur).at(i)+u.at(i).at(g)==u.at(cur).at(g)){
        cur = i;
        res.emplace_back(i);
        break;
      }
    }
  }
  return res;
}
