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

/*
xq el approach de mezclar los segmentos funciona, parece intuitivo pero porque funcionaría eso ??
*/

void mix(stack<pi> &q, pi A)
{
    if (sz(q) == 0)
    {
        if (even(A.first))
        {
            // cout << "CASE_-1" << endl;
        }
        else
        {
            // cout << "CASE_0" << endl;
            q.push(A);
        }
        return;
    }
    auto m = q.top();
    q.pop();
    if (A.second == m.second || (even(A.first) && even(m.first)))
    {
        // cout << "CASE_1" << endl;
        m.first += A.first;
        mix(q, m);
    }
    else if (odd(A.first) && odd(m.first))
    {
        // cout << "CASE_2" << endl;
        q.push(m);
        q.push(A);
    }
    else if (even(A.first))
    {
        // cout << "CASE_3" << endl;
        m.first += A.first;
        mix(q, m);
    }
    else
    {
        // cout << "CASE_4" << endl;
        m.first += A.first;
        m.second = A.second;
        mix(q, m);
    }
}

void Solve()
{
    int n;
    cin >> n;
    vi a(n);
    forn
    {
        cin >> a[i];
    }
    vector<pi> sg;
    forn
    {
        int ed = i;
        while (ed + 1 < n && a[ed + 1] % 2 == a[ed] % 2)
        {
            ed++;
        }
        sg.pb({ed - i + 1, a[i] % 2});
        i = ed;
    }
    stack<pi> q;
    for (int i = 0; i < sz(sg); i++)
    {
        mix(q, sg[i]);
    }
    cout << (sz(q) >= 2 ? "NO" : "YES") << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    // cin >> test_cases;
    test_cases = 1;
    while (test_cases-- > 0)
    {
        Solve();
    }
    return 0;
}
