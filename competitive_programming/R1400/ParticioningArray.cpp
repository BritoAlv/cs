#include <bits/stdc++.h>
#define endl '\n'
#define wp ' '
#define forn for (int i = 0; i < n; i++)
#define form for (int j = 0; j < m; j++)
#define pb push_back
#define ull unsigned long long
using namespace std;

int a[200000];
int n;

int mcd(int a, int b)
{
    if (a < b)
    {
        return mcd(b, a);
    }
    if (a % b == 0)
    {
        return b;
    }
    else
    {
        return mcd(b, a % b);
    }
}

int simulate(int x)
{
    vector<int> mcds;
    for (int u = 0; u < x; u++)
    {
        int mcdd = -1;
        for (int i = 1; i * x + u < n; i++)
        {
            if (a[(i - 1) * x + u] != a[i * x + u])
            {
                mcdd = (mcdd == -1 ? abs(a[(i - 1) * x + u] - a[i * x + u])
                                   : mcd(mcdd, abs(a[(i - 1) * x + u] - a[i * x + u])));
            }
        }
        if (mcdd != -1)
        {
            mcds.pb(mcdd);
        }
    }
    if (mcds.size() > 0)
    {
        int mcd1 = mcds[0];
        for (int i = 1; i < mcds.size(); i++)
        {
            if (mcd1 == 1)
            {
                break;
            }
            mcd1 = mcd(mcd1, mcds[i]);
        }
        if (mcd1 != 1)
        {
            return 1;
        }
    }
    else
    {
        return 1;
    }
    return 0;
}

void Solve()
{
    cin >> n;
    forn
    {
        cin >> a[i];
    }
    vector<int> work;
    vector<int> divisors;
    for (int i = 1; i <= n; i++)
    {
        if (n % i == 0)
        {
            divisors.pb(i);
        }
    }
    int ans = 0;
    for (auto i : divisors)
    {
        if (simulate(i))
        {
            ans++;
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
