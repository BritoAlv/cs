// Problem: B. Swap and Delete
// Contest: Codeforces - Educational Codeforces Round 160 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1913/problem/B
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
#define pb push_back
#define ull unsigned long long
using namespace std;

void Solve()
{
    string S;
    cin >> S;
    int cant0[S.size()];
    int cant1[S.size()];
    for (int i = 0; i < S.size(); i++)
    {
        cant0[i] = 0;
        cant1[i] = 0;
    }
    for (int i = 0; i < S.size(); i++)
    {
        cant0[i] += S[i] == '0';
        cant1[i] += S[i] == '1';
        if (i > 0)
        {
            cant0[i] += cant0[i - 1];
            cant1[i] += cant1[i - 1];
        }
    }
    for (int i = 0; i < S.size(); i++)
    {
        if (cant0[i] > cant1[S.size() - 1] || cant1[i] > cant0[S.size() - 1])
        {
            cout << S.size() - i << endl;
            return;
        }
    }
    cout << 0 << endl;
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
