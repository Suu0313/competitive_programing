template <typename T>
struct BIT2D{
  int H, W; //[1,H]*[1,W]
  vector<vector<T>> node; //1-indexed
  
  BIT2D(int H_, int W_): H(H_+1),W(W_+1),node(H,vector<T>(W,0)){}

  void add(int h, int w, T x){
    for(int i = h; i < H; i += (i&-i)){
      for(int j = w; j < W; j += (j&-j)){
        node.at(i).at(j) += x;
      }
    }
  }

  T sum(int h, int w){ //[1,h]*[1,w]
    T s(0);
    for(int i = h; i > 0; i -= (i&-i)){
      for(int j = w; j > 0; j -= (j&-j)){
        s += node.at(i).at(j);
      }
    }
    return s;
  }

  T query(int h1, int w1, int h2, int w2){ //[h1,h2)*[w1,w2)
    return sum(h2-1,w2-1)-sum(h2-1,w1-1)-sum(h1-1,w2-1)+sum(h1-1,w1-1);
  }
};
