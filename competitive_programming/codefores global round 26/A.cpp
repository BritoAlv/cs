// Problem: A. Strange Splitting
// Contest: Codeforces - Codeforces Global Round 26
// URL: https://codeforces.com/contest/1984/problem/0
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
    int n;
    cin >> n;
    int a[n];
    forn
    {
        cin >> a[i];
    }
    if (a[0] == a[n - 1])
    {
        cout << "NO" << endl;
        return;
    }
    else
    {
        cout << "YES" << endl;
        if (a[1] == a[0])
        {
            cout << "B";
            for (int i = 1; i < n; i++)
            {
                cout << "R";
            }
            cout << endl;
        }
        else
        {
            for (int i = 0; i < n - 1; i++)
            {
                cout << "R";
            }
            cout << "B";
            cout << endl;
        }
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
