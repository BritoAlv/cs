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

void BruteSolve()
{
    return;
}

void Solve()
{
    int n, k;
    cin >> n >> k;
    vector<char> a(n);
    forn
    {
        cin >> a[i];
    }
    vector<int> p(n, 0);
    forn
    {
        if (i == 0 || a[i] != a[i - 1])
        {
            p[i] = 1;
        }
        else
        {
            p[i] = p[i - 1] + 1;
        }
    }
    vector<int> s(n, 0);
    for (int i = n - 1; i >= 0; i--)
    {
        if (i == n - 1 || a[i] != a[i + 1])
        {
            s[i] = 1;
        }
        else
        {
            s[i] = s[i + 1] + 1;
        }
    }
    vector<int> pp(n, 0);
    for (int i = n - 1; i >= 0; i--)
    {
        if (i > n - k)
        {
            pp[i] = i;
        }
        else if (i == n - k)
        {
            pp[i] = (s[i] == k ? n : n - k);
        }
        else
        {
            pp[i] = (s[i] == k ? pp[i + k] : i);
        }
    }
    vector<int> ss(n, 0);
    forn
    {
        if (i < k - 1)
        {
            ss[i] = i;
        }
        else if (i == k - 1)
        {
            ss[i] = (p[i] == k ? -1 : i);
        }
        else
        {
            ss[i] = (p[i] == k ? ss[i - k] : i);
        }
    }

    for (int t = 0; t < n - 1; t++)
    {
        int cp = pp[t + 1];
        if (cp <= n - k)
        {
            continue;
        }
        else
        {
            if (cp == n)
            {
                if (a[t] != a[n - 1])
                {
                    int pc = ss[t];
                    if (pc == -1)
                    {
                        cout << t + 1 << endl;
                        return;
                    }
                }
            }
            else if (p[t] + s[cp] == k && a[t] == a[cp])
            {
                int pc = (t - p[t] >= 0 ? ss[t - p[t]] : t - p[t]);
                if (pc == -1)
                {
                    cout << t + 1 << endl;
                    return;
                }
            }
        }
    }
    cout << -1 << endl;
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