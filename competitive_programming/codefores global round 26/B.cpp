// Problem: B. Large Addition
// Contest: Codeforces - Codeforces Global Round 26
// URL: https://codeforces.com/contest/1984/problem/B
// Memory Limit: 256 MB
// Time Limit: 1000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
#define endl '\n'
#define wp ' '
#define forn for (int i = 0; i < n; i++)
#define form for (int j = 0; j < m; j++)
#define fork for (int i = 0; i < k; i++)
#define pb push_back
#define ull unsigned long long
#define pi pair<int, int>
#define sz size()
// je m appelle Alvaro j ai 21 ans.

using namespace std;

void BruteSolve()
{
    return;
}

void Solve()
{
    long long x;
    cin >> x;
    long long xx = x;
    int digits = 0;
    while (xx > 0)
    {
        digits += 1;
        xx /= 10;
    }
    long long number1 = 0;
    long long number2 = 0;
    for (int i = 0; i < digits - 1; i++)
    {
        number1 *= 10;
        number1 += 5;

        number2 *= 10;
        number2 += 9;
    }
    if (x >= 2 * number1 && x <= 2 * number2)
    {
        xx = x - 2 * number1;
        while (xx > 0)
        {
            if (xx % 10 == 9)
            {
                cout << "NO" << endl;
                return;
            }
            xx /= 10;
        }
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int test_cases;
    cin >> test_cases;
    while (test_cases-- > 0)
    {
        Solve();
    }
    return 0;
}
