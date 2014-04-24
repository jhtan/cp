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
  int d[10] = {0,1,2,3,4,5,6,7,8,9};
  ll s = 0;

  do {
    ll n = 0;
    for(int i=0; i<10; i++) {
      n *= 10;
      n += d[i];
    }

    bool sw = true;
    if((d[1]*100 + d[2]*10 + d[3]) % 2 != 0)
      sw = false;
    if((d[2]*100 + d[3]*10 + d[4]) % 3 != 0)
      sw = false;
    if((d[3]*100 + d[4]*10 + d[5]) % 5 != 0)
      sw = false;
    if((d[4]*100 + d[5]*10 + d[6]) % 7 != 0)
      sw = false;
    if((d[5]*100 + d[6]*10 + d[7]) % 11 != 0)
      sw = false;
    if((d[6]*100 + d[7]*10 + d[8]) % 13 != 0)
      sw = false;
    if((d[7]*100 + d[8]*10 + d[9]) % 17 != 0)
      sw = false;

    if(sw)
      s += n;

  } while (next_permutation(d, d+10));

  printf("%lld\n", s);

  return 0;
}
