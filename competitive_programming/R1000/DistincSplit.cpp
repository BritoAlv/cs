// Problem: D. Distinct Split
// Contest: Codeforces - Codeforces Round 849 (Div. 4)
// URL: https://codeforces.com/problemset/problem/1791/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Math Proof: just implement it, I couldn't find any nice property.
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
    int n;
    cin >> n;
    string S;
    cin >> S;
    unordered_set<char> letters;

    int s[n - 1];
    for (int i = n - 1; i > 0; i--)
    {
        letters.insert(S[i]);
        s[i - 1] = letters.size();
    }
    unordered_set<char> letters2;
    int maxx = 0;
    for (int i = 0; i < n - 1; i++)
    {
        letters2.insert(S[i]);
        maxx = max(maxx, (int)letters2.size() + s[i]);
    }
    cout << maxx << endl;
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
