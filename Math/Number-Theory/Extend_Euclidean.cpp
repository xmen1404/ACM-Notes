pair<int, int> Extended_Euclidean_no_recursion(int a, int b) {
    int x = 1, y = 0, x1 = 0, y1 = 1; // xa + yb = a1 ... x1a + y1b = b1
    while(b) {
        int p = (a/b);
        tie(x, x1) = make_tuple(x1, x - p * x1);
        tie(y, y1) = make_tuple(y1, y - p * y1);
        tie(a, b) = make_tuple(b, a - p * b);
    }
    return {x, y};
}

int Extended_Euclidean(int a, int b, int &x, int &y) {
    if(b == 0) {
        x = 1, y = 0;
        return a;
    }
    int _gcd = Extended_Euclidean(b, a % b, x, y);
    tie(x, y) = make_tuple(y, x - y * (a/b));
    return _gcd;
}
