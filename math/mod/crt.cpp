#pragma once

template<typename T>
pair<int64_t, int64_t> crt(const vector<T> &r, const vector<T> &m){

  auto inv_gcd = [](int64_t a, int64_t b) -> pair<int64_t, int64_t> {
    if(a == 0) return {b, 0};
    int64_t s = b, t = a;
    int64_t m0 = 0, m1 = 1;
    while(t){
      int64_t u = s/t; s -= t*u; m0 -= m1*u;
      int64_t tmp = s; s = t; t = tmp; tmp = m0; m0 = m1; m1 = tmp;
    }
    if(m0 < 0) m0 += b/s;
    return {s, m0};
  };

  int n = int(r.size());
  int64_t r0 = 0, m0 = 1;
  for(int i = 0; i < n; i++){
    int64_t r1 = r[i], m1 = m[i];
    r1 %= m1;
    if(r1 < 0) r1 += m1;
    if(m0 < m1){ swap(r0, r1); swap(m0, m1); }
    if(m0 % m1 == 0){
      if(r0 % m1 != r1) return {0, 0};
      continue;
    }
    auto[g, im] = inv_gcd(m0, m1);
    int64_t u1 = m1 / g;
    if((r1-r0) % g) return {0, 0};
    int64_t x = (r1-r0) / g % u1 * im % u1;
    r0 += x * m0;
    m0 *= u1;
    if(r0 < 0) r0 += m0;
  }
  return {r0, m0};
}
