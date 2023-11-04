// Problem: B. Rock and Lever
// Contest: Codeforces - Codeforces Round 672 (Div. 2)
// URL: https://codeforces.com/contest/1420/problem/B
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Math Proof:
//
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
#define endl '\n'
#define wp ' '
#define forn for (int i = 0; i < n; i++)
using namespace std;

void Solve()
{
    int n;
    cin >> n;
    long long bit[32];
    for (int i = 0; i < 32; i++)
    {
        bit[i] = 0;
    }
    forn
    {
        int a;
        cin >> a;
        for (int j = 31; j >= 0; j--)
        {
            if ((a & (1 << j)) > 0)
            {
                bit[j]++;
                break;
            }
        }
    }
    long long ans = 0;
    for (int i = 0; i < 32; i++)
    {
        ans += (bit[i] * (bit[i] - 1)) / 2;
    }
    cout << ans << endl;
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
