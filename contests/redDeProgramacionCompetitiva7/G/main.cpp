#include <bits/stdc++.h>

using namespace std;

typedef long long          ll;
typedef vector<int>        vi;
typedef pair<int, int>     ii;
typedef vector<ii>         vii;
typedef set<int>           si;
typedef map<string, int>   msi;

int main() {
  int V[7];
  int s = 0;
  double P[7];

  while(scanf("%d %d %d %d %d %d %d", &V[0], &V[1], &V[2], &V[3], &V[4], &V[5], &V[6]) != EOF) {
    s = 0;
    for(int i=0; i<7; i++) { P[i] = 0; s += V[i];}

    for(int i=0; i<7; i++) {
      if(V[i]) {
	P[(i+1)%7] += (0.6 / (double)s);
	P[(i+2)%7] += (0.4 / (double)s);
      }
    }

    for(int i=0; i<7; i++) {
      printf("%lf", P[i]);

      if(i < 7) printf(" ");
      else printf("\n");
    }
    cout << endl;
  }

  return 0;
}
