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

  string M[n];
  for(int i=0; i<n; i++)
    cin >> M[i];

  int c = 0, s=0, x=0;
  for(int i=0; i<n; i++) {
    for(int j=0; j<n; j++) {
      if(M[i][j] == '#') {
	s++;
      }
    }
  }

  for(int i=0; i<n; i++) {
    for(int j=0; j<n; j++) {
      if(i > 0 && j > 0 && i < n-1 && j < n-1) {
	if(M[i][j] == '#') {
	  if(M[i][j+1] == '#' && M[i][j-1] == '#' && M[i+1][j] == '#' && M[i-1][j] == '#') {
	    x++;
	    M[i][j] = '.';
	    M[i+1][j] = '.';
	    M[i-1][j] = '.';
	    M[i][j+1] = '.';
	    M[i][j-1] = '.';
	  }
	}
      }
    }
  }
  
  if(x*5 == s)
    printf("YES\n");
  else
    printf("NO\n");

  return 0;
}
