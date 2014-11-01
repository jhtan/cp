#include <bits/stdc++.h>

using namespace std;

int ed(string s, string t) {
  if(!s.length() && !t.length()) return 0;
  if(!s.length()) return t.length();
  if(!t.length()) return s.length();

  int l = ed(s.substr(0, s.length() - 1), t) + 1;
  int r = ed(s, t.substr(0, t.length() - 1)) + 1;
  int c = ed(s.substr(0, s.length() - 1), t.substr(0, t.length() - 1)) + (s[s.length() - 1] != t[t.length() - 1]);

  return min(l, min(r, c));
}

int main() {
  string s, t;
  cin >> s >> t;
  
  cout << "Edit Distance = " << ed(s, t) << endl;

  return 0;
}
