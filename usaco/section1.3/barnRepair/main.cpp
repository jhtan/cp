/*
ID: jh.tan.1
PROG: barn1
LANG: C++
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long          ll;
typedef vector<int>        vi;
typedef pair<int, int>     ii;
typedef vector<ii>         vii;
typedef set<int>           si;
typedef map<string, int>   msi;

int main() {
  ofstream fout("barn1.out");
  ifstream fin("barn1.in");

  int t, s, n;
  // scanf("%d %d %d", &t, &s, &n);
  fin >> t >> s >> n;
  vi V(n);
  // for(int i=0; i<n; i++) scanf("%d", &V[i]);
  for(int i=0; i<n; i++) fin >> V[i];

  sort(V.begin(), V.end());
  vi W;
  for(int i=0; i<n-1; i++) {
    if(V[i+1]-V[i]-1)
      W.push_back(V[i+1]-V[i]-1);
  }

  sort(W.begin(), W.end());

  int a = V[n-1] - V[0] + 1;
  int j = W.size()-1;
  for(int i=1; i<t; i++) {
    a -= W[j];
    j--;
    if(j < 0)
      break;
  }

  // printf("%d\n", a);
  fout << a << endl;

  return 0;
}
