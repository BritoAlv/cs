// Problem: E. Data Structures Fan
// Contest: Codeforces - Codeforces Round 895 (Div. 3)
// URL: https://codeforces.com/problemset/problem/1872/E
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Math Proof:
//
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
#define endl '\n'
#define wp ' '
#define forn for (int i = 0; i < n; i++)
#define form for (int j = 0; j < m; j++)
#define pb push_back
#define ull unsigned long long

// je m appelle Alvaro j ai 21 ans.

using namespace std;

void Solve()
{
    int n;
    cin >> n;
    int aa[n];
    forn
    {
        cin >> aa[i];
    }
    int psums[n];
    psums[0] = aa[0];
    for (int i = 1; i < n; i++)
    {
        psums[i] = aa[i] ^ psums[i - 1];
    }
    vector<bool> s(n);
    int zero_xor = 0;
    int one_xor = 0;
    forn
    {
        char t;
        cin >> t;
        s[i] = (t == '1');
        if (s[i])
        {
            one_xor ^= aa[i];
        }
        else
        {
            zero_xor ^= aa[i];
        }
    }
    int q;
    cin >> q;
    while (q > 0)
    {
        int a, b;
        cin >> a >> b;
        if (a == 1)
        {
            int c;
            cin >> c;
            b--, c--;
            int xorr = psums[c] ^ (b > 0 ? psums[b - 1] : 0);
            one_xor ^= xorr;
            zero_xor ^= xorr;
        }
        else
        {
            if (b)
            {
                cout << one_xor << wp;
            }
            else
            {
                cout << zero_xor << wp;
            }
        }
        q--;
    }
    cout << endl;
    return;
}

int main()
{
    int test_cases;
    cin >> test_cases;
    while (test_cases > 0)
    {
        Solve();
        test_cases--;
    }
    return 0;
}