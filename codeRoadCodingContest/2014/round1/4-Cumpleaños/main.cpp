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

    vi V(n);
    for(int i=0; i<n; i++) scanf("%d", &V[i]);

    int mx = 0;
    map<int, int> M;
    M[0] = 0;
    for(int i=0; i<n; i++) {
      vii W;
      map<int, int>::iterator it;
      for(it=M.begin(); it!=M.end(); it++) {
	int w = (*it).first + V[i];
	int c = (*it).second + 1;

	if(M.count(w) == 0) {
	  if(w <= s) {
	    mx = max(mx, c);
	    W.push_back(ii(w, c));
	  }
	} else {
	  if(M[w] < c) {
	    mx = max(mx, c);
	    // M[w] = c;
	    W.push_back(ii(w, c));
	  }
	}

	// if(S.count(ii(w, c)) == 0 && w <= s) {
	//   mx = max(mx, c);
	//   W.push_back(ii(w, c));
	// }
      }

      for(int j=0; j<W.size(); j++) {
	  M[W[j].first] = W[j].second;
      }
    }

    printf("%d\n", mx);
  }

  return 0;
}
