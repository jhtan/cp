#include <bits/stdc++.h>

using namespace std;

typedef long long          ll;
typedef vector<int>        vi;
typedef pair<int, int>     ii;
typedef vector<ii>         vii;
typedef set<int>           si;
typedef map<string, int>   msi;

bool intersects(int a, int b, int c, int d) {
  if(a <= c && c <= b) return true;
  if(a <= d && d <= b) return true;
  if(c <= a && a <= d) return true;
  if(c <= b && b <= d) return true;
  return false;
}

int main() {
  int p, q, l, r;
  scanf("%d %d %d %d", &p, &q, &l, &r);

  vii V, W;
  int a, b;
  for(int i=0; i<p; i++) {
    scanf("%d %d", &a, &b);
    V.push_back(ii(a, b));
  }
  for(int i=0; i<q; i++) {
    scanf("%d %d", &a, &b);
    W.push_back(ii(a, b));
  }

  int c = 0;
  for(int k=l; k<=r; k++) {
    bool sw = false;
    for(int i=0; i<p && !sw; i++) {
      for(int j=0; j<q && !sw; j++) {
	if(intersects(V[i].first, V[i].second, W[j].first+k, W[j].second+k)) {
	  sw = true;
	  c++;
	}
      }
    }
  }

  printf("%d\n", c);

  return 0;
}
