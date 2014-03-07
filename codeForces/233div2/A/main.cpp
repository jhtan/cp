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
  int n, p, k;
  scanf("%d %d %d", &n, &p, &k);

  if(p-k > 1)
    printf("<< ");

  for(int i=p-k; i<p; i++) {
    if(i > 0)
      printf("%d ", i);
  }

  printf("(%d) ", p);

  for(int i=p+1; i<=n && i <= p+k; i++) {
    printf("%d", i);
    if(i != n && i != p+k)
      printf(" ");
  }

  if(p+k < n)
    printf(" >>");

  printf("\n");

  return 0;
}
