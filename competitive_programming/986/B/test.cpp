#include <bits/stdc++.h>

#define forn for (int i = 0; i < n; i++)
#define endl '\n'
#define wp ' '
#define ll long long
#define pb push_back
using namespace std;

void solve()
{
    ll n, b, c;
    cin >> n >> b >> c;
    if (b == 0 && n > c+2)
    {
        cout << -1 << endl;
        return;
    }
    /*
    how many numbers from [0, n-1] can be expressed at b * i + c
    */
    if(n - 1 < c)
    {
        cout << n << endl;
    }
    else
    {
        ll tt = (b > 0 ? (n - 1 - c) / b : 0) + 1;
        cout << n - tt << endl;
    }
}

int main()
{
    int t;
    cin >> t;
    while (t-- > 0)
    {
        solve();
    }
}