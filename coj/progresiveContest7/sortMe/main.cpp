#include <bits/stdc++.h>

using namespace std;

typedef long long          ll;
typedef vector<int>        vi;
typedef pair<int, int>     ii;
typedef vector<ii>         vii;
typedef set<int>           si;
typedef map<string, int>   msi;

int main() {
  int n, tc=0;

  scanf("%d", &n);
  while(n) {
    string b;
    cin >> b;
    int a[255];
    for(int i=0; i<b.size(); i++) {
      a[b[i]] = 'A' + i;
    }

    string s, t;
    multimap<string, string> M;
    for(int i=0; i<n; i++) {
      cin >> s;
      t = "";
      for(int j=0; j<s.length(); j++)
	t += a[s[j]];
      M.insert(make_pair(t, s));
    }

    printf("year %d\n", ++tc);

    multimap<string, string>::iterator it;
    for(it=M.begin(); it!=M.end(); it++)
      cout << (*it).second << endl;

    scanf("%d", &n);
  }

  return 0;
}
