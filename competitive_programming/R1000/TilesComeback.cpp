// Problem: C. Tiles Comeback
// Contest: Codeforces - Codeforces Round 888 (Div. 3)
// URL: https://codeforces.com/problemset/problem/1851/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Math Proof: observation is that is enough with 2 tiles
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
    forn
    {
        cin >> a[i];
    }

    if (a[0] == a[n - 1])
    {
        int count = 0;
        forn
        {
            if (a[i] == a[0])
            {
                count++;
            }
        }
        if (count >= k)
        {
            cout << "YES" << endl;
            return;
        }
    }
    else
    {
        int count1 = 0;
        int count2 = 0;
        forn
        {
            if (a[i] == a[0] && count1 < k)
            {
                count1++;
            }

            if (count1 >= k && a[i] == a[n - 1])
            {
                count2++;
            }

            if (count2 >= k)
            {
                cout << "YES" << endl;
                return;
            }
        }
    }
    cout << "NO" << endl;
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
