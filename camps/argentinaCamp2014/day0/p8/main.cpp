#include <bits/stdc++.h>

using namespace std;

typedef long long          ll;
typedef vector<int>        vi;
typedef pair<int, int>     ii;
typedef vector<ii>         vii;
typedef set<int>           si;
typedef map<string, int>   msi;

int main() {
  int n;
  scanf("%d", &n);

  if(n & 1)
    printf("%d\n", ((n-1) * (n-1)) / 2 + n / 2 + n / 2 + 1);
  else
    printf("%d\n", (n * n) / 2);

  for(int i=0; i<n; i++) {
    for(int j=0; j<n; j++) {
      if(i&1)
	if(j&1) printf("C");
	else printf(".");
      else
	if(j&1) printf(".");
	else printf("C");

      if(j == n-1) printf("\n");
    }
  }

  return 0;
}
