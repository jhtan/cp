int tree[400000];
int v[100000];

void init(int node, int a, int b) {
	if (a == b) {
		tree[node] = v[a];
		return;
	}
	init(2*node+1, a, (a + b)/2);
	init(2*node+2, (a+b)/2+1, b);
	tree[node] = tree[2*node+1] + tree[2*node+2];
}

int query(int node, int a, int b, int p, int q) {
	if (q < a || b < p) return 0; // return 0 for sum, 1 for product
	if (p <= a && b <= q) return tree[node];
	return query(2*node+1, a, (a+b)/2, p, q) + query(2*node+2, (a+b)/2+1, b, p, q);
}

void update(int node, int a, int b, int p, int val) {
	if (p < a || b < p) return;
	if (a == b) {
		tree[node] = val;
		return;
	}
	update(2*node+1, a, (a+b)/2, p, val);
	update(2*node+2, (a+b)/2+1, b, p, val);
	tree[node] = tree[2*node+1] + tree[2*node+2];
}

