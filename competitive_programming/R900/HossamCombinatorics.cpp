// Problem: A. Hossam and Combinatorics
// Contest: Codeforces - Codeforces Round 837 (Div. 2)
// URL: https://codeforces.com/problemset/problem/1771/A
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Math Proof: imagine that the array is sorted, got it wrong
// where min == max, because they overlap !!! wrong logic
// conduces to wrong submissions. corner cases.
//
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;

int test_cases;

void Solve()
{
    int n;
    cin >> n;
    int min = 100001;
    int max = 0;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (a[i] < min)
        {
            min = a[i];
        }
        if (a[i] > max)
        {
            max = a[i];
        }
    }

    long long min_count = 0;
    long long max_count = 0;

    for (int i = 0; i < n; i++)
    {
        if (a[i] == min)
        {
            min_count++;
        }
        if (a[i] == max)
        {
            max_count++;
        }
    }
    long long answer;
    if (min == max)
    {
        answer = n;
        answer *= (n - 1);
    }
    else
    {
        answer = 2 * min_count * max_count;
    }
    cout << answer << '\n';
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
