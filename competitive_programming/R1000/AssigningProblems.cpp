// Problem: D. Assigning problems
// Contest: Codeforces - 2023 Argentinian Programming Tournament (TAP)
// URL: https://codeforces.com/gym/104603/problem/D
// Memory Limit: 1024 MB
// Time Limit: 750 ms
// Math Proof: Binary Search on the answer
//
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
#define endl '\n'
#define wp ' '
#define forn for (int i = 0; i < n; i++)
using namespace std;

bool check_works(long long t, vector<long long> C, vector<long long> P, long long K)
{
    long long rem = 0;
    for (int i = 0; i < K; i++)
    {
        rem += P[i];
        if (rem < t * C[i])
        {
            return false;
        }
        else
        {
            rem -= t * C[i];
        }
    }
    return true;
}

void Solve()
{
    int n;
    cin >> n;
    vector<long long> C(n);
    vector<long long> P(n);
    forn
    {
        cin >> C[i];
    }
    forn
    {
        cin >> P[i];
    }

    long long l = 0;
    long long r = 10000000000;

    while (true)
    {
        if (l == r)
        {
            cout << l << endl;
            return;
        }
        else if (r - l == 1)
        {
            if (check_works(r, C, P, n))
            {
                cout << r << endl;
            }
            else
            {
                cout << l << endl;
            }
            return;
        }
        else
        {
            long long middle = (l + r) / 2;
            if (!check_works(middle, C, P, n))
            {
                r = middle;
            }
            else
            {
                l = middle;
            }
        }
    }

    return;
}

int main()
{
    Solve();
    return 0;
}
