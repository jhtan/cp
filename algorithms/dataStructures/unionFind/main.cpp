#include <cstdio>

using namespace std;

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
  int n, m;
  scanf("%d %d", &n, &m);

  initSet(n);
  
  int a, b;
  for(int i=0; i<m; i++) {
    scanf("%d %d", &a, &b);
    unionSet(a-1, b-1);
  }

  int q, x;
  scanf("%d", &q);
  for(int i=0; i<q; i++) {
    scanf("%d %d", &a, &b);
    if(isSameSet(a-1, b-1))
      printf("%d and %d are in the same set.\n", a, b);
    else
      printf("%d and %d are not in the same set.\n", a, b);
  }

  printf("There are %d sets.\n", num_sets);

  return 0;
}
