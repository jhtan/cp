#include <bits/stdc++.h>

using namespace std;

typedef long long          ll;
typedef vector<int>        vi;
typedef pair<int, int>     ii;
typedef vector<ii>         vii;
typedef set<int>           si;
typedef map<string, int>   msi;

int main() {
  vi V;
  vector<bool> S(4000001, false);
  for(int i=1; i<=2000; i++) {
    V.push_back(i*i);
    S[i*i] = true;
  }

  int t; scanf("%d", &t);
  int tc = 0;

  while(t--) {
    int k; scanf("%d", &k);

    int n;
    for(int i=0; i<V.size(); i++) {
      n = V[i] - k;

      if(n < 1 || n & 1) continue;

      if(S[n/2+k])
	break;
    }

    printf("Case %d: %d\n", ++tc, n);
  }

  return 0;
}
