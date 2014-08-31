#include <bits/stdc++.h>

using namespace std;

typedef long long          ll;
typedef vector<int>        vi;
typedef pair<int, int>     ii;
typedef vector<ii>         vii;
typedef set<int>           si;
typedef map<string, int>   msi;

int main() {
  int np = 1000000;
  vector<bool> P(1000001, false);
  P[0] = P[1] = true;
  for(int i=2; i*i<=np; i++) {
    if(!P[i])
      for(int j=i+i; j<=np; j+=i)
	P[j] = true;
  }

  int c = 0;
  for(int i=1; i<=np; i++) {
    if(!P[i]) {
      bool sw = true;
      int x = i;
      vi V;

      do{
	x = x / 10 + ((x % 10) * pow(10, (int)log10(x)));
	V.push_back(x);
	if(P[x]) {
	  sw = false;
	  break;
	}
      } while(x != i);

      if(sw) c++;
    }
  }

  printf("%d\n", c);

  return 0;
}
