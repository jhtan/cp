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
  int n, m, s=0, x;
  scanf("%d %d", &n, &m);

  for(int i=0; i<n; i++) {
    scanf("%d", &x);
    s += x;
  }

  int ans = abs(s) / m;
  if(abs(s) % m > 0)
    ans++;

  printf("%d\n", ans);

  return 0;
}
