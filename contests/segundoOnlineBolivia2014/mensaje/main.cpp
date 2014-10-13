#include <bits/stdc++.h>

using namespace std;

typedef long long          ll;
typedef vector<int>        vi;
typedef pair<int, int>     ii;
typedef vector<ii>         vii;
typedef set<int>           si;
typedef map<string, int>   msi;

int main() {
  int t, tc=0; scanf("%d", &t);

  while(t--) {
    tc++;
    int n; string s;
    cin >> n >> s;

    if(n < 8) {
      printf("Caso #%d: %d\n", tc, 0);
      continue;
    }
    
    vector<int> alp(255, 0);
    map<char, char> M;
    M['C'] = 'c';
    M['('] = 'c';
    M['O'] = 'o';
    M['0'] = 'o';
    M['D'] = 'd';
    M['E'] = 'e';
    M['3'] = 'e';
    M['R'] = 'r';
    M['A'] = 'a';
    M['@'] = 'a';

    for(int i=0; i<s.length(); i++) {
      if(M.count(s[i]) > 0) {
	s[i] = M[s[i]];
      }
    }

    int c = 0;
    for(int i=0; i<s.length()-7; i++) {
      if(s.substr(i, 8) == "coderoad")
	c++;
    }

    printf("Caso #%d: %d\n", tc, c);
  }

  return 0;
}
