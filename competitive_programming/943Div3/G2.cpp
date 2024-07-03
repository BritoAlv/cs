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

vector<int> z_function(string s)
{
    int n = s.size();
    vector<int> z(n);
    int l = 0, r = 0;
    for (int i = 1; i < n; i++)
    {
        if (i < r)
        {
            z[i] = min(r - i, z[i - l]);
        }
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
        {
            z[i]++;
        }
        if (i + z[i] > r)
        {
            l = i;
            r = i + z[i];
        }
    }
    return z;
}

int lg_split(int len, set<int> &fl)
{
    int pt = 0;
    int adv = 1;
    while (1)
    {
        auto search = fl.lower_bound(pt + len);
        if (search == fl.end())
        {
            break;
        }
        else
        {
            adv += 1;
            pt = *search;
        }
    }
    return adv;
}

void Solve()
{
    int n, l, r;
    cin >> n >> l >> r;
    vi ans(r - l + 1, 0);
    string s;
    cin >> s;
    vi zz = z_function(s);
    map<int, vi> pos;
    forn
    {
        pos[i] = vi();
    }
    forn
    {
        pos[zz[i]].pb(i);
    }
    int len = n - 1;
    set<int> fl;
    while (len > 0)
    {
        for (auto x : pos[len])
        {
            fl.insert(x);
        }
        int m = lg_split(len, fl);
        for (int i = min(r - l, m - l); i >= 0; i--)
        {
            if (ans[i] == 0)
            {
                ans[i] = len;
            }
            else
            {
                break;
            }
        }
        len--;
    }
    if (l == 1)
    {
        ans[0] = n;
    }
    for (auto x : ans)
    {
        cout << x << wp;
    }
    cout << endl;
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
