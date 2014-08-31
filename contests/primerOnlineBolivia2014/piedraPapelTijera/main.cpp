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
    int n;
    string s;
    cin >> n >> s;

    int a = 0, b = 0;
    for(int i=0; i<s.length(); i+=2) {
      if(s[i] == 'I' && s[i+1] == 'T') a++;
      if(s[i] == 'T' && s[i+1] == 'I') b++;
      if(s[i] == 'T' && s[i+1] == 'A') a++;
      if(s[i] == 'A' && s[i+1] == 'T') b++;
      if(s[i] == 'A' && s[i+1] == 'I') a++;
      if(s[i] == 'I' && s[i+1] == 'A') b++;
    }

    if(a > b) printf("Angela gana\n");
    else if(b > a) printf("Bernardo gana\n");
    else printf("Empate\n");
  }

  return 0;
}
