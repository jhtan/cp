point pivot(0,0);

bool angleCmp(point a, point b) {
	if (collinear(pivot, a, b))
		return dist(pivot, a) < dist(pivot, b); // determine wich one is closer
	double d1x = a.x - pivot.x, d1y = a.y - pivot.y;
	double d2x = b.x - pivot.x, d2y = b.y - pivot.y;
	return (atan2(d1y, d1x) - atan2(d2y, d2x)) < 0;
}

vector<point> CH(vector<point> P) {
	int i;
	int N = P.size();
	if (N < 3) return P; // special case, the CH is P itself

	// first, find P0 = point with lowest Y and if tie, rightmost X
	int P0 = 0;
	for (i = 1; i < N; i++)
		if (P[i].y < P[P0].y || P[i].y == P[P0].y && P[i].x > P[P0].x)
			P0 = i;
	// swap selected vertex with P[0]
	point temp = P[0];
	P[0] = P[P0];
	P[P0] = temp;

	// second, sort points by angle w.r.t. pivot P0
	pivot = P[0]; // use this global variable as reference
	sort(++P.begin(), P.end(), angleCmp); // notice that we does not sort P[0]

	// third, the ccw tests
	point prev(0,0), now(0,0);
	stack<point> S; S.push(P[N-1]); S.push(P[0]); // initial content of stack S
	i = 1;	// then, we check the rest
	while (i < N) {
		now = S.top();
		S.pop(); prev = S.top(); S.push(now); // get 2nd from top
		if (ccw(prev, now, P[i])) S.push(P[i++]); // left turn, accept
		else S.pop(); // otherwise, pop the top of stack S until we have a left turn
	}

	vector<point> ConvexHull;
	while (!S.empty()) {
		ConvexHull.push_back(S.top());
		S.pop();
	}
	return ConvexHull;
}

int main() {
	vector<point> P;
	P.push_back(point(0,0));
	P.push_back(point(1,0));
	P.push_back(point(2,0));
	P.push_back(point(2,2));
	P.push_back(point(0,2));
	vector<point> R = CH(P);
	for(vector<point>::iterator it = R.begin(); it != R.end(); it++)
		cout << it->x << " " << it-> y << endl;
	return 0;
}
