#include<bits/stdc++.h>

using namespace std;

int n, m;
string M[1010];
bool B[1010][1010];
int X[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
int Y[8] = {-1, 0, 1, 1, 1, 0, -1, -1};

void ff(int a, int b) {
  B[a][b] = true;

  for(int k=0; k<8; k++) {
    int x = a + X[k];
    int y = b + Y[k];

    if(x >= 0 && y >= 0 && x < n && y < m)
      if(M[x][y] == '@' && !B[x][y])
	ff(x, y);
  }
}

int main() {
  scanf("%d %d", &n, &m);

  while(n + m > 0) {
    for(int i=0; i<n; i++) cin >> M[i];
    memset(B, false, sizeof B);

    int c = 0;
    for(int i=0; i<n; i++) {
      for(int j=0; j<m; j++) {
	if(M[i][j] == '@' && !B[i][j]) {
	  ff(i, j);
	  c++;
	}
      }
    }

    printf("%d\n", c);
    scanf("%d %d", &n, &m);
  }

  return 0;
}
