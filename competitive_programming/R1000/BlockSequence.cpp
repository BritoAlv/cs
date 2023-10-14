// Problem: E. Block Sequence
// Contest: Codeforces - Codeforces Round 903 (Div. 3)
// URL: https://codeforces.com/contest/1881/problem/E
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
    int n;
    cin >> n;
    int a[n];
    forn
    {
        cin >> a[i];
    }
    int count[n];
    for (int i = n - 1; i >= 0; i--)
    {
        int next = i + a[i] + 1;
        count[i] = -1;
        if (next <= n)
        {
            count[i] = n - next;
        }
    }
    int ans_index[n];
    forn
    {
        ans_index[i] = -1;
    }

    for (int i = n - 1; i >= 0; i--)
    {
        if (count[i] >= 0)
        {
            int next = i + a[i] + 1;
            if (next < n && ans_index[next] >= 0)
            {
                count[i] = min(count[ans_index[next]] + (ans_index[next] - next), count[i]);
            }
        }

        if (count[i] >= 0)
        {
            ans_index[i] = i;
        }

        if (i < n - 1 && ans_index[i + 1] >= 0)
        {
            if (ans_index[i] == -1)
            {
                ans_index[i] = ans_index[i + 1];
            }
            else
            {
                if (count[ans_index[i]] > count[ans_index[i + 1]] + (ans_index[i + 1]) - i)
                {
                    ans_index[i] = ans_index[i + 1];
                }
            }
        }
    }
    int ans = n;
    for (int i = 0; i < n; i++)
    {
        if (count[i] >= 0 && i + count[i] < ans)
        {
            ans = i + count[i];
        }
    }
    cout << ans << endl;
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