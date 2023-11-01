// Problem: D. In Love
// Contest: Codeforces - Codeforces Round 905 (Div. 3)
// URL: https://codeforces.com/contest/1883/problem/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms
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
    multiset<int> l, r;
    while (n > 0)
    {
        char t;
        int a, b;
        cin >> t >> a >> b;
        if (t == '+')
        {
            l.insert(a);
            r.insert(b);
        }
        else
        {
            l.erase(l.find(a));
            r.erase(r.find(b));
        }
        if (l.size() == 0)
        {
            cout << "NO" << endl;
        }
        else
        {
            int lowest = *(r.begin());
            int upper = *(--l.end());
            if (lowest < upper)
            {
                cout << "YES" << endl;
            }
            else
            {
                cout << "NO" << endl;
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
