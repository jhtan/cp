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

  int a, b, c = 0;
  for(int i=0; i<n; i++) {
    scanf("%d %d", &a, &b);

    if(b - a >= 2) c++;
  }

  printf("%d\n", c);

  return 0;
}
