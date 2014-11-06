#include <iostream>
#include <cstdio>
#include <set>

using namespace std;

int main()
{
    int a, m;
    scanf("%d %d", &a, &m);

    set<int> S;

    bool sw = false;
    while(true) {
        if(S.count(a%m) == 0) {
            S.insert(a%m);
        } else {
            break;
        }

        a += a % m;

        if(a%m == 0) {
            sw = true;
            break;
        }
    }

    if(sw) printf("Yes\n");
    else printf("No\n");

    return 0;
}
