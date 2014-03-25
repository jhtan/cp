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
#define MAX 1000000

int p[MAX], num_sets;
void initSet(int n) {
  for (int i = 0; i < n ; i++) p[i] = i;
  num_sets = n;
}
int findSet(int i) {
  return p[i] == i?i:p[i] = findSet(p[i]);
}
bool isSameSet(int i, int j) {
  return findSet(i) == findSet(j);
}
void unionSet(int i, int j) {
  if(!isSameSet(i, j)) num_sets--;
  p[findSet(i)] = findSet(j);
}

int main() {
  int t;
  scanf("%d", &t);

  int n, b, c;
  scanf("%d", &n);
  initSet(n+1);
  string a;
  int x = 0, y = 0;

  while(cin >> a) {
    if(a == "c") {
      scanf("%d %d", &b, &c);
      unionSet(b, c);
    } else if (a == "q") {
      scanf("%d %d", &b, &c);
      if(isSameSet(b, c)) x++;
      else y++;
    } else {
      n = 0;

      for(int i=0; i<a.length(); i++) {
	n *= 10;
	n += a[i]-'0';
      }

      initSet(n+1);
      printf("%d,%d\n\n", x, y);
      x = 0, y = 0;
    }
  }

  printf("%d,%d\n", x, y);

  return 0;
}
