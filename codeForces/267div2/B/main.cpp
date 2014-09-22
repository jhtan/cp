#include <bits/stdc++.h>

using namespace std;

typedef long long          ll;
typedef vector<int>        vi;
typedef pair<int, int>     ii;
typedef vector<ii>         vii;
typedef set<int>           si;
typedef map<string, int>   msi;

int main() {
  int n, m, k;
  scanf("%d %d %d", &n, &m, &k);
  
  vi V(m); for(int i=0; i<m; i++) scanf("%d", &V[i]);

  int x; scanf("%d", &x);

  int c = 0;
  for(int i=0; i<m; i++) {
    int a = x, b = V[i];

    int s = 0;
    while(a || b) {
      bool swa = a & 1;
      bool swb = b & 1;
      if((swa && !swb) || (!swa && swb)) {
	s++;
      }

      a /= 2;
      b /= 2;
    }

    if(s <= k)
      c++;
  }

  printf("%d\n", c);
  
  return 0;
}
