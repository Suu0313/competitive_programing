#pragma once

template <typename T>
vector<T> Vpress(vector<T> &x) {
    vector<T> vs = x;
    sort(begin(vs), end(vs));
    vs.erase(unique(begin(vs), end(vs)), end(vs));
    for(auto&e : x) e = lower_bound(begin(vs), end(vs), e) - begin(vs);
    return vs;
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
