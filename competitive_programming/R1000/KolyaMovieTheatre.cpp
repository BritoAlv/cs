// Problem: E. Kolya and Movie Theatre
// Contest: Codeforces - Codeforces Round 894 (Div. 3)
// URL: https://codeforces.com/contest/1862/problem/E
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
    long long n, m, d;
    cin >> n >> m >> d;
    long long a[n];
    long long b[n];
    forn
    {
        cin >> a[i];
        b[i] = 0;
    }
    priority_queue<long long, vector<long long>, std::greater<long long>> q;
    long long sum = 0;

    for (int i = 0; i < n; i++)
    {
        if (a[i] <= 0)
        {
            b[i] = (i > 0) ? b[i - 1] : 0;
        }
        else
        {
            if (q.size() < (m - 1))
            {
                sum += a[i];
                b[i] = sum;
                q.push(a[i]);
            }
            else
            {
                if (q.size() > 0 && a[i] > q.top())
                {
                    sum -= q.top();
                    q.pop();
                    sum += a[i];
                    q.push(a[i]);
                    b[i] = sum;
                }
                else
                {
                    b[i] = sum;
                }
            }
        }
    }
    long long answer = 0;
    for (int i = 0; i < n; i++)
    {
        if ((a[i] - (i + 1) * d + ((i > 0) ? b[i - 1] : 0)) > answer)
        {
            answer = (a[i] - (i + 1) * d + ((i > 0) ? b[i - 1] : 0));
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
