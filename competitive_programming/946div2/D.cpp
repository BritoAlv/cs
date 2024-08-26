// Problem: D. Bit Guessing Game
// Contest: Codeforces - Codeforces Round 846 (Div. 2)
// URL: https://codeforces.com/contest/1780/problem/D
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

void Solve()
{
    int bits0;
    cin >> bits0;
    vector<pi> states;

    auto know_on = [&states]() -> int {
        int ans = 0;
        for (auto x : states)
        {
            ans += x.second == 1;
        }
        return ans;
    };

    auto show_ans = [&states]() -> void {
        int number = 0;
        for (auto x : states)
        {
            if (x.second)
            {
                number += (1 << x.first);
            }
        }
        for (int i = 0; i < sz(states); i++)
        {
            number += (1 << i);
        }
        cout << "!" << wp << number << endl;
        cout.flush();
    };

    auto do_query = [](int x) -> int {
        cout << "-" << wp << (1 << x) << endl;
        cout.flush();
        int m;
        cin >> m;
        return m;
    };

    int current = 0;

    for (int i = 0; i < 30; i++)
    {
        if (know_on() == bits0)
        {
            show_ans();
            break;
        }
        int bits1 = do_query(current);
        if (bits1 >= bits0)
        {
            states.pb({current, 1});
        }
        else
        {
            if (bits1 == 0)
            {
                states.pb({current, 0});
                show_ans();
                break;
            }
            else
            {
                states.pb({current, 0});
            }
        }
        current++;
        bits0 = bits1;
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
