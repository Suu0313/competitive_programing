#pragma once

uint64_t isqrt(uint64_t x){
  uint64_t res = 0, over = 1;
  while(over*over <= x) over <<= 1;
  while(over-res > 1){
    uint64_t wj = res + ((over-res) >> 1);
    ((wj*wj <= x) ? res : over) = wj;
  }
  return res;
}
