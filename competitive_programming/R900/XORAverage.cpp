// Problem: B. XOR = Average
// Contest: Codeforces - Codeforces Round 836 (Div. 2)
// URL: https://codeforces.com/contest/1758/problem/B
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Math Proof: for n odd use x xor x = 0, and for n even also.
// (n-2)x + (a+b) = n*(a xor b)
// got solution for x = 4, a = 2, b = 6
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>

using namespace std;

int test_cases;

void Solve()
{
    int n;
    cin >> n;
    if (n % 2 == 1)
    {
        for (int i = 0; i < n; i++)
        {
            cout << 1 << ' ';
        }
        cout << '\n';
    }
    else
    {
        for (int i = 1; i <= n - 2; i++)
        {
            cout << 4 << ' ';
        }
        cout << 2 << ' ' << 6 << '\n';
    }
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
