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
// je m appelle Alvaro j ai 21 ans.

using namespace std;

void Solve()
{
    int n, k;
    cin >> n >> k;
    vi a(n);
    vi b(n);
    forn
    {
        cin >> a[i];
    }
    forn
    {
        cin >> b[i];
    }
    vector<pi> valids;
    forn
    {
        if (b[i] >= a[i])
            valids.pb({b[i], a[i]});
    }
    sort(valids.begin(), valids.end());
    n = valids.sz;
    vector<ll> psums(n);
    forn
    {
        psums[i] = valids[i].first - valids[i].second;
        if (i > 0)
            psums[i] += psums[i - 1];
    }
    if (k == 0)
    {
        ll sum = 0;
        forn
        {
            sum += valids[i].first - valids[i].second;
        }
        cout << sum << endl;
        return;
    }
    priority_queue<int> vals;
    ll sum = 0;
    ll maxx = 0;
    auto umax = [&maxx](ll cd) -> void { maxx = max(cd, maxx); };
    for (int i = n - 1; i > 0; i--)
    {
        if (vals.sz == k && vals.sz > 0 && vals.top() >= valids[i].second)
        {
            sum -= vals.top();
            sum += valids[i].second;
            vals.pop();
            vals.push(valids[i].second);
        }
        else if (vals.sz < k)
        {
            sum += valids[i].second;
            vals.push(valids[i].second);
        }
        if (vals.sz == k)
        {
            umax(-sum + psums[i - 1]);
        }
    }
    cout << maxx << endl;
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int test_cases;
    cin >> test_cases;
    // int start = 0;
    while (test_cases-- > 0)
    {
        /*
        if(test_cases == -1)
        {
            // read and print the input;
            return;
        }
        */
        // cout << start++ << endl;
        Solve();
    }
    return 0;
}
