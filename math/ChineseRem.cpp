PLL InvGcd(LL a, LL b){
  if(a==0) return {b, 0};
  LL s = b, t = a;
  LL m0 = 0, m1 = 1;
  while(t){
    LL u = s/t; s -= t*u; m0 -= m1*u;
    LL tmp = s; s = t; t = tmp; tmp = m0; m0 = m1; m1 = tmp;
  }
  if(m0<0) m0 += b/s;
  return {s, m0};
}
PLL ChineseRem(const VLL &r, const VLL &m){
  int n = SZ(r);
  LL r0 = 0, m0 = 1;
  REP(i,n){
    LL r1 = r.at(i), m1 = m.at(i);
    r1 %= m1;
    if(r1<0) r1 += m1;
    if(m0<m1){
      swap(r0,r1);
      swap(m0,m1);
    }
    if(m0%m1 == 0){
      if(r0%m1 != r1) return {0,0};
      continue;
    }
    LL g, im;
    tie(g,im) = InvGcd(m0, m1);
    LL u1 = m1 / g;
    if((r1-r0) % g) return {0,0};
    LL x = (r1-r0) / g % u1 * im % u1;
    r0 += x * m0;
    m0 *= u1;
    if(r0 < 0) r0 += m0;
  }
  return {r0, m0};
}