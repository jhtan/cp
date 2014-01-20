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

//#define for(i, a, b) \
//  for(int i = int(a); i <= int(b); i++)
//#define Rvi(c, it) \
//  for(vi::iterator it = (c).begin(); it != (c).end(); it++)
//#define Rvii(c, it) \
//  for(vii::iterator it = (c).begin(); it != (c).end(); it++)
//#define Rmsi(c, it) \
//  for(msi::iterator it = (c).begin(); it != (c).end(); it++)

int main() {
  int n, m, x;
  scanf("%d %d %d", &n, &m, &x);
  
  int V[n][m];
  for(int i=0; i<n; i++) {
    for(int j=0; j<m; j++) {
      scanf("%d", &V[i][j]);
    }
  }

  set<ii> S;
  int aux;

  for(int i=0; i<m; i++) {
    for(int j=i+1; j<m; j++) {
      for(int k=0; k<n; k++) {
	if(x) {
	  if(V[k][i] < V[k][j]) {
	    if(S.count(ii(i+1, j+1)) == 0) {
	      S.insert(ii(j+1, i+1));
	    }
	    swap(V[k][i], V[k][j]);
	  }
	} else {
	  if(V[k][i] > V[k][j]) {
	    if(S.count(ii(i+1, j+1)) == 0) {
	      S.insert(ii(i+1, j+1));
	    }
	    swap(V[k][i], V[k][j]);
	  }
	}
      }
    }
  }

  printf("%d\n", S.size());
  set<ii>::iterator it;
  for(it=S.begin(); it!=S.end(); it++) {
    printf("%d %d\n", it->first, it->second);
  }

  return 0;
}
