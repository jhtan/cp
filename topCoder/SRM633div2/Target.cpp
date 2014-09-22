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

using namespace std;


class Target {
public:
  vector <string> draw(int n) {
    char M[n][n];
    for(int i=0; i<n; i++)
      for(int j=0; j<n; j++)
	M[i][j] = ' ';

    int i = 0, j = n-1;
    while(i <= j) {
      for(int k=i; k<=j; k++) {
	M[i][k] = '#';
	M[j][k] = '#';
	M[k][i] = '#';
	M[k][j] = '#';
      }
      i += 2;
      j -= 2;
    }

    for(int a=0; a<n; a++) {
      for(int b=0; b<n; b++)
	cout << M[a][b];
      cout << endl;
    }

    vector<string> V;
    for(int a=0; a<n; a++) {
      string s = "";
      for(int b=0; b<n; b++) {
	s += M[a][b];
      }
      V.push_back(s);
    }

    return V;
  }
};


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, int p0, bool hasAnswer, vector <string> p1) {
	cout << "Test " << testNum << ": [" << p0;
	cout << "]" << endl;
	Target *obj;
	vector <string> answer;
	obj = new Target();
	clock_t startTime = clock();
	answer = obj->draw(p0);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << "{";
		for (int i = 0; int(p1.size()) > i; ++i) {
			if (i > 0) {
				cout << ",";
			}
			cout << "\"" << p1[i] << "\"";
		}
		cout << "}" << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << "{";
	for (int i = 0; int(answer.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << "\"" << answer[i] << "\"";
	}
	cout << "}" << endl;
	if (hasAnswer) {
		if (answer.size() != p1.size()) {
			res = false;
		} else {
			for (int i = 0; int(answer.size()) > i; ++i) {
				if (answer[i] != p1[i]) {
					res = false;
				}
			}
		}
	}
	if (!res) {
		cout << "DOESN'T MATCH!!!!" << endl;
	} else if (double(endTime - startTime) / CLOCKS_PER_SEC >= 2) {
		cout << "FAIL the timeout" << endl;
		res = false;
	} else if (hasAnswer) {
		cout << "Match :-)" << endl;
	} else {
		cout << "OK, but is it right?" << endl;
	}
	cout << "" << endl;
	return res;
}
int main() {
	bool all_right;
	all_right = true;
	
	int p0;
	vector <string> p1;
	
	{
	// ----- test 0 -----
	p0 = 5;
	string t1[] = {"#####","#   #","# # #","#   #","#####"};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	all_right = KawigiEdit_RunTest(0, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	p0 = 9;
	string t1[] = {"#########","#       #","# ##### #","# #   # #","# # # # #","# #   # #","# ##### #","#       #","#########"};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	all_right = KawigiEdit_RunTest(1, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	p0 = 13;
	string t1[] = {"#############","#           #","# ######### #","# #       # #","# # ##### # #","# # #   # # #","# # # # # # #","# # #   # # #","# # ##### # #","# #       # #","# ######### #","#           #","#############"};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	all_right = KawigiEdit_RunTest(2, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	p0 = 17;
	string t1[] = {"#################","#               #","# ############# #","# #           # #","# # ######### # #","# # #       # # #","# # # ##### # # #","# # # #   # # # #","# # # # # # # # #","# # # #   # # # #","# # # ##### # # #","# # #       # # #","# # ######### # #","# #           # #","# ############# #","#               #","#################"};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	all_right = KawigiEdit_RunTest(3, p0, true, p1) && all_right;
	// ------------------
	}
	
	if (all_right) {
		cout << "You're a stud (at least on the example cases)!" << endl;
	} else {
		cout << "Some of the test cases had errors." << endl;
	}
	return 0;
}
// END KAWIGIEDIT TESTING
//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!
