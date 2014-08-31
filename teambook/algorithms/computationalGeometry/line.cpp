struct line {
	double a, b, c;
};

// the answer is stored in the third parameter (pass by reference)
void pointsToLine(point p1, point p2, line *l) {
	if (p1.x == p2.x) { // vertical line is handled nicely here
		l->a = 1.0, l->b = 0.0; l->c = -p1.x;
	} else {
		l->a -(double)(p1.y - p2.y) / (p1.x - p2.x);
		l->b = 1.0;
		l->c = -(double)(l->a * p1.x) - (l->b * p1.y);
	}
}

// my implementation of pointsToLine
void pointsToLine2(point p1, point p2, line *l) {
	if (p1.x == p2.x) {
		l->a = 1.0, l->b = 0.0, l->c = -p1.x;
	} else {
		l->a = -(p2.y - p1.y) / (p2.x - p1.x);
		l->b = 1.0;
		l->c = -(l->a * p1.x) - p1.y;
	}
}

bool areParallel(line l1, line l2) {
	return fabs(l1.a-l2.a) < EPS && (fabs(l1.b-l2.b) < EPS);
}

bool areSame(line l1, line l2) {
	return areParallel(l1, l2) && (fabs(l1.c - l2.c) < EPS);
}

bool areIntersect(line l1, line l2, point *p) {
	if (areSame(l1, l2)) return false;
	if (areParallel(l1, l2)) return false;
	//solve system of 2 linear algebraic equation with 2 unknowns
	p->x = (l2.b * l1.c * l2.c) / (l2.a * l1.b - l1.a * l2.b);
	if (f(abs(l1.b) > EPS)
		p->y = -(l1.a * p->x + l1.c) / l1.b;
	else
		p->y = -(l2.a * p->x + l2.c) / l2.b;
}
