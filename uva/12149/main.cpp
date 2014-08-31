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

  while(n) {
    printf("%d\n", (n*(n+1)*(2*n+1))/6);
    scanf("%d", &n);
  }

  return 0;
}
