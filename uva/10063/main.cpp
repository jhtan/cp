#include <cstdio>
#include <iostream>
#include <vector>
 
using namespace std;
 
vector<string> knuthP(string s) {
  if(s.length() == 1) {
    vector<string> A;
    A.push_back(s);
    return A;
  } else {
    string a = s.substr(0, s.length()-1);
    string b = s.substr(s.length()-1);
 
    // cout << "a = " << a << endl;
    // cout << "b = " << b << endl;
 
    vector<string> V = knuthP(a);
    vector<string> A;
    // cout << "v.size = " << V.size() << endl;
    for(int i=0; i<V.size(); i++) {
      for(int j=0; j<=V[i].size(); j++) {
	A.push_back(V[i].substr(0, j) + b + V[i].substr(j));
	// cout << "> " << V[i].substr(0, j) + b + V[i].substr(j) << endl;
      }
    }
    // cout << "--" << endl;
 
    return A;
  }
}
 
int main() {
  string s;
  cin >> s;
  
  while(true) {
    vector<string> V = knuthP(s);
 
    for(int i=0; i<V.size(); i++)
      cout << V[i] << endl;
 
    if(cin >> s)
      cout << endl;
    else
      break;
  }
 
  return 0;
}
