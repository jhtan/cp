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
  int t, tc=0;
  scanf("%d", &t);

  while(t--) {
    tc++;

    double c, f, x;
    scanf("%lf %lf %lf", &c, &f, &x);

    double cps = 2.0, mn = x / 2.0, s = 0.0;
    while(true) {
      double s2 = s, cps2 = cps + f;
      s2 += c / cps;

      if(s2 + x / cps2 < mn) {
	s = s2;
	mn = s + x / cps2;
	cps = cps2;
      } else {
	s += x / cps;
	break;
      }
    }

    if(s == 0.0)
      s = mn;

    printf("Case #%d: %.7lf\n", tc, s);
  }

  return 0;
}
