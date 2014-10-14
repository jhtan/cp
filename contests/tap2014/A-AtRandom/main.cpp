#include <bits/stdc++.h>

using namespace std;

typedef long long          ll;
typedef vector<int>        vi;
typedef pair<int, int>     ii;
typedef vector<ii>         vii;
typedef set<int>           si;
typedef map<string, int>   msi;

int main() {
  int t; scanf("%d", &t);

  while(t--) {
    int n; scanf("%d", &n);

    int a, b;
    char c, d;
    cin >> a >> c;

    bool sw = true;
    for(int i=1; i<n; i++) {
      cin >> b >> d;
      if(a == b || c == d) sw = false;
      a = b; c = d;
    }

    if(sw) printf("B\n");
    else printf("M\n");
  }

  return 0;
}
