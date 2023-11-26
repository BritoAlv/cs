// Problem: C. Yarik and Array
// Contest: Codeforces - Codeforces Round 909 (Div. 3)
// URL: https://codeforces.com/contest/1899/problem/C
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
    int n;
    cin >> n;
    long long a[n];
    forn
    {
        cin >> a[i];
    }
    long long answer = a[0];
    long long an[n];
    an[0] = max(0ll, a[0]);
    for (int i = 1; i < n; i++)
    {
        if ((abs(a[i]) % 2) == (abs(a[i - 1]) % 2))
        {
            an[i] = max(0ll, a[i]);
        }
        else
        {
            an[i] = max(an[i - 1] + a[i], max(0ll, a[i]));
        }
        answer = max(answer, an[i]);
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
