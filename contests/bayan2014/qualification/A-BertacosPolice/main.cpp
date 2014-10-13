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
    string s;
    cin >> s;
    for(int i=s.length()-1; i>=0; i--) cout << s[i];
    cout << endl;
  }

  return 0;
}
