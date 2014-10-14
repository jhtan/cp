#include <bits/stdc++.h>

using namespace std;

typedef long long          ll;
typedef vector<int>        vi;
typedef pair<int, int>     ii;
typedef vector<ii>         vii;
typedef set<int>           si;
typedef map<string, int>   msi;

int main() {
  int n, m; scanf("%d %d", &n, &m);

  int p = n / 2;
  int s = n / 2 + n % 2;
  
  while(p) {
    if(s % m == 0) break;

    p--;
    s++;
  }

  if(s % m == 0) printf("%d\n", s);
  else printf("-1\n");

  return 0;
}
