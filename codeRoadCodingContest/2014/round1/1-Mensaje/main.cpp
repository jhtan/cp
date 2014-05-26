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
  int t;
  scanf("%d", &t);

  map<int, int> M;
  M['c'] = 'C';
  M['('] = 'C';
  M['O'] = 'o';
  M['0'] = 'o';
  M['D'] = 'd';
  M['E'] = 'e';
  M['3'] = 'e';
  M['r'] = 'R';
  M['A'] = 'a';
  M['@'] = 'a';

  int tc = 0;
  while(t--) {
    tc++;
    int n;
    scanf("%d", &n);
    string s;
    cin >> s;

    for(int i=0; i<s.length(); i++) {
      if(M.count(s[i]) > 0)
	s[i] = M[s[i]];
    }

    int c = 0;
    for(int i=0; i<n-7; i++) {
      if(s.substr(i, 8) == "CodeRoad")
	c++;
    }

    printf("Caso #%d: %d\n", tc, c);
  }

  return 0;
}
