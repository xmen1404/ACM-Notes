int gcd(int x, int y) {
    if(x < y) swap(x, y);
    while(y) {
        int tmp = x % y;
        x = y, y = tmp;
    }
    return x;
}

int Extend_Euclidean(int a, int b, int &x, int &y) {
    if(b == 0) {
        x = 1, y = 0;
        return a;
    }
    int _gcd = Extend_Euclidean(b, a % b, x, y);
    int tmp = x; x = y;
    y = tmp - y * (a / b);
    return _gcd;
}
