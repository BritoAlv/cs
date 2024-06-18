// Problem: A. Verify Password
// Contest: Codeforces - Educational Codeforces Round 166 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1976/problem/A
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

void BruteSolve()
{
    return;
}

void Solve()
{
    int n;
    cin >> n;
    vector<char> a(n);
    int first_let = -1;
    forn
    {
        cin >> a[i];
        if (isalpha(a[i]) && first_let == -1)
        {
            first_let = i;
        }
    }
    for (int j = 1; j < first_let; j++)
    {
        if ((int)(a[j] - '0') < (int)(a[j - 1] - '0'))
        {
            cout << "NO" << endl;
            return;
        }
    }
    for (int j = first_let + 1; j < n; j++)
    {
        if (a[j] < a[j - 1])
        {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
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
