#include<bits/stdc++.h>

using namespace std;

class PeacefulLine {
public:
  string makeLine(vector<int> V) {
    map<int, int> M;
    for(int i=0; i<V.size(); i++)
      M[V[i]]++;

    int mx = 0;
    for(map<int, int>::iterator it=M.begin(); it!=M.end(); it++)
      if((*it).second > mx)
	mx = (*it).second;

    if(mx-1 > V.size() - mx)
      return "impossible";
    else
      return "possible";
  }
};
