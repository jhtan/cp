#include <bits/stdc++.h>

using namespace std;

typedef long long          ll;
typedef vector<int>        vi;
typedef pair<int, int>     ii;
typedef vector<ii>         vii;
typedef set<int>           si;
typedef map<string, int>   msi;

int main() {
  char x;
  cin >> x;

  string a = "qwertyuiop";
  string b = "asdfghjkl;";
  string c = "zxcvbnm,./";

  string s;
  cin >> s;

  map<char, char> L, R;
  for(int i=1; i<a.length(); i++)
    R[a[i]] = a[i-1];
  for(int i=1; i<b.length(); i++)
    R[b[i]] = b[i-1];
  for(int i=1; i<c.length(); i++)
    R[c[i]] = c[i-1];

  for(int i=0; i<a.length()-1; i++)
    L[a[i]] = a[i+1];
  for(int i=0; i<b.length()-1; i++)
    L[b[i]] = b[i+1];
  for(int i=0; i<c.length()-1; i++)
    L[c[i]] = c[i+1];

  if(x == 'R') {
    for(int i=0; i<s.length(); i++)
      cout << R[s[i]];
  } else if (x == 'L') {
    for(int i=0; i<s.length(); i++)
      cout << L[s[i]];
  }

  cout << endl;

  return 0;
}
