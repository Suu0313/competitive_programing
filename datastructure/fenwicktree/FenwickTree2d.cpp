template <typename T>
struct FenwickTree2d{
  int H, W;
  vector<vector<T>> node;
  
  FenwickTree2d(int H_, int W_): H(H_+1), W(W_+1), node(H, vector<T>(W, 0)) {}

  void add(int h, int w, T x){
    for(int i = h+1; i < H; i += (i&-i)){
      for(int j = w+1; j < W; j += (j&-j)){
        node.at(i).at(j) += x;
      }
    }
  }

  T sum(int h, int w) const { // [0,H) * [0,W)
    T s(0);
    for(int i = h; i > 0; i -= (i&-i)){
      for(int j = w; j > 0; j -= (j&-j)){
        s += node.at(i).at(j);
      }
    }
    return s;
  }

  T query(int h1, int w1, int h2, int w2) const { // [h1,h2) * [w1,w2)
    return sum(h2, w2) - sum(h2, w1) - sum(h1, w2) + sum(h1, w1);
  }
};
