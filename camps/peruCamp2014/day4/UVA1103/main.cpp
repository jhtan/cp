#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
 
using namespace std;
 
int n, m;
string M[210];
int M2[210][210];
 
void ff2(int i, int j) {
  M2[i][j] = 1;
  int X[4] = {1, 0, -1, 0};
  int Y[4] = {0, 1, 0, -1};
 
  for(int k=0; k<4; k++) {
    int a = i + X[k];
    int b = j + Y[k];
    if(a >= 0 && b >= 0 && a < n && b < m)
      if(!M2[a][b])
	ff2(a, b);
  }
}
 
void ff1(int i, int j) {
  M[i][j] = '0';
  M2[i][j] = 1;
  int X[4] = {1, 0, -1, 0};
  int Y[4] = {0, 1, 0, -1};
 
  for(int k=0; k<4; k++) {
    int a = i + X[k];
    int b = j + Y[k];
    if(a >= 0 && b >= 0 && a < n && b < m)
      if(M[a][b] == '1')
	ff1(a, b);
  }
}
 
int main() {
  scanf("%d %d", &n, &m);
  int tc=0;
 
  while(n + m != 0) {
    tc++;
    for(int i=1; i<=n; i++) {
      string s;
      cin >> s;
      M[i] = "0";
      for(int j=0; j<m; j++) {
	if(s[j] == '0') M[i] += "0000";
	if(s[j] == '1') M[i] += "0001";
	if(s[j] == '2') M[i] += "0010";
	if(s[j] == '3') M[i] += "0011";
	if(s[j] == '4') M[i] += "0100";
	if(s[j] == '5') M[i] += "0101";
	if(s[j] == '6') M[i] += "0110";
	if(s[j] == '7') M[i] += "0111";
	if(s[j] == '8') M[i] += "1000";
	if(s[j] == '9') M[i] += "1001";
	if(s[j] == 'a') M[i] += "1010";
	if(s[j] == 'b') M[i] += "1011";
	if(s[j] == 'c') M[i] += "1100";
	if(s[j] == 'd') M[i] += "1101";
	if(s[j] == 'e') M[i] += "1110";
	if(s[j] == 'f') M[i] += "1111";
      }
    }
 
    m *= 4;
    n += 2;
    m += 2;
    for(int i=0; i<m; i++) {
      M[0][i] = '0';
      M[n-1][i] = '0';
    }
    for(int i=0; i<n; i++) {
      M[m-1][0] = '0';
    }
 
    string key=" WAKJSD", s = "";
    int c;
 
    for(int i=0; i<n; i++) {
      for(int j=0; j<m; j++) {
	if(M[i][j] == '1') {
	  memset(M2, 0, sizeof(M2));
	  ff1(i, j);
	  c = 0;
	  for(int ii=0; ii<n; ii++) {
	    for(int jj=0; jj<m; jj++) {
	      if(!M2[ii][jj]) {
		ff2(ii, jj);
		c++;
	      }
	    }
	  }
 
	  s += key[c];
	}
      }
    }
    
    sort(s.begin(), s.end());
    cout << "Case " << tc << ": " << s << endl;
    scanf("%d %d", &n, &m);
  }
 
  return 0;
}
