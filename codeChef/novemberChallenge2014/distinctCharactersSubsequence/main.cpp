#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    scanf("%d", &t);

    while(t--) {
        string s;
        cin >> s;

        set<char> S;
        for(int i=0; i<s.length(); i++)
            S.insert(s[i]);

        printf("%d\n", S.size());

    }

    return 0;
}
