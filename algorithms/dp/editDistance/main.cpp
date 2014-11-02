#include <bits/stdc++.h>

using namespace std;

int M[1000][1000];

int ed(string s, string t) {
  int m = s.length(), n = t.length();

  if(M[m][n] != -1) return M[m][n];

  if(!m && !n) return M[m][n] = 0;
  if(!m) return M[m][n] = n;
  if(!n) return M[m][n] = m;

  int l = ed(s.substr(0, m - 1), t) + 1;
  int r = ed(s, t.substr(0, n - 1)) + 1;
  int c = ed(s.substr(0, m - 1), t.substr(0, n - 1)) + (s[m - 1] != t[n - 1]);

  return M[m][n] = min(l, min(r, c));
}

int main() {
  string s, t;
  cin >> s >> t;

  memset(M, -1, sizeof(M));
  cout << "Edit Distance = " << ed(s, t) << endl;

  return 0;
}
