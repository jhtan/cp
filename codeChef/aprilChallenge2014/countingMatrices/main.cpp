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
  int t, n;
  scanf("%d", &t);

  int vs = 1250*1250+1;
  vector<ll> V(vs, 0);

  for(int i=1; i<vs; i++) {
    for(int j=i; j<vs; j+=i) {
      V[j]++;
    }
  }

  for(int i=1; i<vs; i++)
    V[i] += V[i-1];

  while(t--) {
    scanf("%d", &n);

    ll c = 0;

    for(int i=1; i<=n-1; i++) {
      c += V[i*(n-i) - 1];
    }

    printf("%lld\n", c);
  }
  
  return 0;
}
