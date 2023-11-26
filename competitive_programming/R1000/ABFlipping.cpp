// Problem: B. AB Flipping
// Contest: Codeforces - CodeTON Round 7 (Div. 1 + Div. 2, Rated, Prizes!)
// URL: https://codeforces.com/contest/1896/problem/B
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Math Proof:
//
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
#define endl '\n'
#define wp ' '
#define forn for (int i = 0; i < n; i++)
#define form for (int i = 0; i < m; i++)
#define pb push_back

using namespace std;

void Solve()
{
    int n;
    cin >> n;
    vector<char> S(n);
    vector<bool> mark(n, false);
    int first_a = -1;
    int last_b = -1;
    forn
    {
        cin >> S[i];
        mark[i] = S[i] == 'B';
        if (!mark[i] && first_a == -1)
        {
            first_a = i;
        }
        if (mark[i])
        {
            last_b = i;
        }
    }
    if (first_a == -1)
    {
        cout << 0 << endl;
    }
    else if (last_b > first_a)
    {
        cout << last_b - first_a << endl;
    }
    else
    {
        cout << 0 << endl;
    }

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
