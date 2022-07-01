template <typename T>
struct FenwickTree_RAQ{ //ToDo: verify
  int n;
  vector<T> node0, node1;

  FenwickTree_RAQ() : n(0) {}
  FenwickTree_RAQ(int n_) : n(n_+1), node0(n, 0), node1(n, 0) {}

  void add(int l, int r, T x){ // [l,r)
    add_sub(node0, l, -x*l);
    add_sub(node0, r, x*r);
    add_sub(node1, l, x);
    add_sub(node1, r, -x);
  }

  T sum(int i) const { //[0,i)
    return sum_sub(node0, i) + sum_sub(node1, i)*i;
  }

  T query(int l, int r) const { //[l,r)
    return sum(r) - sum(l); 
  }

  T operator[](int i) const { return query(i, i+1); }

private:
  void add_sub(vector<T> &node, int i, T x){
    for(int idx = i+1; idx < n; idx += (idx & -idx)){
      node[idx] += x;
    }
  }

  T sum_sub(const vector<T> &node, int i) const {
    T s(0);
    for(int idx = i; idx > 0; idx -= (idx & -idx)){
      s += node[idx];
    }
    return s;
  }
};
