// Problem: F. You Are So Beautiful
// Contest: Codeforces - Codeforces Round 905 (Div. 3)
// URL: https://codeforces.com/contest/1883/problem/F
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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
    int a[n];
    forn
    {
        cin >> a[i];
    }
    set<int> t;
    int good_pos[n];
    long long answer = 0;
    int good_positions = 0;
    forn
    {
        if (t.find(a[i]) == t.end())
        {
            good_positions++;
            t.insert(a[i]);
        }
        good_pos[i] = good_positions;
    }
    for (int i = n - 1; i >= 0; i--)
    {
        if (t.find(a[i]) != t.end())
        {
            answer += good_pos[i];
            t.erase(a[i]);
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
