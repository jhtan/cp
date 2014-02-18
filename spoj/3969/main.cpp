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
  int t;
  scanf("%d", &t);

  while(t--) {
    int n;
    scanf("%d", &n);

    int x, s=-1;
    bool sw = true;
    for(int i=0; i<n; i++) {
      scanf("%d", &x);

      if(x != 1)
	sw = false;

      if(s == -1) {
	s = x;
      } else {
	s ^= x;
      }
    }

    if(sw)
      if(s == 0)
	printf("John\n");
      else
	printf("Brother\n");
    else
      if(s == 0)
	printf("Brother\n");
      else
	printf("John\n");
  }

  return 0;
}
