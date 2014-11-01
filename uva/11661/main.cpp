#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int n;

    while(scanf("%d", &n), n) {
        string s;
        cin >> s;

        int mn = 1000000000;
        bool sw = false;
        char x;
        int p = -1;
        for(int i=0; i<s.length(); i++) {
            if(s[i] != '.') {
                if(s[i] == 'Z') {
                    mn = 0;
                    break;
                }

                if(p >= 0) {
                    if(s[i] == 'R') {
                        if(x == 'D') {
                            mn = min(mn, i-p);
                        }
                    } else if(s[i] == 'D') {
                        if(x == 'R') {
                            mn = min(mn, i-p);
                        }
                    }
                }

                p = i;
                x = s[i];
            }
        }

        printf("%d\n", mn);
    }

    return 0;
}
