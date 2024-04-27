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
    vector<int> count(n, 0);
    forn
    {
        int t;
        cin >> t;
        count[t]++;
    }
    if (count[0] == 0)
    {
        cout << 0 << endl;
        return;
    }
    int ans = 1;
    int flag = 0;
    for (; ans <= n; ans++)
    {
        if (!flag)
        {
            if (count[ans - 1] > 0 && (ans - 2 < 0 || count[ans - 2] >= 2))
            {
            }
            else
            {
                break;
            }
        }
        else
        {
            if (count[ans - 1] < 2)
            {
                break;
            }
        }
        if (count[ans - 1] == 1)
        {
            flag = true;
        }
    }
    cout << ans - 1 << endl;
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