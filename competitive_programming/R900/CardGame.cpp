// Problem: A. Card Game
// Contest: Codeforces - Good Bye 2019
// URL: https://codeforces.com/contest/1270/problem/A
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Math Proof: sadly, trivially it is the player who takes the bigger number
//
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>

using namespace std;

int test_cases;

void Solve()
{
    int n;
    int c1;
    int c2;
    cin >> n >> c1 >> c2;
    bool is_winner = false;
    while (c1 > 0)
    {
        int t;
        cin >> t;
        if (t == n)
        {
            is_winner = true;
        }
        c1--;
    }
    while (c2 > 0)
    {
        int t;
        cin >> t;
        c2--;
    }
    cout << (is_winner ? "YES" : "NO") << '\n';
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
