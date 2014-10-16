#include <bits/stdc++.h>

using namespace std;

typedef long long          ll;
typedef vector<int>        vi;
typedef pair<int, int>     ii;
typedef vector<ii>         vii;
typedef set<int>           si;
typedef map<string, int>   msi;

int main() {
  int n, z; scanf("%d", &n);
  vii V(n); for(int i=0; i<n; i++) {
    scanf("%d", &z);
    V[i].first = z;
    V[i].second = i + 1;
  }

  sort(V.begin(), V.end());
  int x=-1, y=-1;
  for(int i=1; i<n; i++) {
    if(V[i].first == V[i-1].first) {
      if(x == -1) x = i;
      else if(y == -1) y = i;
      else break;
    }
  }

  if(y == -1) {
    printf("NO\n");
  } else {
    printf("YES\n");
    for(int i=0; i<n; i++) {
      printf("%d", V[i].second);
      if(i == n-1) printf("\n");
      else printf(" ");
    }

    for(int i=0; i<n; i++) {
      if(i == x) printf("%d", V[i-1].second);
      else if(i == x-1) printf("%d", V[i+1].second);
      else printf("%d", V[i].second);

      if(i == n-1) printf("\n");
      else printf(" ");
    }

    for(int i=0; i<n; i++) {
      if(i == y) printf("%d", V[i-1].second);
      else if(i == y-1) printf("%d", V[i+1].second);
      else printf("%d", V[i].second);

      if(i == n-1) printf("\n");
      else printf(" ");
    }
 }

  return 0;
}
