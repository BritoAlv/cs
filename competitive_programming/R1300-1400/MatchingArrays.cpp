// Problem: C. Matching Arrays
// Contest: Codeforces - CodeTON Round 7 (Div. 1 + Div. 2, Rated, Prizes!)
// URL: https://codeforces.com/contest/1896/problem/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Math Proof:
//
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
#define endl '\n'
#define wp ' '
#define forn for (int i = 0; i < n; i++)
#define form for (int i = 0; i < m; i++)
#define pb push_back

using namespace std;

void Solve()
{
    int n, x;
    cin >> n >> x;
    vector<pair<int, int>> a;
    int aa[n];
    forn
    {
        int c;
        cin >> c;
        aa[i] = c;
        a.pb({c, i});
    }

    sort(a.begin(), a.end());
    vector<pair<int, int>> b;
    forn
    {
        int c;
        cin >> c;
        b.pb({c, i});
    }
    sort(b.begin(), b.end());
    int bb[n];
    forn
    {
        if (i < x)
        {
            bb[a[n - x + i].second] = b[i].first;
        }
        else
        {
            bb[a[n - 1 - i].second] = b[n - 1 - (i - x)].first;
        }
    }

    int exp_beauty = 0;
    forn
    {
        if (aa[i] > bb[i])
        {
            exp_beauty++;
        }
    }
    if (exp_beauty == x)
    {
        cout << "YES" << endl;
        forn
        {
            cout << bb[i] << wp;
        }
        cout << endl;
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