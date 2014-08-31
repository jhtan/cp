#include <bits/stdc++.h>

using namespace std;

typedef long long          ll;
typedef vector<int>        vi;
typedef pair<int, int>     ii;
typedef vector<ii>         vii;
typedef set<int>           si;
typedef map<string, int>   msi;

int main() {
  int np = 1000 * 1000;
  vector<bool> P(1000001, false);
  P[0] = P[1] = true;
  vi V;
  for(int i=2; i*i<=np; i++) {
    if(!P[i]) {
      for(int j=i+i; j<=np; j+=i)
	P[j] = true;
    }
  }

  int m = 0;
  for(int i=2; i<=np; i++) {
    if(!P[i]) {
      m++;
      V.push_back(i);
      if(m == 600) break;
    }
  }

  cout << "numP = " << V.size() << endl;

  int mx = 0;
  int n, c, s;

  for(int i=0; i<V.size(); i++) {
    s = 0;
    for(int j=i; j<V.size(); j++) {
      s += V[j];
      
      if(!P[s] && s < 1000000) {
	if(j-i > mx) {
	  mx = j-i;
	  n = s;
	}
      }
    }
  }

  cout << "n = " << n << endl;

  return 0;
}
