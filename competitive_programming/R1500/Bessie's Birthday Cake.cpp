// Problem: C1. Bessie's Birthday Cake (Easy Version)
// Contest: Codeforces - CodeTON Round 8 (Div. 1 + Div. 2, Rated, Prizes!)
// URL: https://codeforces.com/contest/1942/problem/C1
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
    int n, x, y;
    cin >> n >> x >> y;
    vector<int> v(x);
    for (int i = 0; i < x; i++)
    {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    int def_ans = max(0, x - 2);
    vector<int> odd_segms;
    vector<int> even_segms;
    for (int i = 0; i < x - 1; i++)
    {
        if ((v[i + 1] - v[i]) % 2 == 0)
        {
            if (-v[i] + v[i + 1] - 1 <= 1)
            {
                def_ans++;
            }
            else
            {
                odd_segms.pb(-v[i] + v[i + 1] - 1);
            }
        }
        else
        {
            if (-v[i] + v[i + 1] - 1 > 0)
            {
                even_segms.pb(-v[i] + v[i + 1] - 1);
            }
        }
    }

    if ((n - v[x - 1] + v[0]) % 2 == 0)
    {
        if ((n - v[x - 1] + v[0]) - 1 <= 1)
        {
            def_ans++;
        }
        else
        {
            odd_segms.pb((n - v[x - 1] + v[0]) - 1);
        }
    }
    else
    {
        if ((n - v[x - 1] + v[0]) - 1 > 0)
        {
            even_segms.pb((n - v[x - 1] + v[0]) - 1);
        }
    }
    sort(odd_segms.begin(), odd_segms.end());
    sort(even_segms.begin(), even_segms.end());
    int pt1 = 0;
    while (y > 0 && pt1 < odd_segms.sz)
    {
        int taken = min(y, odd_segms[pt1] / 2);
        def_ans += 2 * taken;
        if (odd_segms[pt1] / 2 == taken)
        {
            def_ans++;
        }
        y -= taken;
        pt1++;
    }
    int pt2 = 0;
    while (y > 0 && pt2 < even_segms.sz)
    {
        int taken = min(y, even_segms[pt2] / 2);
        def_ans += 2 * taken;
        y -= taken;
        pt2++;
    }
    cout << def_ans << endl;
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
