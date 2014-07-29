#include <bits/stdc++.h>

using namespace std;

typedef long long          ll;
typedef vector<int>        vi;
typedef pair<int, int>     ii;
typedef vector<ii>         vii;
typedef set<int>           si;
typedef map<string, int>   msi;

int main() {
  int t; scanf("%d", &t);

  while(t--) {
    vi V(6);
    int s = 0;
    for(int i=0; i<V.size(); i++) {
      scanf("%d", &V[i]);
      s += V[i];
    }
    
    if(s & 1) {
      printf("Tobby no puede cruzar\n");
      continue;
    }

    sort(V.begin(), V.end());

    bool sw = false;
    do {
      int c = 0;
      for(int i=0; i<6; i++) {
	c += V[i];
	if(c == s / 2) {
	  sw = true;
	  break;
	}
      }
    } while(next_permutation(V.begin(), V.end()));

    if(sw) printf("Tobby puede cruzar\n");
    else printf("Tobby no puede cruzar\n");
  }

  return 0;
}
