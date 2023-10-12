// Problem: H. Mad City
// Contest: Codeforces - Codeforces Round 898 (Div. 4)
// URL: https://codeforces.com/contest/1873/problem/H
// Memory Limit: 256 MB
// Time Limit: 4000 ms
// Math Proof:
//
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
#define endl '\n'
#define wp ' '
#define forn for (int i = 0; i < n; i++)
using namespace std;

int test_cases;

void Solve()
{
    int n, m, v;
    cin >> n >> m >> v;
    m--;
    v--;
    vector<vector<int>> adyacency;
    forn
    {
        vector<int> row;
        adyacency.push_back(row);
    }
    forn
    {
        int j, k;
        cin >> j >> k;
        adyacency[j - 1].push_back(k - 1);
        adyacency[k - 1].push_back(j - 1);
    }

    int dM[n];
    vector<bool> usedM(n, false);
    queue<int> q;
    q.push(m);
    dM[m] = 0;
    usedM[m] = true;
    while (q.size() > 0)
    {
        int next = q.front();
        q.pop();
        for (auto x : adyacency[next])
        {
            if (!usedM[x])
            {
                usedM[x] = true;
                q.push(x);
                dM[x] = dM[next] + 1;
            }
        }
    }

    vector<bool> usedV(n, false);
    int dV[n];
    int pV[n];
    dV[v] = 0;
    pV[v] = v;
    q.push(v);
    usedV[v] = true;
    unordered_set<int> dr;
    while (q.size() > 0)
    {
        int next = q.front();
        q.pop();
        for (auto x : adyacency[next])
        {
            if (!usedV[x])
            {
                usedV[x] = true;
                q.push(x);
                dV[x] = dV[next] + 1;
                pV[x] = next;
            }
            else if (x != next && x != pV[next])
            {
                queue<int> vals;
                vals.push(x);
                vals.push(next);
                while (vals.size() > 0)
                {
                    int t = vals.front();
                    vals.pop();
                    if (dr.find(t) != dr.end())
                    {
                        break;
                    }
                    else
                    {
                        dr.insert(t);
                        vals.push(pV[t]);
                    }
                }
            }
        }
    }

    for (auto x : dr)
    {
        if (dV[x] < dM[x])
        {
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO" << endl;

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