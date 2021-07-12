int pw(int x, int y, int mod) {
    int res = 1;
    while(y) {
        if(y%2) res = res * x % mod;
        x = x*x%mod;
        y >>= 1;
    }
    return res;
}

bool fermat_prime_check(int x, int iter) {
    if(x < 4) return (x == 2 || x == 3);
    FOR(i, 1, iter) {
        int A = 2 + rand() % (x - 3);
        if(pw(A, x-1, x) != 1) return false;
    }
    return true;
}
