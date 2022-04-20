namespace myliterals{
  constexpr size_t operator ""_sz(unsigned long long n){ return n; }
  constexpr int8_t operator ""_i8(unsigned long long n){ return n; }
  constexpr int16_t operator ""_i16(unsigned long long n){ return n; }
  constexpr int32_t operator ""_i32(unsigned long long n){ return n; }
  constexpr int64_t operator ""_i64(unsigned long long n){ return n; }
  constexpr uint8_t operator ""_u8(unsigned long long n){ return n; }
  constexpr uint16_t operator ""_u16(unsigned long long n){ return n; }
  constexpr uint32_t operator ""_u32(unsigned long long n){ return n; }
  constexpr uint64_t operator ""_u64(unsigned long long n){ return n; }
}
