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

  int V[n];
  for(int i=0; i<n; i++)
    scanf("%d", &V[i]);

  int q;
  scanf("%d", &q);

  while(q--) {
    int x;
    scanf("%d", &x);

    int c=0;
    for(int i=0; i<n; i++) {
      for(int j=i; j<n; j++) {
	bool sw = true, sw2 = false;
	for(int k=i; k<=j; k++) {
	  if(V[k] < x) {
	    sw = false;
	    break;
	  } else if(V[k] == x) {
	    sw2 = true;
	  }
	}

	if(sw && sw2)
	  c++;
      }
    }

    printf("%d\n", c);
  }

  return 0;
}
