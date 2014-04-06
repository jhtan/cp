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

bool comp(ii a, ii b) {
  if(a.first == b.first) {
    return a.second > b.second;
  } else {
    return a.first < b.first;
  }
}

int main() {
  string s;
  bool sw = true;

  while(getline(cin, s)) {

    if(sw)
      sw = false;
    else
      cout << endl;

    vi alp(256, 0);

    for(int i=0; i<s.length(); i++)
      alp[s[i]]++;

    vii V;
    for(int i=0; i<256; i++)
      if(alp[i])
	V.push_back(ii(alp[i], i));

    sort(V.begin(), V.end(), comp);

    for(int i=0; i<V.size(); i++)
      cout << V[i].second << " " << V[i].first << endl;
  }

  return 0;
}
