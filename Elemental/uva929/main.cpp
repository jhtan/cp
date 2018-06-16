#include<bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

int main() {
  int n, m;
  scanf("%d %d", &n, &m);

  int M[n][m];
  for(int i=0; i<n; i++)
    for(int j=0; j<m; j++)
      scanf("%d", &M[i][j]);

  vector<vii> G(n*m, vii());

  for(int i=0; i<n; i++) {
    for(int j=0; j<m; j++) {
      int x = i * m + j;
      
      if(i > 0) {
	int y = x - m;
	G[x].push_back(ii(y, M[i][j-1]));
      }
      if(j < m - 1) {
	int y = x + 1;
	G[x].push_back(ii(y, M[i+1][j]));
      }
      if(j < n - 1) {
	int y = x + m;
      }
      if(j > 0) {
	int y = x - 1;
      }
    }
  }

  return 0;
}
