// Problem: E. Anna and the Valentine's Day Gift
// Contest: Codeforces - Codeforces Round 925 (Div. 3)
// URL: https://codeforces.com/contest/1931/problem/E
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

int get_exp(int g)
{
    int copy = g;
    int ans = 0;
    while (copy % 10 == 0 && copy > 0)
    {
        copy /= 10;
        ans++;
    }
    return ans;
}

int get_digits(int g)
{
    int copy = g;
    int ans = 0;
    while (copy > 0)
    {
        copy /= 10;
        ans++;
    }
    return ans;
}

// 5 3
int reverse(int a)
{
    vector<int> digits;
    while (a > 0)
    {
        digits.pb(a % 10);
        a /= 10;
    }
    int p = 0;
    while (digits[p] == 0)
    {
        p++;
    }
    int num = 0;
    for (int i = p; i < digits.size(); i++)
    {
        num *= 10;
        num += digits[i];
    }
    return num;
}

void Solve()
{
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> div_10;
    vector<int> not_div;
    forn
    {
        int t;
        cin >> t;
        if (t % 10 == 0)
        {
            div_10.pb({get_exp(t), t});
        }
        else
        {
            not_div.pb(t);
        }
    }
    sort(div_10.begin(), div_10.end());
    int k = div_10.size();
    int exp = 0;
    for (int i = k - 2; i >= 0; i -= 2)
    {
        exp += get_digits(div_10[i].second);
    }
    for (int i = k - 1; i >= 0; i -= 2)
    {
        exp += get_digits(reverse(div_10[i].second));
    }
    for (auto x : not_div)
    {
        exp += get_digits(x);
    }
    if (exp - 1 >= m)
    {
        cout << "Sasha" << endl;
    }
    else
    {
        cout << "Anna" << endl;
    }
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
