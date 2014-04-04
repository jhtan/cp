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
  int np = 3000;
  bool P[3001];
  memset(P, false, sizeof(P));
  P[0] = P[1] = true;
  for(int i=2; i*i<=np; i++)
    if(!P[i])
      for(int j=i+i; j<=np; j+=i)
	P[j] = true;

  int t;
  scanf("%d", &t);

  int a, b, c;
  while(t--) {
    scanf("%d %d", &a, &b);

    for(int i=a+b+1; i<=np; i++) {
      if(!P[i]) {
	c = i;
	break;
      }
    }

    printf("%d\n", c-a-b);
  }

  return 0;
}
