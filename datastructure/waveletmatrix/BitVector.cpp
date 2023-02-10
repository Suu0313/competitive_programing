#pragma once


struct BitVector{
  using u16 = uint16_t;
  using u32 = uint32_t;

  static constexpr int s_ws = 16;
  static constexpr int l_ws = 512;

  vector<u16> b_vector;
  vector<u32> l_block;
  vector<u16> s_block;
  u32 cnt_one = 0;

  static int popCount(u32 x){ return __builtin_popcountll(x); }
  static u32 bitMask(int n){ return (u32(1) << n) - 1; }

  BitVector() = default;
  BitVector(const BitVector&) = default;
  BitVector(BitVector&&) = default;
  BitVector(const vector<bool> &bit){ init(bit); }

  BitVector &operator=(const BitVector&) = default;
  BitVector &operator=(BitVector&&) = default;

  void init(const vector<bool> &bit){
    const int n = int(bit.size());
    b_vector.assign(n / s_ws + 1, 0);

    for(int i = 0; i < n; ++i){
      if(!bit[i]) continue;
      b_vector[i / s_ws] |= 1 << (i % s_ws);
    }

    l_block.assign(n / l_ws + 1, 0);
    s_block.assign(n / s_ws + 1, 0);

    for(int i = 0; i <= n; ++i){
      if(i % l_ws == 0) l_block[i / l_ws] = cnt_one;
      if(i % s_ws == 0) s_block[i / s_ws] = cnt_one - l_block[i / l_ws];

      if(i != n && i % s_ws == 0) cnt_one += popCount(b_vector[i / s_ws]);
    }
  }

  bool access(int t) const { return (b_vector[t / s_ws] >> (t % s_ws) & 1); }
  int rank0(int t) const { return t - rank1(t); }
  int rank1(int t) const {
    return l_block[t / l_ws] + s_block[t / s_ws]
    + popCount(b_vector[t / s_ws] & bitMask(t % s_ws));
  }

  int rank0(int s, int t) const { return (t - s) - rank1(s, t); }
  int rank1(int s, int t) const { return (s == t)  ? 0 : rank1(t) - rank1(s); }

  int select0(int t) const;
  int select1(int t) const;
};
