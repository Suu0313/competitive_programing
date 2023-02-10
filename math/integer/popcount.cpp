#pragma once

constexpr int popcount(uint64_t x){
  x -= ((x>>1)&0x5555555555555555ULL);
  x = (x&0x3333333333333333ULL) + ((x&0xCCCCCCCCCCCCCCCCULL)>>2);
  x = (x&0x0F0F0F0F0F0F0F0FULL) + ((x&0xF0F0F0F0F0F0F0F0ULL)>>4);  
  x *= 0x0101010101010101ULL;
  return x >> 56;
}
