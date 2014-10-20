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

  while(getline(cin, s)) {
    if(s.length() == 0) {
      printf("\n");
      continue;
    }

    for(int i=0; i<s.length(); i++) {
      if(s[i] == '!') {
	printf("\n");
      } else {
	int c = 0, k=0;
	for(int j=i; j<s.length(); j++) {
	  k = j;
	  if(s[j] >= '0' && s[j] <= '9')
	    c += s[j]-'0';
	  else
	    break;
	}

	for(int j=0; j<c; j++)
	  if(s[k] == 'b') cout << " ";
	  else cout << s[k];
	i = k;
      }
    }

    cout << endl;
  }

  return 0;
}
