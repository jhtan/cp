#include <bits/stdc++.h>

using namespace std;

typedef long long          ll;
typedef vector<int>        vi;
typedef pair<int, int>     ii;
typedef vector<ii>         vii;
typedef set<int>           si;
typedef map<string, int>   msi;

int main() {
  string a, b;
  while(cin >> a >> b) {

  int h1, h2, m1, m2;

  if(a.length() == 4) {
    h1 = a[0] - '0';
    m1 = a[2] - '0';
    m1 *= 10;
    m1 += a[3] - '0';
  } else if(a.length() == 5) {
    h1 = a[0] - '0';
    h1 *= 10;
    h1 += a[1] - '0';
    m1 = a[3] - '0';
    m1 *= 10;
    m1 += a[4] - '0';
  }

  if(b.length() == 4) {
    h2 = b[0] - '0';
    m2 = b[2] - '0';
    m2 *= 10;
    m2 += b[3] - '0';
  } else if(b.length() == 5) {
    h2 = b[0] - '0';
    h2 *= 10;
    h2 += b[1] - '0';
    m2 = b[3] - '0';
    m2 *= 10;
    m2 += b[4] - '0';
  }

  int h3=0, m3=0;

  while(h1 != h2 || m1 != m2) {
    m1++;
    if(m1 > 59) {
      m1 = 0;
      h1++;
    }
    if(h1 == 24) h1 = 0;


    m3++;
    if(m3 > 59) {
      m3 = 0;
      h3++;
    }

    
    // cout << "h2 = " << h2 << endl;
    // cout << "m2 = " << m2 << endl;
  }

  printf("%d horas, %d minutos\n", h3, m3);

  }

  return 0;
}
