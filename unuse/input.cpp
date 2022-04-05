struct input{
  template<typename T> operator T(){ T e; cin >> e; return e; }
};
#define I =input{}
