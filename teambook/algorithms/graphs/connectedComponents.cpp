int n, e;
vector<vi> graph;
int dfsm[MAX];

void dfs(int start) {
	dfsm[start] = VISITED;
	cout << start << " ";
	for (int i = 0; i < graph[start].size(); i++) {
		if (dfsm[graph[start][i]] == NOT_VISITED) {
			dfs(graph[start][i]);
		}
	}
}

int main() {
	memset(dfsm, NOT_VISITED, sizeof dfsm);
	int numCC = 0;
	for (int i = 0; i < n; i++) {
		if (dfsm[i] == NOT_VISITED) {
			printf("Component %d:", ++numCC);
			dfs(i);
			printf("\n");
		}
	}
	return 0;
}
