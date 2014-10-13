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

  while(cin >> s) {
    if(s == "*") break;

    vi A, V; V.push_back(s[0]-'0'); A.push_back(s[0]-'0'); 
    vector<bool> B; 
    for(int i=1; i<s.length(); i+=2) {
      A.push_back(s[i+1]-'0'); 

      if(s[i] == '+') {
	V.push_back(s[i+1]-'0'+V[V.size()-1]);
	B.push_back(false);
      } else if(s[i] == '-') {
	V.push_back(((s[i+1]-'0')*-1)+V[V.size()-1]);
	B.push_back(true);
      }
    }

    // for(int i=0; i<V.size(); i++) cout << V[i] << " ";
    // cout << endl;

    int s = V[V.size()-1];
    bool sw = false;
    for(int i=0; i<V.size()-1 && !sw; i++) {
      if(B[i]) {
	if(V[i] == s-V[i]+A[i+1]*2) sw = true;
      }	else {
	if(V[i] == s-V[i]) sw = true;
      }
    }

    if(sw) printf("Possible\n");
    else printf("Impossibru\n");
  }

  return 0;
}
