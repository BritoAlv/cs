// Problem: A. AB Balance
// Contest: Codeforces - Educational Codeforces Round 116 (Rated for Div. 2)
// URL: https://codeforces.com/problemset/problem/1606/A
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Math Proof: diference is almost one, to fix it find first
// appearence of letter wrong.
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
    int ab = 0;
    int ba = 0;
    int first_a = (S[0] == 'a' ? 0 : -1);
    int first_b = (S[0] == 'b' ? 0 : -1);
    for (int i = 1; i < S.size(); i++)
    {
        if (first_a < 0 && S[i] == 'a')
        {
            first_a = i;
        }
        if (first_b < 0 && S[i] == 'b')
        {
            first_b = i;
        }
        if (S[i - 1] == 'a' && S[i] == 'b')
        {
            ab++;
        }
        if (S[i - 1] == 'b' && S[i] == 'a')
        {
            ba++;
        }
    }

    if (ab > ba)
    {
        S[first_a] = 'b';
    }
    if (ba > ab)
    {
        S[first_b] = 'a';
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
