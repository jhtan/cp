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
  int tc;
  scanf("%d", &tc);

  while(tc--) {
    int n;
    scanf("%d", &n);
    vector<double> X(n), Y(n), R(n);
    
    for(int i=0; i<n; i++)
      scanf("%lf %lf %lf", &X[i], &Y[i], &R[i]);      
   
    // double M[n][n];
    // memset(M, 0, sizeof(M));
    vector<vector<double> > M(n, vector<double>(n, 0.0));
    for(int i=0; i<n; i++) {
      for(int j=0; j<n; j++) {
    	if(i!=j) {
    	  double dist = sqrt(((X[i]-X[j])*(X[i]-X[j])) + ((Y[i]- Y[j])*(Y[i]-Y[j]))) - R[i] - R[j];

    	  if(dist > 0.0) {
    	    M[i][j] = dist;
    	    M[j][i] = dist;
    	  } else {
	    M[i][j] = 0.0;
	  }
    	}
      }	
    }

    for(int k=0; k<n; k++) {
      for(int i=0; i<n; i++) {
	for(int j=0; j<n; j++) {
	  M[i][j] = min(M[i][j], M[i][k] + M[k][j]);
	}
      }
    }

    int m, a, b;
    scanf("%d", &m);
    for(int i=0; i<m; i++) {
      scanf("%d %d", &a, &b);
      printf("%.4lf\n", M[a][b]);
    }
    if(tc>0)
      printf("\n");
  }

  return 0;
}


