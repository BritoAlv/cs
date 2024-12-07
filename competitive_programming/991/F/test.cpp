#include <bits/stdc++.h>

#define doo(a) for (int i_i = 0; i_i < a; i_i++)
#define fori(a, b) for (int i = a; i <= b; i++)
#define forj(a, b) for (int j = a; j <= b; j++)
#define endl '\n'
#define wp ' '
#define ll long long
#define pb push_back
#define vi vector<int>
#define pi pair<int, int>

using namespace std;

const int MAXN = 200001;
int t[4 * MAXN];

void build(vi &a, int v, int tl, int tr)
{
    if (tl == tr)
    {
        t[v] = a[tl];
    }
    else
    {
        int tm = (tl + tr) / 2;
        build(a, v * 2, tl, tm);
        build(a, v * 2 + 1, tm + 1, tr);
        t[v] = __gcd(t[v * 2], t[v * 2 + 1]);
    }
}

int sum(int v, int tl, int tr, int l, int r)
{
    if (l > r)
        return 0;
    if (l == tl && r == tr)
    {
        return t[v];
    }
    int tm = (tl + tr) / 2;
    return __gcd(sum(v * 2, tl, tm, l, min(r, tm)), sum(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r));
}

void solve2(int n, int q)
{
    vi a(n);
    vi dif(n - 1);
    fori(0, n - 1) cin >> a[i];
    fori(1, n - 1) dif[i - 1] = abs(a[i] - a[i - 1]);
    build(dif, 1, 0, n - 2);
	while(q--){
        int l, r;
        cin >> l >> r;
        l--, r--;
		if(l == r){
            cout << 0 << wp;
        } else {
            int summ = sum(1, 0, n - 2, l, r - 1);
            cout << summ << wp;
        }
    }
    cout << endl;
}

void solve()
{
    int n, q;
    cin >> n >> q;
    if (n >= 2)
    {
        solve2(n, q);
    } else {
        int x;
        cin >> x;
        while (q--)
        {
            int l, r;
            cin >> l >> r;
            cout << 0 << wp;
        }
        cout << endl;
    }
}

int main()
{
    int t = 1;
    cin >> t;
    while (t--)
        solve();
}
