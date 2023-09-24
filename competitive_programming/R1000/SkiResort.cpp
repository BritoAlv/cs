// Problem: C. Ski Resort
// Contest: Codeforces - Codeforces Round 878 (Div. 3)
// URL: https://codeforces.com/problemset/problem/1840/C
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Math Proof: just sum numbers.
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
    int n, k, q;
    cin >> n >> k >> q;
    int a[n];
    forn
    {
        int t;
        cin >> t;
        if (t > q)
        {
            a[i] = 0;
        }
        else
        {
            a[i] = 1;
        }
    }
    long long answer = 0;
    int index = 0;
    while (index < n)
    {
        if (a[index] == 0)
        {
            index++;
        }
        else
        {
            int count = 1;
            index++;
            while (index < n && a[index] == 1)
            {
                index++;
                count++;
            }
            if (count >= k)
            {
                long long a = count - k + 1;
                a *= (count - k + 2);
                a /= 2;
                answer += a;
            }
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
