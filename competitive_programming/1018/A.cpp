// je m appelle Alvaro Brito. J ai 22 ans.
#include <bits/stdc++.h>
#define endl '\n'
#define wp ' '
#define fori(a, b) for (int i = a; i <= b; i++)
#define pb push_back
#define ull unsigned long long
#define pi pair<int, int>
#define ll long long
#define pl pair<ll, ll>
#define vi vector<int>
#define vl vector<ll>

int test_cases;
using namespace std;

void Solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    int less = 0;
    int great = n;
    vl a(n);
    for (int i = n - 2; i >= 0; i--)
    {
        if (s[i] == '<')
        {
            a[i + 1] = ++less;
        }
        else
        {
            a[i + 1] = great--;
        }
    }
    a[0] = great;
    fori(0, n - 1) cout << a[i] << wp;
    cout << endl;
}

int main()
{
    cin >> test_cases;
    while (test_cases--)
    {
        Solve();
    }
    return 0;
}
