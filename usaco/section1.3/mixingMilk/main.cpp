/*
ID: jh.tan.1
PROG: milk
LANG: C++
*/

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
#include <fstream>

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
  ofstream fout("milk.out");
  ifstream fin("milk.in");

  int n, m;
  // scanf("%d %d", &n, &m);
  fin >> n >> m;

  vii V;
  int a, b;
  for(int i=0; i<m; i++) {
    // scanf("%d %d", &a, &b);
    fin >> a >> b;
    V.push_back(ii(a, b));
  }

  sort(V.begin(), V.end());

  int c = 0;
  for(int i=0; i<V.size() && n; i++) {
    if(V[i].second <= n) {
      n -= V[i].second;
      c += V[i].first * V[i].second;
    } else {
      c += n * V[i].first;
      n = 0;
    }
  }

  // printf("%d\n", c);
  fout << c << endl;

  return 0;
}
