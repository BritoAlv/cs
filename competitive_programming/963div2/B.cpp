// Problem: B. Parity and Sum
// Contest: Codeforces - Codeforces Round 963 (Div. 2)
// URL: https://codeforces.com/contest/1993/problem/B
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Math Proof:
//
// Powered by CP Editor (https://cpeditor.org)

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

ll ceil(ll A, ll B)
{
    return A / B + (A % B != 0);
}

void Solve()
{
    int n;
    cin >> n;
    vl a(n);
    forn
    {
        cin >> a[i];
    }
    ll lo = -1;
    ll le = -1;
    int ne = 0;
    ll sum = 0;
    priority_queue<ll, vl, greater<ll>> qq;
    forn
    {
        if (a[i] % 2)
        {
            lo = max(a[i], lo);
        }
        else
        {
            le = max(a[i], le);
            qq.push(a[i]);
            ne++;
        }
    }
    if (lo == -1 || le == -1)
    {
        cout << 0 << endl;
    }
    else if (lo > le)
    {
        cout << ne << endl;
    }
    else
    {
        int ops = 0;
        while (qq.sz > 0)
        {
            ll top = qq.top();
            if (lo > top)
            {
                ops++;
                qq.pop();
                lo += top;
            }
            else
            {
                ops += qq.sz + 1;
                break;
            }
        }
        cout << ops << endl;
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