// Problem: E. Guess the Cycle Size
// Contest: Codeforces - Codeforces Round 820 (Div. 3)
// URL: https://codeforces.com/problemset/problem/1729/E
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

ll do_query(ll a, ll b)
{
    cout << "?" << wp << a << wp << b << endl;
    cout.flush();
    ll x;
    cin >> x;
    return x;
}

void show_ans(ll a)
{
    cout << "!" << wp << a << endl;
    cout.flush();
}

void Solve()
{
    int initial_query = 7;
    while (1)
    {
        ll x = do_query(initial_query, initial_query - 1);
        if (x == -1)
        {
            initial_query -= 1;
        }
        else
        {
            break;
        }
    }
    vector<vl> graph(initial_query, vl(initial_query, 0));
    for (int i = 0; i < initial_query; i++)
    {
        for (int j = 0; j < initial_query; j++)
        {
            if (i != j)
            {
                graph[i][j] = do_query(i + 1, j + 1);
                graph[j][i] = do_query(j + 1, i + 1);
                if (graph[i][j] != graph[j][i])
                {
                    show_ans(graph[i][j] + graph[j][i]);
                    return;
                }
            }
        }
    }
    while (initial_query > 3)
    {
        ll x = do_query(initial_query, initial_query - 1);
        if (x == -1)
        {
            initial_query -= 1;
        }
        else
        {
            break;
        }
    }
    show_ans(initial_query);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    test_cases = 1;
    while (test_cases-- > 0)
    {
        Solve();
    }
    return 0;
}
