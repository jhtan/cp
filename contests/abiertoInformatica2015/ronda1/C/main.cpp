#include <bits/stdc++.h>

using namespace std;

typedef long long          ll;

int main() {
  int n, m; scanf("%d %d", &n, &m);

  while(n + m) {
    ll M[n][m];
    for(int i=0; i<n; i++) for(int j=0; j<m; j++) cin >> M[i][j];

    for(int i=0; i<n; i++) {
      if(m > 2)
	M[i][2] += M[i][0];
      for(int j=3; j<m; j++)
	M[i][j] += max(M[i][j-2], M[i][j-3]);
    }

    for(int i=0; i<n; i++)
      if(m>1)
	M[i][m-1] = max(M[i][m-1], M[i][m-2]);

    if(n > 2)
      M[2][m-1] += M[0][m-1];

    for(int i=3; i<n; i++)
      M[i][m-1] += max(M[i-2][m-1], M[i-3][m-1]);

    printf("%lld\n", max(M[n-1][m-1], M[n-2][m-1]));
    scanf("%d %d", &n, &m);
  }

  return 0;
}
