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

//#define for(i, a, b) \
//  for(int i = int(a); i <= int(b); i++)
//#define Rvi(c, it) \
//  for(vi::iterator it = (c).begin(); it != (c).end(); it++)
//#define Rvii(c, it) \
//  for(vii::iterator it = (c).begin(); it != (c).end(); it++)
//#define Rmsi(c, it) \
//  for(msi::iterator it = (c).begin(); it != (c).end(); it++)

string M[4];
bool B[4][8];
int X[4] = {0, 1, 0, -1};
int Y[4] = {-1, 0, 1, 0};

void ff(int i, int j) {
  if(M[i][j] == '*' && !B[i][j]) {
  B[i][j] = true;
  for(int k=0; k<4; k++) {
    int a = i + X[k];
    int b = j + Y[k];
    if(a >= 0 && b >= 0 && a < 4 && b < 8)
      ff(a, b);
  }
  }
}

int main() {
  int m;
  scanf("%d", &m);

  while(m) {
    for(int i=0; i<4; i++)
      cin >> M[i];

    memset(B, false, sizeof(B));
    ff(0, 1);
    ff(0, 2);
    ff(0, 5);
    ff(0, 6);

    bool c = B[3][1] || B[3][2];
    bool t = B[3][5] || B[3][6];

    if(m > 10) {
      if(!c)
	printf("INVALID\n");
      else
	printf("OUTDATED\n");
    } else if(m < 5) {
      if(c && t)
	printf("PREGNANT\n");
      else if(c && !t)
	printf("WAIT\n");
      else
	printf("INVALID\n");
    } else {
      if(c && t)
	printf("PREGNANT\n");
      else if(c && !t)
	printf("NOT PREGNANT\n");
      else
	printf("INVALID\n");
    }

    scanf("%d", &m);
  }
  
  return 0;
}
