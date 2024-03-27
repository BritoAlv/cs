// Problem: C. Sum on Subarrays
// Contest: Codeforces - Educational Codeforces Round 145 (Rated for Div. 2)
// URL: https://codeforces.com/problemset/problem/1809/C
// Memory Limit: 512 MB
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

int func(int n)
{
    return (n * (n + 1)) / 2;
}

vector<int> solve(int n, int k)
{
    if (n == 0)
    {
        return {};
    }
    else if (n == 1)
    {
        if (k == 0)
        {
            return {-1};
        }
        else if (k == 1)
        {
            return {1};
        }
    }
    else if (k > func(n - 1))
    {
        vector<int> ans1 = solve(n, func(n) - k);
        forn
        {
            ans1[i] = -ans1[i];
        }
        return ans1;
    }
    else
    {
        int st = n - 1; // 3
        while (func(st) >= k && st > 0)
        {
            st--;
        }
        vector<int> ans1 = solve(st + 1, k);
        vector<int> ans2(n, -1000);
        int max_sum = 0;
        for (int i = 0; i < st + 1; i++)
        {
            ans2[i] = ans1[i];
        }
        for (int i = st; i >= 0; i--)
        {
            if (ans2[i] >= 0)
            {
                max_sum += ans2[i];
            }
        }
        for (int i = st + 1; i < n; i++)
        {
            ans2[i] = -max_sum - 1;
        }
        return ans2;
    }
}

void Solve()
{
    int n, k;
    cin >> n >> k;
    auto ans = solve(n, k);
    for (auto x : ans)
    {
        cout << x << wp;
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