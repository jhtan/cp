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

  set<string> B;
  B.insert("fernet");
  B.insert("caipirinha");
  B.insert("cerveza");
  B.insert("ron");
  B.insert("vodka");
  B.insert("whisky");
  B.insert("singani");

  int a = 0, b = 0;

  while(t--) {
    int n;
    scanf("%d", &n);

    string s;
    cin >> s;

    if(B.count(s) != 0) {
      a++;
    } else {
      int sw = 0;
      for(int i=0; i<s.length(); i++) {
	if(s[i] >= '0' && s[i] <= '9')
	  sw++;
      }

      if(sw == s.length())
	if(atoi(s) < 18)
	  b++;
    }
    
    if(b >= a)
      printf("%d\n", b);
    else
      
  }

  return 0;
}
