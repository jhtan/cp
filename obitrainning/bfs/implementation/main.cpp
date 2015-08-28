#include <bits/stdc++.h>

using namespace std;

typedef long long          ll;
typedef vector<int>        vi;
typedef pair<int, int>     ii;
typedef vector<ii>         vii;
typedef set<int>           si;
typedef map<string, int>   msi;

int main() {
  int v, e;
  scanf("%d %d", &v, &e);

  vector<vi> G(v, vi());

  int a, b;
  for(int i=0; i<e; i++) {
    scanf("%d %d", &a, &b);
    G[a].push_back(b);
    G[b].push_back(a);
  }

  vi D(v, -1); // Distances vector.
  vi P(v, -1); // Parents vector.

  queue<int> Q;
  Q.push(0);
  D[0] = 0;

  while(!Q.empty()) {
    int x = Q.front();
    Q.pop();

    for(int i=0; i < G[x].size(); i++) {
      if(D[G[x][i]] == -1) {
	Q.push(G[x][i]);
	D[G[x][i]] = D[x] + 1;
	P[G[x][i]] = x;
      }
    }
  }

  for(int i=0; i<v; i++)
    cout << D[i] << " ";
  cout << endl;

  for(int i=0; i<v; i++)
    cout << P[i] << " ";
  cout << endl;

  return 0;
}
