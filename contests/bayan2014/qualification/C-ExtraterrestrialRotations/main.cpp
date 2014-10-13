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
    string V[6], a;
    for(int i=0; i<6; i++) cin >> V[i];

    int n, m; scanf("%d", &n);
    char c;
    for(int i=0; i<n; i++) {
      cin >> c >> m;
      m %= 4;
      if(c == 'X') {
	for(int j=0; j<m; j++) {
	  a = V[0];
	  V[0] = V[2];
	  V[2] = V[5];
	  V[5] = V[1];
	  V[1] = a;
	}
      } else if(c == 'Y') {
	for(int j=0; j<m; j++) {
	  a = V[1];
	  V[1] = V[3];
	  V[3] = V[2];
	  V[2] = V[4];
	  V[4] = a;
	}
      } else if(c == 'Z') {
	for(int j=0; j<m; j++) {
	  a = V[0];
	  V[0] = V[3];
	  V[3] = V[5];
	  V[5] = V[4];
	  V[4] = a;
	}
      }
    }

    for(int i=0; i<6; i++) {
      cout << V[i];
      if(i < 5) printf(" ");
      else printf("\n");
    }
  }

  return 0;
}
