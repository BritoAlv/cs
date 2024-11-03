#include <bits/stdc++.h>

#define forn for (int i = 0; i < n; i++)
#define endl '\n'
#define wp ' '
#define ll long long
#define pb push_back
using namespace std;

int n;                   
vector<vector<int>> adj;
vector<bool> visited;
vector<int> ans;

void dfs(int v)
{
    visited[v] = true;
    for (int u : adj[v])
    {
        if (!visited[u])
            dfs(u);
    }
    ans.push_back(v);
}

void topological_sort()
{
    visited.assign(n, false);
    ans.clear();
    for (int i = 0; i < n; ++i)
    {
        if (!visited[i])
        {
            dfs(i);
        }
    }
    reverse(ans.begin(), ans.end());
}

int main()
{
    cin >> n;
    vector<pair<int, int>> inputGate(n);
    vector<int> gateBehaviour(n);
    adj = vector<vector<int>>(n);
    int ext_input = 0;
    int ans2 = 0;
    forn
    {
        int a, b, c;
        cin >> a >> b >> c;
        ext_input += a == 0;
        ext_input += b == 0;
        inputGate[i] = {a, b};
        gateBehaviour[i] = c;
        if(a > 0)
            adj[--a].push_back(i);
        if(b > 0)
            adj[--b].push_back(i);
    }
    topological_sort();
    for (int mask = 0; mask < (1 << ext_input); mask++)
    {
        vector<int> values;
        for (int i = 0; i < ext_input; i++)
        {
            int on = (mask & (1 << i)) > 0;
            values.push_back(on);
        }
        vector<int> goodG(n);
        vector<int> badG(n);
        int pt = 0;
        for (int j = 0; j < n; j++)
        {
            int i = ans[j];
            int lG, rG;
            int lB, rB;
            if (inputGate[i].first == 0)
            {
                lG = values[pt];
                lB = values[pt];
                pt++;
            }
            else
            {
                lG = goodG[inputGate[i].first - 1];
                lB = badG[inputGate[i].first - 1];
            }
            if (inputGate[i].second == 0)
            {
                rG = values[pt];
                rB = values[pt];
                pt++;
            }
            else
            {
                rG = goodG[inputGate[i].second - 1];
                rB = badG[inputGate[i].second - 1];
            }
            if (gateBehaviour[i] == -1)
            {
                badG[i] = !(lB && rB);
            }
            else
            {
                badG[i] = gateBehaviour[i];
            }
            goodG[i] = !(lG && rG);
        }
        if (goodG[0] != badG[0])
        {
            //printf("Good is %d and Bad is %d \n", goodG[0], badG[0]);
            ans2++;
        }
    }
    cout << ans2 << endl;
}