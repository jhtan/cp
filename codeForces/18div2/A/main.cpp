#include <bits/stdc++.h>

using namespace std;

typedef long long          ll;
typedef vector<int>        vi;
typedef pair<int, int>     ii;
typedef vector<ii>         vii;
typedef set<int>           si;
typedef map<string, int>   msi;

bool isRight(int x1, int y1, int x2, int y2, int x3, int y3) {
  if(x1*(y2-y3) + x2*(y3-y1) + x3*(y1-y2) == 0)
    return false;

  double a = (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
  double b = (x1-x3)*(x1-x3)+(y1-y3)*(y1-y3);
  double c = (x2-x3)*(x2-x3)+(y2-y3)*(y2-y3);

  if(a == b+c) return true;
  if(b == a+c) return true;
  if(c == a+b) return true;
  return false;
}

int main() {
  int x1, y1, x2, y2, x3, y3;
  scanf("%d %d %d %d %d %d", &x1, &y1, &x2, &y2, &x3, &y3);

  if(isRight(x1, y1, x2, y2, x3, y3)) {
    printf("RIGHT\n");
  } else {
    if(isRight(x1+1, y1, x2, y2, x3, y3)) {
      printf("ALMOST\n");
    } else if(isRight(x1, y1+1, x2, y2, x3, y3)) {
      printf("ALMOST\n");
    } else if(isRight(x1, y1, x2+1, y2, x3, y3)) {
      printf("ALMOST\n");
    } else if(isRight(x1, y1, x2, y2+1, x3, y3)) {
      printf("ALMOST\n");
    } else if(isRight(x1, y1, x2, y2, x3+1, y3)) {
      printf("ALMOST\n");
    } else if(isRight(x1, y1, x2, y2, x3, y3+1)) {
      printf("ALMOST\n");
    } else if(isRight(x1-1, y1, x2, y2, x3, y3)) {
      printf("ALMOST\n");
    } else if(isRight(x1, y1-1, x2, y2, x3, y3)) {
      printf("ALMOST\n");
    } else if(isRight(x1, y1, x2-1, y2, x3, y3)) {
      printf("ALMOST\n");
    } else if(isRight(x1, y1, x2, y2-1, x3, y3)) {
      printf("ALMOST\n");
    } else if(isRight(x1, y1, x2, y2, x3-1, y3)) {
      printf("ALMOST\n");
    } else if(isRight(x1, y1, x2, y2, x3, y3-1)) {
      printf("ALMOST\n");
    } else {
      printf("NEITHER\n");
    }
  }

  return 0;
}
