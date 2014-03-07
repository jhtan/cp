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
typedef pair<double, double>     ff;
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

double dist(double x1, double y1, double x2, double y2) {
  return sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
}

int main() {
  int t, tc=0;
  scanf("%d", &t);

  while(t--) {
    tc++;
    int n;
    scanf("%d", &n);
    vector<ff> V, W;
    map<ff, int> M;

    double a, b;
    for(int i=0; i<n; i++) {
      scanf("%lf %lf", &a, &b);
      V.push_back(ff(a, b));
    }

    vector<pair<double, ii> > K;
    for(int i=0; i<n; i++) {
      for(int j=i+1; j<n; j++) {
	K.push_back(make_pair(dist(V[i].first, V[i].second, V[j].first, V[j].second), ii(i, j)));
      }
    }

    initSet(n);

    int m;
    scanf("%d", &m);

    int aa, bb;
    for(int i=0; i<m; i++) {
      scanf("%d %d", &aa, &bb);
      unionSet(aa-1, bb-1);
    }

    sort(K.begin(), K.end());
    double mst = 0;
    double mx = 0;
    for(int i=0; i<K.size(); i++) {
      if(!isSameSet(K[i].second.first, K[i].second.second)) {
	mst += K[i].first;
	mx = max(mx, K[i].first);
	unionSet(K[i].second.first, K[i].second.second);
      }
    }

    int x = mx;
    printf("Caso %d: %d\n", tc, x);
  }

  return 0;
}
