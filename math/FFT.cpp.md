---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/FFT.cpp\"\n\r\nnamespace FFT{\r\n\r\n  struct Complex{\r\
    \n    double Re,Im;\r\n    Complex():Re(0),Im(0){}\r\n    Complex(double x,double\
    \ y=0.0):Re(x),Im(y){}\r\n\r\n    Complex operator+(const Complex &c) const {\r\
    \n      return Complex(Re+c.Re,Im+c.Im);\r\n    }\r\n    Complex operator-(const\
    \ Complex &c) const {\r\n      return Complex(Re-c.Re,Im-c.Im);\r\n    }\r\n \
    \   Complex operator*(const Complex &c) const {\r\n      return Complex(Re*c.Re-Im*c.Im,Re*c.Im+Im*c.Re);\r\
    \n    }\r\n    Complex conj() const {\r\n      return Complex(Re,-Im);\r\n   \
    \ }\r\n  };\r\n  Complex mpolar(double r, double theta){\r\n    return Complex(r*cos(theta),r*sin(theta));\r\
    \n  }\r\n  \r\n  void DFT(vector<Complex> &f, int inverse){\r\n    int n = f.size();\r\
    \n    if(n==1)return;\r\n    vector<Complex> va(n/2),vb(n/2);\r\n    REP(i,n/2){\r\
    \n      va.at(i) = f.at(2*i);\r\n      vb.at(i) = f.at(2*i+1);\r\n    }\r\n  \
    \  DFT(va,inverse); DFT(vb, inverse);\r\n\r\n    Complex now(1.0),zeta=mpolar(1.0,inverse*2.0*PI/n);\r\
    \n\r\n    REP(i,n){\r\n      f.at(i) = va.at(i%(n/2))+now*vb.at(i%(n/2));\r\n\
    \      now = now * zeta;\r\n    }\r\n  }\r\n  \r\n  template<typename T>\r\n \
    \ VLL multiply(vector<T> &f, vector<T> &g){\r\n    int n = 1;\r\n    while(n <\
    \ SZ(f)+SZ(g)) n*= 2;\r\n    vector<Complex> nf(n), ng(n);\r\n\r\n    REP(i,n){\r\
    \n      nf.at(i) = (i<SZ(f)?f.at(i):0);\r\n      ng.at(i) = (i<SZ(g)?g.at(i):0);\r\
    \n    }\r\n    DFT(nf,1); DFT(ng,1);\r\n    REP(i,n) nf.at(i) = nf.at(i)*ng.at(i);\r\
    \n    DFT(nf,-1);\r\n    VD res(n);\r\n    REP(i,n) res.at(i) =nf.at(i).Re/n;\r\
    \n    //return res;\r\n    VLL ans(n);\r\n    REP(i,n) ans.at(i) = (LL)(res.at(i)+0.5);\r\
    \n    return ans;\r\n  }\r\n}\n"
  code: "#pragma once\r\n\r\nnamespace FFT{\r\n\r\n  struct Complex{\r\n    double\
    \ Re,Im;\r\n    Complex():Re(0),Im(0){}\r\n    Complex(double x,double y=0.0):Re(x),Im(y){}\r\
    \n\r\n    Complex operator+(const Complex &c) const {\r\n      return Complex(Re+c.Re,Im+c.Im);\r\
    \n    }\r\n    Complex operator-(const Complex &c) const {\r\n      return Complex(Re-c.Re,Im-c.Im);\r\
    \n    }\r\n    Complex operator*(const Complex &c) const {\r\n      return Complex(Re*c.Re-Im*c.Im,Re*c.Im+Im*c.Re);\r\
    \n    }\r\n    Complex conj() const {\r\n      return Complex(Re,-Im);\r\n   \
    \ }\r\n  };\r\n  Complex mpolar(double r, double theta){\r\n    return Complex(r*cos(theta),r*sin(theta));\r\
    \n  }\r\n  \r\n  void DFT(vector<Complex> &f, int inverse){\r\n    int n = f.size();\r\
    \n    if(n==1)return;\r\n    vector<Complex> va(n/2),vb(n/2);\r\n    REP(i,n/2){\r\
    \n      va.at(i) = f.at(2*i);\r\n      vb.at(i) = f.at(2*i+1);\r\n    }\r\n  \
    \  DFT(va,inverse); DFT(vb, inverse);\r\n\r\n    Complex now(1.0),zeta=mpolar(1.0,inverse*2.0*PI/n);\r\
    \n\r\n    REP(i,n){\r\n      f.at(i) = va.at(i%(n/2))+now*vb.at(i%(n/2));\r\n\
    \      now = now * zeta;\r\n    }\r\n  }\r\n  \r\n  template<typename T>\r\n \
    \ VLL multiply(vector<T> &f, vector<T> &g){\r\n    int n = 1;\r\n    while(n <\
    \ SZ(f)+SZ(g)) n*= 2;\r\n    vector<Complex> nf(n), ng(n);\r\n\r\n    REP(i,n){\r\
    \n      nf.at(i) = (i<SZ(f)?f.at(i):0);\r\n      ng.at(i) = (i<SZ(g)?g.at(i):0);\r\
    \n    }\r\n    DFT(nf,1); DFT(ng,1);\r\n    REP(i,n) nf.at(i) = nf.at(i)*ng.at(i);\r\
    \n    DFT(nf,-1);\r\n    VD res(n);\r\n    REP(i,n) res.at(i) =nf.at(i).Re/n;\r\
    \n    //return res;\r\n    VLL ans(n);\r\n    REP(i,n) ans.at(i) = (LL)(res.at(i)+0.5);\r\
    \n    return ans;\r\n  }\r\n}"
  dependsOn: []
  isVerificationFile: false
  path: math/FFT.cpp
  requiredBy: []
  timestamp: '2023-02-10 14:54:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/FFT.cpp
layout: document
redirect_from:
- /library/math/FFT.cpp
- /library/math/FFT.cpp.html
title: math/FFT.cpp
---
