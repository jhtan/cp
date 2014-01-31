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
#include <sstream>

using namespace std;

typedef long long          ll;
typedef vector<int>        vi;
typedef pair<int, int>     ii;
typedef vector<ii>         vii;
typedef set<int>           si;
typedef map<string, int>   msi;

#define INF 1000000000

int main() {
  int M[101][101], tc=0;
  string s;
  getline(cin, s);

  while(s.compare("0 0") != 0) {
    tc++;

    stringstream ss(s);
    set<int> A;
    for(int i=0; i<101; i++) {
      for(int j=0; j<101; j++)
	M[i][j] = INF;
      M[i][i] = 0;
    }

    int a, b, mx = 0;
    while(ss >> a >> b) {
      if(a && b) {
	M[a][b] = 1;
	mx = max(mx, a);
	mx = max(mx, b);
	A.insert(a);
	A.insert(b);
      }
    }

    int n = A.size();
    for(int k=1; k<=mx; k++)
      for(int i=1; i<=mx; i++)
	for(int j=1; j<=mx; j++)
	  M[i][j] = min(M[i][j], M[i][k] + M[k][j]);

    int t = 0;
    for(int i=1; i<=mx; i++)
      for(int j=1; j<=mx; j++)
	if(M[i][j] != INF)
	  t += M[i][j];

    printf("Case %d: average length between pages = %.3f clicks\n", tc, t/(float)(n*(n-1)));
    getline(cin, s);
  }

  return 0;
}
