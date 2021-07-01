void dfs(int u) {
    sz[u] = 1;
    for(auto v: vi[u]) if(v != pr[u]) {
        pr[v] = u;
        hi[v] = hi[u] + 1;
        dfs(v);
        sz[u] += sz[v];
    }
}
int LCA(int u, int v) {
    if(hi[u] < hi[v]) swap(u, v);
    FORW(i, 7, 0) if(f[u][i] != -1 && hi[f[u][i]] >= hi[v])
        u = f[u][i];
    FORW(i, 7, 0) if(f[u][i] != -1 && f[v][i] != -1 && f[u][i] != f[v][i])
        u = f[u][i], v = f[v][i];
    if(u != v) return f[u][0];
    return u;
}

void prepare(int root) {
    pr[root] = root;
    hi[root] = 0;
    dfs(root);
    FOR(i, 1, n) {
        FOR(j, 0, 7) f[i][j] = -1;
        if(pr[i] != i) f[i][0] = pr[i];
    }
    FOR(j, 1, 7) FOR(i, 1, n) if(f[i][j - 1] != -1) 
        f[i][j] = f[ f[i][j - 1] ][j - 1];
}
