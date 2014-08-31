#include <cstring>
#include <cstdio>

using namespace std;

int n;
int M[1001][1001];
bool B[1001][1001];

void ff(int i, int j) {
  B[i][j] = true;
  int X[8] = {0, 1, 1, 1, 0, -1, -1, -1};
  int Y[8] = {-1, -1, 0, 1, 1, 1, 0, -1};

  for(int k=0; k<8; k++) {
    int a = X[k] + i;
    int b = Y[k] + j;
    if(a >= 0 && b >= 0 && a < n && b < n) {
      if(!B[a][b] && M[i][j])
      	ff(a, b);
    }
  }
}

int main() {
  scanf("%d", &n);
  
  for(int i=0; i<n; i++)
    for(int j=0; j<n; j++)
      scanf("%d", &M[i][j]);

  memset(B, false, sizeof(B));
  int c = 0;
  for(int i=0; i<n; i++) {
    for(int j=0; j<n; j++) {
      if(!B[i][j] && M[i][j]) {
      	ff(i, j);
	      c++;
      }
    }
  }

  printf("%d\n", c);
  return 0;
}
