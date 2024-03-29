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
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(m);
    form
    {
        cin >> a[j];
    }
    if (k == 1)
    {
        cout << "YES" << endl;
        return;
    }
    int psum[m];
    psum[0] = a[0];
    for (int i = 1; i < m; i++)
    {
        psum[i] = a[i] + psum[i - 1];
    }
    sort(a.begin(), a.end(), greater<int>());
    for (int i = 0; i < k - 1; i++)
    {
        if (a[i] > ((n - psum[i]) / (k - (i + 1)) + 1))
        {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
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
