// Problem: B. Robot Program
// Contest: Codeforces - Educational Codeforces Round 175 (Rated for Div. 2)
// URL: https://codeforces.com/contest/2070/problem/B
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

void Solve()
{
    ll n, x, k;
    cin >> n >> x >> k;
    string s;
    cin >> s;
    ll start_pos = -1;
    ll cur_pos = x;
    ll ans = 0;
    ll pt = 0;
    for (ll i = 0; i < k; i++)
    {
        if (s[pt] == 'L')
            cur_pos -= 1;
        else
            cur_pos += 1;
        pt++;
        if (pt == n)
        {
            if (cur_pos != 0)
            {
                break;
            }
            else
            {
                ans++;
                if (start_pos != -1)
                {
                    // reached 0 from [0, pt]
                    // [i+1, k - 1]
                    ll cycles = ((k - i - 2) / (pt));
                    ans += cycles;
                    i += (pt)*cycles;
                    pt = 0;
                    continue;
                }
                pt = 0;
            }
        }
        else
        {
            if (cur_pos == 0)
            {
                // if reached 0,
                ans++;
                if (start_pos != -1)
                {
                    // reached 0 from [0, pt]
                    // [i+1, k - 1]
                    ll cycles = ((k - i - 2) / (pt));
                    ans += cycles;
                    i += (pt)*cycles;
                    pt = 0;
                    continue;
                }
                start_pos = 0;
                pt = 0;
            }
        }
    }
    cout << ans << endl;
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
