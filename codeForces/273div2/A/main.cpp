#include <bits/stdc++.h>

using namespace std;

typedef long long          ll;
typedef vector<int>        vi;
typedef pair<int, int>     ii;
typedef vector<ii>         vii;
typedef set<int>           si;
typedef map<string, int>   msi;

int main() {
  int s = 0, x;

  for(int i=0; i<5; i++) {
    scanf("%d", &x);
    s += x;
  }

  if(s % 5 == 0 && s != 0)
    printf("%d\n", s / 5);
  else printf("-1\n");

  return 0;
}
