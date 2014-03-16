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
  int n, k;
  scanf("%d %d", &n, &k);

  int V[n];
  for(int i=0; i<n; i++)
    scanf("%d", &V[i]);

  int mn = n+1, x = 0;
  bool sw = false;

  for(int i=0; i<n; i++) {
    int c = 0, aux = V[i];
    for(int j=i-1; j>=0; j--) {
      aux -= k;
      if(aux <= 0) {
	sw = true;
	break;
      }

      if(aux != V[j])
	c++;
    }

    if(sw) {
      sw = false;
      continue;
    }

    aux = V[i];
    for(int k=i+1; k<n; k++) {
      aux += k;
      if(aux != V[k])
	c++;
    }

    if(c < mn) {
      mn = c;
      x = i;
    }
  }

  // cout << "x = " << x << endl;
  // cout << "mn = " << mn << endl;
  printf("%d\n", mn);

  int y = V[x] - x*k;

  for(int i=0; i<n; i++) {
    if(V[i] > y) {
      printf("- %d %d\n", i+1, V[i]-y);
    } else if(V[i] < y) {
      printf("+ %d %d\n", i+1, y-V[i]);
    }
    y += k;
  }

  return 0;
}
