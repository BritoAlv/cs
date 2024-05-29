// Problem: A. Chess For Three
// Contest: Codeforces - Codeforces Round 945 (Div. 2)
// URL: https://codeforces.com/contest/1973/problem/0
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Math Proof:
//
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
#define endl '\n'
#define wp ' '
#define forn for (int i = 0; i < n; i++)
#define form for (int j = 0; j < m; j++)
#define fork for (int i = 0; i < k; i++)
#define pb push_back
#define ull unsigned long long
#define pi pair<int, int>
#define sz size()
// je m appelle Alvaro j ai 21 ans.

using namespace std;

void BruteSolve()
{
    return;
}

void Solve()
{
    int p1, p2, p3;
    cin >> p1 >> p2 >> p3;
    if ((p1 + p2 + p3) % 2)
    {
        cout << -1 << endl;
    }
    else
    {
        int ans = 0;
        vector<int> R = {p1, p2, p3};
        while (true)
        {
            sort(R.begin(), R.end());
            if (R[1] > 0)
            {
                R[2]--;
                R[1]--;
                ans++;
            }
            else
            {
                break;
            }
        }
        cout << ans << endl;
    }

    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int test_cases;
    cin >> test_cases;
    while (test_cases-- > 0)
    {
        Solve();
    }
    return 0;
}
