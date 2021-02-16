// Calculate GCD(a, b) in O(log(min(a, b)))
// This method is faster as it prevents using modulo operation

int fast_gcd(int a, int b) {
    if(!a || !b) return (a|b);
    int shift = __builtin_ctz((a | b));
    a >>= shift, b >>= shift;
    if(a % 2 == 0) swap(a, b);
    do {
        b >>= __builtin_ctz(b);
        if(a > b) swap(a, b);
        b -= a;
    } while(b > 0);
    return (a << shift);
}
