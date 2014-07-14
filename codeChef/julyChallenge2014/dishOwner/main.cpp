#include <bits/stdc++.h>

using namespace std;

typedef long long          ll;
typedef vector<int>        vi;
typedef pair<int, int>     ii;
typedef vector<ii>         vii;
typedef set<int>           si;
typedef map<string, int>   msi;

vi S(10010), O(10010);
vector<bool> B;

int parent(int x) {
  int p = O[x];
  if(B[p])
    p = parent(p);
  return O[x] = p;
}

int main() {
  int t;
  scanf("%d", &t);

  while(t--) {
    int n;
    scanf("%d", &n);

    B.assign(n, false);
    for(int i=0; i<n; i++) {
      scanf("%d", &S[i]);
      O[i] = i;
    }

    int q, a, b, c;
    scanf("%d", &q);
    for(int i=0; i<q; i++) {
      scanf("%d", &c);

      if(!c) {
	scanf("%d %d", &a, &b);
	a--, b--;

	int pa = parent(a);
	int pb = parent(b);
	
	if(pa == pb) {
	  printf("Invalid query!\n");
	} else if(S[pa] > S[pb]) {
	  O[pb] = pa;
	  B[pb] = true;
	} else if(S[pa] < S[pb]) {
	  O[pa] = pb;
	  B[pa] = true;
	}
      } else {
	scanf("%d", &a);
	a--;
	int pa = parent(a);

	printf("%d\n", pa + 1);
      }
    }
  }

  return 0;
}
