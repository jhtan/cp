#include <cstdio>
#include <algorithm>

using namespace std;

#define INF 1000000000

int main() {
  int v, e;
  scanf("%d %d", &v, &e);

  int M[v][v];
  for(int i=0; i<v; i++) {
    for(int j=0; j<v; j++)
      M[i][j] = INF;
    M[i][i] = 0;
  }

  int a, b, c;
  for(int i=0; i<e; i++) {
    scanf("%d %d %d", &a, &b, &c);
    M[a][b] = c;
  }

  // Floyd Warshall Algotithm.
  for(int k=0; k<v; k++)
    for(int i=0; i<v; i++)
      for(int j=0; j<v; j++)
	M[i][j] = min(M[i][j], M[i][k] + M[k][j]);

  for(int i=0; i<v; i++)
    for(int j=0; j<v; j++)
      printf("APSP(%d, %d) = %d\n", i, j, M[i][j]);
  
  return 0;
}
