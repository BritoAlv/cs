// Problem: B. Tenzing and Books
// Contest: Codeforces - CodeTON Round 5 (Div. 1 + Div. 2, Rated, Prizes!)
// URL: https://codeforces.com/contest/1842/problem/B
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
    int n, x;
    cin >> n >> x;
    int actual_or = 0;
    bool stopped = 0;
    for (int j = 0; j < 3; j++)
    {
        stopped = 0;
        for (int i = 0; i < n; i++)
        {
            int a;
            cin >> a;
            if (!stopped)
            {
                if ((a | x) == x)
                {
                    actual_or = a | actual_or;
                }
                else
                {
                    stopped = 1;
                }
            }
        }
    }
    if (actual_or == x)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
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
