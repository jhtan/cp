void printPath(int u) {
	if (u == s) {
		cout << s << " ";
		return;
	}
	printPath(p[u]);
	cout << u << " ";
}

int main() {
	/* Build Graph */
	// SSPU
	// s: start, t: target
	map<int, int> dist;
	dist[s] = 0;
	queue<int> q;
	q.push(s);
	while(!q.empty()) {
		int u = q.front(); q.pop();
		for (int j = 0; j < g[u].size(); j++) {
			int v = g[u][j];
			if (!dist.count(v)) {
				dist[v] = dist[u] + 1;
				p[v] = u;
				q.push(v);
			}
		}
	}
	DBG(dist[t]);
	printPath(t);
	return 0;
}
