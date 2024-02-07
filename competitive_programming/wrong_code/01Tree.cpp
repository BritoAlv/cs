// Problem: D. 01 Tree
// Contest: Codeforces - Hello 2024
// URL: https://codeforces.com/contest/1919/problem/D
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Math Proof:
//
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
#define endl '\n'
#define wp ' '
#define forn for (int i = 0; i < n; i++)
#define form for (int j = 0; j < m; j++)
#define pb push_back
#define ull unsigned long long
using namespace std;

int a[200000];

int cheker_recursive(int start, int end)
{
    if (start == end)
    {
        return a[start] == 0;
    }
    else
    {
        int zero_position = -1;
        for (int i = start; i <= end; i++)
        {
            if (a[i] == 0)
            {
                if (zero_position != -1)
                {
                    return 0;
                }
                else
                {
                    zero_position = i;
                }
            }
        }
        if (zero_position != -1)
        {
            for (int i = start; i < end; i++)
            {
                // split like this.
                //[start, i]
                //[i+1, end]
                if (zero_position <= i)
                {
                    for (int j = i + 1; j <= end; j++)
                    {
                        a[j]--;
                    }
                    if (cheker_recursive(start, i) && cheker_recursive(i + 1, end))
                    {
                        return 1;
                    }
                    for (int j = i + 1; j <= end; j++)
                    {
                        a[j]++;
                    }
                }
                else
                {
                    for (int j = start; j <= i; j++)
                    {
                        a[j]--;
                    }
                    if (cheker_recursive(start, i) && cheker_recursive(i + 1, end))
                    {
                        return 1;
                    }
                    for (int j = start; j <= i; j++)
                    {
                        a[j]++;
                    }
                }
            }
            return 0;
        }
        else
        {
            return 0;
        }
    }
}

void Solve()
{
    int n;
    cin >> n;
    forn
    {
        cin >> a[i];
    }
    cout << cheker_recursive(0, n - 1) << endl;
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
