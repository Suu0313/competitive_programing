template <typename T>
vector<T> Vpress(vector<T> &X) {
    vector<T> vals = X;
    sort(vals.begin(), vals.end());
    vals.erase(unique(vals.begin(), vals.end()), vals.end());
    for(size_t i = 0; i < X.size(); i++){
        X.at(i) = lower_bound(vals.begin(), vals.end(), X.at(i)) - vals.begin();
    }
    return vals;
}
template <typename T>
vector<T> Vpress(vector<T> &C1, vector<T> &C2, T sp = 1) {
    vector<T> vals;
    for(size_t i = 0; i < C1.size(); i++){
        for (T d = 0; d < sp; d++) {  
            T tc1 = C1[i] + d;
            T tc2 = C2[i] + d;
            vals.push_back(tc1);
            vals.push_back(tc2);
        }
    }
    sort(vals.begin(), vals.end());
    vals.erase(unique(vals.begin(), vals.end()), vals.end());

    for(size_t i = 0; i < C1.size(); i++){
        C1[i] = lower_bound(vals.begin(), vals.end(), C1[i]) - vals.begin();
        C2[i] = lower_bound(vals.begin(), vals.end(), C2[i]) - vals.begin();
    }
    return vals;
}
