pair<int, int> Extended_Euclidean(int a, int b) {
    int x = 1, y = 0, x1 = 0, y1 = 1; // xa + yb = a1 ... x1a + y1b = b1
    while(b) {
        int p = (a/b);
        tie(x, x1) = mtp(x1, x - p * x1);
        tie(y, y1) = mtp(y1, y - p * y1);
        tie(a, b) = mtp(b, a - p * b);
    }
    return {x, y};
}
