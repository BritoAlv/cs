// Problem: C. Chamo and Mocha's Array
// Contest: Codeforces - Codeforces Round 947 (Div. 1 + Div. 2)
// URL: https://codeforces.com/contest/1975/problem/C
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

int median(int x, int y, int z)
{
    int a[3];
    a[0] = x;
    a[1] = y;
    a[2] = z;
    sort(a, a + 3);
    return a[1];
}

void Solve()
{
    int n;
    cin >> n;
    int a[n];
    forn
    {
        cin >> a[i];
    }
    vector<int> candidates;
    for (int i = 1; i < n - 1; i++)
    {
        candidates.pb(median(a[i - 1], a[i], a[i + 1]));
    }
    if (candidates.sz == 0)
    {
        cout << min(a[0], a[1]) << endl;
        return;
    }
    sort(candidates.begin(), candidates.end());
    cout << candidates.back() << endl;
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
