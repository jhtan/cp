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

int main() {
  int n;
  scanf("%d", &n);

  while(n) {
    int V[n];
    for(int i=0; i<n; i++)
      scanf("%d", &V[i]);

    int a=-1, b=-1, s=0, mx=0, x=-1, y=-1;

    for(int i=0; i<n; i++) {
      s += V[i];
      if(s > 0) {
	if(a == -1)
	  a = i, b = i;
	else
	  b = i;

	if(s >= mx) {
	  mx = s;
	  x = a, y = b;
	}
      } else {
	s = 0;
	a = -1;
      }
    }

    printf("%d %d %d\n", mx, x, y);

    scanf("%d", &n);
  }

  return 0;
}
