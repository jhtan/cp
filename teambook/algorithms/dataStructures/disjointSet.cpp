int p[MAX];
void initSet(int n) {
	for (int i = 0; i < n ; i++) p[i] = i;
}
int findSet(int i) {
	return p[i] == i?i:p[i] = findSet(p[i]);
}
void unionSet(int i, int j) {
	p[findSet(i)] = findSet(j);
}
bool isSameSet(int i, int j) {
	return findSet(i) == findSet(j);
}
