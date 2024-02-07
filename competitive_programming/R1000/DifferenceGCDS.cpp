// Problem: B. Difference of GCDs
// Contest: Codeforces - Codeforces Round 808 (Div. 2)
// URL: https://codeforces.com/contest/1708/problem/B
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
#define pb push_back
#define ull unsigned long long

// je m appelle Alvaro j ai 21 ans.

using namespace std;

void Solve()
{
    int n, l, r;
    cin >> n >> l >> r;
    // mcd(i, ai) son todos distintos.
    vector<int> ans(n);
    ans[0] = l;
    for (int i = 1; i < n; i++)
    {
        int num = i + 1;
        if (r - r % num >= l)
        {
            ans[i] = r - r % num;
        }
        else if (num + (l - l % num) <= r)
        {
            ans[i] = num + (l - l % num);
        }
        else
        {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
    forn
    {
        cout << ans[i] << wp;
    }
    cout << endl;

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
