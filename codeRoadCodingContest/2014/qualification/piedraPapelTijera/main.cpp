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
    int a = 0, b = 0, n;
    scanf("%d", &n);

    string s;
    cin >> s;

    for(int i=0; i<s.length(); i+=2) {
      if(s[i] == 'I' && s[i+1] == 'A')
	a++;
      if(s[i] == 'A' && s[i+1] == 'I')
	b++;

      if(s[i] == 'A' && s[i+1] == 'T')
	a++;
      if(s[i] == 'T' && s[i+1] == 'A')
	b++;

      if(s[i] == 'T' && s[i+1] == 'I')
	a++;
      if(s[i] == 'I' && s[i+1] == 'T')
	b++;
    }

    if(a == b)
      printf("Empate\n");
    else if(a > b)
      printf("Bernardo gana\n");
    else
      printf("Angela gana\n");
  }

  return 0;
}
