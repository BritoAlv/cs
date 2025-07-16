// Problem: G. Chimpanzini Bananini
// Contest: Codeforces - Codeforces Round 1017 (Div. 4)
// URL: https://codeforces.com/problemset/problem/2094/G
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Math Proof:
//
// Powered by CP Editor (https://cpeditor.org)

// You might break and that's okay.
// Tags : deque, telescopic sum, state machine
#include <bits/stdc++.h>

#define fori(a, b) for (int i = a; i <= b; i++)
#define forj(a, b) for (int j = a; j <= b; j++)
#define wp " "
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
    int q;
    cin >> q;
    ll n = 0;
    ll sum_ai = 0;
    ll sum_total = 0;
    deque<ll> Q;
    int use_back = 1;
    while (q--)
    {
        int s;
        cin >> s;
        if (s == 1)
        {
            if (use_back)
            {
                sum_total = sum_total + sum_ai - n * Q.back();
                ll b = Q.back();
                Q.pop_back();
                Q.push_front(b);
            }
            else
            {
                sum_total = sum_total + sum_ai - n * Q.front();
                ll b = Q.front();
                Q.pop_front();
                Q.push_back(b);
            }
        }
        else if (s == 2)
        {
            sum_total = (n + 1) * sum_ai - sum_total;
            use_back = !use_back;
        }
        else
        {
            ll k;
            cin >> k;
            sum_ai += k;
            n++;
            sum_total += n * k;
            if (use_back)
            {
                Q.push_back(k);
            }
            else
            {
                Q.push_front(k);
            }
        }
        cout << sum_total << endl;
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
