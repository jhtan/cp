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
  int n, m, x;
  scanf("%d %d", &n, &m);

  string s;
  cin >> s;

  int V[10][s.length()];
  memset(V, 0, sizeof(V));

  for(int i=0; i<10; i++) {
    V[i][0] = abs(i-s[0]+'0');
    for(int j=1; j<s.length(); j++) {
      V[i][j] = V[i][j-1] + abs(i-s[j]+'0');
    }
  }

  while(m--) {
    scanf("%d", &x);

    printf("%d\n", V[s[x-1]-'0'][x-1]);
  }

  return 0;
}
