struct StaticRangeInversionsQuery{
  int n, sn;
  vector<int> a;
  vector<vector<int64_t>> binv;
  vector<BIT<int>> bits;

  template<typename T>
  StaticRangeInversionsQuery(const vector<T> &x){
    n = int(x.size());
    sn = 1; while(sn*sn < n) ++sn;
    a = compress(x).first;
    n = sn*sn; a.resize(n, n-1);
    binv = vector(sn, vector<int64_t>(sn+1));

    for(int i = 0; i < n; i += sn){
      int64_t inv = 0;
      BIT<int> bit(n);
      for(int j = i; j < n; ++j){
        inv += (j-i) - bit.sum(a[j] + 1);
        bit.add(a[j], 1);
        if((j+1)%sn == 0) binv[i/sn][(j+1)/sn] = inv;
      }
    }

    bits.assign(sn+1, n);
    for(int i = 0; i < n; ++i){
      if(i%sn == 0) bits[i/sn].node = bits[sn].node;
      bits[sn].add(a[i], 1);
    }
  }

  int64_t query(int l, int r){
    if(l/sn == (r-1)/sn){
      vector<int> b(begin(a)+l, begin(a)+r);
      return MergeSort(b);
    }

    int i = (l+sn-1)/sn, j = r/sn;
    int64_t inv = binv[i][j];
    vector<int> b(begin(a)+l, begin(a)+i*sn);

    for(int k = l; k < i*sn; ++k){
      inv += bits[j].sum(a[k]) - bits[i].sum(a[k]);
    }
    for(int k = j*sn; k < r; ++k){
      inv += bits[j].query(a[k]+1, n) - bits[i].query(a[k]+1, n);
      b.push_back(a[k]);
    }

    inv += MergeSort(b);
    return inv;
  }
};
