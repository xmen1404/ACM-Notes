// Code is checked with GGCodejam 2019 Round 1B task 3

struct RMQ { 
	// Get max value in a interval with O(1)
	// Build process take O(nlog)
	// Modify the comparation and INF value if get min value is needed
	// Array's values need to be assign manually

	int n, max_log;
	vector<int> value;
	vector< vector<int> > frmq;
	RMQ(int n = 0) : n(n) {
		max_log = (int) log2(n) + 5;
		value.assign(n + 100, 0);
		frmq.assign(n + 100, vector<int>() );

		for(int i = 0; i <= n + 10; ++i)  
			frmq[i].assign(max_log + 1, 0); // max number elements = 2 ^ 20
	}

	void build() {
		for(int i = 0; i <= n; ++i) frmq[i][0] = value[i];

		for(int i = 1; i <= max_log; ++i) {
			for(int pos = 1; pos <= n; ++pos) if(pos + (1 << i) - 1 <= n) {
				frmq[pos][i] = max(frmq[pos][i - 1], frmq[pos + (1 << (i - 1))][i - 1]); // modify this operation
			}
		}
	}

	int get(int left, int right) {
		if(left > right || left < 1 || right > n) 
			return printf("Bug here: left and right indices are not consistent"), 0;

		int cur_log = log2(right - left + 1);
		return max(frmq[left][cur_log], frmq[right - (1 << cur_log) + 1][cur_log]); // modify this operation
	}

} rmq; 
