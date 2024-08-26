#include <bits/stdc++.h>

#define endl '\n'
#define wp ' '

using namespace std;

using lld = long long;
using ull = unsigned long long;

const lld maxn = 2e5 + 5;
const lld inf = 1e9 + 1;

int checker(int i, int j, int a, int b, int xx, int x)
{
    int rr = xx * (j - i) <= a * (j - i) + (x - i) * (b - a);
    return rr;
}

void solve()
{
    lld n, m;
    cin >> n >> m;

    vector<string> a(n);
    for (lld i = 0; i < n; i++)
        cin >> a[i];

    priority_queue<pair<lld, pair<lld, lld>>, vector<pair<lld, pair<lld, lld>>>, greater<pair<lld, pair<lld, lld>>>> pq;
    vector<vector<lld>> dist(n, vector<lld>(m, inf));

    dist[0][0] = 0;
    pq.push({0, {0, 0}});

    while (!pq.empty())
    {
        lld r = pq.top().second.first;  // row
        lld c = pq.top().second.second; // column
        pq.pop();

        lld vcur = (a[r][c] - '0'); // value of a[r][c]
        for (lld k = 0; k < n; k++)
        {
            if (k != r)
            {
                lld vnxt = (a[k][c] - '0');
                int pos = 1;
                for (int ww = min(k, r) + 1; ww < max(r, k); ww++)
                {
                    pos &= checker(r, k, vcur, vnxt, (a[ww][c] - '0'), ww);
                }

                if (pos)
                {
                    if (dist[k][c] > dist[r][c] + 1)
                    {
                        dist[k][c] = dist[r][c] + 1;
                        pq.push({dist[k][c], {k, c}});
                    }
                }
            }
        }
        for (lld k = 0; k < m; k++)
        {
            if (k != c)
            {
                lld vnxt = (a[r][k] - '0');
                int pos = 1;
                for (int ww = min(c, k) + 1; ww < max(c, k); ww++)
                {
                    pos &= checker(c, k, vcur, vnxt, (a[r][ww] - '0'), ww);
                }

                if (pos)
                {
                    if (dist[r][k] > dist[r][c] + 1)
                    {
                        dist[r][k] = dist[r][c] + 1;
                        pq.push({dist[r][k], {r, k}});
                    }
                }
            }
        }
    }
    cout << dist[n - 1][m - 1] - 1 << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();

    return 0;
}