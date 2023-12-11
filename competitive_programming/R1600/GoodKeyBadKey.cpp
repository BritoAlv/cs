// Problem: G. Good Key, Bad Key
// Contest: Codeforces - Codeforces Round 806 (Div. 4)
// URL: https://codeforces.com/contest/1703/problem/G
// Memory Limit: 256 MB
// Time Limit: 3000 ms
// Math Proof:
//
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
#define endl '\n'
#define wp ' '
#define forn for (int i = 0; i < n; i++)
#define form for (int j = 0; j < m; j++)
#define pb push_back

using namespace std;

void Solve()
{
    long long n, k;
    cin >> n >> k;
    long long a[n];
    long long psums[n + 1];
    psums[0] = 0;
    forn
    {
        cin >> a[i];
        psums[i + 1] = psums[i] + a[i];
    }
    long long maxx = -1;
    for (int index = 0; index <= n; index++)
    {
        long long sum = -k;
        sum *= index;
        sum += psums[index];
        for (int i = index; i < min(n, (long long)index + 31); i++)
        {
            long long v = a[i];
            v >>= (i - index + 1);
            sum += v;
        }
        maxx = max(maxx, sum);
    }
    cout << maxx << endl;
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