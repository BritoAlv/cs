// Problem: A1. Dual (Easy Version)
// Contest: Codeforces - Codeforces Round 889 (Div. 1)
// URL: https://codeforces.com/contest/1854/problem/A1
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
#define vi vector<int>

using namespace std;

void print_vector(vector<int> &a)
{
    for (auto x : a)
    {
        cout << x << wp;
    }
    cout << endl;
}

void print_yes(int a)
{
    if (a != 0)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
}

void Solve()
{
    int n;
    cin >> n;
    int a[n];
    int mod_max = 0;
    int sign = 0;
    int index = -1;
    forn
    {
        cin >> a[i];
        if (abs(a[i]) > mod_max)
        {
            mod_max = abs(a[i]);
            sign = (a[i] > 0 ? 1 : -1);
            index = i;
        }
    }
    if (mod_max == 0)
    {
        cout << 0 << endl;
        return;
    }
    vector<pair<int, int>> ops;
    if (sign == 1)
    {
        ops.pb({index + 1, index + 1});
        forn
        {
            if (i > 0 && a[i - 1] > a[i])
            {
                a[i] += mod_max;
                ops.pb({i + 1, index + 1});
            }
        }
    }
    else
    {
        ops.pb({index + 1, index + 1});
        for (int i = n - 1; i >= 0; i--)
        {
            if (i > 0 && a[i - 1] > a[i])
            {
                a[i - 1] -= mod_max;
                ops.pb({i, index + 1});
            }
        }
    }
    cout << ops.size() << endl;
    for (auto x : ops)
    {
        cout << x.first << wp << x.second << endl;
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