#include <bits/stdc++.h>

#define forn for (int i = 0; i < n; i++)
#define endl '\n'
#define wp ' '
#define ll long long
#define pb push_back
using namespace std;

int main()
{
    int n, c, s;
    cin >> n >> c >> s;
    s--;
    vector<int> C(c);
    int cs = 0;
    int ans = (cs == s);
    for (int i = 0; i < c; i++)
    {
        cin >> C[i];
        if (C[i] == 1)
        {
            cs = (cs + 1) % n;
        }
        else
        {
            cs = (n + cs - 1) % n;
        }
        ans += (cs == s);
    }
    cout << ans << endl;
}