#include <vector>
#include <set>
#include <algorithm>
#include <iostream>
#include <cstdio>

using namespace std;

typedef vector<int>        vi;
typedef pair<int, int>     ii;

int main() {
  int s, n;
  scanf("%d %d", &s, &n);

  while(s && n) {
    vi V(n), W(n);
    for(int i=0; i<n; i++)
      scanf("%d %d", &V[i], &W[i]);

    set<ii> S;
    S.insert(ii(0, 0));

    int mx = 0;

    for(int i=0; i<n; i++) {
      vector<ii> T;
      set<ii>::iterator it;
      for(it=S.begin(); it!=S.end(); it++) {
	int a = (*it).first + V[i];
	int b = (*it).second + W[i];

	if(b <= s) {
	  if(S.count(ii(a, b)) == 0) {
	    mx = max(mx, a);
	    T.push_back(ii(a, b));
	  }
	}
      }

      for(int j=0; j<T.size(); j++)
	S.insert(ii(T[j].first, T[j].second));
    }

    printf("%d\n", mx);
    scanf("%d %d", &s, &n);
  }

  return 0;
}
