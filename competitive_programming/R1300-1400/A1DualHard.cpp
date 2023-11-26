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

vector<pair<int, int>> increase_positive(vector<int> a)
{
    int n = a.size();
    vector<pair<int, int>> ops;
    int mod_index = -1;
    forn
    {
        if (a[i] > 0 && mod_index == -1)
        {
            mod_index = i;
        }
        else if (mod_index >= 0 && a[i] > a[mod_index])
        {
            mod_index = i;
        }
    }
    if (mod_index != -1)
    {
        forn
        {
            while (abs(a[i]) > abs(a[mod_index]))
            {
                a[mod_index] *= 2;
                ops.pb({mod_index + 1, mod_index + 1});
            }
        }

        for (int i = 1; i < n; i++)
        {
            while (a[i] < a[i - 1])
            {
                a[i] += a[mod_index];
                ops.pb({i + 1, mod_index + 1});
                if (a[i] > 0 && abs(a[i]) > abs(a[mod_index]))
                {
                    mod_index = i;
                }
            }
        }
    }
    return ops;
}

vector<pair<int, int>> increase_negative(vector<int> a)
{
    int n = a.size();
    vector<pair<int, int>> ops;
    int mod_index = -1;
    forn
    {
        if (a[i] < 0 && mod_index == -1)
        {
            mod_index = i;
        }
        else if (mod_index >= 0 && a[i] < a[mod_index])
        {
            mod_index = i;
        }
    }
    if (mod_index != -1)
    {
        forn
        {
            while (abs(a[i]) > abs(a[mod_index]))
            {
                a[mod_index] *= 2;
                ops.pb({mod_index + 1, mod_index + 1});
            }
        }
        for (int i = n - 1; i > 0; i--)
        {
            while (a[i] < a[i - 1])
            {
                a[i - 1] += a[mod_index];
                ops.pb({i, mod_index + 1});
                if (a[i - 1] < 0 && abs(a[i - 1]) > abs(a[mod_index]))
                {
                    mod_index = i - 1;
                }
            }
        }
    }

    return ops;
}

void Solve()
{
    int n;
    cin >> n;
    vi a(n);
    forn
    {
        cin >> a[i];
    }
    vector<pair<int, int>> a1 = increase_positive(a);
    vector<pair<int, int>> a2 = increase_negative(a);

    if (a1.size() > 0 && (a2.size() == 0 || a1.size() <= a2.size()))
    {
        cout << a1.size() << endl;
        for (auto x : a1)
        {
            cout << x.first << wp << x.second << endl;
        }
    }
    else if (a2.size() > 0 && (a1.size() == 0 || a2.size() < a1.size()))
    {
        cout << a2.size() << endl;
        for (auto x : a2)
        {
            cout << x.first << wp << x.second << endl;
        }
    }
    else
    {
        cout << 0 << endl;
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
