#include <bits/stdc++.h>

using namespace std;

typedef long long          ll;
typedef vector<int>        vi;
typedef pair<int, int>     ii;
typedef vector<ii>         vii;
typedef set<int>           si;
typedef map<string, int>   msi;

int main() {
  int n , m;
  scanf("%d %d", &n, &m);

  map<string, string> M;
  string a, b;
  for(int i=0; i<m; i++) {
    cin >> a >> b;
    M[a] = b;
  }

  string s;
  for(int i=0; i<n; i++) {
    cin >> s;

    if(M[s].length() < s.length())
      cout << M[s];
    else
      cout << s;

    if(i < n-1) cout << " ";
    else cout << endl;
  }

  return 0;
}
