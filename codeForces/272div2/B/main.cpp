#include <bits/stdc++.h>

using namespace std;

typedef long long          ll;
typedef vector<int>        vi;
typedef pair<int, int>     ii;
typedef vector<ii>         vii;
typedef set<int>           si;
typedef map<string, int>   msi;

int main() {
  string s, t;
  cin >> s >> t;

  int a = 0;
  for(int i=0; i<s.length(); i++)
    if(s[i] == '+') a++;
    else if(s[i] == '-') a--;

  vi V;
  V.push_back(0);

  for(int i=0; i<t.length(); i++) {
    vi W;
    for(int j=0; j<V.size(); j++) {
      if(t[i] == '+') W.push_back(V[j] + 1);
      else if(t[i] == '-') W.push_back(V[j] - 1);
      else if(t[i] == '?') {
	W.push_back(V[j] + 1);
	W.push_back(V[j] - 1);
      }
    }
    V = W;
  }

  int c = 0;
  for(int i=0; i<V.size(); i++)
    if(V[i] == a) c++;

  double p = (double)c / (double)V.size();
  printf("%.12lf\n", p);

  return 0;
}
