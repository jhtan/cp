#include <bits/stdc++.h>

using namespace std;

typedef long long          ll;
typedef vector<int>        vi;
typedef pair<int, int>     ii;
typedef vector<ii>         vii;
typedef set<int>           si;
typedef map<string, int>   msi;

int main() {
  int t; scanf("%d", &t);

  while(t--) {
    int n, m; scanf("%d %d", &n, &m);
    vi V(n); 
    int mx = 0;
    for(int i=0; i<n; i++) {
      scanf("%d", &V[i]);
      mx = max(mx, V[i]);
    }

    int c = 0;
    for(int i=0; i<n; i++)
      c += mx - V[i];

    if((m - c) % n == 0) printf("Yes\n");
    else printf("No\n");
  }

  return 0;
}
