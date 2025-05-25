// Problem: B. Set of Strangers
// Contest: Codeforces - Educational Codeforces Round 174 (Rated for Div. 2)
// URL: https://codeforces.com/contest/2069/problem/B
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Math Proof:
//
// Powered by CP Editor (https://cpeditor.org)

// je m appelle Alvaro Brito. J ai 22 ans.
#include <bits/stdc++.h>
#define endl '\n'
#define wp ' '
#define fori(a, b) for (int i = a; i <= b; i++)
#define forj(a, b) for (int j = a; j <= b; j++)
#define pb push_back
#define ull unsigned long long
#define pi pair<int, int>
#define ll long long
#define pl pair<ll, ll>
#define vi vector<int>
#define vl vector<ll>

int test_cases;
using namespace std;

void Solve()
{
    int n, m;
    cin >> n >> m;
    map<int, vector<pi>> col1;
    map<int, vector<pi>> col2;
    fori(0, n - 1)
    {
        for (int j = 0; j < m; j++)
        {
            int a;
            cin >> a;
            col1[a].pb({i, j});
            col2[a].pb({j, i});
        }
    }
    int ans = 0;
    ans += col1.size() - 1;
    int first = 0;
    for (auto z : col1)
    {
        vector<pi> one = z.second;
        vector<pi> two = col2[z.first];
        sort(one.begin(), one.end());
        sort(two.begin(), two.end());
        fori(1, (int)one.size() - 1)
        {
            pi current = one[i];
            pi prev = one[i - 1];
            if (current.first == prev.first && prev.second + 1 == current.second)
            {
                first = 1;
                ans++;
                break;
            }
            current = two[i];
            prev = two[i - 1];
            if (current.first == prev.first && prev.second + 1 == current.second)
            {
                first = 1;
                ans++;
                break;
            }
        }
    }
    cout << ans - first << endl;
}

int main()
{
    cin >> test_cases;
    while (test_cases--)
    {
        Solve();
    }
    return 0;
}
