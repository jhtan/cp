#include <bits/stdc++.h>

using namespace std;

typedef long long          ll;
typedef vector<int>        vi;
typedef pair<int, int>     ii;
typedef vector<ii>         vii;
typedef set<int>           si;
typedef map<string, int>   msi;

int main() {
  int n; scanf("%d", &n);

  bool B[n+1];
  memset(B, false, sizeof(B));
  int m, x; scanf("%d", &m);
  for(int i=0; i<m; i++) {
    scanf("%d", &x);
    B[x] = true;
  }

  scanf("%d", &m);
  for(int i=0; i<m; i++) {
    scanf("%d", &x);
    B[x] = true;
  }

  for(int i=1; i<=n; i++) {
    if(!B[i]) {
      printf("Oh, my keyboard!\n");
      return 0;
    }
  }

  printf("I become the guy.\n");

  return 0;
}
