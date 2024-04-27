// Problem: C. Ticket Hoarding
// Contest: Codeforces - Codeforces Global Round 25
// URL: https://codeforces.com/contest/1951/problem/C
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
    int n, m, k;
    cin >> n >> m >> k;
    vector<pi> arr;
    forn
    {
        int r;
        cin >> r;
        arr.pb({r, i});
    }
    sort(arr.begin(), arr.end());
    int ceil = k / m + ((k % m) != 0);
    vector<pi> selected;
    for (int i = 0; i < ceil; i++)
    {
        selected.pb({arr[i].second, arr[i].first});
    }
    int pos_max = 0;
    sort(selected.begin(), selected.end());
    for (int i = 1; i < selected.sz; i++)
    {
        if (selected[i].second > selected[pos_max].second)
        {
            pos_max = i;
        }
    }
    ull ans = 0;
    ull prev = 0;
    for (int i = 0; i < selected.sz; i++)
    {
        int t_c = m;
        if (i == pos_max && (k % m != 0))
        {
            t_c = k % m;
        }
        ans += t_c * (selected[i].second + prev);
        prev += t_c;
    }
    cout << ans << endl;
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
