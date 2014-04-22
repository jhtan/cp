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
  int n;
  scanf("%d", &n);

  while(n) {
    int V[n];
    for(int i=0; i<n; i++)
      scanf("%d", &V[i]);

    int mx = -1, s = 0;
    for(int i=0; i<n; i++) {
      s += V[i];
      mx = max(mx, s);

      if(s < 0)
	s = 0;
    }

    if(mx > 0)
      printf("The maximum winning streak is %d.\n", mx);
    else
      printf("Losing streak.\n");

    scanf("%d", &n);
  }

  return 0;
}
