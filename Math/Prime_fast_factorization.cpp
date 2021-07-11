# algorithm return lp[i] = smallest prime number in factorization of i
# O(N) in total

const int N = 1e7 + 100; # maximum size
int lp[N];
vector<int> prime;

void load_prime() {
    FOR(i, 2, N - 1) {
        if(!lp[i]) {
            lp[i] = i;
            prime.pb(i);
        }
        for(int j = 0; j < SZ(prime) && prime[j] <= lp[i] && prime[j]*i < N; j += 1) {
            lp[prime[j]*i] = prime[j];
        }
    }
}

vector<ii> factorize(int x) {
    vector<ii> res;
    while(x > 1) {
        int cur = lp[x], cnt = 0;
        while(x % cur == 0) {
            cnt += 1;
            x /= cur;
        }
        res.pb({cur, cnt});
    }
    return res;
}
