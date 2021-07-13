// phi-function = number integer [1, n] which coprime to n
// p = prime        -> phi(p) = p-1
// p=prime, k>=1    -> phi(p^k) = p^k - p^(k-1)
// gcd(a, b) = 1    -> phi(ab) = phi(a) * phi(b)
// gcd(a, b) != 1   -> phi(ab) = phi(a)*phi(b)*gcd(a, b)/phi(gcd(a, b))    

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
