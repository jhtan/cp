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
    int n; scanf("%d", &n);
    vii V;
    int a, b;
    for(int i=0; i<n; i++) {
      scanf("%d %d", &a, &b);
      V.push_back(ii(b, a));
    }

    sort(V.begin(), V.end());

    vector<int> K(35000, -1);
    K[0] = 0;
    for(int i=0; i<n; i++) {
      for(int j=30000; j>=0; j--) {
	if(K[j] != -1) {
	  K[V[i].first+j] = max(K[V[i].first+j], K[j]+V[i].second);
	}
      }
    }

    int m, x, s = 0; scanf("%d", &m);

    while(m--) {
      int mx = 0;
      scanf("%d", &x);

      for(int i=0; i<=x; i++)
	mx = max(mx, K[i]);

      s += mx;
    }

    printf("%d\n", s);

  }

  return 0;
}
