// Problem: E. Turtle vs. Rabbit Race: Optimal Trainings
// Contest: Codeforces - Codeforces Round 929 (Div. 3)
// URL: https://codeforces.com/problemset/problem/1933/E
// Memory Limit: 256 MB
// Time Limit: 5000 ms
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

long long a[100000];

long long fc(int l, int r, int u)
{
    long long sections = a[r] - (l > 0 ? a[l - 1] : 0);
    long long ans = sections * u;
    ans -= (sections * (sections - 1)) / 2;
    return ans;
}

void Solve()
{
    int n;
    cin >> n;
    forn
    {
        cin >> a[i];
        if (i > 0)
        {
            a[i] += a[i - 1];
        }
    }
    int q;
    cin >> q;
    while (q > 0)
    {
        int l, u;
        cin >> l >> u;
        l--;
        if (n - 1 == l || fc(l, l, u) >= fc(l, l + 1, u))
        {
            cout << l + 1 << wp;
        }
        else
        {
            int st = l;
            int ed = n - 1;

            while (ed - st > 1)
            {
                int middle = st + (ed - st) / 2;
                if (fc(l, middle - 1, u) < fc(l, middle, u))
                {
                    st = middle;
                }
                else
                {
                    ed = middle;
                }
            }
            pair<long long, int> maxx = {fc(l, max(st - 2, l), u), max(st - 2, l)};
            for (int i = max(st - 2, l); i <= min(ed + 1, n - 1); i++)
            {
                if (fc(l, i, u) > maxx.first)
                {
                    maxx = {fc(l, i, u), i};
                }
            }
            cout << maxx.second + 1 << wp;
        }
        q--;
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
