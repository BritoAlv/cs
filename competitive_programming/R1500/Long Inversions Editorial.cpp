// Problem: E. Long Inversions
// Contest: Codeforces - Codeforces Round 938 (Div. 3)
// URL: https://codeforces.com/contest/1955/problem/E
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

int w(int k, string &s)
{
    int n = s.size();
    int last_k1_ops = 0;
    vector<int> op(n, 0);
    for (int i = 0; i <= n - k; i++)
    {
        if (i >= k && op[i - k])
        {
            last_k1_ops--;
        }
        if ((int(s[i] - '0') + last_k1_ops) % 2 == 0)
        {
            last_k1_ops++;
            op[i] = 1;
        }
    }
    int val = (int(s[n - k] - '0') + last_k1_ops) % 2;
    for (int i = n - k + 1; i < n; i++)
    {
        if (i >= k && op[i - k])
        {
            last_k1_ops--;
        }
        if ((int(s[i] - '0') + last_k1_ops) % 2 != val)
        {
            return 0;
        }
    }
    return 1;
}

void Solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    for (int i = n; i >= 1; i--)
    {
        if (w(i, s))
        {
            cout << i << endl;
            return;
        }
    }
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