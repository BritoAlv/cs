// Problem: B. Mocha and Red and Blue
// Contest: Codeforces - Codeforces Round 738 (Div. 2)
// URL: https://codeforces.com/problemset/problem/1559/B
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Math Proof: implementation only
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
    string S;
    cin >> n;
    cin >> S;
    for (int i = 0; i <= n; i++)
    {
        if (i == n)
        {
            char last_color = 'R';
            for (int m = 0; m < n; m++)
            {
                cout << last_color;
                last_color = (last_color == 'B' ? 'R' : 'B');
            }
            cout << endl;
            break;
        }
        if (S[i] != '?')
        {
            char first_color = (i % 2 == 0 ? S[i] : (S[i] == 'B' ? 'R' : 'B'));
            for (int j = 0; j <= i - 1; j++)
            {
                cout << first_color;
                first_color = (first_color == 'B' ? 'R' : 'B');
            }
            cout << S[i];
            char last_color = S[i];
            for (int m = i + 1; m < n; m++)
            {
                if (S[m] == '?')
                {
                    last_color = (last_color == 'B' ? 'R' : 'B');
                }
                else
                {
                    last_color = S[m];
                }
                cout << last_color;
            }
            cout << endl;
            break;
        }
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
