// Problem: B. 250 Thousand Tons of TNT
// Contest: Codeforces - Codeforces Round 909 (Div. 3)
// URL: https://codeforces.com/contest/1899/problem/B
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Math Proof:
//
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
#define endl '\n'
#define wp ' '
#define forn for (int i = 0; i < n; i++)
#define pb push_back

using namespace std;

int n;
long long a[150000];
long long prefix_sums[150000];

long long Solve2(int x)
{
    set<long long> values;
    for (int i = 0; i + (x - 1) <= n - 1; i += x)
    {
        values.insert(prefix_sums[i + (x - 1)] - (i > 0 ? prefix_sums[i - 1] : 0));
    }
    return *values.rbegin() - *values.begin();
}

void Solve()
{
    cin >> n;
    forn
    {
        cin >> a[i];
    }
    prefix_sums[0] = a[0];
    for (int i = 1; i < n; i++)
    {
        prefix_sums[i] = a[i] + prefix_sums[i - 1];
    }
    long long answer = -1;
    for (int i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            answer = max(answer, Solve2(i));
            answer = max(answer, Solve2(n / i));
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
