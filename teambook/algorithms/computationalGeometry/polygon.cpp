// return the perimeter, which is the sum of Euclidian distances
// of consecutive line segments (polygon edges)
double perimeter(vector<point> P) {
	double result = 0.0;
	for (int i = 0; i < P.size() - 1; i++)
		result += dist(P[i],P[i+1]);
	return result;
}

// returns the area, which is half the determinant
double area(vector<point> P) {
	double result = 0.0;
	double x1, y1, x2, y2;
	for (int i = 0; i < P.size() - 1; i++) {
		x1 = P[i].x; x2 = P[i+1].x;
		y1 = P[i].y; y2 = P[i+1].y;
		result += (x1 * y2 - x2 * y1);
	}
	return fabs(result)/ 2.0;
}

// returns true if all three consecutive vertices of P form the same turns
bool isConvex(vector<point> P) {
	int sz = P.size() - 1;
	if (sz < 3)
		return false;
	bool isLeft = ccw(P[0], P[1], P[2]);
	for (int i = 1; i < P.size(); i++)
		if (ccw(P[i], P[(i+1) % sz], P[(i+2) % sz]) != isLeft)
			return false;
	return true;
}

double angle(point a, point b, point c) {
	double ux = b.x - a.x, uy = b.y - a.y;
	double vx = c.x - a.x, vy = c.y - a.y;
	return acos((ux*vx + uy*vy)/ sqrt((ux*ux + uy*uy)*(vx*vx+vy*vy)));
}

// returns true if point p is in either convex/concave polygon P
bool inPolygon(point p, vector<point> P) {
	if (P.size() == 0) return false;
	for (int i = 0; i < P.size(); i++) // point is in P
		if (fabs(P[i].x - p.x) < EPS && fabs(P[i].y - p.y) < EPS)
			return true;
	double sum = 0;
	for (int i = 0; i < P.size() - 1; i++) 
		if (cross(p, P[i], P[i+1]) < 0)
			sum -= angle(p, P[i], P[i+1]);
		else
			sum += angle(p, P[i], P[i+1]);
	return (fabs(sum - 2*PI) < EPS || fabs(sum + 2*PI) < EPS);
}

int main() {
	vector<point> P;
	P.push_back(point(0,0));
	P.push_back(point(0,10));
	P.push_back(point(10,0));
	P.push_back(point(0,0));
	point p(5,5);

	if (inPolygon(p, P))
		cout << "IN POLYGON" << endl;
	else
		cout << "NOT IN POLYGON" << endl; 
	return 0;
}
