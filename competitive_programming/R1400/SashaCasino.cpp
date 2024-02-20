// Problem: C. Sasha and the Casino
// Contest: Codeforces - Codeforces Round 926 (Div. 2)
// URL: https://codeforces.com/contest/1929/problem/C
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
#define pb push_back
#define ull unsigned long long

// je m appelle Alvaro j ai 21 ans.

using namespace std;

ull ceill(ull A, ull d)
{
    return A / d + 1;
}

void Solve()
{
    ull k, x, a;
    cin >> k >> x >> a;
    vector<ull> smaller(x);
    smaller[0] = 1;
    ull sum = 1;
    for (int i = 1; i < x; i++)
    {
        smaller[i] = ceill(sum, k - 1);
        sum += smaller[i];
        if (sum >= a)
        {
            cout << "NO" << endl;
            return;
        }
    }
    if (a * (k - 1) > sum * k)
    {
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
    int test_cases;
    cin >> test_cases;
    while (test_cases > 0)
    {
        Solve();
        test_cases--;
    }
    return 0;
}
