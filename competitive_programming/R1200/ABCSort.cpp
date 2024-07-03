// Problem: D. A-B-C Sort
// Contest: Codeforces - Codeforces Round 786 (Div. 3)
// URL: https://codeforces.com/problemset/problem/1674/D
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
    int n;
    cin >> n;
    int a[n];
    int b[n];
    forn
    {
        cin >> a[i];
        b[i] = a[i];
    }
    sort(b, b + n);
    for (int i = n - 1; i >= 1; i -= 2)
    {
        vector<int> one = {a[i], a[i - 1]};
        vector<int> two = {b[i], b[i - 1]};
        sort(one.begin(), one.end());
        sort(two.begin(), two.end());
        if (one != two)
        {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
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