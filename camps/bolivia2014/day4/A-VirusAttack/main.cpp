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

// map<ii,int> M;

ll mcm(ll a, ll b) {
  return (a*b) / __gcd(a, b);
  // if(M.count(ii(a,b)) == 0) 
  //   M[ii(a,b)] = (a*b) / __gcd(a, b);

  // return M[ii(a,b)];
}
int V[100];
ll M[1100000];

ll bt(int msk, int p) {
  if(M[msk] != -1)
    return M[msk];

  if(msk == 0)
    M[msk] = 1;
  if(msk == h)
    M[msk] = V[0];

  if(msk & (1<<p))
    M[msk] = mcm(V[p], bt(msk-(msk&(1<<p)), p-1));
  else
    M[msk] = bt(msk-(msk&(1<<p)), p-1);

  return M[msk];
}

int main() {
  int x, n;
  scanf("%d %d", &x, &n);

  while(x && n) {
    for(int i=0; i<n; i++) scanf("%d", &V[i]);

    memset(M, -1, sizeof(M));
    ll s = 0;

    for(int i=1; i<(1<<n); i++) {
      ll m = bt(i, n);
      // for(int j=n-1; j>=0; j--) {
      // 	// if(i & (1<<j)) {
      // 	//   m = mcm(m, V[j]);
      // 	// }
      // }

      // cout << i << " -> " << M[i] << endl;
      if(__builtin_popcount(i) % 2 == 0)
	s -= ((x-1) / m + 1);
      else
	s += ((x-1) / m + 1);
    }
    
    printf("%lld\n", s);
    scanf("%d %d", &x, &n);
  }

  return 0;
}
