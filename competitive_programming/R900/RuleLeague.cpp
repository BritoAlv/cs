// Problem: B. Rule of League
// Contest: Codeforces - Codeforces Round 821 (Div. 2)
// URL: https://codeforces.com/problemset/problem/1733/B
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Math Proof: notice that min(x,y) == 0 && max(x,y) > 0 is required,
// also (n-1) % max(x,y) == 0, the interesting stuff (4 WA) comes when
// printing the winners, an implicit game, I didn't notice at first.
//
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>

using namespace std;

int test_cases;

void Solve()
{
    int n, x, y;
    cin >> n >> x >> y;
    if (x > 0 && (n - 1) % x == 0 && y == 0)
    {
        int winner = 1;
        int rep = (n - 1) / x;
        while (rep > 0)
        {
            for (int i = 0; i < x; i++)
            {
                cout << winner << ' ';
            }
            if (rep == (n - 1) / x)
            {
                winner += (x + 1);
            }
            else
            {
                winner += x;
            }
            rep--;
        }

        cout << '\n';
    }
    else if (y > 0 && (n - 1) % y == 0 && x == 0)
    {
        int winner = 1;
        int rep = (n - 1) / y;
        while (rep > 0)
        {
            for (int i = 0; i < y; i++)
            {
                cout << winner << ' ';
            }
            if (rep == (n - 1) / y)
            {
                winner += (y + 1);
            }
            else
            {
                winner += y;
            }
            rep--;
        }
        // logic to determine next_winner:
        // old_winner wins y games, he wins to the players:
        // old_winner+1
        // old_winner+2
        // ...
        // old_winner+y
        // next_winner should be old_winner+y+1
        cout << '\n';
    }
    else
    {
        cout << -1 << '\n';
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
