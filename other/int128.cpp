using int128 = __int128_t;

istream& operator>>(istream& is, __int128_t &a){
  string s; is >> s;
  __int128_t res = 0;
  for(auto&&c : s) if('0' <= c && c <= '9') res = 10*res + c-'0';
  a = res * (s[0]=='-' ? -1 : 1);
  return is;
}

ostream& operator<<(ostream& os, __int128_t &a){
  ostream::sentry s(os);
  if(s){
    __uint128_t tmp = a<0 ? -a : a;
    char buffer[128];
    char *d = std::end(buffer);
    do{
      --d;
      *d = "0123456789"[tmp%10];
      tmp /= 10;
    }while(tmp != 0);
    if(a < 0){
      --d; *d = '-';
    }
    int len = std::end(buffer) - d;
    if(os.rdbuf()->sputn(d, len) != len){
      os.setstate(ios_base::badbit);
    }
  }
  return os;
}