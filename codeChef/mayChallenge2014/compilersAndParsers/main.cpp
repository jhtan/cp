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

  while(t--) {
    string s;
    cin >> s;

    stack<char> S;
    int n = 0;

    for(int i=0; i<s.length(); i++) {
      if(S.size() == 0) {
	n = i;
	S.push(s[i]);
      } else {
	if(s[i] == '>' && S.top() == '<')
	  S.pop();
	else
	  S.push(s[i]);
      }
    }

    if(S.size() == 0)
      printf("%d\n", s.length());
    else
      printf("%d\n", n);
  }

  return 0;
}
