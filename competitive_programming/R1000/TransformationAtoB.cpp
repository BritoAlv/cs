// Problem: A. Transformation: from A to B
// Contest: Codeforces - Technocup 2017 - Elimination Round 1 (Unofficially Open for Everyone, Rated for Div. 2)
// URL: https://codeforces.com/contest/727/problem/A
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Math Proof:
//
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
#define endl '\n'
#define wp ' '
#define forn for (int i = 0; i < n; i++)
#define pb push_back

using namespace std;

void Solve()
{
    int a, b;
    cin >> a >> b;
    stack<int> final;
    final.push(b);
    while (true)
    {
        if (final.top() == a)
        {
            cout << "YES" << endl;
            cout << final.size() << endl;
            while (final.size() > 0)
            {
                cout << final.top() << wp;
                final.pop();
            }
            cout << endl;
            break;
        }
        if (final.top() < a)
        {
            cout << "NO" << endl;
            return;
        }
        if (final.top() % 2 == 0)
        {
            final.push(final.top() / 2);
        }
        else if (final.top() % 10 == 1)
        {
            final.push(final.top() / 10);
        }
        else
        {
            cout << "NO" << endl;
            return;
        }
    }
    return;
}

int main()
{
    int test_cases = 1;
    Solve();
    return 0;
}