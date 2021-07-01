int frac[N], fracw[N];

int add(int x, int y) { return (x+y) % MOD; }
int mul(int x, int y) { return (x * y) % MOD; }

int pw(int x, int y) {
    int res = 1;
    while(y) {
        if(y&1) res = mul(res, x);
        x = mul(x, x);
        y >>= 1;
    }
    return res;
}

int ckn(int k, int n) {
    if(k > n) return 0;
    return mul(frac[n], mul(fracw[n-k], fracw[k]));
}
  
