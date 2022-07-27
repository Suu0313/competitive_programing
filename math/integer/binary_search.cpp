template<typename T, typename F>
pair<T, T> binary_search(T ok, T ng, const F &isok){
  while(abs(ok - ng) > 1){
    T wj = (ok & ng) + ((ok ^ ng) >> 1);
    (isok(wj)?ok : ng) = wj;
  }
  return {ok, ng};
}


uint64_t ftou(double f){
  uint64_t u; memcpy(&u, &f, sizeof f);
  return (u >> 63 & 1) ? ~u : u ^ (1ull << 63);
}
double utof(uint64_t u){
  u = ((u >> 63 & 1) ? u ^ (1ull << 63) : ~u);
  double f; memcpy(&f, &u, sizeof u);
  return f;
}

template<typename F>
double binary_search_exactly(double ok, double ng, const F &f){
  uint64_t uok = ftou(ok), ung = ftou(ng);
  while(true){
    uint64_t uwj = (uok & ung) + (uok ^ ung)/2;
    if(uok == uwj || ung == uwj) break;
    double wj = utof(uwj);
    (f(wj) ? uok : ung) = uwj;
  }
  return utof(uok);
}
