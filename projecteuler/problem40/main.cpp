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

string toStr(int n) {
  string s = "";
  while(n) {
    s = (char)((n%10)+'0') + s;
    n /= 10;
  }
  
  return s;
}

int main() {
  string s = ".";

  int c = 0;
  while(s.length() <= 1000000) {
    c++;
    s += toStr(c);
  }

  int x = (s[1] - '0') * (s[10] - '0') * (s[100] - '0') * (s[1000] - '0') * (s[10000] - '0') * (s[100000] - '0') * (s[1000000] - '0');

  printf("%d\n", x);

  return 0;
}
