// Problem: C. Cat, Fox and Double Maximum
// Contest: Codeforces - Codeforces Round 945 (Div. 2)
// URL: https://codeforces.com/contest/1973/problem/C
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

void Solve()
{
    int n;
    cin >> n;
    int a[n];
    int ones_pos = 0;
    forn
    {
        cin >> a[i];
        if (a[i] == 1)
        {
            ones_pos = i;
        }
    }
    int flag = ones_pos % 2 && ones_pos != n - 1 && ones_pos != 0;
    set<int> ww;
    forn
    {
        ww.insert(i + 1);
    }
    vector<int> best(n, 0);
    for (int i = 1 + flag; i < n - 1; i += 2)
    {
        best[i] = n + 2 - a[i];
        ww.erase(best[i]);
    }
    forn
    {
        if (best[i] == 0)
        {
            auto t = ww.lower_bound(n + 2 - a[i]);
            t--;
            best[i] = *t;
            ww.erase(best[i]);
        }
    }
    forn
    {
        cout << best[i] << wp;
    }
    cout << endl;

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
