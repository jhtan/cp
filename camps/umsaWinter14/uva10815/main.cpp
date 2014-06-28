#include <bits/stdc++.h>

using namespace std;

typedef long long          ll;
typedef vector<int>        vi;
typedef pair<int, int>     ii;
typedef vector<ii>         vii;
typedef set<int>           si;
typedef map<string, int>   msi;

int main() {
  char c;
  c = getchar();

  while(c != '\377') {

    if(c >= 'A' && c <= 'Z') {
      c += 32;
    }

    if(c >= 'a' && c <= 'z') {
      cout << c;
    }
    
    c = getchar();
  }

  return 0;
}
