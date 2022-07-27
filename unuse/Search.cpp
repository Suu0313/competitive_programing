template<typename F>
pair<double,double> Binary(double ok, double ng, const F &isok, int m = 200){
  for(int t = 0; t < m; t++){
    double wj = ((ok - ng)/2) + ng;
    (isok(wj)?ok : ng) = wj;
  }
  return {ok, ng};
}

template<typename T, typename F>
pair<T,T> Binary(T ok, T ng, const F &isok){
  while(abs(ok - ng) > 1){
    T wj = ((ok - ng) >> 1) + ng;
    (isok(wj)?ok : ng) = wj;
  }
  return {ok, ng};
}

template<typename F>
pair<double,double> Golden(double l, double r, const F &f, bool maximize = true, int m = 200){
  const double phi =(1 + sqrt(5.0)) / 2;
  double ml = (phi*l + r)/(1 + phi);
  double mr = (l + phi*r)/(1 + phi);
  auto fl = f(ml), fr = f(mr);
  for(int t = 0; t < m; t++){
    if((fl < fr)^maximize){
      r = mr; mr = ml; fr = fl;
      ml = (phi*l + r)/(1 + phi);
      fl = f(ml);
    }else{
      l = ml; ml = mr; fl = fr;
      mr = (l + phi*r)/(1 + phi);
      fr = f(mr);
    }
  }
  return {ml, mr};
}

template<typename T, typename F>
T Golden(T dl, T dr, const F &f, bool maximize = true){
  vector<T> fib(2, 1);
  while(fib.back() <= (dr - dl)) fib.push_back(fib.back() + fib[fib.size()-2]);
  int d = fib.size()-1;
  T l = dl, r = l + fib[d--];
  T ml = l + fib[d-1], mr = l + fib[d--];
  auto fl = f(ml), fr = f(mr);

  while(l+2 < r){
    if(mr >= dr){
      r = mr; mr = ml; fr = fl;
      ml = l + fib[--d];
      fl = f(ml);
      continue;
    }
    if((fl < fr)^maximize){
      r = mr; mr = ml; fr = fl;
      ml = l + fib[--d];
      if(ml < dr) fl = f(ml);
    }else{
      l = ml; ml = mr; fl = fr;
      mr = l + fib[d--];
      if(mr < dr) fr = f(mr);
    }
  }
  return ++l;
}
