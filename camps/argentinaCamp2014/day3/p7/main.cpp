#include <bits/stdc++.h>

using namespace std;

typedef long long          ll;
typedef vector<int>        vi;
typedef pair<int, int>     ii;
typedef vector<ii>         vii;
typedef set<int>           si;
typedef map<string, int>   msi;

int main() {
  int n, v; scanf("%d %d", &n, &v);

  vi A(n), B(n);
  for(int i=0; i<n; i++) scanf("%d", &A[i]);
  for(int i=0; i<n; i++) scanf("%d", &B[i]);

  int c = 0;
  double mn = 2000000000;
  for(int i=0; i<n; i++) {
    c += A[i];
    mn = min(mn, B[i]/(double)A[i]);
  }

  if(c * mn > v)
    printf("%d\n", v);
  else
    printf("%lf\n", c * mn);

  return 0;
}
