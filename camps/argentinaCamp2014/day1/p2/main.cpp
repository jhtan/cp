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

  vi V(2, 0);
  bool sw = true;

  int x;
  for(int i=0; i<n; i++) {
    scanf("%d", &x);

    if(x == 25) {
      V[0]++;
    } else if(x == 50) {
      if(V[0]) {
	V[0]--;
	V[1]++;
      } else {
	sw = false;
      }
    } else if(x == 100) {
      if(V[0] && V[1]) {
	V[0]--;
	V[1]--;
      } else if(V[0] >= 3) {
	V[0] -= 3;
      } else {
	sw = false;
      }
    }
  }

  if(sw) printf("YES\n");
  else printf("NO\n");

  return 0;
}
