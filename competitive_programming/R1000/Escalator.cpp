// Problem: E. Escalator
// Contest: Codeforces - 2021-2022 ACM-ICPC Brazil Subregional Programming Contest
// URL: https://codeforces.com/gym/103388/problem/E
// Memory Limit: 1024 MB
// Time Limit: 500 ms
// Math Proof:
//
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
#define endl '\n'
#define wp ' '
#define forn for (int i = 0; i < n; i++)
using namespace std;

int simulate(int start_time, queue<int> &g1, queue<int> &g2)
{
    if (g1.size() == 0 && g2.size() == 0)
    {
        return start_time;
    }
    else if (g1.size() == 0)
    {

        int start = max(start_time, g2.front());
        g2.pop();
        while (g2.size() > 0 && g2.front() < start_time)
        {
            g2.pop();
        }
        while (g2.size() > 0 && g2.front() < start + 10)
        {
            start = g2.front();
            g2.pop();
        }
        return start + 10;
    }
    else if (g2.size() == 0)
    {
        int start = max(start_time, g1.front());
        g1.pop();
        while (g1.size() > 0 && g1.front() < start_time)
        {
            g1.pop();
        }
        while (g1.size() > 0 && g1.front() < start + 10)
        {
            start = g1.front();
            g1.pop();
        }
        return start + 10;
    }
    else
    {
        if (g2.front() < g1.front())
        {
            int start = max(start_time, g2.front());
            g2.pop();
            while (g2.size() > 0 && g2.front() < start_time)
            {
                g2.pop();
            }
            while (g2.size() > 0 && g2.front() < start + 10)
            {
                start = g2.front();
                g2.pop();
            }
            return start + 10;
        }
        else
        {
            int start = max(start_time, g1.front());
            g1.pop();
            while (g1.size() > 0 && g1.front() < start_time)
            {
                g1.pop();
            }
            while (g1.size() > 0 && g1.front() < start + 10)
            {
                start = g1.front();
                g1.pop();
            }
            return start + 10;
        }
    }
}

void Solve()
{
    int n;
    cin >> n;
    queue<int> g1;
    queue<int> g2;
    forn
    {
        int a, b;
        cin >> a >> b;
        if (b == 0)
        {
            g1.push(a);
        }
        else
        {
            g2.push(a);
        }
    }
    int start_time = 0;
    while (true)
    {
        int x = simulate(start_time, g1, g2);
        if (x == start_time)
        {
            break;
        }
        else
        {
            start_time = x;
        }
    }
    cout << start_time << endl;
    return;
}

int main()
{
    Solve();
    return 0;
}