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

  char a, b;
  bool sw = true;
  
  string s;
  for(int i=0; i<n; i++) {
    cin >> s;

    if(i == 0) {
      a = s[0];
      b = s[1];
    } 

    if(a == b)
      sw = false;

    for(int j=0; j<n; j++) {
      if(i == j || i == (n-j-1)) {
	if(s[j] != a) {
	  sw = false;
	  break;
	}
      } else {
	if(s[j] != b) {
	  sw = false;
	  break;
	}
      }
    }
  }

  if(sw)
    printf("YES\n");
  else
    printf("NO\n");

  return 0;
}
