// Problem: B. Two Out of Three
// Contest: Codeforces - Codeforces Round 908 (Div. 2)
// URL: https://codeforces.com/contest/1894/problem/B
// Memory Limit: 512 MB
// Time Limit: 3000 ms
// Math Proof:
//
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
#define endl '\n'
#define wp ' '
#define forn for (int i = 0; i < n; i++)
#define pb push_back

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
    vector<vector<int>> name(100);
    forn
    {
        int t;
        cin >> t;
        name[t - 1].pb(i);
    }
    vector<int> go;
    for (int i = 0; i < 100; i++)
    {
        if (name[i].size() >= 2)
        {
            go.pb(i);
        }
    }

    if (go.size() >= 2)
    {
        int b[n];
        forn
        {
            b[i] = 1;
        }
        b[name[go[0]][0]] = 2;
        b[name[go[1]][0]] = 3;
        forn
        {
            cout << b[i] << wp;
        }
        cout << endl;
    }
    else
    {
        cout << -1 << endl;
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
