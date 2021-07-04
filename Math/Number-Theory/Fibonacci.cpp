// F(n-1) * F(n+1) - F(n) ^ 2 = (-1) ^ n
// F(n+k) = F(k) * F(n+1) + F(k-1) * F(n)
// => F(2n) = F(n) * (F(n+1) + F(n-1))
// => F(2n + 1) = F(n+1) ^ 2 + F(n) ^ 2
// For any integer k > 0: F(nk) is multiple of F(n)
// For any integer m that F(m) is multiple of F(n) => m is multiple of n
// GCD(Fm, Fn) = F(GCD(m, n))
// Any natural number n can be uniquely represented as a sum of Fibonacci numbers
