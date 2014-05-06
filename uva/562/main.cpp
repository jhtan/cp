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

  bool M[25001][100];

  while(t--) {
    int n;
    scanf("%d", &n);

    int V[n], s = 0;
    for(int i=0; i<n; i++) {
      scanf("%d", &V[i]);
      s += V[i];
    }

    memset(M, false, sizeof(M));

    M[0][0] = true;
    M[V[0]][0] = true;

    for(int j=1; j<n; j++) {
      for(int i=0; i<=25000; i++) {
	if(M[i][j-1]) {
	  M[i][j] = true;

	  if(i + V[j] <= 25000)
	    M[i+V[j]][j] = true;
	}
      }
    }

    int mn = s;

    for(int i=0; i<= s / 2; i++) {
      if(M[i][n-1]) {
	mn = min(mn, s - i * 2);
      }
    }

    printf("%d\n", mn);
  }

  return 0;
}
