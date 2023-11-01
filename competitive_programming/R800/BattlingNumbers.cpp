// Problem: B. Battling with Numbers
// Contest: Codeforces - COMPFEST 15 - Preliminary Online Mirror (Unrated, ICPC Rules, Teams Preferred)
// URL: https://codeforces.com/contest/1866/problem/B
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Math Proof:
//
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
#define endl '\n'
#define wp ' '
#define forn for (int i = 0; i < n; i++)
using namespace std;

int test_cases;

long long fast_exp(int exp)
{
    if (exp == 0)
    {
        return 1;
    }
    if (exp == 1)
    {
        return 2;
    }
    long long ans = fast_exp(exp / 2);
    ans *= ans;
    ans %= 998244353;
    if (exp % 2 == 1)
    {
        ans *= 2;
        ans %= 998244353;
    }
    return ans;
}

void Solve()
{
    int A;
    cin >> A;
    int a[A];
    for (int i = 0; i < A; i++)
    {
        cin >> a[i];
    }
    int expA[A];
    for (int i = 0; i < A; i++)
    {
        cin >> expA[i];
    }

    unordered_map<int, int> a_exp;
    for (int i = 0; i < A; i++)
    {
        a_exp[a[i]] = expA[i];
    }

    int B;
    cin >> B;
    int b[B];
    for (int i = 0; i < B; i++)
    {
        cin >> b[i];
    }
    int expB[B];
    for (int i = 0; i < B; i++)
    {
        cin >> expB[i];
    }

    unordered_map<int, int> b_exp;
    for (int i = 0; i < B; i++)
    {
        b_exp[b[i]] = expB[i];
    }
    long long exp = 0;
    for (auto t : a_exp)
    {
        if (b_exp.find(t.first) != b_exp.end())
        {
            if (b_exp[t.first] > t.second)
            {
                cout << 0 << endl;
                return;
            }
            exp += (t.second != b_exp[t.first]);
        }
        else
        {
            exp += 1;
        }
    }
    for (auto t : b_exp)
    {
        if (a_exp.find(t.first) == a_exp.end())
        {
            cout << 0 << endl;
            return;
        }
    }
    cout << fast_exp(exp) << endl;
    return;
}

int main()
{
    Solve();
    return 0;
}
