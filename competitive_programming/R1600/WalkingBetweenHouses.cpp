// Problem: D. Walking Between Houses
// Contest: Codeforces - Codeforces Round 501 (Div. 3)
// URL: https://codeforces.com/contest/1015/problem/D
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

int n, k;
int actual = 1;
ull s;
int get_next_city(int distance)
{
    if (actual + distance <= n)
    {
        return actual += distance;
    }
    else
    {
        return actual -= distance;
    }
}

void Solve()
{
    cin >> n >> k >> s;
    vector<int> ans;
    while (k > 0 && s > k - 1 + (n - 1))
    {
        ans.pb(get_next_city(n - 1));
        s -= (n - 1);
        k--;
    }
    // at this point is sure that s <= (k-1) + (n-1).
    if (k > 0 && s > (k - 1))
    {
        // do (k-1) 1's'
        // do in one step s - (k-1).
        ans.pb(get_next_city(s - (k - 1)));
        s = (k - 1);
        k--;
    }
    while (k > 0)
    {
        ans.pb(get_next_city(1));
        k--;
        s--;
    }
    if (s == 0 && k == 0)
    {
        cout << "YES" << endl;
        for (auto x : ans)
        {
            cout << x << wp;
        }
        cout << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
    return;
}

int main()
{
    int test_cases = 1;
    while (test_cases > 0)
    {
        Solve();
        test_cases--;
    }
    return 0;
}