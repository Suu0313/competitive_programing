int ChromaticNumber(const vector<int> &es){
  const int n = int(es.size());
  vector<int> ind(1 << n), cnt((1 << n) + 1);
  ind[0] = 1; cnt[1] = 1;

  for(int s = 1; s < (1 << n); ++s){
    int v = __builtin_ctz(s);
    ind[s] = ind[s ^ (1 << v)] + ind[(s ^ (1 << v)) & ~es[v]];
    cnt[ind[s]] += __builtin_parity(s) ? -1 : 1;
  }
  vector<pair<int,int>> buf;
  for(int i = 1; i <= (1 << n); ++i){
    if(cnt[i]) buf.emplace_back(i, cnt[i]);
  }
  
  constexpr int bil = 1000000000;
  constexpr int mods[] = {bil+7, bil+11, bil+21};
  int res = n;
  for(auto m : mods){
    auto indk = buf;
    for(int k = 1; k < res; ++k){
      int64_t sum = 0;
      for(auto&&[i, x] : indk) sum += (x = int64_t(x)*i % m);
      if(sum % m) res = k;
    }
  }
  return res;
}
