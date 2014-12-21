#include <bits/stdc++.h>

using namespace std;

typedef long long          ll;
typedef vector<int>        vi;
typedef pair<int, string>     is;
typedef set<int>           si;
typedef map<string, int>   msi;

int main() {
  int t, tc=0; scanf("%d", &t);

  while(t--) {
    int n, m;
    scanf("%d %d", &n, &m);

    set<string> S;

    string s;
    for(int i=0; i<n; i++) {
      cin >> s;

      s += '/';
      string t = "";
      for(int j=1; j<s.length(); j++) {
	if(s[j] == '/') {
	  t += "/";
	  S.insert(t);
	} else {
	  t += s[j];
	}
      }
    }

    int c = 0;
    for(int i=0; i<m; i++) {
      cin >> s;

      s += '/';
      string t = "";
      for(int j=1; j<s.length(); j++) {
	if(s[j] == '/') {
	  t += "/";
	  if(S.count(t) == 0) {
	    c++;
	    S.insert(t);
	  }
	} else {
	  t += s[j];
	}
      }
    }

    printf("Case #%d: %d\n", ++tc, c);
  }

  return 0;
}
