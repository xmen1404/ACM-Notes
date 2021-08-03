// mod P = small
// O(mod)
// Wilson theorem: (p - 1)! % p == -1 for every prime p

int add(int x, int y, int mod) { return (x + y) % mod; }
int mul(int x, int y, int mod) { return x % mod * (y % mod) % mod; }
int fract(int n, int mod) {
    vector<int> fract;
    fract.pb(1); fract.pb(1);
    for(int i = 2; i <= mod; ++i) 
        fract.pb(fract.back() * i % mod);

    int res = 1;
    while(n > 0) {
        if((n/mod) % 2 == 1) 
            res = mod - res;
        res = mul(res, fract[n % mod], mod);
        n /= mod;
    }
    return res;    
}
