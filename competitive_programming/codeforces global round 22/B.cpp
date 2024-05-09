// Problem: B. Prefix Sum Addicts
// Contest: Codeforces - Codeforces Global Round 22
// URL: https://codeforces.com/contest/1738/problem/B
// Memory Limit: 512 MB
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
    int n, k;
    cin >> n >> k;
    vector<int> last_prefix(k);
    fork
    {
        cin >> last_prefix[i];
    }
    vector<int> a(n);
    int to_find = n - k + 1;
    int part = last_prefix[0] / to_find;
    int pt1 = n - 1;
    int pt2 = k - 1;
    while (pt2 >= 1)
    {
        a[pt1--] = last_prefix[pt2] - last_prefix[pt2 - 1];
        pt2--;
    }
    while (pt1 >= 0)
    {
        a[pt1--] = part;
    }
    int to_distribute = last_prefix[0] % to_find;
    if (last_prefix[0] >= 0)
    {
        for (int j = n - k; j >= 0 && to_distribute > 0; j--)
        {
            a[j] += 1;
            to_distribute--;
        }
    }
    else
    {
        for (int j = 0; j <= n - k && to_distribute > 0; j++)
        {
            a[j] -= 1;
            to_distribute--;
        }
    }
    forn
    {
        if (i < n - 1 && a[i] > a[i + 1])
        {
            cout << "No" << endl;
            return;
        }
    }
    cout << "Yes" << endl;
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