// Problem: C. Divisor Chain
// Contest: Codeforces - Harbour.Space Scholarship Contest 2023-2024 (Div. 1 + Div. 2)
// URL: https://codeforces.com/contest/1864/problem/C
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Math Proof: write the number in binary, choose as divisor the largest power of two that divides it, until it become a power of two, then each time choose halt the number, both steps choose a divisor at most once.
//
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
#define endl '\n'
#define wp ' '
#define forn for (int i = 0; i < n; i++)
using namespace std;

int lgptwo(int x)
{
    int count = 0;
    while (x % 2 == 0)
    {
        x = x / 2;
        count++;
    }
    return count;
}

void Solve()
{
    int x;
    cin >> x;
    vector<int> ans;
    while (x != (1 << lgptwo(x)))
    {
        ans.push_back(x);
        x -= (1 << lgptwo(x));
    }
    ans.push_back(x);
    while (x > 1)
    {
        x /= 2;
        ans.push_back(x);
    }
    cout << ans.size() << endl;
    for (auto x : ans)
    {
        cout << x << wp;
    }
    cout << endl;
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
