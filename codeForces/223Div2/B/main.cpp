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

  int V[100001];
  memset(V, 0, sizeof(V));

  int x;
  for(int i=0; i<n; i++) {
    scanf("%d", &x);
    V[x]++;
  }

  int s = 0;
  bool as = false;
  for(int i=1; i<=100000; i++) {
    if(V[i] == 1) {
      s++;
      as = false;
    } else if(V[i] >= 2) {
      s+=2;
      as = true;
    }
  }

  if(as)
    s--;

  printf("%d\n", s);

  bool sw = true;
  for(int i=1; i<=100000; i++) {
    if(V[i]) {
      if(sw) {
	sw = false;
      } else {
	printf(" ");
      }
      printf("%d", i);
    }
  }

  for(int i=100000; i>=1; i--) {
    if(V[i] >= 2) {
      if(as) {
	as = false;
      } else {
	printf(" %d", i);
      }
    }
  }
  
  printf("\n");

  return 0;
}
