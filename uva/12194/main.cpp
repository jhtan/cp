#include <bits/stdc++.h>

using namespace std;

typedef long long          ll;
typedef vector<int>        vi;
typedef pair<int, int>     ii;
typedef vector<ii>         vii;
typedef set<int>           si;
typedef map<string, int>   msi;

struct Point {
  double x, y;
};

double dist(const Point &a, const Point &b) {
  return hypot(a.x - b.x, a.y - b.y);
}

int main() {
  int n; scanf("%d", &n);

  while(n) {
    Point P[n];
    int a, b;
    for(int i=0; i<n; i++) {
      scanf("%d %d", &a, &b);
      P[i].x = a;
      P[i].y = b;
    }

    int c = 0;
    for(int i=0; i<n; i++) {
      vector<double> V;
      for(int j=0; j<n; j++) {
	if(i != j) V.push_back(dist(P[i], P[j]));
      }

      sort(V.begin(), V.end());
      double v = V[0], s = 1;
      for(int i=1; i<V.size(); i++) {
	if(V[i] != V[i-1]) {
	  if(s>1) c += (s*(s-1))/2;
	  s = 1;
	} else {
	  s++;
	}
      }
      if(s>1) c += (s*(s-1))/2;

    }

    printf("%d\n", c);
    scanf("%d", &n);
  }

  return 0;
}
