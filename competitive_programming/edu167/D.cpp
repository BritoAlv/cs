#include <bits/stdc++.h>
#define endl '\n'
#define wp ' '
#define forn for (int i = 0; i < n; i++)
#define form for (int j = 0; j < m; j++)
#define fork for (int i = 0; i < k; i++)
#define pb push_back
#define ull unsigned long long
#define pi pair<int, int>
#define ll long long
#define pl pair<ll, ll>
#define sz size()
#define vi vector<int>
#define vl vector<ll>
#define exist(container, obj) (container.find(obj) != container.end())
#define yesno(obj) cout << (obj ? "YES" : "NO") << endl
#define print(x, name)                                                                                                 \
    cout << name << endl;                                                                                              \
    for (auto z : x)                                                                                                   \
        cout << z << wp;                                                                                               \
    cout << endl;
// je m appelle Alvaro j ai 21 ans.
int test_cases;
int test_cases_original;
#define t_number test_cases_original - test_cases

using namespace std;

void Solve()
{
    int n, m;
    cin >> n >> m;
    vector<pi> a(n);
    vi c(m);
    forn
    {
        cin >> a[i].first;
    }
    forn
    {
        cin >> a[i].second;
    }
    priority_queue<pi, vector<pi>, greater<pi>> A;
    forn
    {
        A.push(a[i]);
    }
    form
    {
        cin >> c[j];
    }
    set<int> best;
    vl dp(1000001, 0);
    for (int c = 0; c < 1000001; c++)
    {
        while (A.sz > 0 && c >= A.top().first)
        {
            auto next = A.top();
            best.insert(next.first - next.second);
            A.pop();
        }
        if (best.sz == 0)
        {
            dp[c] = 0;
        }
        else
        {
            int best_dif = *best.begin();
            dp[c] = 2 + dp[c - best_dif];
        }
    }
    ll ans = 0;
    form
    {
        ll part = 0;
        if (c[j] > 1000000)
        {
            ll dif = c[j] - 1000000;
            dif /= *best.begin();
            c[j] -= dif * *best.begin();
            part += 2 * dif;
        }
        while (c[j] > 1000000)
        {
            c[j] -= *best.begin();
            part += 2;
        }
        part += dp[c[j]];
        ans += part;
    }
    cout << ans << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    test_cases_original = 1;
    test_cases = test_cases_original;
    while (test_cases-- > 0)
    {
        Solve();
    }
    return 0;
}
