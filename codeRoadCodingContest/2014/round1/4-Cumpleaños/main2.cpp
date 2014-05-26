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
    int n, s;
    scanf("%d %d", &n, &s);

    int x;
    multiset<int> S;
    for(int i=0; i<n; i++) {
      scanf("%d", &x);
      S.insert(x);
    }

    int c = 0, w=0;
    multiset<int>::iterator it;
    for(it=S.begin(); it!=S.end(); it++) {
      if(w + (*it) <= s) {
	w += (*it);
	c++;
      }
    }

    printf("%d\n", c);
  }

  return 0;
}
