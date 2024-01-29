// Problem: D. 01 Tree
// Contest: Codeforces - Hello 2024
// URL: https://codeforces.com/contest/1919/problem/D
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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
using namespace std;

void Solve()
{
    int n;
    cin >> n;
    int a[n];
    forn
    {
        cin >> a[i];
    }
    int zero_position = -1;
    forn
    {
        if (a[i] == 0)
        {
            if (zero_position == -1)
            {
                zero_position = i;
            }
            else
            {
                cout << "NO" << endl;
                return;
            }
        }
    }
    if (zero_position == -1)
    {
        cout << "NO" << endl;
        return;
    }
    for (int i = zero_position - 1; i >= 0; i--)
    {
        if ((a[i] - a[i + 1] <= 1) && (a[i] - a[i + 1] >= 0))
        {
        }
        else
        {
            cout << "NO" << endl;
            return;
        }
    }
    for (int i = zero_position + 1; i < n; i++)
    {
        if ((a[i] - a[i - 1] >= 0) && (a[i] - a[i - 1] <= 1))
        {
        }
        else
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
    int test_cases;
    cin >> test_cases;
    while (test_cases > 0)
    {
        Solve();
        test_cases--;
    }
    return 0;
}
