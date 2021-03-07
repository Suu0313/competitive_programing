template <typename T>
vector<T> Vpress(vector<T> &X) {
    vector<T> vals = X;
    SORT(vals);
    vals.erase(unique(ALL(vals)), vals.end());
    REP(i,SZ(X)){
        X.at(i) = LB(ALL(vals), X.at(i)) - vals.begin();
    }
    return vals;
}
template <typename T>
vector<T> Vpress(vector<T> &C1, vector<T> &C2) {
    vector<T> vals;
    int N = SZ(C1);
    REP(i,N) {
        for (T d = 0; d < 1; d++) {  
            T tc1 = C1[i] + d;
            T tc2 = C2[i] + d;
            vals.push_back(tc1);
            vals.push_back(tc2);
        }
    }
    SORT(vals);
    vals.erase(unique(ALL(vals)), vals.end());
    REP(i,N) {
        C1[i] = LB(ALL(vals), C1[i]) - vals.begin();
        C2[i] = LB(ALL(vals), C2[i]) - vals.begin();
    }
    return vals;
}