// Problem: C. Smilo and Monsters
// Contest: Codeforces - Codeforces Round 907 (Div. 2)
// URL: https://codeforces.com/contest/1891/problem/C
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

long long solve_recursive(int start, int end, long long a[])
{
    long long ans = 0;
    if (start == end)
    {
        if (a[start] % 2 == 0)
        {
            ans = a[start] / 2 + 1;
        }
        else if (a[start] == 1)
        {
            ans = 1;
        }
        else
        {
            ans = 2 + a[start] / 2;
        }
    }
    else if (end == start + 1)
    {
        long long b[1];
        b[0] = a[start] + a[end];
        ans = solve_recursive(0, 0, b);
    }
    else
    {
        long long sum = 0;
        for (int i = start; i <= end; i++)
        {
            if (i == end)
            {
                long long b[1];
                b[0] = a[end] + sum;
                ans += solve_recursive(0, 0, b);
            }
            else
            {
                sum += a[i];
                if (sum == a[end])
                {
                    ans = sum + 1;
                    if (i != end - 1)
                    {
                        ans += solve_recursive(i + 1, end - 1, a);
                    }
                    break;
                }
                else if (sum > a[end])
                {
                    ans = a[end] + 1;
                    sum -= a[i];
                    a[i] -= (a[end] - sum);
                    ans += solve_recursive(i, end - 1, a);
                    break;
                }
            }
        }
    }
    return ans;
}
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
    cout << solve_recursive(0, n - 1, a) << endl;
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
