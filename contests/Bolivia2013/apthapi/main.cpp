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

int main() {
  int n;
  scanf("%d", &n);

  while(n) {
    vii V;
    set<int> S;
    
    for(int i=0; i<n; i++) {
      int a = 0, b = 0;
      string s, t;
      cin >> s >> t;

      for(int j=0; j<s.length(); j++) {
	if(s[j] == 'a') a |= 16;
	if(s[j] == 'e') a |= 8;
	if(s[j] == 'i') a |= 4;
	if(s[j] == 'o') a |= 2;
	if(s[j] == 'u') a |= 1;
      }

      for(int j=0; j<t.length(); j++) {
	if(t[j] == 'a') b |= 16;
	if(t[j] == 'e') b |= 8;
	if(t[j] == 'i') b |= 4;
	if(t[j] == 'o') b |= 2;
	if(t[j] == 'u') b |= 1;
      }

      V.push_back(ii(a, b));
    }

    bool sw = false;
    S.insert(V[0].first);
    S.insert(V[0].second);
    for(int i=1; i<V.size(); i++) {
      set<int> aux;
      set<int>::iterator it;
      for(it=S.begin(); it!=S.end(); it++) {
	aux.insert(*it | V[i].first);
	aux.insert(*it | V[i].second);

	if((*it | V[i].first) == 31 || (*it | V[i].second) == 31) {
	  sw = true;
	  break;
	}
      }

      S = aux;
      if(sw) break;
    }

    if(sw)
      printf("EXISTE\n");
    else
      printf("NO EXISTE\n");

    scanf("%d", &n);
  }

  return 0;
}
