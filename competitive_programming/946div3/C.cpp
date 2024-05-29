// Problem: C. Beautiful Triple Pairs
// Contest: Codeforces - Codeforces Round 946 (Div. 3)
// URL: https://codeforces.com/contest/1974/problem/C
// Memory Limit: 256 MB
// Time Limit: 4000 ms
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

void Solve()
{
    int n;
    cin >> n;
    long long a[n];
    forn
    {
        cin >> a[i];
    }
    vector<vector<long long>> triplets1;
    vector<vector<long long>> triplets2;
    vector<vector<long long>> triplets3;
    for (int i = 1; i < n - 1; i++)
    {
        triplets1.pb({a[i - 1], a[i], a[i + 1]});
        triplets2.pb({a[i], a[i + 1], a[i - 1]});
        triplets3.pb({a[i + 1], a[i - 1], a[i]});
    }
    ull ans = 0;
    sort(triplets1.begin(), triplets1.end());
    sort(triplets2.begin(), triplets2.end());
    sort(triplets3.begin(), triplets3.end());
    vector<vector<vector<long long>>> triplets;
    triplets.pb(triplets1);
    triplets.pb(triplets2);
    triplets.pb(triplets3);
    for (auto x : triplets)
    {
        for (int i = 0; i < x.sz; i++)
        {
            int ed = i;
            while (ed + 1 < x.sz && (x[ed + 1][0] == x[i][0]) && (x[ed + 1][1] == x[i][1]))
            {
                ed += 1;
            }
            map<long long, long long> counts;
            for (int j = i; j <= ed; j++)
            {
                if (counts.find(x[j][2]) == counts.end())
                {
                    counts[x[j][2]] = 0;
                }
                counts[x[j][2]]++;
            }
            ull aport = 0;
            ull summ = 0;
            for (auto y : counts)
            {
                aport -= (y.second * (y.second - 1)) / 2;
                summ += y.second;
            }
            aport += (summ * (summ - 1)) / 2;
            ans += aport;
            i = ed;
        }
    }
    cout << ans << endl;
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