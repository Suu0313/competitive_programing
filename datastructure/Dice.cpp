#pragma once

struct Dice{
  static constexpr array<int, 6> dice[24] = { // {u, d, f, b, l, r}
    {1,6,2,5,4,3}, {1,6,3,4,2,5}, {1,6,4,3,5,2}, {1,6,5,2,3,4},
    {2,5,1,6,3,4}, {2,5,3,4,6,1}, {2,5,4,3,1,6}, {2,5,6,1,4,3},
    {3,4,1,6,5,2}, {3,4,2,5,1,6}, {3,4,5,2,6,1}, {3,4,6,1,2,5},
    {4,3,1,6,2,5}, {4,3,2,5,6,1}, {4,3,5,2,1,6}, {4,3,6,1,5,2},
    {5,2,1,6,4,3}, {5,2,3,4,1,6}, {5,2,4,3,6,1}, {5,2,6,1,3,4},
    {6,1,2,5,3,4}, {6,1,3,4,5,2}, {6,1,4,3,2,5}, {6,1,5,2,4,3}
  };

  static constexpr int rot[24][6] = { // {N, S, E, W, L, R}
    {7, 16, 13, 9, 2, 13}, {11, 12, 5, 17, 0, 5}, {15, 8, 18, 6, 3, 18}, {19, 4, 10, 14, 1, 10}, 
    {3, 20, 8, 12, 5, 8}, {10, 13, 21, 1, 7, 21}, {14, 9, 2, 22, 4, 2}, {23, 0, 15, 11, 6, 15}, 
    {2, 21, 16, 4, 10, 16}, {6, 17, 0, 20, 8, 0}, {18, 5, 23, 3, 11, 23}, {22, 1, 7, 19, 9, 7}, 
    {1, 22, 4, 16, 13, 4}, {5, 18, 20, 0, 15, 20}, {17, 6, 3, 23, 12, 3}, {21, 2, 19, 7, 14, 19}, 
    {0, 23, 12, 8, 18, 12}, {9, 14, 1, 21, 16, 1}, {13, 10, 22, 2, 19, 22}, {20, 3, 11, 15, 17, 11}, 
    {4, 19, 9, 13, 21, 9}, {8, 15, 17, 5, 23, 17}, {12, 11, 6, 18, 20, 6}, {16, 7, 14, 10, 22, 14}
  };

  static constexpr bool check(const array<int, 6> &a, const array<int, 6> &b){
    for(int i = 0; i < 6; ++i){
      if(!a[i] || !b[i]) continue;
      if(a[i] != b[i]) return false;
    }
    return true;
  }

  int state, x, y;

  constexpr Dice(const array<int, 6> &ds, int x = 0, int y = 0): state(-1), x(x), y(y) {
    for(int i = 0; i < 24; ++i){
      if(check(dice[i], ds)){
        state = i;
        break;
      }
    }
    assert(state != -1);
  }

  constexpr void rotN(){ state = rot[state][0]; ++y; }
  constexpr void rotS(){ state = rot[state][1]; --y; }
  constexpr void rotE(){ state = rot[state][2]; ++x; }
  constexpr void rotW(){ state = rot[state][3]; --x; }
  constexpr void rotL(){ state = rot[state][4]; }
  constexpr void rotR(){ state = rot[state][5]; }

  constexpr int getU(){ return dice[state][0]; }
  constexpr int getD(){ return dice[state][1]; }
  constexpr int getF(){ return dice[state][2]; }
  constexpr int getB(){ return dice[state][3]; }
  constexpr int getL(){ return dice[state][4]; }
  constexpr int getR(){ return dice[state][5]; }
};
