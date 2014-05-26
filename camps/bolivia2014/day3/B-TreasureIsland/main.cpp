#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;

typedef long long          ll;
typedef vector<int>        vi;
typedef pair<int, int>     ii;
typedef vector<ii>         vii;
typedef set<int>           si;
typedef map<string, int>   msi;

//#define for(i, a, b) \
//  for(int i = int(a); i <= int(b); i++)
//#define Rvi(c, it) \
//  for(vi::iterator it = (c).begin(); it != (c).end(); it++)
//#define Rvii(c, it) \
//  for(vii::iterator it = (c).begin(); it != (c).end(); it++)
//#define Rmsi(c, it) \
//  for(msi::iterator it = (c).begin(); it != (c).end(); it++)

int main() {
  int t;
  scanf("%d", &t);

  while(t--) {
    int n, m;
    scanf("%d %d", &n, &m);
    int B[n][n];
    memset(B, false, sizeof(B));

    int a, b;
    for(int i=0; i<m; i++) {
      scanf("%d %d", &a, &b);
      B[a][b] = true;
    }

    int mn = 0;

    for(int i=0; i<(1<<n); i++) {
      vi V;
      bool sw = true;
      for(int j=0; j<n; j++) {
	if(i & (1 << j)) {
	  V.push_back(j);
	}
      }

      for(int j=0; j<V.size() && sw; j++) {
	for(int k=0; k<V.size() && sw; k++) {
	  if(B[V[j]][V[k]])
	    sw = false;
	}
      }

      if(sw)
	mn = max(mn, (int)V.size());
    }

    printf("%d\n", mn);
  }

  return 0;
}
