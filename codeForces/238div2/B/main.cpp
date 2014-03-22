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
  string s;

  scanf("%d", &n);
  cin >> s;
  s += 'R';

  int x = 'L', y = '.', c = 0, a = 0;

  for(int i=0; i<s.length(); i++) {
    if(s[i] == '.') {
      c++;
    } else if(s[i] == 'L') {
      if(x == 'R') {
	a += c%2;
      }
      c = 0;
      x = 'L';
    } else if(s[i] == 'R') {
      if(x == 'L') {
	a += c;
      }
      c = 0;
      x = 'R';
    }
  }

  printf("%d\n", a);

  return 0;
}
