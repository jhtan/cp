#include <bits/stdc++.h>

using namespace std;

typedef long long          ll;
typedef vector<int>        vi;
typedef pair<int, int>     ii;
typedef vector<ii>         vii;
typedef set<int>           si;
typedef map<string, int>   msi;

int main() {
  int n, k, x; scanf("%d %d", &n, &k);
  vii V(n); 
  for(int i=0; i<n; i++) {
    scanf("%d", &x);
    V[i] = ii(x, i+1);
  }

  vii S;

  int m=0;
  while(k--) {
    sort(V.begin(), V.end());
    if(V[n-1].first > V[0].first+1) {
      m++;
      V[n-1].first--;
      V[0].first++;
      S.push_back(ii(V[n-1].second, V[0].second));
    } else {
      break;
    }
  }
  sort(V.begin(), V.end());

  printf("%d %d\n", V[n-1].first-V[0].first, m);
  for(int i=0; i<S.size(); i++)
    printf("%d %d\n", S[i].first, S[i].second);

  return 0;
}
