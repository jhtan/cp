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

  int alp[255];
  memset(alp, 0, sizeof(alp));

  string s;
  for(int i=0; i<n; i++) {
    cin >> s;
    alp[s[0]]++;
  }

  string sol = "";
  bool sw = false;
  for(int i='a'; i<='z'; i++) {
    if(alp[i] >= 5) {
      sol += i;
      sw = true;
    }
  }

  if(sw)
    cout << sol << endl;
  else
    cout << "PREDAJA" << endl;

  return 0;
}
