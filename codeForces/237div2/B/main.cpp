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
  double a, d;
  int n;
  scanf("%lf %lf %d", &a, &d, &n);

  double x = 0.0, y = 0.0, p = 0.0;

  for(int i=0; i<n; i++) {
    p += d;
    p = fmod(p, a*4);

    x = 0.0, y = 0.0;

    if(p >= a) {
      x += a;
      
      if(p >= 2*a) {
	y += a;

	if(p >= 3*a) {
	  x -= a;

	  if(p >= 4*a)
	    y -= a;
	  else
	    y -= p-3*a;
	} else {
	  x -= p-2*a;
	}
      } else {
	y += p-a;
      }
    } else {
      x = p;
    }

    printf("%lf %lf\n", x, y);
  }

  return 0;
}
