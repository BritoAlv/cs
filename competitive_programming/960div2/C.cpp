// Problem: C. Mad MAD Sum
// Contest: Codeforces - Codeforces Round 960 (Div. 2)
// URL: https://codeforces.com/contest/1990/problem/C
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
#define even(x) (x % 2 == 0)
#define odd(x) (x % 2 == 1)
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

ll sum;

vi madd(vi &A)
{
    int n = A.sz;
    vi madd(n);
    set<int> freq;
    forn
    {
        if (exist(freq, A[i]))
        {
            madd[i] = max(A[i], madd[i - 1]);
        }
        else
        {
            freq.insert(A[i]);
            madd[i] = (i > 0 ? madd[i - 1] : 0);
        }
        sum += A[i];
    }
    return madd;
}

void Solve()
{
    int n;
    cin >> n;
    vi a(n);
    sum = 0;
    forn
    {
        cin >> a[i];
    }
    a = madd(a);
    a = madd(a);
    stack<pl> F;
    forn
    {
        int st = i;
        int ed = i;
        while (ed + 1 < n && a[ed] == a[ed + 1])
        {
            ed++;
        }
        i = ed;
        F.push({a[ed], ed - st + 1});
    }
    auto sq = [](ll q) -> ll { return (q * (q + 1)) / 2; };
    int pen = 0;
    while (F.sz > 0)
    {
        auto top = F.top();
        F.pop();
        sum += top.first * top.second * pen;
        sum += sq(top.second) * top.first;
        pen += top.second;
    }
    cout << sum << endl;
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
