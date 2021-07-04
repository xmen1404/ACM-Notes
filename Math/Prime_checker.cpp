struct Prime_checker {
    int n;              // find prime numbers upto n
    vector<bool> prime; 
    vector<int> plist;  // list of prime numbers

    Prime_checker(int n = 0): n(n) {
        prime.assign(n + 10, true);
    }
    void find_prime() {
        for(int i = 4; i <= n; i += 2) 
            prime[i] = false;
        for(int i = 3; i * i <= n; i += 2) 
            if(prime[i]) {
                for(int j = i * i; j <= n; j += i) 
                    prime[j] = false;
            }
        FOR(i, 2, n) if(prime[i]) 
            plist.pb(i);
    }
    // now we have prime[x] = check if x is a prime number
} tmp;
