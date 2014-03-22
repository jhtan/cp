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
  int n;
  scanf("%d", &n);

  vi V(n, 0);
  for(int i=0; i<n; i++)
    scanf("%d", &V[i]);

  sort(V.begin(), V.end());

  for(int i=0; i<n; i++) {
    printf("%d", V[i]);

    if(i < n-1)
      printf(" ");
    else
      printf("\n");
  }

  return 0;
}
