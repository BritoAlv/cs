// Problem: B. The Corridor or There and Back Again
// Contest: Codeforces - Codeforces Round 895 (Div. 3)
// URL: https://codeforces.com/contest/1872/problem/B
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Math Proof: read carefully the statment of the problem, nothing
// else, when the statment of the problem is nor right understood
// time get wasted like in this round.
//
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
#define endl '\n'
#define forn for (int i = 0; i < n; i++)
using namespace std;

int test_cases;

void Solve()
{
    int n;
    cin >> n;
    int min_largest = 100001;
    while (n > 0)
    {
        int d, s;
        cin >> d >> s;
        if (s == 1)
        {
            min_largest = min(min_largest, d);
        }
        else
        {
            if (d == 1)
            {
                min_largest = min(min_largest, d + s / 2 + (s % 2 == 0 ? -1 : 0));
            }
            else
            {
                // s == 2: 0
                // s == 3: 1
                // s == 4: 1
                // s == 5: 2
                min_largest = min(min_largest, d + (s - 2) / 2 + (s % 2 == 1 ? 1 : 0));
            }
        }
        n--;
    }
    cout << min_largest << endl;

    return;
}

int main()
{
    cin >> test_cases;
    while (test_cases > 0)
    {
        Solve();
        test_cases--;
    }
    return 0;
}
