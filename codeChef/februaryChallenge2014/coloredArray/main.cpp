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
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);

    vector<bool> B(n+1, false);
    vector<int> V(n+1);
    for(int i=1; i<=n; i++)
      scanf("%d", &V[i]);

    int A[n+1][m+1];

    for(int i=1; i<=n; i++) {
      for(int j=1; j<=m; j++) {
	scanf("%d", &A[i][j]);
      }
    }

    multiset<pair<int, int> > S;
    int x;
    for(int i=1; i<=n; i++) {
      for(int j=1; j<=m; j++) {
	scanf("%d", &x);
	x *= -1;
	x += A[i][j];
	x -= A[i][V[i]];

	if(x > 0)
	  S.insert(ii(x, i));
      }
    }

    ll s = 0;
    for(int i=1; i<=n; i++)
      s += A[i][V[i]];

    multiset<pair<int, int> >::reverse_iterator rit;
    for(rit=S.rbegin(); rit!=S.rend(); rit++) {
      if(!k) break;
      
      if(!B[(*rit).second]) {
	B[(*rit).second] = true;
	s += (*rit).first;
	k--;
      }
    }

    cout << s << endl;
  }

  return 0;
}
