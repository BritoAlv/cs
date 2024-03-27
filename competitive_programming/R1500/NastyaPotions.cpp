// Problem: E. Nastya and Potions
// Contest: Codeforces - Codeforces Round 888 (Div. 3)
// URL: https://codeforces.com/problemset/problem/1851/E
// Memory Limit: 256 MB
// Time Limit: 3000 ms
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
    int n, k;
    cin >> n >> k;
    int prices[n];
    forn
    {
        cin >> prices[i];
    }
    fork
    {
        int t;
        cin >> t;
        prices[--t] = 0;
    }
    vector<vector<int>> recipe(n);
    vector<ull> costs(n, 0);
    map<int, vector<int>> affected;
    forn
    {
        int size;
        cin >> size;
        for (int q = 0; q < size; q++)
        {
            int r;
            cin >> r;
            recipe[i].pb(--r);
            costs[i] += prices[r];
            if (affected.find(r) == affected.end())
            {
                affected[r] = vector<int>();
            }
            affected[r].pb(i);
        }
    }
    set<pi> pq;
    forn
    {
        if (recipe[i].sz > 0)
        {
            pq.insert({costs[i], i});
        }
    }
    while (pq.size() > 0)
    {
        auto top = *(pq.begin());
        int i = top.second;
        pq.erase(top);
        if (costs[i] < prices[i])
        {
            for (auto x : affected[i])
            {
                if (pq.find({costs[x], x}) != pq.end())
                {
                    pq.erase(pq.find({costs[x], x}));
                }
                costs[x] -= (prices[i] - costs[i]);
                pq.insert({costs[x], x});
            }
            prices[i] = costs[i];
        }
    }
    forn
    {
        cout << prices[i] << wp;
    }
    cout << endl;
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