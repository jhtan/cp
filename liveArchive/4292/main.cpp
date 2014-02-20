#include <cstdio>
#include <iostream>
 
using namespace std;
 
int main() {
  int t;
  scanf("%d", &t);
 
    string V[13] = {"", "", "1", "7", "4", "2", "6", "8", "10", "18", "22", "20", "28"};
 
  while(t--) {
    int n;
    scanf("%d", &n);
 
    // MIN
    if(n < 13) {
      cout << V[n];
    } else {
      int m = n - 6;
      bool sw;
      (m%7) == 4 ? sw = true : sw = false;
      (sw) ? cout << "200" : cout << V[(m%7)+6];
      for(int i=0; i<m/7; i++) {
	if(sw)
	  sw = false;
	else
	  cout << "8";
      }
    }
    cout << " ";
 
    // MAX
    if(n % 2 == 0) {
      for(int i=0; i<n/2; i++)
	cout << "1";
    } else {
      cout << "7";
      for(int i=0; i<(n-3)/2; i++)
	cout << "1";
    }
    cout << endl;
  }
 
  return 0;
}
