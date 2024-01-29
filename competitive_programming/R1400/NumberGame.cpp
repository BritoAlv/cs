// Problem: C. Number Game
// Contest: Codeforces - Educational Codeforces Round 138 (Rated for Div. 2)
// URL: https://codeforces.com/problemset/problem/1749/C
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
using namespace std;

int a[101];
int n;
int simulate(int k)
{
    vector<int> values;
    forn
    {
        if (a[i] > k)
        {
            break;
        }
        values.pb(a[i]);
    }
    int round = 0;
    while (true)
    {
        int found = 0;
        vector<int> n_val;
        for (int j = values.size() - 1; j >= 0; j--)
        {
            if (values[j] <= k - round)
            {
                for (int l = 0; l < values.size(); l++)
                {
                    if (l != j && l != 0)
                    {
                        n_val.pb(values[l]);
                    }
                }
                found = 1;
                break;
            }
        }
        if (!found)
        {
            break;
        }
        else
        {
            values = n_val;
            round++;
        }
    }
    return round == k;
}

void Solve()
{
    cin >> n;
    int p = 0;
    forn
    {
        cin >> a[i];
        p += (a[i] == 1);
    }
    sort(a, a + n);
    // alice can play as long as posible. so simulate.
    for (int i = 1; i <= 101; i++)
    {
        if (!simulate(i))
        {
            cout << i - 1 << endl;
            break;
        }
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
