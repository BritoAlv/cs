// Problem: C. Min Max Sort
// Contest: Codeforces - Educational Codeforces Round 142 (Rated for Div. 2)
// URL: https://codeforces.com/problemset/problem/1792/C
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
    int pos[n + 1];
    forn
    {
        cin >> a[i];
        pos[a[i]] = i;
    }
    int nn_start_l = n / 2 + (n % 2);
    int nn_start_r = n / 2 + 1;
    int minn = pos[nn_start_l];
    int maxx = pos[nn_start_r];
    if (minn > maxx)
    {
        cout << n / 2 << endl;
        return;
    }
    while (minn <= maxx)
    {
        if (nn_start_l - 1 >= 1 && nn_start_r + 1 <= n && pos[nn_start_l - 1] < minn && pos[nn_start_r + 1] > maxx)
        {
            nn_start_l--;
            nn_start_r++;
            minn = pos[nn_start_l];
            maxx = pos[nn_start_r];
        }
        else
        {
            break;
        }
    }
    cout << nn_start_l - 1 << endl;
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
