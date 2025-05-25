// Problem: C. Limited Repainting
// Contest: Codeforces - Educational Codeforces Round 175 (Rated for Div. 2)
// URL: https://codeforces.com/contest/2070/problem/C
// Memory Limit: 512 MB
// Time Limit: 2000 ms
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

int w(int mid, vl &c, string &p, int k)
{
    int n = c.size();
    // all the numbers greater than mid should be painted correctly.
    fori(0, n - 1)
    {
        if (p[i] == 'B' && c[i] > mid)
        {
            if (k == 0)
            {
                return 0;
            }
            int ed = i;
            while (ed + 1 < n && (p[ed + 1] == 'B' || (p[ed + 1] == 'R' && c[ed + 1] <= mid)))
            {
                ed++;
            }
            i = ed;
            k--;
        }
    }
    return 1;
}

void Solve()
{
    int n, k;
    cin >> n >> k;
    vl a(n);
    string s;
    cin >> s;
    fori(0, n - 1) cin >> a[i];
    int low = 0;
    int up = 1e9;
    while (up - low > 1)
    {
        int mid = low + (up - low) / 2;
        if (w(mid, a, s, k))
        {
            up = mid;
        }
        else
            low = mid + 1;
    }
    if (up - 1 >= 0 && w(up - 1, a, s, k))
    {
        up--;
    }
    cout << up << endl;
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
