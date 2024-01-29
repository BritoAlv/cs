// Problem: D. Game with Multiset
// Contest: Codeforces - Educational Codeforces Round 160 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1913/problem/C
// Memory Limit: 256 MB
// Time Limit: 1500 ms
// Math Proof:
//
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
#define endl '\n'
#define wp ' '
#define forn for (int i = 0; i < n; i++)
#define form for (int j = 0; j < m; j++)
#define pb push_back

using namespace std;

void Solve()
{
    int n, m;
    cin >> n >> m;
    map<int, int> multiset;
    for (int i = 0; i <= 29; i++)
    {
        multiset[i] = 0;
    }
    forn
    {
        int a;
        cin >> a;
        int pow = 0;
        while (a > 1)
        {
            a /= 2;
            pow++;
        }
        multiset[pow]++;
    }
    while (m > 0)
    {
        int b;
        cin >> b;
        int x = b;
        vector<int> taken(30, 0);
        while (true)
        {
            int pow = 0;
            while (x >= (1 << pow))
            {
                pow++;
            }
            pow--;
            int ff = 0;
            for (int i = pow; i >= 0; i--)
            {
                if (multiset[i] > 0)
                {
                    int factor = min(multiset[i], x / (1 << i));
                    x -= (1 << i) * factor;
                    multiset[i] -= factor;
                    taken[i] += factor;
                    ff = 1;
                    break;
                }
            }
            if (ff == 0)
            {
                cout << -1 << endl;
                break;
            }
            else if (x == 0)
            {
                long long ans = 0;
                for (int i = 0; i <= 29; i++)
                {
                    ans += taken[i];
                }
                cout << ans << endl;
                break;
            }
        }
        for (int i = 0; i <= 29; i++)
        {
            multiset[i] += taken[i];
            taken[i] = 0;
        }

        m--;
    }
    return;
}

int main()
{
    int test_cases = 1;
    while (test_cases > 0)
    {
        Solve();
        test_cases--;
    }
    return 0;
}