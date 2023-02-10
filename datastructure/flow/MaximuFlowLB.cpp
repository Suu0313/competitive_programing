#pragma once

template<class F>
struct MaximuFlowLB{
  using Cap = F::cap_type;
  F f;
  int S, T;
  Cap lb_sum;

  MaximuFlowLB(int n): f(n + 2), S(n), T(S + 1), lb_sum(0) {}

  void add_edge(int from, int to, Cap lb, Cap ub){

    if(lb != ub){
      f.add_edge(from, to, ub - lb);
    }

    if(lb != 0){
      lb_sum += lb;
      f.add_edge(S, to, lb);
      f.add_edge(from, T, lb);
    }
  }

  Cap flow(int s, int t){
    Cap a = f.flow(S, T);
    Cap b = f.flow(s, T);
    Cap c = f.flow(S, t);
    Cap d = f.flow(s, t);
    if(lb_sum == a + b && lb_sum == a + c) return b + d;
    return -1;
  }
};
//TODO: verify