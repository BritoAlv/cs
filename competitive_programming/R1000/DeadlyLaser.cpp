// Problem: B. Deadly Laser
// Contest: Codeforces - Educational Codeforces Round 134 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1721/problem/B
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

vector<pair<int, int>> get_candidates(pair<int, int> q)
{
    vector<pair<int, int>> r;
    r.push_back(make_pair(q.first + 1, q.second));
    r.push_back(make_pair(q.first - 1, q.second));
    r.push_back(make_pair(q.first, q.second + 1));
    r.push_back(make_pair(q.first, q.second - 1));
    return r;
}

bool inside_board(int n, int m, pair<int, int> p)
{
    if (0 <= p.first && p.first <= n - 1)
    {
        if (0 <= p.second && p.second <= m - 1)
        {
            return true;
        }
    }
    return false;
}

bool close_laser(int laserx, int lasery, int d, pair<int, int> position)
{
    return (abs(laserx - position.first) + abs(lasery - position.second) <= d);
}

void Solve()
{
    int n, m, sx, sy, d;
    cin >> n >> m >> sx >> sy >> d;
    bool touch1 = max((sx - d), 1) == 1;
    bool touch2 = max(sy - d, 1) == 1;
    bool touch3 = min(sx + d, n) == n;
    bool touch4 = min(sy + d, m) == m;
    int touch_count = 0;
    touch_count += touch1;
    touch_count += touch2;
    touch_count += touch3;
    touch_count += touch4;

    if (touch_count <= 1 || ((touch_count == 2) && ((touch1 && touch4) || (touch2 && touch3))))
    {
        cout << m + n - 2 << endl;
    }
    else
    {
        cout << -1 << endl;
    }

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
