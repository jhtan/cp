#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

int main() {
  string s; cin >> s;
  int alp[255];
  memset(alp, 0, sizeof(alp));

  for(int i=0; i<s.length(); i++)
    alp[s[i]]++;

  int n; scanf("%d", &n);
  string t;
  int b[255];

  for(int i=0; i<n; i++) {
    cin >> t;
    bool sw = true;
    memset(b, 0, sizeof(b));

    for(int j=0; j<t.length(); j++)
      b[t[j]]++;

    for(int j='A'; j<='Z'; j++)
      if(alp[j] < b[j])
	sw = false;

    if(sw) printf("SI\n");
    else printf("NO\n");
  }

  return 0;
}
