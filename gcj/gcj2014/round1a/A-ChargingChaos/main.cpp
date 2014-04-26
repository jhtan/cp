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
  int t, tc=0;
  scanf("%d", &t);

  while(t--) {
    tc++;
    int n, l;
    scanf("%d %d", &n, &l);

    vector<string> A(n), B(n);
    for(int i=0; i<n; i++)
      cin >> A[i];
    for(int i=0; i<n; i++)
      cin >> B[i];

    int c = l+1;

    for(int i=0; i<(1<<l); i++) {
      map<string, int> M;
      int pc = 0;
      for(int j=0; j<A.size(); j++) {
	string ax = A[j];
	for(int k=0; k<l; k++) {
	  if(i & (1<<k)) {
	    pc++;
	    if(ax[k] == '0')
	      ax[k] = '1';
	    else
	      ax[k] = '0';
	  }
	}

	if(M.count(ax) > 0)
	  M[ax]++;
	else
	  M[ax] = 1;
      }

      pc /= A.size();
      bool sw = true;

      // map<string, int>::iterator it;
      // for(it=M.begin(); it!=M.end(); it++)
      // 	cout << (*it).first << " -> " << (*it).second << endl;
      // cout << "----" << endl;

      for(int i=0; i<B.size() && sw; i++) {
	if(M[B[i]])
	  M[B[i]]--;
	else
	  sw = false;
      }

      if(sw)
	c = min(c, pc);
    }

    if(c == l+1)
      printf("Case #%d: NOT POSSIBLE\n", tc);
    else
      printf("Case #%d: %d\n", tc, c);
  }

  return 0;
}
