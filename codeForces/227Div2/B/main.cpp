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
  int n, m;
  scanf("%d %d", &n, &m);

  int V[n], W[m];
  int mv = 0;

  for(int i=0; i<n; i++)
    scanf("%d", &V[i]);

  for(int i=0; i<m; i++) {
    scanf("%d", &W[i]);
    mv = max(mv, W[i]);
  }

  sort(V, V+n);
  sort(W, W+m);

  int j=0, c=0;
  for(int i=0; i<n; i++) {
    while(j < m && W[j] < V[i]) {
      j++;
    }

    if(j < m && W[j] >= V[i]) {
      c++;
      j++;
    }
  }
  
  //cout << "c = " << c << endl;
  printf("%d\n", n-c);

  return 0;
}
