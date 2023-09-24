// Problem: C. Best Binary String
// Contest: Codeforces - Educational Codeforces Round 149 (Rated for Div. 2)
// URL: https://codeforces.com/problemset/problem/1837/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Math Proof: in the problems where a binary string is given
// and operations are with substring, it's possible to think
// a block of [00000] as only one 0.
//
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
#define endl '\n'
#define wp ' '
#define forn for (int i = 0; i < n; i++)
using namespace std;

int test_cases;

void Solve()
{
    string S;
    cin >> S;
    for (int i = 0; i < S.size(); i++)
    {
        if (S[i] == '?')
        {
            S[i] = (i == 0 ? '0' : S[i - 1]);
        }
    }
    cout << S << endl;
    return;
}

int main()
{
    cin >> test_cases;
    while (test_cases > 0)
    {
        Solve();
        test_cases--;
    }
    return 0;
}
