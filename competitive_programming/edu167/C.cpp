// Problem: C. Two Movies
// Contest: Codeforces - Educational Codeforces Round 167 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1989/problem/C
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

void Solve()
{
    int n;
    cin >> n;
    int mov1 = 0;
    int mov2 = 0;
    auto to_min = [&mov1, &mov2](int dt) -> void {
        if (mov1 < mov2)
        {
            mov1 += dt;
        }
        else
        {
            mov2 += dt;
        }
    };
    auto to_max = [&mov1, &mov2](int dt) -> void {
        if (mov1 > mov2)
        {
            mov1 += dt;
        }
        else
        {
            mov2 += dt;
        }
    };
    int pp = 0;
    int mm = 0;
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
    forn
    {
        if (a[i] == -1 && b[i] == -1)
        {
            mm++;
        }
        if (a[i] == 0 && b[i] == 1)
        {
            mov2++;
        }
        if (a[i] == 1 && b[i] == 0)
        {
            mov1++;
        }
        if (a[i] == 1 && b[i] == 1)
        {
            pp++;
        }
        if (a[i] == -1 && b[i] == 1)
        {
            mov2++;
        }
        if (a[i] == 1 && b[i] == -1)
        {
            mov1++;
        }
    }
    while (pp > 0)
    {
        to_min(1);
        pp--;
    }
    while (mm > 0)
    {
        to_max(-1);
        mm--;
    }
    cout << min(mov1, mov2) << endl;
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