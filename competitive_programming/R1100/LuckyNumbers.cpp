#include <bits/stdc++.h>
#define endl '\n'
#define wp ' '
#define forn for (int i = 0; i < n; i++)
#define form for (int j = 0; j < m; j++)
#define fork for (int i = 0; i < k; i++)
#define pb push_back
#define ull unsigned long long
#define pi pair<int, int>
#define sz size()
// je m appelle Alvaro j ai 21 ans.

using namespace std;

set<long long> luckiest;
vector<long long> prefix;
map<int, int> pos;
void generate_luckiest()
{
    for (int d = 1; d < 11; d++)
    {
        for (int i = 0; i < (1 << d); i++)
        {
            long long lucky = 0;
            for (int j = 0; j < d; j++)
            {
                lucky *= 10;
                lucky += ((i & (1 << j)) ? 4 : 7);
            }
            luckiest.insert(lucky);
        }
    }
    int prev = 0;
    for (auto x : luckiest)
    {
        pos[x] = prefix.sz;
        if (prefix.sz == 0)
        {
            prefix.pb(x * x);
        }
        else
        {
            prefix.pb(x * (x - prev) + prefix.back());
        }
        prev = x;
    }
}

long long rsolve(int l, int r)
{
    if (l > r)
    {
        return 0;
    }
    else
    {
        long long ans = 0;
        long long pt1 = *luckiest.lower_bound(l);
        long long pt2 = *luckiest.lower_bound(r);
        ans += (pt1 - l + 1) * pt1; // [l, pt1]
        if (pt2 > r)
            ans -= (pt2 - r - 1 + 1) * pt2;         // [r+1, pt2]
        ans += prefix[pos[pt2]] - prefix[pos[pt1]]; // [pt1+1, pt2]
        return ans;
    }
}

void Solve()
{
    int l, r;
    cin >> l >> r;
    cout << rsolve(l, r) << endl;
    return;
}

int main()
{
    generate_luckiest();
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int test_cases = 1;
    while (test_cases-- > 0)
    {
        Solve();
    }
    return 0;
}
