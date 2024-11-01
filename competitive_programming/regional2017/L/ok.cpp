#include <bits/stdc++.h>

#define forn for (int i = 0; i < n; i++)
#define endl '\n'
#define wp ' '
#define ll long long
#define pb push_back
using namespace std;

const int maxn = 1e5 + 4;
int n;
int north[maxn];
int west[maxn];

#define Node pair<pair<int, int>, int>


const int H = 0;
const int V = 1;

vector<int> dxV = {0, 0};
vector<int> dyV = {1, -1};
vector<int> dxH = {1, -1};
vector<int> dyH = {0, 0};

ll solve(pair<int, int> S, pair<int, int> E)
{
    map<Node, ll> dp;   
    dp[{S, H}] = 0;
    dp[{S, V}] = 0;
    queue<Node> Q;
    Q.push({S, H});
    Q.push({S, V});

    while (Q.size() > 0)
    {
        auto top = Q.front();
        Q.pop();

        int i = top.first.first;
        int j = top.first.second;
        int direction = top.second;

        if (direction == H)
        {
            for (int z = 0; z < 2; z++)
            {
                int di = i + dxV[z];
                int dj = j + dyV[z];
                if (di >= 1 && di <= n && dj >= 1 && dj <= n)
                {
                    int edge_weight = west[min(j, dj)];
                    Node update = {{di, dj}, V};
                    if (dp.find(update) == dp.end())
                    {
                        dp[update] = dp[top] + edge_weight;
                        Q.push(update);
                    }
                    else
                    {
                        dp[update] = min(dp[update], dp[top] + edge_weight);
                    }
                }
            }
        }
        else
        {
            for (int z = 0; z < 2; z++)
            {
                int di = i + dxH[z];
                int dj = j + dyH[z];
                if (di >= 1 && di <= n && dj >= 1 && dj <= n)
                {
                    int edge_weight = north[min(i, di)];
                    Node update = {{di, dj}, H};
                    if (dp.find(update) == dp.end())
                    {
                        dp[update] = dp[top] + edge_weight;
                        Q.push(update);
                    }
                    else
                    {
                        dp[update] = min(dp[update], dp[top] + edge_weight);
                    }
                }
            }
        }
    }
    return min(dp[{E, V}], dp[{E, H}]);
}

int main()
{
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        cin >> north[i+1];
    }
    for (int i = 0; i < n - 1; i++)
    {
        cin >> west[i+1];
    }
    int q;
    cin >> q;
    while (q--)
    {
        int p1, p2, q1, q2;
        cin >> p1 >> p2 >> q1 >> q2;
        cout << solve({p1, p2}, {q1, q2}) << endl;
    }
}