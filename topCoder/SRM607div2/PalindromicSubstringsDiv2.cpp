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

string s = "";
int dp[5000][5000];

class PalindromicSubstringsDiv2 {
  bool pal(int i, int j) {
    if(!dp[i][j]) {
      if(i == j || i+1 == j){ 
	if(s[i] == s[j])
	  dp[i][j] = 1;
	else
	  dp[i][j] = 2;
      } else {
	if(s[i] == s[j] && pal(i+1, j-1))
	  dp[i][j] = 1;
	else
	  dp[i][j] = 2;
      }
    } 

    if(dp[i][j] == 1)
      return true;
    else
      return false;
  }

public:
  int count(vector <string> S1, vector <string> S2) {
    s = "";
    for(int i=0; i<S1.size(); i++)
      s += S1[i];
    for(int j=0; j<S2.size(); j++)
      s += S2[j];

    int c = 0;
    memset(dp, 0, sizeof(dp));
    for(int i=0; i<s.length(); i++) {
      for(int j=i+1; j<s.length(); j++) {
	if(pal(i, j))
	  c++;
      }
    }
    
    return c + s.length();
  }
};


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, vector <string> p0, vector <string> p1, bool hasAnswer, int p2) {
	cout << "Test " << testNum << ": [" << "{";
	for (int i = 0; int(p0.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << "\"" << p0[i] << "\"";
	}
	cout << "}" << "," << "{";
	for (int i = 0; int(p1.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << "\"" << p1[i] << "\"";
	}
	cout << "}";
	cout << "]" << endl;
	PalindromicSubstringsDiv2 *obj;
	int answer;
	obj = new PalindromicSubstringsDiv2();
	clock_t startTime = clock();
	answer = obj->count(p0, p1);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << p2 << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << answer << endl;
	if (hasAnswer) {
		res = answer == p2;
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
	
	vector <string> p0;
	vector <string> p1;
	int p2;
	
	{
	// ----- test 0 -----
	string t0[] = {"a","a",""};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	string t1[] = {"a"};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 6;
	all_right = KawigiEdit_RunTest(0, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	string t0[] = {"zaz"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1.clear() /*{}*/;
	p2 = 4;
	all_right = KawigiEdit_RunTest(1, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	string t0[] = {"top"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	string t1[] = {"coder"};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 8;
	all_right = KawigiEdit_RunTest(2, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	p0.clear() /*{}*/;
	string t1[] = {"daata"};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 7;
	all_right = KawigiEdit_RunTest(3, p0, p1, true, p2) && all_right;
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