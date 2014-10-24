#include <bits/stdc++.h>

using namespace std;

typedef long long          ll;
typedef vector<int>        vi;
typedef pair<int, int>     ii;
typedef vector<ii>         vii;
typedef set<int>           si;
typedef map<string, int>   msi;

double cross(double x1, double y1, double x2, double y2) {
  return x1 * y2 - y1 * x2;
}

double area(double x1, double y1, double x2, double y2, double x3, double y3) {
  return cross(x2-x1, y2-y1, x3-x1, y3-y1);
}

int main() {
  int n;

  while(scanf("%d", &n), n) {
    vi X(n), Y(n);
    for(int i=0; i<n; i++) scanf("%d %d", &X[i], &Y[i]);
    int px, py; scanf("%d %d", &px, &py);

    int c = 0;
    for(int i=0; i<n; i++) {
      int inf = i, sup = (i +1) % n;
      if(Y[inf] > Y[sup]) swap(inf, sup);
      if(Y[inf] <= py && py < Y[sup])
	if(area(px, py, X[inf], Y[inf], X[sup], Y[sup]) > 0)
	  c++;
    }

    if(c & 1) printf("T\n");
    else printf("F\n");
  }

  return 0;
}
