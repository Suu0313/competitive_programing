namespace FFT{

  struct Complex{
    double Re,Im;
    Complex():Re(0),Im(0){}
    Complex(double x,double y=0.0):Re(x),Im(y){}

    Complex operator+(const Complex &c) const {
      return Complex(Re+c.Re,Im+c.Im);
    }
    Complex operator-(const Complex &c) const {
      return Complex(Re-c.Re,Im-c.Im);
    }
    Complex operator*(const Complex &c) const {
      return Complex(Re*c.Re-Im*c.Im,Re*c.Im+Im*c.Re);
    }
    Complex conj() const {
      return Complex(Re,-Im);
    }
  };
  Complex mpolar(double r, double theta){
    return Complex(r*cos(theta),r*sin(theta));
  }
  
  void DFT(vector<Complex> &f, int inverse){
    int n = SZ(f);
    if(n==1)return;
    vector<Complex> va(n/2),vb(n/2);
    REP(i,n/2){
      va.at(i) = f.at(2*i);
      vb.at(i) = f.at(2*i+1);
    }
    DFT(va,inverse); DFT(vb, inverse);

    Complex now(1.0),zeta=mpolar(1.0,inverse*2.0*PI/n);

    REP(i,n){
      f.at(i) = va.at(i%(n/2))+now*vb.at(i%(n/2));
      now = now * zeta;
    }
  }
  
  template<typename T>
  VLL multiply(vector<T> &f, vector<T> &g){
    int n = 1;
    while(n < SZ(f)+SZ(g)) n*= 2;
    vector<Complex> nf(n), ng(n);

    REP(i,n){
      nf.at(i) = (i<SZ(f)?f.at(i):0);
      ng.at(i) = (i<SZ(g)?g.at(i):0);
    }
    DFT(nf,1); DFT(ng,1);
    REP(i,n) nf.at(i) = nf.at(i)*ng.at(i);
    DFT(nf,-1);
    VD res(n);
    REP(i,n) res.at(i) =nf.at(i).Re/n;
    //return res;
    VLL ans(n);
    REP(i,n) ans.at(i) = (LL)(res.at(i)+0.5);
    return ans;
  }
}