// Problem: D. Labelling Cities
// Contest: Codeforces - Tinkoff Challenge - Final Round (Codeforces Round 414, rated, Div. 1 + Div. 2)
// URL: https://codeforces.com/contest/794/problem/D
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

vector<long long> hashes1(300000, 0);
vector<long long> hashes2(300000, 0);
vector<long long> hashes3(300000, 0);
int labels[300000];
int dist[300000];

long long MOD1 = 1000000007;
long long MOD2 = 13432431;
long long MOD3 = 34324237;

long long pow(long long base, long long exp, long long MOD)
{
    if (exp == 0)
    {
        return 1ll;
    }
    else if (exp == 1)
    {
        return base % MOD;
    }
    else
    {
        if (exp % 2 == 0)
        {
            long long A = pow(base, exp / 2, MOD) % MOD;
            A *= A;
            A %= MOD;
            return A;
        }
        else
        {
            long long A = pow(base, 1, MOD);
            A *= pow(base, exp - 1, MOD);
            A %= MOD;
            return A;
        }
    }
}

void labeller(int n, int lab, vector<vector<long long>> &graph)
{
    labels[n] = lab;
    bool at_most_one = false;
    long long saved_hash1 = -1;
    long long saved_hash2 = -1;
    long long saved_hash3 = -1;
    int vertex = -1;
    for (auto x : graph[n])
    {
        if (x != n && labels[x] == -1)
        {
            if (hashes1[n] == hashes1[x] && hashes2[n] == hashes2[x] && hashes3[n] == hashes3[x])
            {
                labels[x] = lab;
            }
            else
            {
                if (!at_most_one)
                {
                    vertex = x;
                    saved_hash1 = hashes1[x];
                    saved_hash2 = hashes2[x];
                    saved_hash3 = hashes3[x];
                    at_most_one = true;
                }
                else if (hashes1[x] == saved_hash1 && hashes2[x] == saved_hash2 && hashes3[x] == saved_hash3)
                {
                    labels[x] = lab + 1;
                }
                else
                {
                    labels[n] = -2;
                    return;
                }
            }
        }
    }
    if (at_most_one)
    {
        labeller(vertex, lab + 1, graph);
    }
}

void Solve()
{
    long long n, m;
    cin >> n >> m;
    vector<vector<long long>> graph;
    forn
    {
        graph.pb(vector<long long>());
        graph[i].pb(i);
    }
    for (int i = 0; i < m; i++)
    {
        long long a, b;
        cin >> a >> b;
        graph[a - 1].pb(b - 1);
        graph[b - 1].pb(a - 1);
    }
    forn
    {
        long long sum1 = 0;
        long long sum2 = 0;
        long long sum3 = 0;
        for (auto x : graph[i])
        {
            sum1 += pow(2314233, x, MOD1);
            sum2 += pow(3241242, x, MOD2);
            sum3 += pow(2839133, x, MOD3);
        }
        hashes1[i] = sum1;
        hashes2[i] = sum2;
        hashes3[i] = sum3;
    }
    forn
    {
        dist[i] = -1;
        labels[i] = -1;
    }
    dist[0] = 0;
    queue<int> q;
    q.push(0);
    while (q.size() > 0)
    {
        auto top = q.front();
        q.pop();
        for (auto x : graph[top])
        {
            if (dist[x] == -1)
            {
                dist[x] = dist[top] + 1;
                q.push(x);
            }
        }
    }
    int deepest = 0;
    forn
    {
        if (dist[i] > dist[deepest])
        {
            deepest = i;
        }
        else if (dist[i] == dist[deepest] && hashes1[i] != hashes1[0])
        {
            deepest = i;
        }
    }
    labeller(deepest, 1, graph);
    forn
    {
        if (labels[i] < 0)
        {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
    forn
    {
        cout << labels[i] << wp;
    }
    cout << endl;
    return;
}

int main()
{
    int test_cases = 1;
    while (test_cases > 0)
    {
        Solve();
        test_cases--;
    }
    return 0;
}