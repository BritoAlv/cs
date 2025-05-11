// Problem: C. Maximum Subarray Sum
// Contest: Codeforces - Codeforces Round 1023 (Div. 2)
// URL: https://codeforces.com/contest/2107/problem/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Math Proof:
//
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
#define endl '\n'
#define wp ' '
#define forn for (int i = 0; i < n; i++)
#define form for (int j = 0; j < m; j++)
#define fork for (int i = 0; i < k; i++)
#define fori(a, b) for (int i = a; i <= b; i++)
#define even(x) ((x) % 2 == 0)
#define odd(x) ((x) % 2 == 1)
#define pb push_back
#define ull unsigned long long
#define pi pair<int, int>
#define ll long long
#define pl pair<ll, ll>
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
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

long long n_inf = -1e18;

ll max_sub_sum(vl &a)
{
    int n = a.size();
    vl dp(n);
    dp[n - 1] = a[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        dp[i] = a[i];
        dp[i] = max(dp[i], a[i] + dp[i + 1]);
    }
    ll maxx = dp[0];
    forn maxx = max(dp[i], maxx);
    return maxx;
}

void Solve()
{
    ll n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vl a(n);
    vl b(n);
    forn cin >> a[i];
    forn b[i] = a[i];
    forn if (s[i] == '0') b[i] = n_inf;
    vector<int> zeros_pos;
    forn
    {
        if (s[i] == '0')
        {
            zeros_pos.pb(i);
        }
    }
    ll sub_sum = max_sub_sum(b);
    if (k < sub_sum)
    {
        cout << "No" << endl;
    }
    else if (zeros_pos.size() == 0)
    {
        if (sub_sum == k)
        {
            cout << "Yes" << endl;
            forn cout << b[i] << wp;
            cout << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }
    else
    {
        int pos = zeros_pos[0];
        ll left_sum = 0;
        ll left_max_sum = n_inf;
        ll right_sum = 0;
        ll right_max_sum = n_inf;
        for (int i = pos - 1; i >= 0; i--)
        {
            if (b[i] == n_inf)
            {
                break;
            }
            left_sum += a[i];
            left_max_sum = max(left_sum, left_max_sum);
        }
        for (int i = pos + 1; i < n; i++)
        {
            if (b[i] == n_inf)
            {
                break;
            }
            right_sum += a[i];
            right_max_sum = max(right_sum, right_max_sum);
        }
        // cout << left_max_sum << wp << right_max_sum << endl;
        if (left_max_sum >= 0 && right_max_sum >= 0)
        {
            b[pos] = k - left_max_sum - right_max_sum;
        }
        else if (left_max_sum >= 0)
        {
            b[pos] = k - left_max_sum;
        }
        else if (right_max_sum >= 0)
        {
            b[pos] = k - right_max_sum;
        }
        else
        {
            b[pos] = k;
        }
        ll sec = max_sub_sum(b);
        assert(sec == k);
        cout << "Yes" << endl;
        forn cout << b[i] << wp;
        cout << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> test_cases_original;
    test_cases = test_cases_original;
    while (test_cases-- > 0)
    {
        Solve();
    }
    return 0;
}
