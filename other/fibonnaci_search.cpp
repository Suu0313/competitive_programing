template<typename T, typename U, typename F, typename C>
T fibonnaci_search(T l, T r, const F &f, const C &cmp){
  if(l >= r) return l;
  vector<T> fib(2, 1);
  T d = r - l;
  for(int i = 0; fib.back() <= d + 1; ++i) fib.push_back(fib[i] + fib[i + 1]);

  auto sf = [&](T x) -> optional<U>{
    if(x < l || r < x) return nullopt;
    return f(x);
  };

  int i = int(fib.size());
  T lx = l-1, rx = lx + fib[--i];
  T nl = lx + fib[i - 2], nr = lx + fib[--i];
  optional<U> lv = sf(nl), rv = sf(nr);

  while(lx + 2 < rx){
    --i;
    if(!rv || cmp(lv.value(), rv.value())){
      rx = nr; nr = nl; rv = lv;
      nl = lx + fib[i - 1];
      lv = sf(nl);
    }else{
      lx = nl; nl = nr; lv = rv;
      nr = lx + fib[i];
      rv = sf(nr);
    }
  }

  return lx + 1;
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

template<typename T, typename F, typename C>
double fibonnaci_search_exactly(double l, double r, const F &f, const C &cmp){
  uint64_t x = fibonnaci_search<uint64_t, T>(
      ftou(l), ftou(r), [&](uint64_t x){ return f(utof(x)); }, cmp
  );
  return utof(x);
}
