VI RestPath(int s, int g, VVI &v, VVI &u){
  //vをﾜｼｬってuにしたときsからgへのpath
  int n = SZ(v);
  VI res;
  int cur = s;
  while(s != g){
    REP(i,n){
      if(i==cur)continue;
      if(v.at(cur).at(i)+u.at(i).at(g)==u.at(cur).at(g)){
        cur = i;
        res.EB(i);
        break;
      }
    }
  }
  return res;
}
