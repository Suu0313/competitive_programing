#pragma once

template<typename T>
long long merge_sort(vector<T> &a){
  int n = int(a.size());
  long long inv = 0;

  vector<T> b(n);
  for(int len = 1; len < n; len *= 2){
    for(int l=0,m=len,r=min(len*2,n),i=0; l<n; l=r,m=min(l+len,n),r=min(m+len,n)){
      for(int p = l, q = m; p < m || q < r; ){
        if(p == m){
          while(q < r) b[i++] = a[q++];
          break;
        }
        if(q == r){
          while(p < m) b[i++] = a[p++];
          break;
        }

        if(a[p] > a[q]){
          b[i++] = a[q++]; inv += m - p;
        }else{
          b[i++] = a[p++];
        }
      }
    }
    swap(a, b);
  }

  return inv;
}
