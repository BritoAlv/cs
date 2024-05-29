// Problem: B. Tape
// Contest: Codeforces - Codeforces Global Round 1
// URL: https://codeforces.com/contest/1110/problem/B
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
#define fork for (int i = 0; i < k; i++)
#define pb push_back
#define ull unsigned long long
#define pi pair<int, int>
#define sz size()
// je m appelle Alvaro j ai 21 ans.

using namespace std;

void Solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<pi> difs;
    int a[n];
    forn
    {
        cin >> a[i];
        if (i > 0)
        {
            difs.pb({a[i] - a[i - 1], i});
        }
    }
    sort(difs.begin(), difs.end());
    set<int> marked;
    for (int j = n - k; j < n - 1; j++)
    {
        marked.insert(difs[j].second);
    }
    ull ans = 0;
    forn
    {
        int ed = i;
        while (ed + 1 < n && marked.find(ed + 1) == marked.end())
        {
            ed++;
        }
        ans += a[ed] - a[i] + 1;
        i = ed;
    }
    cout << ans << endl;
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int test_cases = 1;
    while (test_cases-- > 0)
    {
        Solve();
    }
    return 0;
}
