// Problem: B. Astrophysicists
// Contest: Codeforces - Codeforces Round 880 (Div. 2)
// URL: https://codeforces.com/contest/1836/problem/B
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
    long long n, k, g;
    cin >> n >> k >> g;
    long long num = g / 2 + (g % 2 == 1);
    if (k * g - (num - 1) * n <= 0)
    {
        cout << k * g << endl;
    }
    else
    {
        long long last = k * g - (num - 1) * (n - 1);
        long long saved = (num - 1) * (n - 1);
        if (last % g < num)
        {
            cout << saved + (last % g) << endl;
        }
        else
        {
            cout << saved - (g - last % g) << endl;
        }
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
