int res[100][100];
int mf, f;
vi p;
int s, t;

void augment(int v, int minEdge) {
	if (v == s) {
		f = minEdge;
		return;
	} else if (p[v] != -1) {
		augment(p[v], min(minEdge, res[p[v]][v]));
		res[p[v]][v] -= f;
		res[v][p[v]] += f;
	}
}

int main() {
	/* Build adjacency matrix res */
	scanf("%d %d", &s, &t);
	mf = 0;
	while (1) {
		f = 0;
		vi dist(n, INT_INF);
		dist[s] = 0;
		queue<int> q; q.push(s);
		p.assign(n, -1);
		while (!q.empty()) {
			int u = q.front(); q.pop();
			if (u == t) break;
			for (int v = 0; v < n; v++)
				if (res[u][v] > 0 && dist[v] == INT_INF)
					dist[v] = dist[u] + 1, q.push(v), p[v] = u;
		}
		augment(t, INT_INF);
		if (f == 0) break;
		mf += f;
	}
	DBG(mf);
	return 0;
}
