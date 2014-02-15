#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
 
using namespace std;
 
int p[100001];
int ns;
void initSet(int n) {
  ns = n;
  for (int i = 0; i < n ; i++) p[i] = i;
}
int findSet(int i) {
  return p[i] == i?i:p[i] = findSet(p[i]);
}
bool isSameSet(int i, int j) {
  return findSet(i) == findSet(j);
}
void unionSet(int i, int j) {
  if(!isSameSet(i, j)) ns--;
  p[findSet(i)] = findSet(j);
}
 
 
int main() {
  int n, m;
  scanf("%d %d", &n, &m);
 
  vector<pair<int, int> > E;
  int a, b;
  for(int i=0; i<m; i++) {
    scanf("%d %d", &a, &b);
    E.push_back(pair<int, int>(a, b));
  }
 
  int q;
  scanf("%d", &q);
  int V[q];
  bool B[m+1]; memset(B, false, sizeof(B));
  for(int i=0; i<q; i++) {
    scanf("%d", &V[i]);
    V[i]--;
    B[V[i]] = true;
  }
 
  initSet(n);
  for(int i=0; i<m; i++) {
    if(!B[i]) {
      unionSet(E[i].first, E[i].second);
      // cout << "union >> " << E[i].first << " - " << E[i].second << endl;
    }
  }
 
  vector<int> S;
  for(int i=q-1; i>=0; i--) {
    S.push_back(ns);
    unionSet(E[V[i]].first, E[V[i]].second);
  }
 
  for(int i=S.size()-1; i>=0; i--) {
    printf("%d", S[i]);
    if(i > 0) printf(" ");
    else printf("\n");
  }
}
