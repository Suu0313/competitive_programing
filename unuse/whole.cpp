#define WHOLE(some_of, n, i, ...) ([&]{ vector<int> index(n); iota(begin(index), end(index), 0); return some_of(begin(index), end(index) , [&](int i){ __VA_ARGS__; } );})()
