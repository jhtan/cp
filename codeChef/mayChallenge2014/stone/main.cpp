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

  ll V[n];
  for(int i=0; i<n; i++)
    scanf("%lld", &V[i]);

  if(k == 0) {
    for(int i=0; i<n; i++)
      if(i < n-1)
	printf("%lld ", V[i]);
      else
	printf("%lld\n", V[i]);
    return 0;
  }

  if(k % 2 == 0)
    k = 2;
  else
    k = 1;

  for(int i=0; i<k; i++) {
    ll mx = *max_element(V, V+n);
    for(int j=0; j<n; j++)
      V[j] = mx - V[j];
  }

  for(int i=0; i<n; i++)
    if(i < n-1)
      printf("%lld ", V[i]);
    else
      printf("%lld\n", V[i]);

  return 0;
}
