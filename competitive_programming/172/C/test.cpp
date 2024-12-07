#include <bits/stdc++.h>

#define doo(a) for (int i_i = 0; i_i < a; i_i++)
#define fori(a, b) for (int i = a; i <= b; i++)
#define forj(a, b) for (int j = a; j <= b; j++)
#define endl '\n'
#define wp ' '
#define ll long long
#define pb push_back
#define vi vector<int>
#define pi pair<int, int>

using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int ones = 0;
    int zeros = 0;
    vector<int> vals;
    for (int i = n - 1; i >= 1; i--)
    {
        ones += s[i] == '1';
        zeros += s[i] == '0';
        if (ones - zeros > 0)
        {
            vals.push_back(ones - zeros);
        }
    }
    sort(vals.begin(), vals.end(), greater<int>());
    ll sum = 0;
    fori(0, (int)vals.size() - 1)
    {
        sum += vals[i];
        if (sum >= k)
        {
            cout << (i + 2) << endl;
            return;
        }
    }
    cout << -1 << endl;
}

int main()
{
    int t = 1;
    cin >> t;
    while (t--)
        solve();
}
