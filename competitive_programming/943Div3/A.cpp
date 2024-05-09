// Problem: A. Maximize?
// Contest: Codeforces - Codeforces Round 943 (Div. 3)
// URL: https://codeforces.com/contest/1968/problem/A
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Math Proof:
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

int mcd(int a, int b)
{
    if (a < b)
    {
        return mcd(b, a);
    }
    if (a % b == 0)
    {
        return b;
    }
    else
    {
        return mcd(b, a % b);
    }
}

void Solve()
{
    int x;
    cin >> x;
    int best = 1;
    for (int i = 2; i < x; i++)
    {
        if (mcd(x, i) + i > mcd(x, best) + best)
        {
            best = i;
        }
    }
    cout << best << endl;
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
