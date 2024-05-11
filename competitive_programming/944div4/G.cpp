// Problem: G. XOUR
// Contest: Codeforces - Codeforces Round 944 (Div. 4)
// URL: https://codeforces.com/contest/1971/problem/G
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
    vector<pi> a(n);
    forn
    {
        int x;
        cin >> x;
        a[i].first = x % (4);
        a[i].second = x - a[i].first;
    }
    map<int, set<pi>> comp;
    forn
    {
        if (comp.find(a[i].second) == comp.end())
        {
            comp[a[i].second] = set<pi>();
        }
        comp[a[i].second].insert({a[i].first + a[i].second, i});
    }
    vector<int> b(n);
    for (auto m : comp)
    {
        set<int> index;
        queue<int> values;
        for (auto w : m.second)
        {
            values.push(w.first);
            index.insert(w.second);
        }
        for (auto w : index)
        {
            b[w] = values.front();
            values.pop();
        }
    }
    forn
    {
        cout << b[i] << wp;
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
