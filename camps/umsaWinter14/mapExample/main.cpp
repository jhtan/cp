#include <bits/stdc++.h>
//#include <map>

using namespace std;

int main() {
  int n;
  scanf("%d", &n);

  map<string, int> M;
  vector<string> V;
  string s;
  int x;
  for(int i=0; i<n; i++) {
    cin >> s >> x;
    
    V.push_back(s);

    if(M.count(s) == 0) {
      // M[s] = x;
      M.insert(make_pair(s, x));
    } else {
      M[s] += x;
    }
  }

  for(int i=0; i<V.size(); i++) {
    cout << V[i] << ", ";
  }
  cout << endl;

  map<string, int>::iterator it;
  for(it=M.begin(); it!=M.end(); it++) {
    // cout << (*it).first << " -> " << (*it).second << endl;
    pair<string, int> p = (*it);
    cout << p.first << " => " << p.second << endl;
  }

  return 0;
}
