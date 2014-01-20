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
  cin >> s >> t;

  string a = "", b = "";

  bool sw = false;
  for(int i=0; i<s.length(); i++) {
    if(s[i] == '|') {
      sw = true;
      continue;
    }

    if(sw) {
      b += s[i];
    } else {
      a += s[i];
    }
  }

  int it = 0;
  while(a.length() != b.length() && it < t.length()) {
    if(a.length() < b.length()) {
      a += t[it];
      it++;
    } else {
      b += t[it];
      it++;
    }
  }

  // cout << "a = " << a << endl;
  // cout << "b = " << b << endl;

  for(int i=it; i<t.length(); i++) {
    if(i-it < (t.length()-it)/2) {
      a += t[i];
    } else {
      b += t[i];
    }
  }

  // cout << "a = " << a << endl;
  // cout << "b = " << b << endl;

  if(a.length() == b.length()) {
    cout << a << "|" << b << endl;
  } else {
    cout << "Impossible" << endl;
  }

  return 0;
}
