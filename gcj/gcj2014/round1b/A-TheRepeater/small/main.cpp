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
    int n;
    scanf("%d", &n);

    vector<string> V(n), W(n);
    for(int i=0; i<n; i++) {
      cin >> V[i];
      W[i] = "";
      W[i] += V[i][0];
      for(int j=1; j<V[i].length(); j++) {
	if(V[i][j-1] != V[i][j])
	  W[i] += V[i][j];
      }
    }

    bool sw = true;
    for(int i=1; i<W.size() && sw; i++) {
      if(W[i] != W[i-1])
	sw = false;
    }

    if(sw) {
      int c = 0;

      for(int i=0; i<n; i++) {
	int asdf = V[i].length() - W[0].length();
	// cout << V[i] << endl;
	// cout << W[0] << endl;
	// cout << "asdf = " << asdf << endl;
	c += abs(asdf);
      }
      // cout << "c = " << c << endl;

      for(int i=0; i<n; i++) {
	int pc = 0;

	for(int j=0; j<n; j++) {
	  if(i != j) {
	    vector<int> X, Y;

	    X.push_back(1);
	    for(int k=1; k<V[i].length(); k++) {
	      if(V[i][k] == V[i][k-1])
		X[X.size()-1]++;
	      else
		X.push_back(1);
	    }

	    Y.push_back(1);
	    for(int k=1; k<V[j].length(); k++) {
	      if(V[j][k] == V[j][k-1])
		Y[Y.size()-1]++;
	      else
		Y.push_back(1);
	    }

	    for(int k=0; k<X.size(); k++) {
	      pc += abs(X[k] - Y[k]);
	    }
	  }
	}

	c = min(c, pc);
      }

      printf("Case #%d: %d\n", tc, c);
    } else {
      printf("Case #%d: Fegla Won\n", tc);
    }
  }

  return 0;
}
