// You might break and that's okay.
// Tags:
#include <bits/stdc++.h>

#define fori(a, b) for (int i = a; i <= b; i++)
#define forj(a, b) for (int j = a; j <= b; j++)
#define wp " "
#define pb push_back
#define ull unsigned long long
#define pi pair<int, int>
#define ll long long
#define pl pair<ll, ll>
#define vi vector<int>
#define vl vector<ll>

int test_cases;
using namespace std;

int n;
int m;
vector<vi> edges;
vl a;

template <typename T> void print(const T &container)
{
    for (const auto &element : container)
    {
        std::cout << element << " ";
    }
    std::cout << "\n";
}

int solve(int max_weight)
{
    vl dp(n, -1);
    dp[0] = a[0];
    for (auto z : edges)
    {
        int from = z[0];
        int to = z[1];
        int weight = z[2];
        if (weight <= max_weight && dp[from] != -1 && dp[from] >= weight)
        {
            dp[to] = max(dp[to], dp[from] + a[to]);
        }
    }
    return dp[n - 1] != -1;
}

void Solve()
{
    cin >> n >> m;
    a = vl(n);
    edges = vector<vi>();
    fori(0, n - 1) cin >> a[i];
    set<int> weights;
    fori(0, m - 1)
    {
        int a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        weights.insert(c);
        edges.push_back({a, b, c});
    }
    if (m == 0)
    {
        cout << -1 << endl;
        return;
    }
    sort(edges.begin(), edges.end());
    vi wei;
    for (auto z : weights)
        wei.pb(z);
    if (!solve(wei.back()))
    {
        cout << -1 << endl;
        return;
    }
    int k = wei.size();
    int st = 0;
    int ed = k - 1;
    while (ed - st > 1)
    {
        int middle = st + (ed - st) / 2;
        if (solve(wei[middle]))
        {
            ed = middle;
        }
        else
        {
            st = middle + 1;
        }
    }
    if (ed - 1 >= st && solve(wei[ed - 1]))
    {
        ed--;
    }
    cout << wei[ed] << endl;
}

int main()
{
    cin >> test_cases;
    while (test_cases--)
    {
        Solve();
    }
    return 0;
}
