struct RangeInversionsQuery{
  int n, upper;
  vector<int> a;
  
  vector<FenwickTree<int>> prefix_freq;
  vector<FenwickTree<int>> large_inv;
  vector<int> small_inv;
  FenwickTree<int> fw;

  void init(const vector<int> &b, int upper){
    this->upper = upper;
    int N = int(b.size());
    for(n = 1; n * n < N; ++n);
    a.assign(n * n, 0);
    for(int i = 0; i < N; ++i) a[i] = b[i];

    prefix_freq.assign(n + 1, upper);

    for(int i = 0; i < n; ++i){
      prefix_freq[i + 1] = prefix_freq[i];
      for(int j = 0; j < n; ++j){
        prefix_freq[i + 1].add(a[i * n + j], 1);
      }
    }

    fw = FenwickTree<int>(upper);
    large_inv.assign(n, n);

    for(int j = 1; j < n; ++j){
      for(int k = j * n; k < j * n + n; ++k) fw.add(a[k], 1);
      for(int i = 0; i < j; ++i){
        int x = 0;
        for(int k = i * n; k < i * n + n; ++k) x += fw.sum(a[k]);
        large_inv[i].add(j, x);
      }
      for(int k = j * n; k < j * n + n; ++k) fw.add(a[k], -1);
    }

    small_inv.assign(n, 0);
    for(int i = 0; i < n; ++i){
      small_inv[i] = cal_inv_short(i * n, i * n + n);
    }
  }

  void update(int k, int x){
    int px = a[k]; a[k] = x;

    for(int i = k/n; i < n; ++i){
      prefix_freq[i + 1].add(px, -1);
      prefix_freq[i + 1].add(x, 1);
    }

    int bk = k / n;
    for(int i = 0; i < n; ++i){
      if(bk < i){
        int pfr = prefix_freq[i + 1].sum(px) - prefix_freq[i].sum(px);
        int fr = prefix_freq[i + 1].sum(x) - prefix_freq[i].sum(x);
        large_inv[bk].add(i, fr - pfr);
      }

      if(i < bk){
        int pfr = prefix_freq[i + 1].query(px + 1, upper) - prefix_freq[i].query(px + 1, upper);
        int fr = prefix_freq[i + 1].query(x + 1, upper) - prefix_freq[i].query(x + 1, upper);
        large_inv[i].add(bk, fr - pfr);
      }
    }

    small_inv[k] = cal_inv_short(bk * n, bk * n + n);
  }

  int64_t query(int l, int r){
    if(l >= r) return 0;
    int bl = (l + n - 1)/n, br = r / n;
    if(bl > br) return cal_inv_short(l, r);

    int64_t inv = cal_inv_short(l, bl * n, br * n, r);

    for(int i = bl; i < br; ++i) inv += large_inv[i].sum(br);

    for(int i = l; i < bl * n; ++i){
      inv += prefix_freq[br].sum(a[i]) - prefix_freq[bl].sum(a[i]);
    }

    for(int i = br * n; i < r; ++i){
      inv += (br * n - bl * n) - (prefix_freq[br].sum(a[i] + 1) - prefix_freq[bl].sum(a[i] + 1));
    }

    for(int i = bl; i < br; ++i) inv += small_inv[i];
    return inv;
  }

  int cal_inv_short(int l, int r){
    int inv = 0;
    for(int i = r - 1; i >= l; --i){ inv += fw.sum(a[i]); fw.add(a[i], 1); }

    for(int i = r - 1; i >= l; --i) fw.add(a[i], -1);

    return inv;
  }

  int cal_inv_short(int l1, int r1, int l2, int r2){
    int inv = 0;
    for(int i = r2 - 1; i >= l2; --i){
      inv += fw.sum(a[i]);
      fw.add(a[i], 1);
    }
    for(int i = r1 - 1; i >= l1; --i){
      inv += fw.sum(a[i]);
      fw.add(a[i], 1);
    }

    for(int i = r2 - 1; i >= l2; --i) fw.add(a[i], -1);
    for(int i = r1 - 1; i >= l1; --i) fw.add(a[i], -1);

    return inv;
  }
};
