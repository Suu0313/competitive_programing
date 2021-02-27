template< typename T >
void Vcout(const vector<T> &v, string sep = " "){
  for(int i = 0; i < SZ(v); i++) {
    cout << v[i] << (i + 1 != SZ(v) ? sep : "");
  }
  cout << endl;
}