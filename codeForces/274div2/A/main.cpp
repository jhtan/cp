#include <bits/stdc++.h>

using namespace std;

typedef long long          ll;
typedef vector<int>        vi;
typedef pair<int, int>     ii;
typedef vector<ii>         vii;
typedef set<int>           si;
typedef map<string, int>   msi;

int main() {
  int a, b, c;
  scanf("%d %d %d", &a, &b, &c);

  printf("%d\n", max(
		     max(max((a*b)*c, (a*b)+c), max((a+b)*c, (a+b)+c)),
		     max(max(a*(b*c), a*(b+c)), max(a+(b*c), a+(b+c)))));

  return 0;
}
