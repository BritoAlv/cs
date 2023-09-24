// Problem: B. Chips on the Board
// Contest: Codeforces - Educational Codeforces Round 155 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1879/problem/B
// Memory Limit: 256 MB
// Time Limit: 2000 ms
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
    long long n;
    cin >> n;
    long long a[n];
    long long b[n];
    long long sumA = 0;
    long long sumB = 0;
    forn
    {
        cin >> a[i];
        sumA += a[i];
    }
    forn
    {
        cin >> b[i];
        sumB += b[i];
    }
    long long answer = n * a[0] + sumB;
    for (int i = 0; i < n; i++)
    {
        answer = min(answer, n * a[i] + sumB);
        answer = min(answer, n * b[i] + sumA);
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
