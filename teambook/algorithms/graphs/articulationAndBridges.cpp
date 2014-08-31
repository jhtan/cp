int dfsn[MAX];
int dfsl[MAX];
int dfsp[MAX];
int aVertex[MAX];
int dfsNumberCounter = 0;
int dfsRoot;
int rootChildren;

void articulationPointAndBridges(int u) {
	dfsl[u] = dfsn[u] = dfsNumberCounter++;
	for (int j = 0; j < graph[u].size(); j++) {
		if (dfsn[graph[u][j]] == NOT_VISITED) {
			dfsp[graph[u][j]] = u;
			if (u == dfsRoot) rootChildren++;
			articulationPointAndBridges(graph[u][j]);
			if (dfsl[graph[u][j]] >= dfsn[u])
				aVertex[u] = 1;
			if (dfsl[graph[u][j]] > dfsn[u])
				DBG(graph[u][j] << " " << u); // u and graph[u][j] are a bridge
			dfsl[u] = min(dfsl[u], dfsl[graph[u][j]]);
		} else if(graph[u][j] != dfsp[u]) {
			dfsl[u] = min(dfsl[u], dfsn[graph[u][j]]);
		}
	}
}

int main() {
	memset(dfsn, 0, sizeof dfsn);
	memset(dfsl, 0, sizeof dfsl);
	memset(dfsp, 0, sizeof dfsp);
	memset(aVertex, 0, sizeof aVertex);
	dfsNumberCounter = 0;
	for (int i = 0; i < n; i++) {
		if (dfsn[i] == NOT_VISITED) {
			dfsRoot = i;
			rootChildren = 0;
			articulationPointAndBridges(i);
			aVertex[dfsRoot] = (rootChildren > 1);
		}
	}
	for (int i = 0; i < n; i++) {
		if (aVertex[i])
			DBG(i); // i is a articulation point
	}
	return 0;
}
