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
  int np=10000;
  bool P[10001];
  memset(P, false, sizeof(P));
  P[0] = P[1] = true;
  for(int i=2; i*i<=np; i++) {
    if(!P[i]) {
      for(int j=i+i; j<=np; j+=i)
	P[j] = true;
    }
  }
 
  int x, y;
  scanf("%d %d", &x, &y);

  while(x+y > 0) {
    initSet(y-x+1);

    for(int i=x; i<=y; i++) {
      for(int j=i+1; j<=y; j++) {
	if(!P[i+j])
	  unionSet(i-x, j-x);
      }
    }

    printf("%d\n", num_sets);
    scanf("%d %d", &x, &y);
  }

  return 0;
}
