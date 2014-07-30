#include <bits/stdc++.h>

using namespace std;

typedef long long          ll;
typedef vector<int>        vi;
typedef pair<int, int>     ii;
typedef vector<ii>         vii;
typedef set<int>           si;
typedef map<string, int>   msi;

int main() {
  string s; cin >> s;
  string t = "hello";
  int j = 0;

  for(int i=0; i<s.length() && j < 5; i++)
    if(s[i] == t[j])
      j++;

  if(j == 5) printf("YES\n");
  else printf("NO\n");

  return 0;
}
