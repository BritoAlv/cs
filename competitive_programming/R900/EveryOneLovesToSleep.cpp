// Problem: A. Everyone Loves to Sleep
// Contest: Codeforces - Codeforces Round 811 (Div. 3)
// URL: https://codeforces.com/problemset/problem/1714/A
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Math Proof: an implementation problem.
//
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
#define endl '\n'
#define forn for (int i = 0; i < n; i++)
using namespace std;

int test_cases;

void Solve()
{
    int n, H, M;
    cin >> n >> H >> M;
    int min_alarm = 24 * 60 + 1;
    int min_alarm_after = 24 * 60 + 1;
    while (n > 0)
    {
        int h, m;
        cin >> h >> m;
        if (60 * h + m < min_alarm)
        {
            min_alarm = 60 * h + m;
        }
        if (60 * h + m >= 60 * H + M && 60 * h + m < min_alarm_after)
        {
            min_alarm_after = 60 * h + m;
        }
        n--;
    }
    int time = 0;
    if (min_alarm_after == 24 * 60 + 1)
    {
        time = 24 * 60 - H * 60 - M + min_alarm;
    }
    else
    {
        time = min_alarm_after - H * 60 - M;
    }
    cout << time / 60 << ' ' << time % 60 << endl;

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