int x[N];
int lis[N];
void lis() {
	lis[0] = 1;
	int maxim = 0;
	for (int i = 1; i < x.size(); i++) {
		int ma = 0;
		for (int j = 0; j < i; j++) if (x[j] < x[i]) ma = max(ma, lis[j]);
		lis[i] = 1 + ma;
		maxim = max(maxim, ma);
	}
}
