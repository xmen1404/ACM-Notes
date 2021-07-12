// Improved version of Fermat prime check (iter >= 25 is enough)
// n = 2^s * d (d odd)
// Check for a random base A, if A^d % n == 1 or A^d % n == -1
// if both not satisfy => composite
// 75% prob that a random base will test correctly if n composite
// for 64bit integers, only need to check base A in {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}

int pw(int x, int y, int mod) {
    int res = 1;
    while(y) {
        if(y%2) res = res * x % mod;
        x = x*x%mod;
        y >>= 1;
    }
    return res;
}
bool check_prime(int n, int A, int s, int d) {
    int x = pw(A, d, n);
    if(x == 1 || x == (n - 1)) return true;
    FOR(r, 1, s - 1) {
        x = (x * x) % n;
        if(x == (n - 1)) return true;
    }
    return false;
}
bool miller_rabin_prime_check(int n) { // int64
    if(n < 4) return (n == 2 || n == 3);

    int s = 0, tmp_n = n - 1;
    while(tmp_n % 2 == 0) {
        s += 1;
        tmp_n /= 2;
    }
    int d = (n / (1ll << s));
    // iter = 25 -> prob of failing = 1e-16
    FOR(i, 1, 25) {
        int A = 2 + rand() % (n-3);
        if(!check_prime(n, A, s, d)) {
            return false;
        }
    }
    return true;
}
