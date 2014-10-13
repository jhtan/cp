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
    string s; cin >> s;
    int c = 0;
    for(int i=0; i<s.length(); i++)
      if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
	c++;
    if(c&1) printf("PESAR\n");
    else printf("DOKHTAR\n");
  }

  return 0;
}
