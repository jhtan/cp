#include <bits/stdc++.h>

using namespace std;

typedef long long          ll;
typedef vector<int>        vi;
typedef pair<int, int>     ii;
typedef vector<ii>         vii;
typedef set<int>           si;
typedef map<string, int>   msi;

int main() {
  int n, t;
  
  while(scanf("%d %d", &n, &t) != EOF) {
    vi V(n);
    for(int i=0; i<n; i++) scanf("%d", &V[i]);
    sort(V.begin(), V.end());
    int c = 0;
    int x = 0;
    while(t > 0 && x < V.size()) {
      if(t >= V[x]) {
	t -= V[x];
	c++;
      }
      x++;
    }

    printf("%d\n", c);
  }

  return 0;
}
