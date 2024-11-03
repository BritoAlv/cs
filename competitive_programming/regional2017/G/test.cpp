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

const ll MOD = 1000000000 + 7;
const int maxn = 1e5 + 5;

int gate_l[maxn];
int gate_r[maxn];
int gate_b[maxn];
ll dpGood[maxn][2];

vector<int> NAND1_X = {0, 0, 1};
vector<int> NAND1_Y = {1, 0, 0};

vector<int> BAD_X = {0, 1, 1};
vector<int> BAD_Y = {1, 1, 0};

map<pair<int, int>, ll> diferent;
map<pair<int, int>, ll> common;

ll rec_solve(int cur, int correct_value);

ll common_value(int cur, int common_val)
{
    pair<int, int> v = {cur, common_val};
    if (common.find(v) != common.end())
    {
        return common[v];
    }
    ll result;
    if (cur == -1)
    {
        result = 1;
    }
    else if (gate_b[cur] == 0)
    {
        if (common_val == 0)
            result = dpGood[cur][0];
        else
            result = 0;
    }
    else if (gate_b[cur] == 1)
    {
        if (common_val == 1)
            result = dpGood[cur][1];
        else
            result = 0;
    }
    else
    {
        if (common_val == 0)
        {
            result = common_value(gate_l[cur] - 1, 1) * common_value(gate_r[cur] - 1, 1);
            result %= MOD;
            // l (0, 1), (0, 0), (1, 0), (1, 1)
            // r (0, 1), (0, 0), (1, 0), (1, 1)
        }
        else
        {
            result = 0;
            int l = gate_l[cur] - 1;
            int r = gate_r[cur] - 1;
            result += (rec_solve(l, 0) * common_value(r, 0)) % MOD;
            result %= MOD;
            result += (rec_solve(l, 0) * rec_solve(r, 1)) % MOD;
            result %= MOD;
            result += (common_value(l, 0) * rec_solve(r, 0)) % MOD;
            result %= MOD;
            result += (common_value(l, 0) * common_value(r, 0)) % MOD;
            result %= MOD;
            result += (common_value(l, 0) * common_value(r, 1)) % MOD;
            result %= MOD;
            result += (common_value(l, 0) * rec_solve(r, 1)) % MOD;
            result %= MOD;
            result += (rec_solve(l, 1) * rec_solve(r, 0)) % MOD;
            result %= MOD;
            result += (rec_solve(l, 1) * common_value(r, 0)) % MOD;
            result %= MOD;
            result += (common_value(l, 1) * common_value(r, 0)) % MOD;
            result %= MOD;
        }
    }

    // printf("From gate %d with common value %d can be created %Ld test patterns \n", cur + 1, common_val, result);
    return common[v] = result;
}

ll rec_solve(int cur, int correct_value)
{
    /*
    count in how many ways in this gate we can have different values,
    so that in the ok circuit result up to this gate is correct_value,
    thus in the broken circuit it will be !correct_value.
    */
    pair<int, int> v = {cur, correct_value};
    if (diferent.find(v) != diferent.end())
    {
        return diferent[v];
    }
    ll result;
    if (cur == -1)
    {
        result = 0;
    }
    else if (gate_b[cur] == 0)
    {
        /*
        if in the broken the gate always outputs 0 then
        if the correct value its one then
        */
        if (correct_value == 0)
        {
            result = 0;
        }
        else
        {
            result = dpGood[cur][1];
        }
    }
    else if (gate_b[cur] == 1)
    {
        if (correct_value == 1)
        {
            result = 0;
        }
        else
        {
            result = dpGood[cur][0];
        }
    }
    else
    {
        if (correct_value == 0)
        {
            /*
            correct value will be 1 from left, and 1 to right. this correct will be 0.
            O NAND 1 = 1, incorrect will be 1.
            */
            ll ans = 0;
            ll part1 = rec_solve(gate_l[cur] - 1, 1); // (1, 0)
            ll part2 = rec_solve(gate_r[cur] - 1, 1); // (1, 0)
            ans += part1 * part2;
            ans %= MOD;
            /*
            have to count patterns gates such that in both good and bad gave the same result.
            */
            ans += (part1 * (common_value(gate_r[cur] - 1, 1))) % MOD; // (1, 1)
            ans %= MOD;
            ans += (part2 * (common_value(gate_l[cur] - 1, 1))) % MOD; // (1, 1)
            ans %= MOD;

            result = ans;
        }
        else
        {
            ll ans = 0;
            ll part1 = rec_solve(gate_l[cur] - 1, 0); // (0, 1)
            ll part2 = rec_solve(gate_r[cur] - 1, 0); // (0, 1)
            ans += part1 * part2;
            ans %= MOD;
            ans += (part1 * (common_value(gate_r[cur] - 1, 1))) % MOD; // (1, 1)
            ans %= MOD;
            ans += (part2 * (common_value(gate_l[cur] - 1, 1))) % MOD; // (1, 1)
            ans %= MOD;
            result = ans;
        }
    }
    //printf("From gate %d with correct value %d can be created %Ld test patterns \n", cur + 1, correct_value, result);
    return diferent[v] = result;
}

int main()
{
    cin >> n;
    adj = vector<vector<int>>(n);
    forn
    {
        cin >> gate_l[i] >> gate_r[i] >> gate_b[i];
        if (gate_l[i] > 0)
            adj[gate_l[i] - 1].push_back(i);
        if (gate_r[i] > 0)
            adj[gate_r[i] - 1].push_back(i);
    }

    topological_sort();
    for (int i : ans)
    {
        dpGood[i][0] =
            (gate_l[i] == 0 ? 1 : dpGood[gate_l[i] - 1][1]) * (gate_r[i] == 0 ? 1 : dpGood[gate_r[i] - 1][1]);
        dpGood[i][0] %= MOD;
        dpGood[i][1] = 0;
        for (int j = 0; j < 3; j++)
        {
            dpGood[i][1] += ((gate_l[i] == 0 ? 1 : dpGood[gate_l[i] - 1][NAND1_X[j]]) *
                            (gate_r[i] == 0 ? 1 : dpGood[gate_r[i] - 1][NAND1_Y[j]])) % MOD;
            dpGood[i][1] %= MOD;
        }

        // printf("Gate %d values are: (0,ok) = %Ld, (1,ok) = %Ld  \n", i + 1, dpGood[i][0], dpGood[i][1]);
    }
    cout << (rec_solve(0, 0) + rec_solve(0, 1)) % MOD << endl;
}