#include <bits/stdc++.h>

using namespace std;

typedef long long          ll;
typedef vector<int>        vi;
typedef pair<int, int>     ii;
typedef vector<ii>         vii;
typedef set<int>           si;
typedef map<string, int>   msi;

bool isSegment(int a, int b, int c) {
  vi V(3); V[0] = a; V[1] = b; V[2] = c;
  sort(V.begin(), V.end());
  if(V[0] + V[1] == V[2]) return true;
  return false;
}

bool isTriangle(int a, int b, int c) {
  vi V(3); V[0] = a; V[1] = b; V[2] = c;
  sort(V.begin(), V.end());
  if(V[0] + V[1] > V[2]) return true;
  return false;
}

int main() {
  int a, b, c, d; scanf("%d %d %d %d", &a, &b, &c, &d);

  if(isTriangle(a, b, c) || isTriangle(a, b, d) ||
     isTriangle(a, c, d) || isTriangle(b, c, d))
    printf("TRIANGLE\n");
  else if(isSegment(a, b, c) || isSegment(a, b, d) || 
     isSegment(a, c, d) || isSegment(b, c, d))
      printf("SEGMENT\n");
  else
      printf("IMPOSSIBLE\n");

  return 0;
}
