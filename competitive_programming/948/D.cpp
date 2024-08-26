// Problem: D. XORificator
// Contest: Codeforces - Codeforces Round 948 (Div. 2)
// URL: https://codeforces.com/contest/1977/problem/D
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
const ll MOD1 = 998244353;
const ll MOD2 = 1000000007;
int test_cases;
int test_cases_original;
#define t_number test_cases_original - test_cases

using namespace std;

ll f_pow(ll base, ll exp, ll mod)
{
    if (exp == 0)
        return 1;
    if (exp == 1)
        return base % mod;
    ll middle = f_pow(base, exp / 2, mod);
    middle *= middle;
    middle %= mod;
    if (exp % 2)
    {
        middle *= base;
        middle %= mod;
    }
    return middle;
}

void validator(vector<vi> &board, vi st, int expected)
{
    int goods = 0;
    int m = sz(board[0]);
    int n = sz(board);
    vi count(m, 0);
    forn
    {
        form
        {
            if (board[i][j] ^ st[i])
            {
                count[j] += 1;
            }
        }
    }
    form
    {
        goods += count[j] == 1;
    }
    if (goods != expected)
    {
        cout << "BLA" << endl;
        forn
        {
            form
            {
                cout << board[i][j];
            }
            cout << endl;
        }
        cout << "BLA" << endl;
    }
}

void Solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> board(n, vector<int>(m));
    forn
    {
        form
        {
            char x;
            cin >> x;
            board[i][j] = (x - '0');
        }
    }
    map<pi, pl> states;
    map<pl, vector<pi>> reverse;
    vi cur_state(n, 0);
    ll cur_hash1 = 0;
    ll cur_hash2 = 0;
    auto update_hash = [&cur_state, &cur_hash1, &cur_hash2](int pos) -> void {
        ll change1 = f_pow(2, pos + 1, MOD1);
        ll change2 = f_pow(3, pos + 1, MOD2);
        if (cur_state[pos])
        {
            cur_hash1 -= change1;
            cur_hash2 -= change2;
        }
        else
        {
            cur_hash1 += change1;
            cur_hash2 += change2;
        }
        cur_hash1 %= MOD1;
        cur_hash2 %= MOD2;
        cur_state[pos] = !cur_state[pos];
    };
    form
    {
        forn
        {
            if (i == 0)
            {
                cur_state = vi(n, 0);
                cur_hash1 = 0;
                cur_hash2 = 0;
                for (int z = 0; z < n; z++)
                {
                    if (z == 0 && !board[z][j])
                    {
                        update_hash(0);
                    }
                    else if (z != 0 && board[z][j])
                    {
                        update_hash(z);
                    }
                }
            }
            else
            {
                update_hash(i - 1);
                update_hash(i);
            }
            pl cur_hash = {cur_hash1, cur_hash2};
            states[{i, j}] = cur_hash;
            if (!exist(reverse, cur_hash))
            {
                reverse[cur_hash] = vector<pi>();
            }
            reverse[cur_hash].pb({i, j});
        }
    }
    pl def = {-1, -1};
    pl maxx = def;
    for (auto x : reverse)
    {
        if (maxx == def || sz(reverse[maxx]) < sz(x.second))
        {
            maxx = x.first;
        }
    }
    cout << sz(reverse[maxx]) << endl;
    pi best = reverse[maxx][0];
    int row = best.first;
    int col = best.second;
    cur_state = vi(n, 0);
    forn
    {
        if (i == row && !board[row][col])
        {
            cur_state[i] = 1;
        }
        if (i != row && board[i][col])
        {
            cur_state[i] = 1;
        }
    }
    validator(board, cur_state, sz(reverse[maxx]));
    for (auto x : cur_state)
    {
        cout << x;
    }
    cout << endl;
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