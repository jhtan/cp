#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> vi;
#define pb push_back

string s, t;
vi P;
vi M;

void KMPPreprocess() {
  P.assign(t.size() + 1, -1);
  for(int i=1; i<=t.size(); i++) {
    int pos = P[i-1];
    while(pos != -1 && t[pos] != t[i-1]) pos = P[pos];
    P[i] = pos + 1;
  }
}

void KMPSearch() {
  M.clear();
  for(int sp=0, kp=0; sp<s.size(); sp++) {
    while(kp != -1 && (kp == t.size() || t[kp] != s[sp]))
      kp = P[kp];
    kp++;
    if(kp == t.size()) M.pb(sp + 1 - t.size());
  }
}

int main() {
  cin >> s >> t;

  KMPPreprocess();
  KMPSearch();

  for(int i=0; i<M.size(); i++)
    printf("%d\n", M[i]);

  return 0;
}
