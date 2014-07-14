#include <bits/stdc++.h>

using namespace std;

typedef long long          ll;
typedef vector<int>        vi;
typedef pair<int, int>     ii;
typedef vector<ii>         vii;
typedef set<int>           si;
typedef map<string, int>   msi;

int main() {
  int t;
  scanf("%d", &t);
  string s = "GCAT";

  srand (time(NULL));

  while(t--) {
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);

    for(int i=0; i<n; i++) {
      for(int j=0; j<m; j++) {
	printf("%c", s[rand() % 4]);
      }
      printf("\n");
    }
  }

  return 0;
}
