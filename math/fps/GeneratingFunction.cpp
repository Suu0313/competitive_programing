#pragma once

#include ".\\Formalpowerseries.cpp"

template<typename T>
T GeneratingFunction(Formalpowerseries<T> P, Formalpowerseries<T> Q, long long n){
  while(n > 0){
    Formalpowerseries<T> V(Q);
  
    int d = V.size();
    for(int i = 0; i < d; i++) if(i&1) V[i] = -V[i];
  
    auto U = P * V;
    V *= Q;

    if(n&1){
      d = U.size();
      P.resize(d/2);
      for(int i = 1; i < d; i += 2) P[i/2] = U[i];
    }else{
      d = U.size();
      P.resize((d+1)/2);
      for(int i = 0; i < d; i += 2) P[i/2] = U[i];
    }
    d = Q.size();
    for(int i = 0; i < d; i++) Q[i] = V[i*2];
    n >>= 1;
  }
  return P[0];
}
