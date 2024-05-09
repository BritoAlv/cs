// Problem: A. Card Exchange
// Contest: Codeforces - Codeforces Round 941 (Div. 2)
// URL: https://codeforces.com/contest/1966/problem/A
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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

void BruteSolve()
{
    return;
}

void Solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> count(101, 0);
    forn
    {
        int x;
        cin >> x;
        count[x]++;
    }
    for (int i = 0; i < 101; i++)
    {
        if (count[i] >= k)
        {
            cout << (k - 1) << endl;
            return;
        }
    }
    cout << n << endl;
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
