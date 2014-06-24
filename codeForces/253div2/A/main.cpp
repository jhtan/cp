#include <bits/stdc++.h>

using namespace std;

typedef long long          ll;
typedef vector<int>        vi;
typedef pair<int, int>     ii;
typedef vector<ii>         vii;
typedef set<int>           si;
typedef map<string, int>   msi;

int main() {
  string s;
  getline(cin , s);

  vi alp(255, 0);
  int c = 0;

  for(int i=0; i<s.length(); i++) {
    if(s[i] >= 'a' && s[i] <= 'z') {
      if(alp[s[i]] == 0) {
	c++;
	alp[s[i]] = 1;
      }
    }
  }

  printf("%d\n", c);

  return 0;
}
