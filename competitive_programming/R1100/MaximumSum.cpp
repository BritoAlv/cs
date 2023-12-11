// Problem: B. Maximum Sum
// Contest: Codeforces - Educational Codeforces Round 148 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1832/problem/B
// Memory Limit: 256 MB
// Time Limit: 2000 ms
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
    int n, k;
    cin >> n >> k;
    int a[n];
    forn
    {
        cin >> a[i];
    }
    sort(a, a + n);
    long long psums[n];
    long long ssums[n];
    psums[0] = a[0];
    ssums[n - 1] = a[n - 1];
    for (int i = 1; i < n; i++)
    {
        psums[i] = psums[i - 1] + a[i];
    }
    for (int i = n - 2; i >= 0; i--)
    {
        ssums[i] = ssums[i + 1] + a[i];
    }
    long long minn = -1;
    for (int i = 0; i <= k; i++)
    {
        long long removed = 0;
        removed += (i == 0 ? 0 : psums[2 * i - 1]);
        // will do k - i operations of remove max.
        removed += (k == i ? 0 : ssums[n - (k - i)]);
        minn = (minn == -1 ? removed : min(removed, minn));
    }
    cout << psums[n - 1] - minn << endl;
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
