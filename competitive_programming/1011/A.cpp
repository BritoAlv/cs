// Problem: A. Serval and String Theory
// Contest: Codeforces - Codeforces Round 1011 (Div. 2)
// URL: https://codeforces.com/contest/2085/problem/A
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Math Proof:
//
// Powered by CP Editor (https://cpeditor.org)

// je m appelle Alvaro Brito. J ai 22 ans.
#include <bits/stdc++.h>
#define endl '\n'
#define wp ' '
#define fori(a, b) for (int i = a; i <= b; i++)
#define forj(a, b) for (int j = a; j <= b; j++)
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
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    string rev_s;
    rev_s = s;
    reverse(rev_s.begin(), rev_s.end());
    if (k == 0)
    {
        fori(0, n - 1)
        {
            if (s[i] < rev_s[i])
            {
                cout << "YES" << endl;
                return;
            }
            else if (s[i] > rev_s[i])
            {
                cout << "NO" << endl;
                return;
            }
        }
        cout << "NO" << endl;
    }
    else
    {
        sort(s.begin(), s.end());
        if (s[n - 1] != s[0])
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
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
