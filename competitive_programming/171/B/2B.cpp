#include <bits/stdc++.h>

#define forn for (int i = 0; i < n; i++)
#define endl '\n'
#define wp ' '
#define ll long long
#define pb push_back
#define vi vector<int>
#define pi pair<int, int>

using namespace std;

int w(ll k, vector<ll> &a)
{
    int n = a.size();
    if (n == 1)
        return 1;
    if (n % 2 == 0)
    {
        for (int i = 0; i < n; i += 2)
        {
            if (abs(a[i] - a[i + 1]) > k)
                return 0;
        }
        return 1;
    }
    vi p(n);
    vi s(n);
    for (int i = 1; i < n; i++)
    {
        if (abs(a[i] - a[i - 1]) <= k)
        {
            p[i] = 1;
            if (i > 2)
            {
                p[i] &= p[i - 2];
            }
        }
    }
    for (int i = n - 2; i >= 0; i--)
    {
        if (abs(a[i] - a[i + 1]) <= k)
        {
            s[i] = 1;
            if (i < n - 3)
            {
                s[i] &= s[i + 2];
            }
        }
    }
    if (s[1] || p[n - 2])
        return 1;
    for (int i = 1; i < n - 1; i++)
    {
        if (i % 2 == 0 && p[i - 1] && (i + 2 <= n - 1 && s[i + 1]))
        {

            return 1;
        }
        if (i % 2 == 1 && p[i] && (i + 2 <= n - 1 && s[i + 2]))
        {
            return 1;
        }
    }
    return 0;
}

void solve()
{
    int n;
    cin >> n;
    vector<ll> b(n);
    forn
    {
        cin >> b[i];
    }
    ll l = 0;
    ll g = 1e18;
    while (g - l > 1)
    {
        ll middle = l + (g - l) / 2;
        if (w(middle, b))
        {
            g = middle;
        }
        else
        {
            l = middle + 1;
        }
    }
    while (g - 1 >= 1 && w(g - 1, b))
    {
        g--;
    }
    cout << g << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}
