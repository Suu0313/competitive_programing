template<typename T>
struct SemiRelaxedConvolution{
  using fps = Formalpowerseries<T>;

  SemiRelaxedConvolution() = default;
  SemiRelaxedConvolution(const fps &f): f(f) {}
  fps f, g, h;

  static fps subfps(const fps& y, int p, int l){
    int n = int(y.size());
    return {begin(y) + min(n, p), begin(y) + min(n, p + l)};
  }

  T append(const T &x){
    g.push_back(x);
    int n = int(g.size());
    if(int(h.size()) <= n) h.resize(n + 1);
    if(int(f.size()) < 2) f.resize(2);
    h[n - 1] += f[0] * x;
    h[n] += f[1] * x;

    for(int i = 2; n % i == 0; i *= 2){
      fps co = subfps(f, i, i) * subfps(g, n - i, i);
      int m = int(co.size());
      if(int(h.size()) < n + m) h.resize(n + m);
      for(int j = 0; j < m; ++j){
        h[j + n] += co[j];
      }
    }
    return h[n - 1];
  }
};
