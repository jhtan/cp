#include <bits/stdc++.h>

using namespace std;

typedef long long          ll;
typedef vector<int>        vi;
typedef pair<int, int>     ii;
typedef vector<ii>         vii;
typedef set<int>           si;
typedef map<string, int>   msi;

int main() {
  int t;
  scanf("%d", &t);

  while(t--) {
    string s;
    cin >> s;
    vi alp(255, 0);

    for(int i=0; i<s.length(); i++)
      alp[s[i]]++;

    double c = alp['c'] / 3.0;
    double h = alp['h'] / 2.0;
    double u = alp['u'] / 2.0;
    double a = alp['a'] / 1.0;

    if(c == h && h == u && u == a)
      printf("SI\n");
    else
      printf("NO\n");
  }

  return 0;
}
