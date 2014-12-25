#include <bits/stdc++.h>

using namespace std;

typedef long long          ll;
typedef vector<int>        vi;
typedef pair<int, int>     ii;
typedef vector<ii>         vii;
typedef set<int>           si;
typedef map<string, int>   msi;

int main() {
  int n, m;
  scanf("%d %d", &n, &m);

  vii V;
  int a, b;
  for(int i=0; i<n; i++) {
    scanf("%d %d", &a, &b);
    V.push_back(ii(a, b));
  }

  sort(V.begin(), V.end());

  int c = 0, s = 0, i = 0;

  while(c <= 100000 ) {
    if(c + m < V[i].first) {
      c += m;
    } else {
      s += (V[i].second - c);
      c = V[i].second;
      i++;
      if(i == n) break;
    }
  }

  printf("%d\n", s);

  return 0;
}
