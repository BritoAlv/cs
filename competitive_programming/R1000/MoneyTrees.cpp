// Problem: F. Money Trees
// Contest: Codeforces - Codeforces Round 898 (Div. 4)
// URL: https://codeforces.com/problemset/problem/1873/F
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
    int n, k;
    cin >> n >> k;
    int a[n];
    int h[n];
    forn
    {
        cin >> a[i];
    }
    forn
    {
        cin >> h[i];
    }
    int start = 0;
    int end = 0;
    int answer = 0;
    for (int i = 1; i <= n; i++)
    {
        if (i < n && ((h[i - 1] % h[i]) == 0))
        {
            end++;
        }
        else
        {
            while (start <= end && a[start] > k)
            {
                start++;
            }
            if (start <= end)
            {
                if (start != end)
                {
                    long long sum = a[start];
                    int pointer2 = start;
                    for (int pointer1 = start; pointer1 <= end; pointer1++)
                    {
                        if (pointer1 > start)
                        {
                            sum -= a[pointer1 - 1];
                        }

                        while (pointer2 + 1 <= end && sum + a[pointer2 + 1] <= k)
                        {
                            pointer2++;
                            sum += a[pointer2];
                        }
                        answer = max(answer, pointer2 - pointer1 + 1);
                    }
                }
                else
                {
                    if (a[start] <= k)
                    {
                        answer = max(answer, 1);
                    }
                }
            }
            start = i;
            end = i;
        }
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