#include <bits/stdc++.h>

using namespace std;

typedef long long          ll;
typedef vector<int>        vi;
typedef pair<int, int>     ii;
typedef vector<ii>         vii;
typedef set<int>           si;
typedef map<string, int>   msi;

int main() {
  map<string, int> M;
  int n; scanf("%d", &n);
  string s;
  int m;

  while(n--) {
    cin >> s >> m;
    M[s] = m;
  }

  for(map<string, int>::iterator it = M.begin(); it!=M.end(); it++) {
    cout << (*it).first << " -> " << (*it).second << endl;
  }

  cout << "-------> Verres!" << endl;
  for(map<string, int>::reverse_iterator rit=M.rbegin(); rit!=M.rend(); rit++) {
    cout << (*rit).first << " -> " << (*rit).second << endl;
  }

  vector<pair<int, string> > V;
  for(map<string, int>::iterator it=M.begin(); it!=M.end(); it++) {
    // V.push_back(make_pair((*it).second, (*it).first));
    V.push_back(pair<int, string>((*it).second, (*it).first));
  }

  sort(V.rbegin(), V.rend());

  for(int i=0; i<V.size(); i++) {
    cout << V[i].first << " --> " << V[i].second << endl;
  }

  vector<map<string, int>> V;
  
  return 0;
}
