// Problem: A. Contest Proposal
// Contest: Codeforces - Codeforces Round 942 (Div. 2)
// URL: https://codeforces.com/contest/1972/problem/A
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
    int n;
    cin >> n;
    stack<int> aa;
    forn
    {
        int x;
        cin >> x;
        aa.push(x);
    }
    stack<int> bb;
    forn
    {
        int x;
        cin >> x;
        bb.push(x);
    }
    int ans = 0;
    while (bb.sz > 0 && aa.sz > 0)
    {
        if (aa.top() <= bb.top())
        {
            aa.pop();
            bb.pop();
        }
        else
        {
            while (aa.sz > 0 && aa.top() > bb.top())
            {
                aa.pop();
                ans++;
            }
        }
    }
    cout << ans << endl;
    // a[i] <= b[i].
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
