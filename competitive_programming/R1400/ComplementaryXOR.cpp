// Problem: C. Complementary XOR
// Contest: Codeforces - CodeTON Round 3 (Div. 1 + Div. 2, Rated, Prizes!)
// URL: https://codeforces.com/problemset/problem/1750/C
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
    int n;
    cin >> n;
    vector<char> a(n);
    vector<char> b(n);
    forn
    {
        cin >> a[i];
    }
    forn
    {
        cin >> b[i];
    }
    int alternating = 0;
    int equal = 0;
    forn
    {
        if (a[i] == b[i])
        {
            equal = 1;
        }
        else
        {
            alternating = 1;
        }
    }
    if (alternating && equal)
    {
        cout << "NO" << endl;
        return;
    }
    vector<pair<int, int>> ans;
    if (alternating)
    {
        ans.pb({0, n - 1});
        forn
        {
            a[i] = (a[i] == '1' ? '0' : '1');
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (a[i] == '1')
        {
            int start = i;
            int end = i;
            while (end + 1 < n && a[end + 1] == '1')
            {
                end++;
            }
            if (start > 0)
            {
                ans.pb({start - 1, end});
                ans.pb({start - 1, start - 1});
            }
            else if (end == n - 1)
            {
                ans.pb({0, 0});
                ans.pb({1, n - 1});
            }
            else
            {
                ans.pb({start, end + 1});
                ans.pb({end + 1, end + 1});
            }

            i = end;
        }
    }
    cout << "YES" << endl;
    cout << ans.size() << endl;
    for (auto x : ans)
    {
        cout << x.first + 1 << wp << x.second + 1 << endl;
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