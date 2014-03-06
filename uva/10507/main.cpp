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

vector<vi> G;

int main() {
  int v, e;
  
  while(scanf("%d %d", &v, &e) != EOF) {
    vector<bool> B(255, false), I(v, false);
    int ni = 0;
    int ix=0;
    map<int, int> M;

    string s;
    cin >> s;

    for(int i=0; i<s.length(); i++) {
      B[s[i]] = true;
      // M[ix] = s[i];
      M[s[i]] = ix;
      I[ix] = true;
      ix++;
      ni++;
    }

    G.assign(26, vi());
    for(int i=0; i<e; i++) {
      
      char a, b;
      // scanf("%s %s", &a, &b);
      cin >> a >> b;
      // cout << "a = " << a << endl << "b = " << b << endl;

      if(!B[a]) {
	B[a] = true;
	// M[ix] = a;
	M[a] = ix;
	ix++;
      } 
      
      if(!B[b]) {
	B[b] = true;
	// M[ix] = b;
	M[b] = ix;
	ix++;
      }
      
      G[M[a]].push_back(M[b]);
      G[M[b]].push_back(M[a]);      
      // cout << M[a] << " -> " << M[b] << endl;
    }
    
    // cout << "ding!" << endl;
    
    int year = 0;

    while(true) {
      vector<int> I2;

      for(int i=0; i<v; i++) {

	if(!I[i]){
	  int c = 0;

	  for(int j=0; j<G[i].size(); j++) {
	  
	    if(I[G[i][j]]) 
	      c++;
	  }
	
	  if (c>=3) {
	    I2.push_back(i);
	    ni++;
	  }
	}

      }
      
      if(!I2.size()) {
	break;
      } else {
	for(int i=0; i<I2.size(); i++) {
	  I[I2[i]] = true;
	}
	year++;
      }
      
    }

    // cout << "ni = " << ni << endl;
    // cout << "year = " << year << endl;
      

    if(ni == v)
      printf("WAKE UP IN, %d, YEARS\n", year);
    else
      printf("THIS BRAIN NEVER WAKES UP\n");



  }

  return 0;
}
