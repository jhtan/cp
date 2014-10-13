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
    int r, g, b, m, x;
    scanf("%d %d %d %d", &r, &g, &b, &m);

    vii V;
    for(int i=0; i<r; i++) {
      scanf("%d", &x);
      V.push_back(ii(x, 'r'));
    }
    for(int i=0; i<g; i++) {
      scanf("%d", &x);
      V.push_back(ii(x, 'g'));
    }
    for(int i=0; i<b; i++) {
      scanf("%d", &x);
      V.push_back(ii(x, 'b'));
    }

    while(m--) {
      sort(V.rbegin(), V.rend());
      for(int i=0; i<V.size(); i++) {
	if(V[i].second == V[0].second)
	  V[i].first /= 2;
      }
    }

    sort(V.rbegin(), V.rend());
    printf("%d\n", V[0].first);
  }

  return 0;
}
