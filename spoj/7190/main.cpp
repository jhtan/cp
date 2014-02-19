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

int gcd(int a, int b) {
  if(b == 0)
    return a;
  else
    return gcd(b, a%b);
}

int main() {
  string s;
  cin >> s;

  while(s.compare("*") != 0) {
    vi A, B;
    vector<bool> C(s.length()+1, false);

    for(int i=0; i<s.length(); i++) {
      if(s[i] == 'Y') {
	A.push_back(i+1);
	C[i+1] = true;
      } else
	B.push_back(i+1);
    }

    for(int i=A.size()-1; i>=0; i--) {
      for(int j=i-1; j>=0; j--) {
    	if(C[A[i]] && A[i] % A[j] == 0) {
    	  C[A[j]] = false;
    	}
      }
    }

    ll l = 1;
    int g=1, m=1;
    for(int i=0; i<A.size(); i++) {
      if(C[A[i]]) {
	g = gcd(max((int)l, A[i]), min((int)l, A[i]));
	l = (l*A[i])/g;
      }
    }

    bool sw = false;
    for(int i=0; i<B.size(); i++) {
      if(l % B[i] == 0) {
	sw = true;
	break;
      }
    }

    if(sw)
      printf("-1\n");
    else
      printf("%d\n", l);

    cin >> s;
  }

  return 0;
}
