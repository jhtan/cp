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

#define INF 2000000000

int main() {
  int t;
  scanf("%d", &t);

  while(t--) {
    int n, m;
    scanf("%d %d", &n, &m);

    int M[n][m];
    for(int i=0; i<n; i++)
      for(int j=0; j<m; j++)
	scanf("%d", &M[i][j]);

    vi D(n*m, INF);
    priority_queue<ii, vector<ii>, greater<ii> > pq;
    D[0] = M[0][0];
    pq.push(ii(M[0][0], 0));

    while(!pq.empty()) {
      ii front = pq.top(); pq.pop();
      int u = front.second, d = front.first;

      if(d > D[u]) continue;

      if(u/m > 0) {
    	ii v = ii(u-m, M[u/m-1][u%m]);
    	if(D[u] + v.second < D[v.first]) {
    	  D[v.first] = D[u] + v.second;
    	  pq.push(ii(D[v.first], v.first));
    	}
      }

      if(u/m < n-1) {
    	ii v = ii(u+m, M[u/m+1][u%m]);
    	if(D[u] + v.second < D[v.first]) {
    	  D[v.first] = D[u] + v.second;
    	  pq.push(ii(D[v.first], v.first));
    	}
      }
      if(u%m > 0) {
    	ii v = ii(u-1, M[u/m][u%m-1]);
    	if(D[u] + v.second < D[v.first]) {
    	  D[v.first] = D[u] + v.second;
    	  pq.push(ii(D[v.first], v.first));
    	}
      }
      if(u%m < m-1) {
    	ii v = ii(u+1, M[u/m][u%m+1]);
    	if(D[u] + v.second < D[v.first]) {
    	  D[v.first] = D[u] + v.second;
    	  pq.push(ii(D[v.first], v.first));	  
    	}
      }
    }

    // vector<vii> G(n*m, vii());
    // for(int i=0; i<n; i++) {
    //   for(int j=0; j<m; j++) {
    // 	if(i > 0)
    // 	  G[i*m+j].push_back(ii((i-1)*m+j, M[i-1][j]));
    // 	if(i < n-1)
    // 	  G[i*m+j].push_back(ii((i+1)*m+j, M[i+1][j]));
    // 	if(j > 0)
    // 	  G[i*m+j].push_back(ii(i*m+j-1, M[i][j-1]));
    // 	if(j < m-1)
    // 	  G[i*m+j].push_back(ii(i*m+j+1, M[i][j+1]));
    //   }
    // }

    // vi D(n*m, INF);
    // priority_queue<ii, vector<ii>, greater<ii> > pq;
    // D[0] = 0;
    // pq.push(ii(0, 0));

    // while(!pq.empty()) {
    //   ii front = pq.top(); pq.pop();
    //   int u = front.second, d = front.first;

    //   if(d > D[u]) continue;

    //   for(int i=0; i<G[u].size(); i++) {
    // 	ii v = G[u][i];

    // 	if(D[u] + v.second < D[v.first]) {
    // 	  D[v.first] = D[u] + v.second;
    // 	  pq.push(ii(D[v.first], v.first));
    // 	}
    //   }
    // }

    printf("%d\n", D[n*m-1]);
  }

  return 0;
}
