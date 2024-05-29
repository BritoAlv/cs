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
    set<pi> a;
    int pos[n];
    forn
    {
        int x;
        cin >> x;
        pos[x - 1] = i;
        a.insert({i, x});
    }
    for (int i = n; i >= 2; i--)
    {
        auto pt = *(a.lower_bound({pos[i - 1], 0}));
        if (pt == *(a.rbegin()))
        {
            cout << "YES" << endl;
            return;
        }
        else
        {
            if (pt == *(a.begin()))
            {
                cout << "NO" << endl;
                return;
            }
            else
            {
                a.erase(pt);
            }
        }
    }
    cout << "YES" << endl;
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
