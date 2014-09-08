#include <bits/stdc++.h>

using namespace std;

typedef long long          ll;
typedef vector<int>        vi;
typedef pair<int, int>     ii;
typedef vector<ii>         vii;
typedef set<int>           si;
typedef map<string, int>   msi;

int main() {
  int n; scanf("%d", &n);
  int V[n], x = 0; 
  for(int i=0; i<n; i++) {
    scanf("%d", &V[i]);
    if(V[i]) x++;
  }

  if(x == 0) {
    printf("0\n");
    return 0;
  }

  int c = 0, y = 0;
  bool sw = false;

  for(int i=0; i<n && y < x; i++) {
    if(V[i]) {
      y++;
      c++;
    }
    
    if(i > 0) {
      if(!V[i] && V[i-1])
	c++;
    }
  }

  printf("%d\n", c);

  return 0;
}
