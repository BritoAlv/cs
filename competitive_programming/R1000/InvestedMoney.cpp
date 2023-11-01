// Problem: I. Invested Money
// Contest: Codeforces - 2021-2022 ACM-ICPC Latin American Regional Programming Contest
// URL: https://codeforces.com/gym/103640/problem/I
// Memory Limit: 1024 MB
// Time Limit: 350 ms
// Math Proof:
//
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
#define endl '\n'
#define wp ' '
#define forn for (int i = 0; i < n; i++)
using namespace std;

pair<int, int> simulate(int res)
{
    if (res == 1)
    {
        return make_pair(30, 3);
    }
    if (res == 2)
    {
        return make_pair(30, 4);
    }
    if (res == 3)
    {
        return make_pair(30, 5);
    }
    if (res == 4)
    {
        return make_pair(32, 1);
    }
    if (res == 5)
    {
        return make_pair(31, 1);
    }
}

void Solve()
{
    string S;
    int n;
    cin >> S >> n;
    int start_pos = 0;
    if (S == "Mon")
    {
        start_pos = 1;
    }
    if (S == "Tue")
    {
        start_pos = 2;
    }
    if (S == "Wed")
    {
        start_pos = 3;
    }
    if (S == "Thu")
    {
        start_pos = 4;
    }
    if (S == "Fri")
    {
        start_pos = 5;
    }
    if (S == "Sat")
    {
        start_pos = 6;
    }
    if (S == "Sun")
    {
        start_pos = 0;
    }
    int a[n];
    forn
    {
        int t;
        cin >> t;
        if (t == 0)
        {
            a[i] = simulate(start_pos).first;
        }
        else
        {
            int dep_start = (-(t % 7) + start_pos + 7) % 7;
            while (t > 0)
            {
                if (dep_start == 1)
                {
                    t -= (t / 91) * 91;
                }
                pair<int, int> a = simulate(dep_start);
                t -= a.first;
                dep_start = a.second;
            }
            a[i] = -t;
        }
    }
    int minn = a[0];
    forn
    {
        minn = min(minn, a[i]);
    }
    cout << minn << endl;
    return;
}

int main()
{
    Solve();
    return 0;
}
