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
  int t = 10;
  while(t--) {
    string s;
    cin >> s;
    s += ".";

    int c = 1;
    for(int i=1; i<s.length(); i++) {
      if(s[i] == s[i-1]) {
	c++;
      } else {
	printf("%d%c", c, s[i-1]);
	c = 1;
      }
    }
    printf("\n");
  }

  t = 10;
  while(t--) {
    string s;
    cin >> s;

    for(int i=0; i<s.length(); i+=2) {
      for(int j=0; j<s[i]-'0'; j++)
	printf("%c", s[i+1]);	
    }
    printf("\n");
  }

  return 0;
}
