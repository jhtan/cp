#include <bits/stdc++.h>

using namespace std;

typedef long long          ll;
typedef vector<int>        vi;
typedef pair<int, int>     ii;
typedef vector<ii>         vii;
typedef set<int>           si;
typedef map<string, int>   msi;

int main() {
  int np = 1000;
  vector<bool> B(np+1, false);
  B[0] = B[1] = true;
  for(int i=2; i*i<=np; i++) {
    if(!B[i]) {
      for(int j=i+i; j<=np; j+=i)
	B[j] = true;
    }
  }

  int t; scanf("%d", &t);
  while(t--) {
    int n; scanf("%d", &n);

    int c = 0;
    for(int i=2; i<=n/2; i++)
      if(!B[i] && !B[n-i])
	c++;

    printf("%d\n", c);
  }

  return 0;
}
