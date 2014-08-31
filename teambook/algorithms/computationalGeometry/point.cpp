#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

#define EPS 1e-8
#define PI acos(-1)

struct point {
	double x, y;
	point(double _x, double _y) {
		x = _x, y = _y;
	}
	bool operator < (point other) {
		if (fabs(x - other.x) < EPS)
			return x < other.x;
		return y < other.y;
	}
};

bool areSame(point p1, point p2) {
	return fabs(p1.x - p2.x) < EPS && fabs(p1.y - p2.y) < EPS;
}

double dist(point p1, point p2) {
	return hypot(p1.x - p2.x, p1.y - p2.y);	
}

// cross product between 3 points
double cross(point p, point q, point r) {
	return (r.x - q.x) * (p.y - q.y) - (r.y - q.y) * (p.x - q.x);
}

// return true if point r is on the same line as the line pq
bool collinear (point p, point q, point r) {
	return fabs(cross(p,q,r)) < EPS;
}

// return true if point r is on the left side of line pq
bool ccw(point p, point q, point r) {
	return cross(p, q, r) > 0; // can be modified to accept collinear points
}

double DEG_to_RAD(double deg) {
	return deg * PI / 180.0;
}

point rotate(point p, double theta) {
	double rad = DEG_to_RAD(theta);
	return point(p.x * cos(rad) - p.y * sin(rad), p.x * sin(rad) + cos(rad));
}


int main() {
	point r(3,0);
	point q(6,0);
	point p(6,4);
	printf("%f\n", cross(p,q,r));
	if (collinear(p,q,r))
		printf("Collinear\n");
	else
		printf("No collinear\n");
	if (ccw(p,q,r))
		printf("CCW\n");
	else
		printf("No CCW\n");
	return 0;
}
