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
    vector<vector<int>> distance;
    for (int i = 0; i < n; i++)
    {
        distance.push_back(vector<int>(m, -1));
    }
    queue<pair<int, int>> cola;
    cola.push(make_pair(0, 0));
    distance[0][0] = 0;

    while (cola.size() > 0)
    {
        auto q = cola.front();
        cola.pop();
        for (auto candidate1 : get_candidates(q))
        {
            if (inside_board(n, m, candidate1) && !close_laser(sx - 1, sy - 1, d, candidate1))
            {
                if (distance[candidate1.first][candidate1.second] == -1)
                {
                    distance[candidate1.first][candidate1.second] = distance[q.first][q.second] + 1;
                    cola.push(candidate1);
                }
            }
        }
    }
    cout << distance[n - 1][m - 1] << endl;
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
