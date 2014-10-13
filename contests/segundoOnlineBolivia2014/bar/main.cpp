#include <bits/stdc++.h>

using namespace std;

typedef long long          ll;
typedef vector<int>        vi;
typedef pair<int, int>     ii;
typedef vector<ii>         vii;
typedef set<int>           si;
typedef map<string, int>   msi;

int main() {
  int t; scanf("%d", &t);

  while(t--) {
    int n; scanf("%d", &n);
    int x=0, y=0, b=0;
    
    set<string> S;
    S.insert("fernet");
    S.insert("caipirinha");
    S.insert("cerveza");
    S.insert("ron");
    S.insert("vodka");
    S.insert("whisky");
    S.insert("singani");

    string s;
    for(int i=0; i<n; i++) {
      cin >> s;

      if(s[0] >= '0' && s[0] <= '9') {
	if(s.length()>2 || atoi(s.c_str()) >= 18) x++;
	else y++;
      } else {
	if(S.count(s) > 0)
	  b++;
      }
    }

    printf("%d\n", min(b, y));
  }

  return 0;
}
