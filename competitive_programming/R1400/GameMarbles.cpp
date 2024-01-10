// Problem: E2. Game with Marbles (Hard Version)
// Contest: Codeforces - Codeforces Round 916 (Div. 3)
// URL: https://codeforces.com/problemset/problem/1914/E2
// Memory Limit: 256 MB
// Time Limit: 3500 ms
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
#define ll long long
using namespace std;

int a[200000];
int b[200000];

int cmp1(pair<int, int> A, pair<int, int> B)
{
    return A.first + A.second < B.first + B.second;
}

void Solve()
{
    int n;
    cin >> n;
    forn
    {
        cin >> a[i];
    }
    vector<pair<int, int>> v;
    forn
    {
        cin >> b[i];
        v.pb({a[i], b[i]});
    }
    sort(v.begin(), v.end(), cmp1);
    long long sum = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        if (i % 2 == (n - 1) % 2)
        {
            sum += v[i].first - 1;
        }
        else
        {
            sum -= v[i].second - 1;
        }
    }
    cout << sum << endl;
    return;
}

int main()
{
    int test_cases;
    cin >> test_cases;
    while (test_cases > 0)
    {
        Solve();
        test_cases--;
    }
    return 0;
}