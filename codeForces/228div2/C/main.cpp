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
  int n;
  scanf("%d", &n);

  vector<int> V;
  int n0 = 0, aux;
  for(int i=0; i<n; i++) {
    scanf("%d", &aux);
    V.push_back(aux);
  }

  sort(V.begin(), V.end());
  int c = 0, p=0;
  bool B[n];
  memset(B, false, sizeof(B));
  
  while(p < V.size()) {
    c++;
    int s = 0;
    for(int i=0; i<V.size(); i++) {
      if(!B[i]) {
	if(V[i] >= s) {
	  s += 1;
	  B[i] = true;
	  p++;
	}
      }
    }
  }

  printf("%d\n", c);

  return 0;
}
