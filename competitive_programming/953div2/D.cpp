// Problem: D. Elections
// Contest: Codeforces - Codeforces Round 953 (Div. 2)
// URL: https://codeforces.com/contest/1978/problem/D
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
    long long n, c;
    cin >> n >> c;
    vector<pi> queries;
    vector<long long> a(n);
    forn
    {
        cin >> a[i];
    }
    set<pi> A;
    vector<long long> psums(n);
    psums[0] = a[0];
    for (int i = 1; i < n; i++)
    {
        psums[i] = psums[i - 1] + a[i];
    }
    queries.pb({0, a[0] + c});
    A.insert({a[0], 0});
    for (int j = 1; j < n; j++)
    {
        if (a[0] + c >= a[j])
        {
            queries.pb({j, psums[j] + c});
        }
        else
        {
            pi next = {a[j], -1};
            // find lg st : {a[j], m};
            auto sr = A.lower_bound(next);
            if (sr != A.end())
            {
                queries.pb({j, psums[j] + c});
            }
            else
            {
                queries.pb({0, a[j]});
            }
        }
        A.insert({a[j], j});
    }
    set<pair<long long, long long>> B;
    vector<int> ans(n, 0);
    forn
    {
        ans[i] = queries[i].first;
    }
    for (int i = n - 1; i >= 0; i--)
    {
        if (B.sz > 0)
        {
            long long maxx = (*B.rbegin()).first;
            if (maxx > queries[i].second)
            {
                if (queries[i].first == 0)
                {
                    ans[i] += i;
                    if (maxx > psums[i] + c)
                    {
                        ans[i]++;
                    }
                }
                else
                {
                    ans[i]++;
                }
            }
        }
        B.insert({a[i], i});
    }
    forn
    {
        cout << ans[i] << wp;
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