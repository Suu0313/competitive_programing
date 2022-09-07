template<int pw>
constexpr uint64_t hilbert_length(int x, int y, int rot = 0){
  if constexpr (pw == 0) return 0;
  else{
    int mid = 1 << (pw - 1);
    int seg = (x < mid) ? ((y < mid) ? 0 : 3) : ((y < mid) ? 1 : 2);
    seg = (seg + rot) & 3;
    constexpr int rotd[4] = {3, 0, 0, 1};
    int nx = x & (x ^ mid), ny = y & (y ^ mid);
    int nrot = (rot + rotd[seg]) & 3;
    uint64_t sqsz = uint64_t(1) << (pw*2 - 2);
    uint64_t ans = seg * sqsz, rec = hilbert_length<pw - 1>(nx, ny, nrot);

    return ans + ((seg == 1 || seg == 2) ? rec : (sqsz - rec - 1));
  }
}

vector<int> hilbert_sort(const vector<int> &l, const vector<int> &r){
  int n = int(l.size());
  vector<uint64_t> len(n);
  for(int i = 0; i < n; ++i) len[i] = hilbert_length<30>(l[i], r[i]);
  vector<int> idx(n); iota(begin(idx), end(idx), 0);
  sort(begin(idx), end(idx), [&](int i, int j){ return len[i] < len[j]; });
  return idx;
}
