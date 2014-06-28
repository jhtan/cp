#include <bits/stdc++.h>
//#include <set>

using namespace std;

int main() {
  int n;
  scanf("%d", &n); // read n

  set<string> S;c 
  string s;
  for(int i=0; i<n; i++) {
    cin >> s;
    S.insert(s);
  }

  printf("%d\n", S.size());

  set<string>::iterator it;
  for(it=S.begin(); it!=S.end(); it++) {
    cout << *it << endl;
  }

  return 0;
}
