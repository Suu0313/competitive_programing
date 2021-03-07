VI Erat(int x) {
  VI a(x,1);
  VI res;

  for(int i = 2; i < sqrt(x); i++){
    if(a.at(i)) {
      for(int j = 0; i*(j+2) < (x); j++) {
        a.at(i*(j+2)) = 0;
      }
    }
  }
  
  for(int i = 2; i < (x); i++){
    if(a.at(i)) {
      res.PB(i);
    }
  }

  return res;
}