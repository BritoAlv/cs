// Problem: D. Grid Puzzle
// Contest: Codeforces - Codeforces Round 960 (Div. 2)
// URL: https://codeforces.com/contest/1990/problem/D
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

int abs(int a, int b)
{
    return max(a, b) - min(a, b);
}

void Solve()
{
    int n;
    cin >> n;
    vi a(n);
    vector<stack<pi>> AA;
    AA.pb(stack<pi>());
    forn
    {
        cin >> a[i];
    }
    for (int i = n - 1; i >= 0; i--)
    {
        if (a[i] > 0)
            AA.back().push({1, a[i]});
        else
        {
            AA.pb(stack<pi>());
        }
    }
    vector<int> ops;
    for (auto A : AA)
    {
        while (sz(A) > 0)
        {
            auto next = A.top();
            A.pop();
            if (next.second == 0)
            {
                continue;
            }
            if (next.second - next.first + 1 >= 3)
            {
                ops.pb(1);
            }
            else
            {
                if (sz(A) > 0)
                {
                    int l = next.first;
                    int r = next.second;

                    pi next_next = A.top();
                    if ((next_next.first >= l && next_next.second <= r) ||
                        (next_next.second - next_next.first + 1 <= 2 && r <= next_next.second))
                    {
                        ops.pb(2);
                        A.pop();
                    }
                    else if (l < next_next.first && r > next_next.second)
                    {
                        ops.pb(3);
                    }
                    else if (l == next_next.first && next_next.second > r)
                    {
                        ops.pb(4);
                        next_next.first = min(next_next.first + 2, next_next.second);
                        A.pop();
                        A.push(next_next);
                    }
                    else if (l == next_next.second - 1)
                    {
                        ops.pb(5);
                        next_next.second = max(l - 1, 1);
                        A.pop();
                        A.push(next_next);
                    }
                    else if (l == next_next.second)
                    {
                        ops.pb(6);
                        next_next.second = max(l - 2, 1);
                        A.pop();
                        A.push(next_next);
                    }
                    else
                    {
                        ops.pb(7);
                    }
                }
                else
                {
                    ops.pb(8);
                }
            }
        }
    }
    cout << sz(ops) << endl;
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
