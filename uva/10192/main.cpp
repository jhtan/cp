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
  string s, t;
  int tc = 0;
  getline(cin, s);

  while(s.compare("#") != 0) {
    tc++;
    getline(cin, t);

    int M[s.length()+1][t.length()+1];
    memset(M, 0, sizeof(M));

    for(int i=1; i<=s.length(); i++)
      for(int j=1; j<=t.length(); j++)
	if(s[i-1] == t[j-1])
	  M[i][j] = M[i-1][j-1] + 1;
	else
	  M[i][j] = max(M[i][j-1], M[i-1][j]);

    printf("Case #%d: you can visit at most %d cities.\n", tc, M[s.length()][t.length()]);

    getline(cin, s);
  }

  return 0;
}
