#include <bits/stdc++.h>

using namespace std;

typedef long long          ll;
typedef vector<int>        vi;
typedef pair<int, int>     ii;
typedef vector<ii>         vii;
typedef set<int>           si;
typedef map<string, int>   msi;

int main() {
  int t, a, b, c;
  scanf("%d", &t);

  while(t--) {
    scanf("%d %d %d", &a, &b, &c);
    printf("%d\n", a+b+c);
  }

  return 0;
}
