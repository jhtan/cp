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
  int t, tc=0;
  scanf("%d", &t);

  while(t--) {
    tc++;
    int A[4][4], B[4][4];
    int x, y;

    scanf("%d", &x);

    for(int i=0; i<4; i++)
      for(int j=0; j<4; j++)
	scanf("%d", &A[i][j]);

    scanf("%d", &y);

    for(int i=0; i<4; i++)
      for(int j=0; j<4; j++)
	scanf("%d", &B[i][j]);

    vi V(17, 0);

    for(int i=0; i<4; i++) {
      V[A[x-1][i]]++;
      V[B[y-1][i]]++;
    }

    x = y = -1;
    for(int i=1; i<=16; i++) {
      if(V[i] == 2) {
	if(x == -1)
	  x = i;
	else
	  y = i;
      }
    }

    printf("Case #%d: ", tc);
    if(x == -1 && y == -1)
      printf("Volunteer cheated!\n");
    else if(y != -1)
      printf("Bad magician!\n");
    else
      printf("%d\n", x);

  }

  return 0;
}
