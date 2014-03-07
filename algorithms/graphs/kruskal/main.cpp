#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> ii;
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
  int v, e;
  scanf("%d %d", &v, &e);

  vector<pair<int, ii> > K;

  int a, b, c;
  for(int i=0; i<e; i++) {
    scanf("%d %d %d", &a, &b, &c);
    K.push_back(make_pair(c, ii(a, b)));
  }

  sort(K.begin(), K.end());

  int mst = 0;
  initSet(v);

  for(int i=0; i<e; i++) {
    if(!isSameSet(K[i].second.first, K[i].second.second)) {
      unionSet(K[i].second.first, K[i].second.second);
      mst += K[i].first;
    }
  }

  printf("mst = %d\n", mst);

  return 0;
}
