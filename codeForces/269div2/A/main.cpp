#include <bits/stdc++.h>

using namespace std;

typedef long long          ll;
typedef vector<int>        vi;
typedef pair<int, int>     ii;
typedef vector<ii>         vii;
typedef set<int>           si;
typedef map<string, int>   msi;

int main() {
  vi V(6);
  for(int i=0; i<6; i++) scanf("%d", &V[i]);
  sort(V.begin(), V.end());

  if(V[0] == V[3]) {
    if(V[4] == V[5]) printf("Elephant\n");
    else printf("Bear\n");
  } else if(V[1] == V[4]) {
    if(V[0] == V[5]) printf("Elephant\n");
    else printf("Bear\n");
  } else if(V[2] == V[5]) {
    if(V[0] == V[1]) printf("Elephant\n");
    else printf("Bear\n");
  } else {
    printf("Alien\n");
  }

  return 0;
}
