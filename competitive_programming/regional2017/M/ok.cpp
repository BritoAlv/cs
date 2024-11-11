#include <bits/stdc++.h>

#define forn for (int i = 0; i < n; i++)
#define endl '\n'
#define wp ' '
#define ll long long
#define pb push_back
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<vector<int>> P(n);
    vector<pair<int, int>> Q;
    int pt = 0;
    forn
    {
        int k;
        cin >> k;
        for (int j = 0; j < k; j++)
        {
            int x;
            cin >> x;
            P[i].pb(x);
            Q.push_back({i, pt++});
        }
    }
    unsigned long long score = 0;
    vector<int> ans;
    do
    {
        unsigned long long cur = 0;
        vector<int> vals;
        vector<int> pts(n, 0);
        for (auto op : Q)
        {
            int q = op.first;
            int val = P[q][pts[q]];
            vals.push_back(P[q][pts[q]++]);
            cur *= 10;
            cur += val;
        }
        if (ans.size() == 0 || cur < score)
        {
            ans = vals;
            score = cur;
        }
    } while (next_permutation(Q.begin(), Q.end()));
    for (auto z : ans)
    {
        cout << z;
    }
    cout << endl;
}

int main()
{
    int t;
    cin >> t;
    while(t-- > 0)
    {
        solve();
    }
}