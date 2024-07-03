// Problem: G. Money Buys Less Happiness Now
// Contest: Codeforces - Codeforces Round 946 (Div. 3)
// URL: https://codeforces.com/contest/1974/problem/G
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
    int n, x;
    cin >> n >> x;
    vector<int> c(n);
    forn
    {
        cin >> c[i];
    }
    long long salary = 0;
    set<pi> used;
    int hap = 0;
    forn
    {
        if (salary >= c[i])
        {
            salary -= c[i];
            used.insert({c[i], i});
            hap++;
        }
        else if (used.sz > 0 && (*used.rbegin()).first > c[i])
        {
            auto pt = *used.rbegin();
            used.erase(pt);
            salary += pt.first - c[i];
            used.insert({c[i], i});
        }
        salary += x;
    }
    cout << hap << endl;
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
