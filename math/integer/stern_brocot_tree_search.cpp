#pragma once

/**
 * @brief binary search on stern-brocot tree
 * 
 * @tparam F bool<uint64_t, uint64_t>
 * @param f (a, b) => check(a / b) f(0, 1) != f(1, 0)
 * @param limit a <= limit && b <= limit
 * @return pair<pair<uint64_t, uint64_t>, pair<uint64_t, uint64_t>>
 */
template<typename F>
auto stern_brocot_tree_search(const F &f, uint64_t limit){
  using P = pair<uint64_t, uint64_t>;
  auto add = [](const P &a, const P &b) -> P { return { a.first+b.first, a.second+b.second }; };
  auto mul = [](const P &a, uint64_t k) -> P { return { a.first * k, a.second * k }; };
  auto Pf = [&](const P &a) -> bool { return f(a.first, a.second); };

  P low(0, 1), high(1, 0);
  bool low_judge = f(0, 1);
  while(true){
    P mid = add(low, high);
    if(max(mid.first, mid.second) > limit) break;
    bool mid_judge = Pf(mid);
    P &s = (low_judge!=mid_judge ? low : high);
    P &l = (low_judge==mid_judge ? low : high);

    uint64_t a = 0, b = 1;
    while(true){
      P wj = add(mid, mul(s, b));
      if(max(wj.first, wj.second) > limit || mid_judge != Pf(wj)) break;
      a = b; b += b;
    }

    while(a + 1 < b){
      uint64_t m = (a + b)/2;
      P wj = add(mid, mul(s, m));
      if(max(wj.first, wj.second) > limit) b = m;
      else (Pf(wj)==mid_judge ? a : b) = m;
    }
    l = add(mid, mul(s, a));
  }

  return make_pair(low, high);
}
