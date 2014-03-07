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
  vi V(5);
  for(int i=0; i<5; i++)
    scanf("%d", &V[i]);
  sort(V.begin(), V.end());

  while(V[0] + V[4] > 0) {
    if(V[0] == V[3] || V[1] == V[4]) {
      printf("No\n");
    } else {
      bool sw = false;

      if(V[0] == V[2] && (V[0] == 7-V[3] || V[0] == 7-V[4]))
	sw = true;
      
      if(V[1] == V[3] && (V[1] == 7-V[0] || V[1] == 7-V[4]))
	sw = true;

      if(V[2] == V[4] && (V[2] == 7-V[0] || V[2] == 7-V[1]))
	sw = true;

      if(sw)
	printf("Poquer de huevo\n");
      else
	printf("No\n");
    }

    for(int i=0; i<5; i++)
      scanf("%d", &V[i]);
    sort(V.begin(), V.end());
  }

  return 0;
}
