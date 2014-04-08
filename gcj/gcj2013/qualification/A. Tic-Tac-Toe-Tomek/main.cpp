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
  int t, tc=0;
  scanf("%d", &t);

  while(t--) {
    tc++;
    string M[4];
    vi Ar(4, 0), Ac(4, 0), Br(4, 0), Bc(4, 0);
    int c = 0;
    for(int i=0; i<4; i++) {
      string s;
      cin >> s;
      M[i] = s;
      for(int j=0; j<4; j++) {
	if(s[j] == 'O') {
	  Ar[i]++;
	  Ac[j]++;
	} else if(s[j] == 'X') {
	  Br[i]++;
	  Bc[j]++;
	} else if(s[j] == 'T') {
	  Ar[i]++; Ac[j]++;
	  Br[i]++; Bc[j]++;
	} else {
	  c++;
	}
      }
    }

    bool brk = false;

    for(int i=0; i<4; i++) {
      if(Ar[i] == 4 || Ac[i] == 4) {
	printf("Case #%d: O won\n", tc);
	brk = true;
	break;
      } else if(Br[i] == 4 || Bc[i] == 4) {
	printf("Case #%d: X won\n", tc);
	brk = true;
	break;
      }
    }

    if(brk) continue;

    int d1A=0, d2A=0, d1B=0, d2B=0;
    for(int i=0; i<4; i++) {
      if(M[i][i] == 'O') {
	d1A++;
      } else if(M[i][i] == 'X') {
	d1B++;
      } else if(M[i][i] == 'T') {
	d1A++; d1B++;
      }

      if(M[i][3-i] == 'O') {
	d2A++;
      } else if(M[i][3-i] == 'X') {
	d2B++;
      } else if(M[i][3-i] == 'T') {
	d2A++; d2B++;
      }
    }

    if(d1A == 4 || d2A == 4) {
      printf("Case #%d: O won\n", tc);
      continue;
    }

    if(d1B == 4 || d2B == 4) {
      printf("Case #%d: X won\n", tc);
      continue;
    }

    if(c)
      printf("Case #%d: Game has not completed\n", tc);
    else
      printf("Case #%d: Draw\n", tc);
  }

  return 0;
}
