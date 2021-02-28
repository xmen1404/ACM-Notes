// ax + by = c
// Find all solution of the eq with x in range[lx, rx]
// 0 = no solution
// 1 = finite solution
// 2 = infinite solution

int gcd(int x, int y) {
	while(y > 1) {
		tie(x, y) = make_tuple(y, x % y);
	} 
	return x;
}
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

vector<ii> result;
int diophantine_equation(int a, int b, int c, int lx, int rx) { 
	if(!a && !b) {
		if(!c) return 2;
		return 0;
	}
	if(!b) {
		if(c % a == 0) return 2;
		return 0;
	}

	int _gcd = gcd(a, b);
	if(c % _gcd != 0) return 0;

	ii n0 = Extended_Euclidean_no_recursion(a, b); // n0.fi * a + n0.se * b = _gcd
	n0 = {n0.fi * (c / _gcd), n0.se * (c / _gcd)}; // n0.fi * a + n0.se * b = c
	if(n0.fi > lx) {
		int p = (n0.fi - lx) / abs(b / _gcd);
		if((b / _gcd) > 0) {
			n0.fi -= p * (b / _gcd);
			n0.se += p * (a / _gcd);	
		} else {
			n0.fi += p * (b / _gcd);
			n0.se -= p * (a / _gcd);
		}
	} else {
		int p = (n0.fi - lx + abs(b / _gcd) - 1) / abs(b / _gcd);
		if((b / _gcd) > 0) {
			n0.fi += p * (b / _gcd);
			n0.se -= p * (a / _gcd);	
		} else {
			n0.fi -= p * (b / _gcd);
			n0.se += p * (a / _gcd);
		}
	}
	while(n0.fi <= rx) {
		result.pb(n0);
		if((b / _gcd) > 0) {
			n0.fi += (b / _gcd);
			n0.se -= (a / _gcd);	
		} else {
			n0.fi -= (b / _gcd);
			n0.se += (a / _gcd);
		}
	}
}
