// Problem: B. Basketball Together
// Contest: Codeforces - COMPFEST 14 - Preliminary Online Mirror (Unrated, ICPC Rules, Teams Preferred)
// URL: https://codeforces.com/contest/1725/problem/B
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

void Solve()
{
    int n, d;
    cin >> n >> d;
    int a[n];
    forn
    {
        cin >> a[i];
    }
    sort(a, a + n);
    int last_used = -1;
    int answer = 0;
    for (int i = n - 1; i > last_used; i--)
    {
        long long sum = a[i];
        while (sum <= d)
        {
            if (last_used + 1 == i)
            {
                break;
            }
            last_used++;
            sum += a[i];
        }
        if (sum > d)
        {
            answer++;
        }
        else
        {
            break;
        }
    }
    cout << answer << endl;
    return;
}

int main()
{
    Solve();
    return 0;
}
