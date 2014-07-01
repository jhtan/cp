#include <bits/stdc++.h>

using namespace std;

typedef long long          ll;
typedef vector<int>        vi;
typedef pair<int, int>     ii;
typedef vector<ii>         vii;
typedef set<int>           si;
typedef map<string, int>   msi;

int main() {
  int n, m;
  scanf("%d %d", &n, &m);

  vector<bool> B(n, false);
  int c = 0;
  for(int i=0; i<n; i++) {
    int k, x;
    scanf("%d", &k);
    for(int j=0; j<k; j++) {
      scanf("%d", &x);
      if(!B[i] && m > x) {
	c++;
	B[i] = true;
      }
    }
  }

  printf("%d\n", c);

  bool sw = false;
  for(int i=0; i<n; i++) {
    if(B[i]) {
      if(sw) printf(" ");
      else sw = true;
      printf("%d", i+1);
    }
  }

  if(c)
    printf("\n");

  return 0;
}
