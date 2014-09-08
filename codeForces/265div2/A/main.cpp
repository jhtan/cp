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
  string s; cin >> s;

  int c = 0;
  for(int i=0; i<s.length(); i++) {
    if(s[i] == '1')
      c++;
    else
      break;
  }

  if(c < s.length()) c++;

  printf("%d\n", c);

  return 0;
}
