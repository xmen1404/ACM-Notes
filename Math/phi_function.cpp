// phi-function = number integer [1, n] which coprime to n
// p = prime        -> phi(p) = p-1
// p=prime, k>=1    -> phi(p^k) = p^k - p^(k-1)
// gcd(a, b) = 1    -> phi(ab) = phi(a) * phi(b)
// gcd(a, b) != 1   -> phi(ab) = phi(a)*phi(b)*gcd(a, b)/phi(gcd(a, b))   
// for every d sthat d|n -> sigma(phi(d)) = n (use this to calculate all phi(n) take O(nlogn)) 
// Use Sieve of Eratosthenes-like algorithm calculate all phi(n) take O(nloglog) 
// gcd(a, m) == 1   -> a^phi(m) % m = 1
// in case m prime  -> Fermat's little theorem: a^(m-1) % m = 1
// a^n ≡ a^(n % ϕ(m)) (mod m)
// gcd(x, m) != 1, n >= log2(m)   -> x^n ≡ x^(ϕ(m)+[n % ϕ(m)]) (mod m)

int phi(int n) {
    // factoraization O(sqrt(n))
    // lower complexity if list of prime numbers is prepared
    int result = 1;
    for(int i = 2; i*i <= n; i += 1) if(n % i == 0) {
        int factor = 1;
        while(n % i == 0) {
            factor *= i;
            n /= i;
        }
        result = result * (factor - factor/i);
    }
    if(n > 1) result = result * (n - 1);
    return result;
}
