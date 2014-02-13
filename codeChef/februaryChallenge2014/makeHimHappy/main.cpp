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
  int n, k;
  scanf("%d %d", &n, &k);

  int V[1000001], x;
  memset(V, 0, sizeof(V));
  for(int i=1; i<=n; i++) {
    scanf("%d", &x);

    if(!V[x])
      V[x] = min(i, n-i+1);
    else
      V[x] = min(V[x], min(i, n-i+1));
  }

  int mn = 1000000000;
  for(int i=k-1; i>=1; i--) {
    if(V[i] && V[k-i] && i != k-i) {
      mn = min(mn, max(V[i],V[k-i]));
    }
  }

  if(mn == 1000000000)
    printf("-1\n");
  else
    printf("%d\n", mn);

  return 0;
}
