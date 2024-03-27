// Problem: E. Living Sequence
// Contest: Codeforces - Codeforces Round 863 (Div. 3)
// URL: https://codeforces.com/contest/1811/problem/E
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Math Proof:
//
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
#define endl '\n'
#define wp ' '
#define forn for (int i = 0; i < n; i++)
#define form for (int j = 0; j < m; j++)
#define fork for (int i = 0; i < k; i++)
#define pb push_back
#define ull long long
#define pi pair<int, int>
#define sz size()
// je m appelle Alvaro j ai 21 ans.

using namespace std;

ull ans[100];
ull poww[100];

ull cant_4_le(ull n)
{
    vector<int> digits;
    while (n > 0)
    {
        digits.pb(n % 10);
        n /= 10;
    }
    vector<ull> anss(digits.size());
    anss[0] = (digits[0] >= 4);
    ull prev_number = 0;
    for (int i = 1; i < digits.size(); i++)
    {
        prev_number = digits[i - 1] * poww[i - 1] + prev_number;
        if (digits[i] < 4)
        {
            ull part1 = anss[i - 1];
            ull part2 = ans[i] * digits[i];
            anss[i] = part1 + part2;
        }
        else if (digits[i] == 4)
        {
            ull part1 = prev_number + 1;
            ull part2 = ans[i] * digits[i];
            anss[i] = part1 + part2;
        }
        else
        {
            ull part1 = anss[i - 1];
            ull part2 = poww[i];
            ull part3 = ans[i] * (digits[i] - 1);
            anss[i] = part1 + part2 + part3;
        }
    }
    return anss[anss.size() - 1];
}

ull formula(ull i)
{
    return i - cant_4_le(i);
}

ull before(ull e)
{
    // find largest four un the number.
    vector<int> digits;
    while (e > 0)
    {
        digits.pb(e % 10);
        e /= 10;
    }
    for (int i = digits.size() - 1; i >= 0; i--)
    {
        if (digits[i] == 4)
        {
            digits[i] = 3;
            for (int j = i - 1; j >= 0; j--)
            {
                digits[j] = 9;
            }
            break;
        }
    }
    ull number = 0;
    for (int i = digits.size() - 1; i >= 0; i--)
    {
        number *= 10;
        number += digits[i];
    }
    return number;
}

void Solve()
{
    ull n;
    cin >> n;
    ull s = 1;
    ull e = 4398046511104;
    while (e - s > 1)
    {
        ull middle = s + (e - s) / 2;
        ull result = formula(middle);
        if (result <= n)
        {
            s = middle;
        }
        else
        {
            e = middle - 1;
        }
    }
    while (formula(e) != n)
    {
        e--;
    }
    cout << before(e) << endl;
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ans[0] = 0;
    ans[1] = 1;
    poww[0] = 1;
    poww[1] = 10;
    for (int i = 2; i <= 32; i++)
    {
        poww[i] = 10 * poww[i - 1];
        ans[i] = poww[i - 1] + 9 * ans[i - 1];
    }
    int test_cases;
    cin >> test_cases;
    while (test_cases-- > 0)
    {
        Solve();
    }
    return 0;
}