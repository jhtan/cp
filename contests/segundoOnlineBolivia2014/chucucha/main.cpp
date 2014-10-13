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
    vector<int> alp(255, 0);

    for(int i=0; i<s.length(); i++) {
      alp[s[i]]++;
    }

    if(alp['a']*2 == alp['u'] && alp['a']*2 == alp['h'] &&
       alp['a']*3 == alp['c'] && alp['a'])
      printf("SI\n");
    else
      printf("NO\n");
  }

  return 0;
}
