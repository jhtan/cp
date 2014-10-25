#include <bits/stdc++.h>

using namespace std;

typedef long long          ll;
typedef vector<int>        vi;
typedef pair<int, int>     ii;
typedef vector<ii>         vii;
typedef set<int>           si;
typedef map<string, int>   msi;

struct point {
  double x, y;
  point(){}
  point(double a, double b) {x = a, y = b;}
};

point operator -(const point &A, const point &B) {
  return point(A.x - B.x, A.y - B.y);
}

// Cross product.
double cross(const point &A, const point &B) {
  return A.x * B.y - A.y * B.x;
}

// Area of parallelogram formed by two vectors.
double area(const point &A, const point &B, const point &C) {
  return cross(B-A, C-A);
}

// Determines whether point C is at the segment AB.
bool onSegment(const point &A, const point &B, const point &C) {
  return area(A, B, C) == 0 && min(A.x, B.x) <= C.x && C.x <= max(A.x, B.x) && min(A.y, B.y) <= C.y && C.y <= max(A.y, B.y);
}

// Determines whether the segment AB intersects the segment CD.
bool intersects(const point &A, const point &B, const point &C, const point &D) {
  double a1 = area(C, D, A);
  double a2 = area(C, D, B);
  double a3 = area(A, B, C);
  double a4 = area(A, B, D);

  if(((a1>0 && a2<0) || (a1<0 && a2>0)) && ((a3>0 && a4<0) || (a3<0 && a4>0)))
    return true;
  if(!a1 && onSegment(C, D, A)) return true;
  if(!a2 && onSegment(C, D, B)) return true;
  if(!a3 && onSegment(A, B, C)) return true;
  if(!a4 && onSegment(A, B, D)) return true;
  return false;
}

int main() {
  int t; scanf("%d", &t);

  while(t--) {
    double x1, y1, x2, y2, ax, ay, bx, by, cx, cy, dx, dy;
    scanf("%lf %lf %lf %lf %lf %lf %lf %lf", &x1, &y1, &x2, &y2, &ax, &ay, &dx, &dy);

    if(ax > dx) swap(ax, dx);
    if(dy > ay) swap(ay, dy);

    bx = ax, by = dy;
    cx = dx, cy = ay;

    point X, Y, A, B, C, D;
    X.x = x1, X.y = y1;
    Y.x = x2, Y.y = y2;
    A.x = ax, A.y = ay;
    B.x = bx, B.y = by;
    C.x = cx, C.y = cy;
    D.x = dx, D.y = dy;

    if(intersects(X, Y, A, B)) printf("T\n");
    else if(intersects(X, Y, B, D)) printf("T\n");
    else if(intersects(X, Y, D, C)) printf("T\n");
    else if(intersects(X, Y, C, A)) printf("T\n");
    else if(X.x>=A.x && X.x<=D.x && Y.x>=A.x && Y.x<=D.x && X.y>=D.y && X.y<=A.y && Y.y>=D.y && Y.y<=A.y) printf("T\n");

    else printf("F\n");
  }

  return 0;
}
