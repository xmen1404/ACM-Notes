// Code is checked by GG Kickstart 2021 - Round B - Problem 4
struct IT{
	int n;
	vector<int> node, lazy;

	IT(int n = 0): n(n) {
		node.assign(4 * n + 100, 0);
		lazy.assign(4 * n + 100, 0);
	}

	int add(int x, int y) { // modify this operation
		while(y != 0) {
			x %= y;
			swap(x, y);
		}
		return x;
	}

	void push_lazy(int i, int lef, int rig) {
		if(lef > rig) return;
		node[i] = add(node[i], lazy[i]);
		if(lef < rig) {
			lazy[2 * i] = add(lazy[2*i], lazy[i]);
			lazy[2*i + 1] = add(lazy[2*i + 1], lazy[i]);
		}
		lazy[i] = 0; // modify this value
	}

	void upd_add(int i, int lef, int rig, int qlef, int qrig, int val) {
		push_lazy(i, lef, rig);
		if(lef > rig || qlef > rig || qrig < lef) return;
		if(qlef <= lef && rig <= qrig) {
			lazy[i] = val;
			return;
		}
		int mid = (lef + rig) / 2;
		upd_add(2*i, lef, mid, qlef, qrig, val);
		upd_add(2 * i + 1, mid + 1, rig, qlef, qrig, val);
		node[i] = add(node[2*i], node[2*i + 1]);
	}

	int get_pos(int i, int lef, int rig, int pos) { // modify this operation
		push_lazy(i, lef, rig);
		if(lef > pos || pos > rig || lef > rig) return 0; // modify this value
		if(lef == rig) return node[i];
		int mid = (lef + rig) / 2;
		
		if(pos <= mid) return get_pos(2 * i, lef, mid, pos);
		else return get_pos(2 * i + 1, mid + 1, rig, pos);
	}

	int get_range(int i, int lef, int rig, int qlef, int qrig) {
		push_lazy(i, lef, rig);
		if(lef > rig || lef > qrig || rig < qlef) return 0; // modify this value
		if(qlef <= lef && rig <= qrig) return node[i];
		int mid = (lef + rig) / 2;
		return add(get_range(2*i, lef, mid, qlef, qrig), get_range(2 * i + 1, mid + 1, rig, qlef, qrig));
	}

	void reset(int _n) {
		node.clear();
		lazy.clear();
		n = _n;
		node.assign(4 * n + 100, 0);
		lazy.assign(4 * n + 100, 0);
	}
} it;
