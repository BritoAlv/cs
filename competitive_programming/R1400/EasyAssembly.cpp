// Problem: E. Easy Assembly
// Contest: Codeforces - 2022-2023 ICPC, NERC, Northern Eurasia Onsite (Unrated, Online Mirror, ICPC Rules, Teams
// Preferred) URL: https://codeforces.com/problemset/problem/1773/E Memory Limit: 1024 MB Time Limit: 3000 ms Math
// Proof:
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
    vector<vector<int>> tow;
    vector<int> values;
    forn
    {
        int k;
        cin >> k;
        tow.pb(vector<int>(k));
        for (int j = 0; j < k; j++)
        {
            cin >> tow[i][j];
            values.pb(tow[i][j]);
        }
    }
    long long split = 0;
    sort(values.begin(), values.end());
    map<int, int> corr;
    for (int i = 0; i < values.size(); i++)
    {
        corr[values[i]] = (i == values.size() - 1 ? -1 : values[i + 1]);
    }
    forn
    {
        for (int j = 0; j < tow[i].size() - 1; j++)
        {
            if (tow[i][j + 1] != corr[tow[i][j]])
            {
                split++;
            }
        }
    }
    cout << split << wp << n + split - 1 << endl;
    return;
}

int main()
{
    int test_cases = 1;
    while (test_cases > 0)
    {
        Solve();
        test_cases--;
    }
    return 0;
}
