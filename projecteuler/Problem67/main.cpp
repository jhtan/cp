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
  int M[1000][1000], x;
  int a = 0, b = 0;

  while(scanf("%d", &x) != EOF) {
    M[a][b] = x;
    b++;
    if(b > a) {
      a++;
      b = 0;
    }
  }

  int n = a;

  for(int i=1; i<n; i++) {
    for(int j=0; j<=i; j++) {
      if(j == 0)
	M[i][j] += M[i-1][j];
      else if(j == i)
	M[i][j] += M[i-1][j-1];
      else
      	M[i][j] += max(M[i-1][j-1], M[i-1][j]);
    }
  }

  int mx = 0;
  for(int i=0; i<n; i++)
    mx = max(mx, M[n-1][i]);

  printf("%d\n", mx);

  return 0;
}
