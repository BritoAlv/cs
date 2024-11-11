#include <bits/stdc++.h>

#define forn for (int i = 0; i < n; i++)
#define endl '\n'
#define wp ' '
#define ll long long
#define pb push_back
using namespace std;

int cost(int a, int b)
{
    int t = abs(a - b);
    return min(t, 24 - t);
}

int len(int a, int b)
{
    return b - a + 1;
}

map<pair<int, int>, int> dp;

int rec_solve(vector<int> &val, int l, int r)
{
    if(dp.find({l, r}) != dp.end())
    {
        return dp[{l, r}];
    }
    int result = 1000000000;
    for (int i = l + 1; i <= r; i += 2)
    {
        if(len(l+1, i-1) % 2 == 0 && len(i+1, r) % 2 == 0)
        {
            int aport = cost(val[l], val[i]);
            if(len(l+1, i-1))
            {
                aport += rec_solve(val, l + 1, i - 1);
            }
            if(len(i+1, r))
            {
                aport += rec_solve(val, i + 1, r);
            }
            result = min(aport, result);
        }
    }
    return dp[{l, r}] = result;
}

int main()
{
    int n ;
    cin >> n;
    map<int, int> Q;
    forn
    {
        int x;
        cin >> x;
        if(Q.find(x) == Q.end())
        {
            Q.emplace(x, 0);
        }
        Q[x]++;
    }
    vector<int> values;
    for(auto z : Q)
    {
        if(z.second % 2)
        {
            values.push_back(z.first);
        }
    }
    n = values.size();
    sort(values.begin(), values.end());
    cout << rec_solve(values, 0, n - 1) << endl;
}