// Problem: C. Vampiric Powers, anyone?
// Contest: Codeforces - Codeforces Round 882 (Div. 2)
// URL: https://codeforces.com/contest/1847/problem/C
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Math Proof:
//
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
#define endl '\n'
#define wp ' '
#define forn for (int i = 0; i < n; i++)
#define pb push_back

using namespace std;

void Solve()
{
    int n;
    cin >> n;
    int maxx = 0;
    vector<int> obtanible_xors(256, 0);
    forn
    {
        int a;
        cin >> a;
        vector<int> new_one(256, 0);
        new_one[a] = 1;
        maxx = max(a, maxx);
        if (i > 0)
        {
            for (int j = 0; j < 256; j++)
            {
                if (obtanible_xors[j])
                {
                    new_one[j ^ a] = 1;
                    maxx = max(maxx, j ^ a);
                }
            }
        }
        obtanible_xors = new_one;
    }
    cout << maxx << endl;
    return;
}

int main()
{
    int test_cases;
    cin >> test_cases;
    while (test_cases > 0)
    {
        Solve();
        test_cases--;
    }
    return 0;
}
