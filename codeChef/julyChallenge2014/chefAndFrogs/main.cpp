#include <bits/stdc++.h>

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
  int n, k, q;
  scanf("%d %d %d", &n, &k, &q);

  vii V;
  int a, b;
  for(int i=1; i<=n; i++) {
    scanf("%d", &a);
    V.push_back(ii(a, i));
  }

  sort(V.begin(), V.end());
  initSet(n+1);
  for(int i=0; i<n-1; i++) {
    if(V[i+1].first - V[i].first <= k)
      unionSet(V[i+1].second, V[i].second);
  }

  for(int i=0; i<q; i++) {
    scanf("%d %d", &a, &b);
    if(isSameSet(a, b))
      printf("Yes\n");
    else
      printf("No\n");
  }

  return 0;
}
