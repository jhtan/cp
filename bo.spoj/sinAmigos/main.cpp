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

  vi V(10001, 0);

  for(int i=1; i<=10000; i++) {
    for(int j=i+i; j<=10000; j+=i)
      V[j] += i;
  }

  while(scanf("%d", &n) != EOF) {
    if(n == V[V[n]])
      printf("%d\n", V[n]);
    else
      printf("-1\n");
  }

  return 0;
}
