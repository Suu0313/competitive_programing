#ifdef _DEBUG
template<typename T> void debug_out(T &&t) { cout << t << "\n"; }
template <typename T, typename... Ts>
void debug_out(T&& t, Ts&&... ts){ cout << t << ", "; debug_out(ts...); }
#define dbg(...) do{ cout <<"L: "<<__LINE__<<" [ " << #__VA_ARGS__ << " ]: "; debug_out(__VA_ARGS__); } while(false)
#else
#define dbg(...)
#endif