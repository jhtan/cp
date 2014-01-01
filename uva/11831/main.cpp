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

int main() {
  int n, m, t;
  scanf("%d %d %d", &n, &m, &t);

  while(n+m+t > 0) {
    string M[n];
    int a, b, c;
    for(int i=0; i<n; i++) {
      cin >> M[i];
      for(int j=0; j<M[i].length(); j++) {
	if(M[i][j] == 'N' || M[i][j] == 'S' || M[i][j] == 'L' || M[i][j] == 'O') {
	  a = i, b = j, c = M[i][j];
	}
      }
    }

    string s;
    cin >> s;

    int sc = 0;
    for(int i=0; i<s.length(); i++) {
      if(s[i] == 'D' && c == 'N')
	c = 'L';
      else if(s[i] == 'D' && c == 'L')
	c = 'S';
      else if(s[i] == 'D' && c == 'S')
	c = 'O';
      else if(s[i] == 'D' && c == 'O')
	c = 'N';
      else if(s[i] == 'E' && c == 'N')
	c = 'O';
      else if(s[i] == 'E' && c == 'O')
	c = 'S';
      else if(s[i] == 'E' && c == 'S')
	c = 'L';
      else if(s[i] == 'E' && c == 'L')
	c = 'N';
      else if(s[i] == 'F') {
	int x = a, y = b;
	if(c == 'N')
	  x--;
	if(c == 'S')
	  x++;
	if(c == 'O')
	  y--;
	if(c == 'L')
	  y++;

	if(x >= 0 && y >= 0 && x < n && y < m && M[x][y] != '#') {
	  if(M[x][y] == '*') {
	    sc++;
	    M[x][y] = '.';
	  }
	  a = x, b = y;
	}
      }
    }

    printf("%d\n", sc);
    scanf("%d %d %d", &n, &m, &t);
  }

  return 0;
}
