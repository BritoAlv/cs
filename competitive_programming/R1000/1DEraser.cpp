// Problem: D. 1D Eraser
// Contest: Codeforces - Codeforces Round 898 (Div. 4)
// URL: https://codeforces.com/contest/1873/problem/D
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

int test_cases;

void Solve()
{
    int n, k;
    cin >> n >> k;
    int answer = 0;
    int start = 0;
    while (n > 0)
    {
        char t;
        cin >> t;
        if (start == 0 && t == 'B')
        {
            start++;
            answer++;
        }
        else if (start > 0)
        {
            start++;
        }
        start = start % k;
        n--;
    }
    cout << answer << endl;
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
