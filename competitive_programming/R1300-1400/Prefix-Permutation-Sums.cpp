// Problem: D. Prefix Permutation Sums
// Contest: Codeforces - Codeforces Round 888 (Div. 3)
// URL: https://codeforces.com/contest/1851/problem/D
// Memory Limit: 256 MB
// Time Limit: 3000 ms
// Math Proof:
//
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
#define endl '\n'
#define wp ' '
#define forn for (int i = 0; i < n; i++)
#define pb push_back

using namespace std;

void Solve()
{
    int n;
    cin >> n;
    long long psums[n - 1];
    int marked[n];
    for (int i = 0; i < n - 1; i++)
    {
        cin >> psums[i];
    }
    forn
    {
        marked[i] = 0;
    }

    if (psums[0] <= n)
    {
        marked[psums[0] - 1]++;
    }
    for (int i = 1; i < n - 1; i++)
    {
        if (psums[i] - psums[i - 1] <= n)
        {
            marked[psums[i] - psums[i - 1] - 1]++;
        }
    }
    int count = 0;
    vector<long long> rems;
    forn
    {
        if (marked[i] > 0)
        {
            count++;
        }
        else
        {
            rems.pb(i + 1);
        }
    }
    long long expected_end = n;
    expected_end *= (n + 1);
    expected_end /= 2;
    if (count == n - 1)
    {
        if (psums[n - 2] + rems[0] == expected_end)
        {
            cout << "YES" << endl;
            return;
        }
    }
    else if (count == n - 2)
    {
        long long sum = rems[0] + rems[1];
        int works = 0;
        if (psums[0] == sum)
        {
            works = 1;
        }
        for (int i = 1; i < n - 1; i++)
        {
            if (psums[i] - psums[i - 1] > n && sum != psums[i] - psums[i - 1])
            {
                works = 0;
                break;
            }
            if (sum == psums[i] - psums[i - 1])
            {
                works = 1;
            }
        }
        if (works && expected_end == psums[n - 2])
        {
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO" << endl;
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