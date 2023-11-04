// Problem: B. Coloring Rectangles
// Contest: Codeforces - Technocup 2022 - Elimination Round 2
// URL: https://codeforces.com/contest/1584/problem/B
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

int Solve2(int n, int m)
{
    if (n % 3 == 0 || m % 3 == 0)
    {
        return (n * m) / 3;
    }
    else
    {
        if (n % 3 == 1)
        {
            int ans = ((n - 1) * m) / 3;
            ans += (m - m % 3) / 3;
            ans += 1;
            return ans;
        }
        else
        {
            int ans = ((n - 2) * m) / 3;
            ans += 2 * ((m - m % 3) / 3);
            m = m % 3;
            if (m == 1)
            {
                ans += 1;
            }
            if (m == 2)
            {
                ans += 2;
            }
            return ans;
        }
    }
}

void Solve()
{
    int n, m;
    cin >> n >> m;
    cout << max(Solve2(n, m), Solve2(m, n)) << endl;

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
