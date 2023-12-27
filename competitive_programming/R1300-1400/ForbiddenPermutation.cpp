// Problem: B. The Forbidden Permutation
// Contest: Codeforces - Codeforces Round 848 (Div. 2)
// URL: https://codeforces.com/problemset/problem/1778/B
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

void Solve()
{
    int n, m, d;
    cin >> n >> m >> d;
    int a[n];
    map<int, int> pos;
    forn
    {
        cin >> a[i];
        pos[a[i]] = i;
    }
    int b[m];
    form
    {
        cin >> b[j];
    }
    int ans = n;
    for (int i = 1; i < m; i++)
    {
        int pos1 = pos[b[i]];
        int pos2 = pos[b[i - 1]];
        ans = min(ans, max(0, pos1 - pos2));
        if (pos1 > pos2)
        {
            int dif = pos1 - pos2;
            if (dif >= d + 1)
            {
                ans = 0;
            }
            else
            {
                int left = d + 1 - dif;
                if (pos2 + (n - 1 - pos1) >= left)
                {
                    ans = min(ans, left);
                }
            }
        }
    }
    cout << ans << endl;
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
