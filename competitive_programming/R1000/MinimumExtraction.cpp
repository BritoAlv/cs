// Problem: C. Minimum Extraction
// Contest: Codeforces - Codeforces Round 753 (Div. 3)
// URL: https://codeforces.com/contest/1607/problem/C
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
    long long a[n];
    forn
    {
        cin >> a[i];
    }
    sort(a, a + n);
    long long answer = a[0];
    for (int i = 0; i < n - 1; i++)
    {
        answer = max(answer, a[i + 1] - a[i]);
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
