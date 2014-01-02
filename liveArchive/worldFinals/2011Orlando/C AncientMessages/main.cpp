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
typedef vector<ii>         vii;
typedef set<int>           si;
typedef map<string, int>   msi;

int n, m, ac;
bool M[200][200];
bool B[200][200];
bool C[210][210];

void ff2(int i, int j) {
  C[i][j] = true;
  int X[4] = {1, 0, -1, 0};
  int Y[4] = {0, 1, 0, -1};
  // int X[8] = {1, 1, 0, -1, -1, -1, 0, 1};
  // int Y[8] = {0, 1, 1, 1, 0, -1, -1, -1};

  for(int k=0; k<4; k++) {
    int a = i + X[k];
    int b = j + Y[k];

    if(a >= 0 && b >= 0 && a < n+2 && b < m*4+2) {
      if(!C[a][b])
	ff2(a, b);
    }
  }
}

void ff(int i, int j) {
  B[i][j] = true;
  C[i+1][j+1] = true;
  int X[4] = {1, 0, -1, 0};
  int Y[4] = {0, 1, 0, -1};
  // int X[8] = {1, 1, 0, -1, -1, -1, 0, 1};
  // int Y[8] = {0, 1, 1, 1, 0, -1, -1, -1};

  for(int k=0; k<4; k++) {
    int a = i + X[k];
    int b = j + Y[k];

    if(a >= 0 && b >= 0 && a < n && b < m*4) {
      if(M[a][b] && !B[a][b])
	ff(a, b);
    }
  }
}

int main() {
  string key = "-WAKJSD";
  int tc = 0;
  scanf("%d %d", &n, &m);
  
  while(n+m > 0) {
    tc++;
    memset(M, false, sizeof(M));

    for(int i=0; i<n; i++) {
      string s;
      cin >> s;
      for(int j=0; j<s.length(); j++) {
	if(s[j] == '1')
	  M[i][j*4+3] = true;
	else if(s[j] == '2')
	  M[i][j*4+2] = true;
	else if(s[j] == '3')
	  M[i][j*4+2] = M[i][j*4+3] = true;
	else if(s[j] == '4')
	  M[i][j*4+1] = true;
	else if(s[j] == '5')
	  M[i][j*4+1] = M[i][j*4+3] = true;
	else if(s[j] == '6')
	  M[i][j*4+1] = M[i][j*4+2] = true;
	else if(s[j] == '7')
	  M[i][j*4+1] = M[i][j*4+2] = M[i][j*4+3] = true;
	else if(s[j] == '8')
	  M[i][j*4+0] = true;
	else if(s[j] == '9')
	  M[i][j*4+0] = M[i][j*4+3] = true;
	else if(s[j] == 'a')
	  M[i][j*4+0] = M[i][j*4+2] = true;
	else if(s[j] == 'b')
	  M[i][j*4+0] = M[i][j*4+2] = M[i][j*4+3] = true;
	else if(s[j] == 'c')
	  M[i][j*4+0] = M[i][j*4+1] = true;
	else if(s[j] == 'd')
	  M[i][j*4+0] = M[i][j*4+1] = M[i][j*4+3] = true;
	else if(s[j] == 'e')
	  M[i][j*4+0] = M[i][j*4+1] = M[i][j*4+2] = true;
	else if(s[j] == 'f')
	  M[i][j*4+0] = M[i][j*4+1] = M[i][j*4+2] = M[i][j*4+3] = true;
      }
    }

    memset(B, false, sizeof(B));
    string s = "";

    for(int i=0; i<n; i++) {
      for(int j=0; j<m*4; j++) {    
	if(M[i][j] && !B[i][j]) {
	  memset(C, false, sizeof(C));
	  ff(i, j);

	  // for(int ii=0; ii<n+2; ii++) {
	  //   for(int jj=0; jj<m*4+2; jj++) {
	  //     if(C[ii][jj])
	  // 	cout << "1";
	  //     else
	  // 	cout << "0";
	  //   }
	  //   cout << endl;
	  // }

	  int c = 0;
	  for(int ii=0; ii<n+2; ii++) {
	    for(int jj=0; jj<m*4+2; jj++) {
	      if(!C[ii][jj]) {
		ff2(ii, jj);
		c++;
	      }
	    }
	  }
	  s += key[c];
	}
      }
    }

    string key2 = "ADJKSW", ss = "";
    for(int i=0; i<key2.length(); i++) {
      for(int j=0; j<s.length(); j++) {
	if(key2[i] == s[j])
	  ss += key2[i];
      }
    }

    cout << "Case " << tc << ": " << ss << endl;
    scanf("%d %d", &n, &m);
  }

  return 0;
}
