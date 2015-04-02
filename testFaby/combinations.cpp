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

  vector<int> V(n);
  for(int i=0; i<n; i++) scanf("%d", &V[i]);

  for(int i=0; i<(1<<n); i++) {
    int s = 0;
    for(int j=0; j<n; j++) {
      if(i & (1<<j)) {
	cout << V[j] << ", ";
	s += V[j];
      }
    }
    cout << " -> " << s;
    cout << endl;
  }

  return 0;
}
