namespace FFT{
  template<int mod>
  vector<ModInt<mod>> tovMint(const vector<long long> &a){
    vector<ModInt<mod>> res(a.size());
    for (size_t i = 0; i < a.size(); i++) res[i] = a[i];
    return res;
  }

  vector<long long> multiply(const vector<long long> &a, const vector<long long> &b){
    int n = int(a.size()), m = int(b.size());
    if (!n || !m) return {};

    static constexpr unsigned long long MOD1 = 754974721;
    static constexpr unsigned long long MOD2 = 167772161;
    static constexpr unsigned long long MOD3 = 469762049;
    static constexpr unsigned long long M2M3 = MOD2 * MOD3;
    static constexpr unsigned long long M1M3 = MOD1 * MOD3;
    static constexpr unsigned long long M1M2 = MOD1 * MOD2;
    static constexpr unsigned long long M1M2M3 = MOD1 * MOD2 * MOD3;

    static constexpr unsigned long long i1 = 190329765;
    static constexpr unsigned long long i2 = 58587104;
    static constexpr unsigned long long i3 = 187290749;

    auto c1 = NTT::multiply(tovMint<MOD1>(a), tovMint<MOD1>(b));
    auto c2 = NTT::multiply(tovMint<MOD2>(a), tovMint<MOD2>(b));
    auto c3 = NTT::multiply(tovMint<MOD3>(a), tovMint<MOD3>(b));

    
    
    vector<long long> c(n + m - 1);

    for(int i = 0; i < n+m-1; i++){
      unsigned long long x = 0, x1 = c1[i].x, x2 = c2[i].x, x3 = c3[i].x;
        x += (x1 * i1) % MOD1 * M2M3;
        x += (x2 * i2) % MOD2 * M1M3;
        x += (x3 * i3) % MOD3 * M1M2;
        int diff = (c1[i] - (long long)x).x;
        static constexpr unsigned long long offset[5] = {0, 0, M1M2M3, 2 * M1M2M3, 3 * M1M2M3};
        x -= offset[diff % 5];
        c[i] = x;
    }
    return c;
  }

  template<int mod>
  vector<ModInt<mod>> multiply(const vector<ModInt<mod>> &a, const vector<ModInt<mod>> &b){
    int n = int(a.size()), m = int(b.size());
    if (!n || !m) return {};

    static constexpr long long MOD1 = 754974721;
    static constexpr long long MOD2 = 167772161;
    static constexpr long long MOD3 = 469762049;

    static const ModInt<MOD2> i1 = ModInt<MOD2>(MOD1).inverse();
    static const ModInt<MOD3> i2 = ModInt<MOD3>(MOD1 * MOD2).inverse();
    static const ModInt<mod> M12 = MOD1 * MOD2;

    vector<long long> a2(n), b2(m);
    for(int i = 0; i < n; i++) a2[i] = a[i].x;
    for(int i = 0; i < m; i++) b2[i] = b[i].x;

    auto c1 = NTT::multiply(tovMint<MOD1>(a2), tovMint<MOD1>(b2));
    auto c2 = NTT::multiply(tovMint<MOD2>(a2), tovMint<MOD2>(b2));
    auto c3 = NTT::multiply(tovMint<MOD3>(a2), tovMint<MOD3>(b2));

    vector<ModInt<mod>> c(n + m - 1);
    for(int i = 0; i < n+m-1; i++){
      ModInt<MOD2> v1 = (c2[i] - c1[i].x) * i1;
      ModInt<MOD3> v2 = (c3[i] - c1[i].x  - v1.x * MOD1) * i2;
      c[i] = M12 * v2.x + c1[i].x + MOD1 * v1.x;
    }
    return c;
  }
}
