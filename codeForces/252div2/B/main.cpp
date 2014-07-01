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

  vii F;
  int a, b;
  for(int i=0; i<n; i++) {
    scanf("%d %d", &a, &b);
    F.push_back(ii(a, b));
  }

  sort(F.begin(), F.end());

  int c = 0, d = -1, x = m;
  while(true) {
    d++;
    x = m;
    
    int c2 = 0, c3 = 0;
    for(int i=0; i<F.size() && x; i++) {
      if(F[i].first - d == 0 || F[i].first - d == 1) {
	if(x >= F[i].second) {
	  c2 += F[i].second;
	  x -= F[i].second;
	  F[i].second = 0;
	} else {
	  c2 += x;
	  F[i].second -= x;
	  x = 0;
	}
      }

      if(d > F[i].first)
	c3++;
    }

    if(c3 == n)
      break;

    c += c2;
  }

  printf("%d\n", c);

  return 0;
}
