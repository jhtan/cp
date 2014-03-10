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
  int n, m;
  scanf("%d %d", &n, &m);

  vector<bool> B(n+1, false);
  B[n] = true;

  int x, a, b;
  for(int i=0; i<m; i++) {
    scanf("%d", &x);

    if(x == 1) {
      scanf("%d %d", &a, &b);
      B[a] = true;
      B[b] = true;
    } else if(x == 2) {
      scanf("%d", &a);
      B[a] = true;
    }
  }

  int mn=0, mx=0, c=0, sw=false;
  for(int i=1; i<=n; i++) {
    if(B[i]) {
      mn += c / 2 + c % 2;
      mx += c;
      c = 0;
    } else {
      c++;
    }
  }

  if(c > 0) {
    mn += c / 2 + c % 2;
    mx += c;
  }

  printf("%d %d\n", mn, mx);

  return 0;
}
