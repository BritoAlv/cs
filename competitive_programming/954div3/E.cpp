// Problem: E. Beautiful Array
// Contest: Codeforces - Codeforces Round 954 (Div. 3)
// URL: https://codeforces.com/contest/1986/problem/E
// Memory Limit: 256 MB
// Time Limit: 2000 ms
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
#define pi pair<long long, long long>
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
    map<int, vector<long long>> A;
    forn
    {
        int x;
        cin >> x;
        if (A.find(x % k) == A.end())
        {
            A[x % k] = vector<long long>();
        }
        A[x % k].pb(x);
    }
    if (n % 2 == 0)
    {
        long long ans = 0;
        for (auto x : A)
        {
            if (x.second.sz % 2)
            {
                cout << -1 << endl;
                return;
            }
            else
            {
                sort(x.second.begin(), x.second.end());
                for (int i = 1; i < x.second.sz; i += 2)
                {
                    ans += (x.second[i] - x.second[i - 1]) / k;
                }
            }
        }
        cout << ans << endl;
    }
    else
    {
        long long ans = 0;
        int count = 0;
        for (auto x : A)
        {
            if (x.second.sz % 2)
            {
                count += 1;
                if (count >= 2)
                {
                    cout << -1 << endl;
                    return;
                }
                long long best = 1e18;
                sort(x.second.begin(), x.second.end());
                vector<pi> couples(x.second.sz / 2 + 1);
                couples[0].first = 0;
                int ptt = 0;
                for (int i = 1; i < couples.sz; i++)
                {
                    couples[i].first = x.second[ptt + 1] - x.second[ptt];
                    couples[i].first += couples[i - 1].first;
                    ptt += 2;
                }
                couples[couples.sz - 1].second = 0;
                int pt = x.second.sz - 1;
                for (int i = couples.sz - 2; i >= 0; i--)
                {
                    couples[i].second = x.second[pt] - x.second[pt - 1];
                    couples[i].second += couples[i + 1].second;
                    pt -= 2;
                }
                for (auto x : couples)
                {
                    // cout << x.first << wp << x.second << endl;
                    best = min(best, (x.first + x.second) / k);
                }
                ans += best;
            }
            else
            {
                sort(x.second.begin(), x.second.end());
                for (int i = 1; i < x.second.sz; i += 2)
                {
                    ans += (x.second[i] - x.second[i - 1]) / k;
                }
            }
        }
        cout << ans << endl;
    }
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