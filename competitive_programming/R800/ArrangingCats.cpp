// Problem: B. Arranging Cats
// Contest: Codeforces - Codeforces Round 920 (Div. 3)
// URL: https://codeforces.com/contest/1921/problem/B
// Memory Limit: 512 MB
// Time Limit: 2000 ms
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
using namespace std;

void Solve()
{
    int n;
    cin >> n;
    vector<char> S(n);
    vector<char> P(n);
    forn
    {
        cin >> S[i];
    }
    forn
    {
        cin >> P[i];
    }
    int ones_exchange = 0;
    int zeros_exchange = 0;
    forn
    {
        if (P[i] != S[i])
        {
            ones_exchange += (S[i] == '1');
            zeros_exchange += (S[i] == '0');
        }
    }
    cout << max(ones_exchange, zeros_exchange) << endl;
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
