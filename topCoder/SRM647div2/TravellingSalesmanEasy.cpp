#include<bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

class TravellingSalesmanEasy {
public:
  int getMaxProfit(int n, vi A, vi B, vi C) {
    map<int, vi> M;

    for(int i=0; i<A.size(); i++)
      M[B[i]].push_back(A[i]);
    
    int s = 0;
    for(int i=0; i<C.size(); i++)
      if(M.count(C[i]) != 0 && M[C[i]].size()) {
	vi::iterator p_mx = max_element(M[C[i]].begin(), M[C[i]].end());
	s += *(p_mx);
	M[C[i]].erase(p_mx);
      }

    return s;
  }
};
