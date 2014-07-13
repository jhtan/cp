#include <bits/stdc++.h>

using namespace std;

typedef long long          ll;
typedef vector<int>        vi;
typedef pair<int, int>     ii;
typedef vector<ii>         vii;
typedef set<int>           si;
typedef map<string, int>   msi;

int main() {
  int p, n;
  scanf("%d %d", &p, &n);

  set<int> S, T;
  int c = 0;
  bool sw = true;
  for(int i=0; i<n; i++) {
    int x;
    scanf("%d", &x);

    x %= p;
    if(S.count(x) == 0)
      S.insert(x);
    else {
      if(sw) {
	c = i + 1;
	sw = false;
      }
    }
  }

  if(c)
    printf("%d\n", c);
  else
    printf("-1\n");

  return 0;
}
