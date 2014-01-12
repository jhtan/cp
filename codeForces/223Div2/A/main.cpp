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

  int V[n];
  for(int i=0; i<n; i++)
    scanf("%d", &V[i]);

  int a=0, b=0, i=0, j=n-1;
  bool sw = true;
  while(i <= j) {
    if(sw) {
      if(V[i] >= V[j]) {
	a += V[i];
	i++;
      } else {
	a += V[j];
	j--;
      }
      sw = false;
    } else {
      if(V[i] >= V[j]) {
	b += V[i];
	i++;
      } else {
	b += V[j];
	j--;
      }
      sw = true;
    }
  }

  printf("%d %d\n", a, b);

  return 0;
}
