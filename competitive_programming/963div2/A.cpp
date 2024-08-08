// Problem: A. Question Marks
// Contest: Codeforces - Codeforces Round 963 (Div. 2)
// URL: https://codeforces.com/contest/1993/problem/A
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

void Solve()
{
    int n;
    cin >> n;
    n *= 4;
    map<int, int> A;
    A['A'] = 0;
    A['B'] = 0;
    A['C'] = 0;
    A['D'] = 0;
    A['?'] = 0;
    forn
    {
        char x;
        cin >> x;
        A[x]++;
    }
    int additional = 0;
    int correct = 0;
    int prop = 0;
    for (auto x : A)
    {
        if (x.first != '?')
        {
            additional += max(0, n / 4 - x.second);
            correct += min(n / 4, x.second);
        }
        else
        {
            prop += x.second;
        }
    }
    cout << correct << endl;
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
