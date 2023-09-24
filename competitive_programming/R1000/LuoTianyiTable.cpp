// Problem: B. LuoTianyi and the Table
// Contest: Codeforces - Codeforces Round 872 (Div. 2)
// URL: https://codeforces.com/problemset/problem/1825/B
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

long long max(long long a, long long b)
{
    return a > b ? a : b;
}

void Solve()
{
    long long n, m;
    cin >> n >> m;
    long long t = n * m;
    long long min_first = 1000000;
    long long min_second = 1000000;
    long long max_first = -1000000;
    long long max_second = -1000000;
    while (t > 0)
    {
        long long r;
        cin >> r;

        if (r <= min_first)
        {
            min_second = min_first;
            min_first = r;
        }

        else if (r < min_second)
        {
            min_second = r;
        }

        if (r >= max_first)
        {
            max_second = max_first;
            max_first = r;
        }
        else if (r > max_second)
        {
            max_second = r;
        }
        t--;
    }
    long long answer = -n * m * min_first + (min_first + max_second * (n - 1) + max_first * (n * m - n));
    answer = max(answer, -n * m * min_first + (min_first + max_second * (m - 1) + max_first * (n * m - m)));
    answer = max(answer, n * m * max_first - (max_first + min_second * (m - 1) + min_first * (n * m - m)));
    answer = max(answer, n * m * max_first - (max_first + min_second * (n - 1) + min_first * (n * m - n)));
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