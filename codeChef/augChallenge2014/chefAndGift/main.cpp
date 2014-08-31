#include <bits/stdc++.h>

using namespace std;

typedef long long          ll;
typedef vector<int>        vi;
typedef pair<int, int>     ii;
typedef vector<ii>         vii;
typedef set<int>           si;
typedef map<string, int>   msi;

int main() {
  int t;
  scanf("%d", &t);

  while(t--) {
    int n, k;
    scanf("%d %d", &n, &k);

    int x, c = 0;
    for(int i=0; i<n; i++) {
      scanf("%d", &x);
      x = abs(x);
      if(x % 2 == 0)
	c++;
    }

    if(k == 0 && c == n) {
      printf("NO\n");
      continue;
    }

    if(k == 0 && c < n) {
      printf("YES\n");
      continue;
    }

    if(c >= k)
      printf("YES\n");
    else
      printf("NO\n");
  }

  return 0;
}
