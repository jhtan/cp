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

  while(n) {
    vector<double> X(n+1), Y(n+1);

    for(int i=0; i<n; i++) {
      scanf("%lf %lf", &X[i], &Y[i]);
    }
    X[n] = X[0]; Y[n] = Y[0];

    if(n == 1 || n == 2) {
      printf("0\n");
      scanf("%d", &n);
      continue;
    }

    double a = 0;
    for(int i=0; i<n; i++) {
      a += X[i]*Y[i+1];
      a -= X[i+1]*Y[i];
    }

    a = abs(a /= 2.0);
    printf("%d\n", (int)round(a));
    scanf("%d", &n);
  }

  return 0;
}
