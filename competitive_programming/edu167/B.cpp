// Problem: B. Substring and Subsequence
// Contest: Codeforces - Educational Codeforces Round 167 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1989/problem/B
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

int subseq(string &a, string &b)
{
    int pt1 = 0;
    int pt2 = 0;
    while (pt1 < a.sz && pt2 < b.sz)
    {
        if (a[pt1] != b[pt2])
        {
            pt1++;
        }
        else
        {
            pt2++;
            pt1++;
        }
    }
    return pt2;
}

void Solve()
{
    string a, b;
    cin >> a >> b;
    int lz = a.sz + b.sz;
    for (int p = 0; p <= b.sz; p++)
    {
        string r = "";
        for (int i = 0; i < p; i++)
        {
            r += b[i];
        }
        r += a;
        auto adv = subseq(r, b);
        lz = min(lz, (int)a.sz + (int)b.sz - adv + p);
    }
    cout << lz << endl;
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