// Problem: C. Game on Permutation
// Contest: Codeforces - Educational Codeforces Round 153 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1860/problem/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Math Proof: call a position W, L, then find the concept of a W position which is
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
    int a[n];
    int answer = 0;
    int lowest_winner = -1;
    int lowest_loser = -1;
    forn
    {
        cin >> a[i];
        if (i == 0)
        {
            lowest_loser = a[i];
        }
        else
        {
            if (a[i] > lowest_loser && (lowest_winner < 0 || (lowest_winner > 0 && lowest_winner > a[i])))
            {
                if (lowest_winner < 0)
                {
                    lowest_winner = a[i];
                }
                lowest_winner = min(lowest_winner, a[i]);
                answer++;
            }
            else
            {
                lowest_loser = min(lowest_loser, a[i]);
            }
        }
    }
    cout << answer << endl;
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
