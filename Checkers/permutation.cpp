struct Permutation {
    int n;
    vector<vector<int> > p;
    vector<bool> visit;
    vector<int> tmp;

    Permutation(int n = 0) : n(n) {
        visit.assign(n + 100, false);
    }

    void backtrack(int pos) {
        if(pos == n + 1) {
            p.pb(tmp);
            return;
        }
        FOR(i, 1, n) if(!visit[i]) {
            tmp.pb(i);
            visit[i] = 1;
            backtrack(pos + 1);
            visit[i] = 0;
            tmp.pop_back();
        }
        return;
    }
    void load_permutation() { // call to initialize calculation
        backtrack(1);
    }
};
