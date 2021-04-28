priority_queue<T, vector<T>, decltype(compare)> pq{compare};
priority_queue pq{compare, vector<T>()};