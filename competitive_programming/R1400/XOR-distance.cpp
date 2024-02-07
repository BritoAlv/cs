// Problem: C. XOR-distance
// Contest: Codeforces - Codeforces Round 922 (Div. 2)
// URL: https://codeforces.com/problemset/problem/1918/C
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

ull ans;
ull a, b, r;

void set_ans(ull candidate)
{
    ans = min(ans, max(a ^ candidate, b ^ candidate) - min(a ^ candidate, b ^ candidate));
}

string get_mask(ull n, int len)
{
    string result = "";
    while (n > 0)
    {
        result = result + (n % 2 == 0 ? "0" : "1");
        n = n / 2;
    }
    while (result.size() < len)
    {
        result = result + "0";
    }
    return result;
}

void Solve()
{
    ans = 3e18;
    cin >> a >> b >> r;
    if (a < b)
    {
        ull temp = b;
        b = a;
        a = temp;
    }
    string mask_a = get_mask(a, 64);
    string mask_b = get_mask(b, 64);
    string mask_r = get_mask(r, 64);
    int first_dismatch = -1;
    int first_bit_r = -1;
    for (int i = 63; i >= 0; i--)
    {
        if (mask_a[i] != mask_b[i])
        {
            first_dismatch = i;
            break;
        }
    }
    for (int i = 63; i >= 0; i--)
    {
        if (mask_r[i] == '1')
        {
            first_bit_r = i;
            break;
        }
    }
    ull number = 0;
    set_ans(number);
    for (int i = min(first_dismatch - 1, first_bit_r); i >= 0; i--)
    {
        if (mask_a[i] != mask_b[i])
        {
            if (mask_a[i] == '1')
            {
                ull pow = 1;
                for (int y = 1; y <= i; y++)
                {
                    pow *= 2;
                }
                if (number + pow <= r)
                {
                    number += pow;
                }
                set_ans(number);
            }
        }
    }
    cout << ans << endl;
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
