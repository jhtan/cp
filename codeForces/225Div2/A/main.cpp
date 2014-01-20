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

  if(n%2 == 0) {
    printf("%d\n", (n/2)*n);
  } else {
    printf("%d\n", (n/2)*n+(n/2+1));
  }

  for(int i=0; i<n; i++) {
    for(int j=0; j<n; j++) {
      if(i%2 == 0) {
	if(j%2 == 0) {
	  printf("C");
	} else {
	  printf(".");
	}
      } else {
	if(j%2 == 0) {
	  printf(".");
	} else {
	  printf("C");
	}
      }
    }
    printf("\n");
  }

  return 0;
}
