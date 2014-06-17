#include <bits/stdc++.h>

using namespace std;

typedef long long          ll;
typedef vector<int>        vi;
typedef pair<int, int>     ii;
typedef vector<ii>         vii;
typedef set<int>           si;
typedef map<string, int>   msi;

vi V, W;

bool win(int n) {
  if(W[n] == 1)
    return true;
  if(W[n] == 2)
    return false;

  for(int i=0; i<V.size(); i++) {
    if(n-V[i] >= 0 && !win(n-V[i])) {
      W[n] = 1;
      return true;
    }
  }

  W[n] = 2;
  return false;
}

int main() {
  int t, tc=0;
  scanf("%d", &t);

  while(t--) {
    int n, m;
    scanf("%d %d", &n, &m);
    V.assign(m, 0);
    W.assign(n+1, 0);

    for(int i=0; i<m; i++) {
      scanf("%d", &V[i]);
      if(V[i] < n)
	W[V[i]] = 1;
    }

    if(win(n))
      printf("Caso #%d: SI\n", ++tc);
    else
      printf("Caso #%d: NO\n", ++tc);
  }

  return 0;
}
