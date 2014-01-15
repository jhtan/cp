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

class UnionFind {
private: vi p, rank;
public:
  UnionFind(int n) { 
    rank.assign(n, 0); 
    p.assign(n,0); 
    for(int i=0; i<n; i++) 
      p[i] = i;
  }
  
  int findset(int i) {
    return (p[i] == i) ? i: (p[i] = findset(p[i]));
  }
  
  bool isSameSet(int i, int j) {
    return findset(i) == findset(j);
  }
  
  void unionSet(int i, int j) {
    if(!isSameSet(i,j)) {
      int x= findset(i), y=findset(j);
      if(rank[x] > rank[y]) 
	p[y] = x;
      else {
	p[x] = y;

	if(rank[x] == rank[y]) 
	  rank[y]++;
	  
      }
    }
  }
};

int main() {
  int t;
  scanf("%d", &t);
  
  while(t--) {
    int n, m;
    scanf("%d %d", &n, &m);
    UnionFind V(n+1);
  
    for(int i=0; i<m; i++) {
      int a, b;
      scanf("%d %d", &a, &b);
      V.unionSet(a, b);
    }
    
    vi C(n+1, 0);
    
    for(int i=1; i<n+1; i++)
      C[V.findset(i)]++;
    
    int mv=0;
    for(int i=1; i<n+1; i++)
      mv = max(mv, C[i]);
      // if(C[i] > max) max = C[i];
    
    printf("%d\n", mv);
  }

  return 0;
}
