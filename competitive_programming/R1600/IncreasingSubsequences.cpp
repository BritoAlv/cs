// Problem: E. Increasing Subsequences
// Contest: Codeforces - Educational Codeforces Round 161 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1922/problem/E
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
using namespace std;

vector<int> get_mask(ull n)
{
    vector<int> maskk(64, 0);
    string result = "";
    while (n > 0)
    {
        result = result + (n % 2 == 0 ? "0" : "1");
        n = n / 2;
    }
    for (int i = 0; i < result.size(); i++)
    {
        maskk[i] = (result[i] == '1' ? 1 : 0);
    }
    return maskk;
}

void Solve()
{
    ull n;
    cin >> n;
    vector<int> mask = get_mask(n);
    vector<int> result;
    int highest_bit_on = -1;
    for (int i = 63; i >= 0; i--)
    {
        if (mask[i])
        {
            highest_bit_on = i;
            break;
        }
    }
    if (highest_bit_on == 0)
    {
        cout << 0 << endl << endl;
        return;
    }
    int start = 0;
    for (int j = 1; j <= highest_bit_on; j++)
    {
        result.pb(start);
        start += 200;
    }
    for (int j = highest_bit_on - 1; j >= 0; j--)
    {
        if (mask[j])
        {
            result.pb(result[j] - 1);
        }
    }
    cout << result.size() << endl;
    for (auto x : result)
    {
        cout << x << wp;
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
