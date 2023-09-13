// Problem: A. Long Comparison
// Contest: Codeforces - Educational Codeforces Round 118 (Rated for Div. 2)
// URL: https://codeforces.com/problemset/problem/1613/A
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Math Proof: just implement
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
    string x1, x2;
    int p1, p2;
    cin >> x1 >> p1;
    cin >> x2 >> p2;

    if (x1.size() + p1 > x2.size() + p2)
    {
        cout << '>' << endl;
        return;
    }
    else if (x1.size() + p1 < x2.size() + p2)
    {
        cout << '<' << endl;
        return;
    }

    else
    {
        for (int i = 0; i < max(x1.size(), x2.size()); i++)
        {
            char to_compare1 = i >= x1.size() ? '0' : x1[i];
            char to_compare2 = i >= x2.size() ? '0' : x2[i];

            if (to_compare1 > to_compare2)
            {
                cout << '>' << endl;
                return;
            }
            if (to_compare1 < to_compare2)
            {
                cout << '<' << endl;
                return;
            }
        }
    }
    cout << '=' << endl;
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
