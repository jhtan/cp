#include <bits/stdc++.h>

using namespace std;

typedef long long          ll;
typedef vector<int>        vi;
typedef pair<int, int>     ii;
typedef vector<ii>         vii;
typedef set<int>           si;
typedef map<string, int>   msi;

int main() {
  int np = 1000000;
  vector<bool> P(1000001, false);
  P[0] = P[1] = true;
  for(int i=2; i*i<=np; i++)
    if(!P[i])
      for(int j=i+i; j<=np; j+=i)
	P[j] = true;

  int n;
  scanf("%d", &n);

  vi V(n);
  for(int i=0; i<n; i++) scanf("%d", &V[i]);

  int c = 0;
  for(int i=1; i<(1<<n); i++) {
    int s = 0;
    for(int j=0; j<n; j++) {
      if(i & (1<<j))
	s += V[j];
    }
    if(!P[s]) {
      c++;
    }
  }

  printf("%d\n", c);

  return 0;
}
