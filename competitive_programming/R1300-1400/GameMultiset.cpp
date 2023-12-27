// Problem: C. Game with Multiset
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
    int n;
    cin >> n;
    map<int, int> multiset;
    for (int i = 0; i <= 29; i++)
    {
        multiset[i] = 0;
    }
    while (n > 0)
    {
        int a, b;
        cin >> a >> b;
        if (a == 1)
        {
            multiset[b]++;
        }
        else if (b == 0)
        {
            cout << "YES" << endl;
        }
        else
        {
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
                    cout << "NO" << endl;
                    break;
                }
                else if (x == 0)
                {
                    cout << "YES" << endl;
                    break;
                }
            }
            for (int i = 0; i <= 29; i++)
            {
                multiset[i] += taken[i];
                taken[i] = 0;
            }
        }
        n--;
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
