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

int n;
int M[1000][1000];

int sqr() {
  int s = 0;
  for(int i=0; i<n; i++) {
    int sp = 0;
    for(int j=0; j<n; j++) {
      sp += M[i][j] * M[j][i];
    }
    sp %= 2;
    s += sp;
  }

  s %= 2;

  return s;
}

int main() {
  int q, a, b, c;
  scanf("%d", &n);

  for(int i=0; i<n; i++)
    for(int j=0; j<n; j++)
      scanf("%d", &M[i][j]);

  scanf("%d", &q);
  int sw = sqr();
  for(int i=0; i<q; i++) {
    scanf("%d", &a);

    if(a == 3) {
      printf("%d", sw);
    } else {
      scanf("%d", &b);
      sw++;
      sw %= 2;
    }
  }

  printf("\n");

  return 0;
}
