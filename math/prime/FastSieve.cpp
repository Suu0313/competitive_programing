#pragma once

struct FastSieve{
  using i8 = uint8_t;
  int n, m;
  vector<i8> table;

  FastSieve() = default;
  FastSieve(int n): n(n), m(n/30 + 1), table(m, 0xff) {
    table[0] = 0xfe;
    int sn = ceil(sqrt(n) + 0.1), sni = sn / 30;
    for(int i = 0; i <= sni ; ++i){
      for(int bit = table[i]; bit; bit &= (bit - 1)){
        int pos = ctz(bit), k = ptoi[pos];
        int p = 30 * i + 2 * k;
        for(int j = i * p + (k * k)/30, np = pos; j < m; j += i * c1[np] + c0[pos][np], np = (np + 1)&7){
          table[j] &= mask[pos][np];
        }
      }
    }
  }

  static int ctz(int bit){ return (bit == 0) ? -1 : __builtin_ctz(bit); }
  static constexpr int ptoi[8] = {1, 7, 11, 13, 17, 19, 23, 29};
  static constexpr int c1[8] = {6, 4, 2, 4, 2, 4, 6, 2};

  static constexpr int c0[8][8] = {
    {0, 0, 0, 0, 0, 0, 0, 1}, {1, 1, 1, 0, 1, 1, 1, 1},
    {2, 2, 0, 2, 0, 2, 2, 1}, {3, 1, 1, 2, 1, 1, 3, 1},
    {3, 3, 1, 2, 1, 3, 3, 1}, {4, 2, 2, 2, 2, 2, 4, 1},
    {5, 3, 1, 4, 1, 3, 5, 1}, {6, 4, 2, 4, 2, 4, 6, 1}
  };
  static constexpr int mask[8][8] = {
    {0xfe, 0xfd, 0xfb, 0xf7, 0xef, 0xdf, 0xbf, 0x7f},
    {0xfd, 0xdf, 0xef, 0xfe, 0x7f, 0xf7, 0xfb, 0xbf},
    {0xfb, 0xef, 0xfe, 0xbf, 0xfd, 0x7f, 0xf7, 0xdf},
    {0xf7, 0xfe, 0xbf, 0xdf, 0xfb, 0xfd, 0x7f, 0xef},
    {0xef, 0x7f, 0xfd, 0xfb, 0xdf, 0xbf, 0xfe, 0xf7},
    {0xdf, 0xf7, 0x7f, 0xfd, 0xbf, 0xfe, 0xef, 0xfb},
    {0xbf, 0xfb, 0xf7, 0x7f, 0xfe, 0xef, 0xdf, 0xfd},
    {0x7f, 0xbf, 0xdf, 0xef, 0xf7, 0xfb, 0xfd, 0xfe}
  };

  vector<int> prime_table() const {
    vector<int> ps;
    for(int p : {2, 3, 5}){
      if(p > n) return ps;
      ps.push_back(p);
    }
    for(int i = 0; i < m; ++i){
      for(int bit = table[i]; bit; bit &= (bit - 1)){
        int pos = ctz(bit), k = ptoi[pos];
        int p = i * 30 + k;
        if(p > n) return ps;
        ps.push_back(p);
      }
    }
    return ps;
  }
};
