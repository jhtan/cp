#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;

typedef long long          ll;
typedef vector<int>        vi;
typedef pair<int, int>     ii;
typedef vector<ii>         vii;
typedef set<int>           si;
typedef map<string, int>   msi;

#define MAX 1000000

int p[MAX], num_sets;
void initSet(int n) {
  for (int i = 0; i < n ; i++) p[i] = i;
  num_sets = n;
}
int findSet(int i) {
  return p[i] == i?i:p[i] = findSet(p[i]);
}
bool isSameSet(int i, int j) {
  return findSet(i) == findSet(j);
}
void unionSet(int i, int j) {
  if(!isSameSet(i, j)) num_sets--;
  p[findSet(i)] = findSet(j);
}

int main() {
  int t;
  scanf("%d", &t);

  while(t--) {
    int n, m;
    scanf("%d %d", &n, &m);

    vector<vi> G(n, vi());
    int a, b;
    for(int i=0; i<m; i++) {
      scanf("%d %d", &a, &b);
      G[a].push_back(b);
      G[b].push_back(a);
    }

    int q;
    scanf("%d", &q);
    int Q[q];
    bool B[n];
    memset(B, false, sizeof(B));
    for(int i=0; i<q; i++) {
      scanf("%d", &Q[i]);
      B[Q[i]] = true;
    }

    initSet(n);
    for(int i=0; i<n; i++) {
      if(!B[i]) {
	for(int j=0; j<G[i].size(); j++) {
	  if(!B[G[i][j]]) {
	    unionSet(i, G[i][j]);
	  }
	}
      }
    }

    vi S;

    int x = q;
    // printf("%d\n", num_sets - q);
    S.push_back(num_sets - x);

    for(int i=q-1; i>=0; i--) {
      if(B[Q[i]]) {
	x--;
	B[Q[i]] = false;
	for(int j=0; j<G[Q[i]].size(); j++) {
	  if(!B[G[Q[i]][j]])
	    unionSet(Q[i], G[Q[i]][j]);
	}

	// printf("%d\n", num_sets - x);
	S.push_back(num_sets - x);
      }
    }

    for(int i=S.size()-1; i>=0; i--)
      printf("%d\n", S[i]);

    if(t) printf("\n");
  }

  return 0;
}
