// Problem: A. Lucky Numbers
// Contest: Codeforces - Codeforces Round 861 (Div. 2)
// URL: https://codeforces.com/problemset/problem/1808/A
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Math Proof: if the difference is less than 100 then
// find by brute force, else there exist a number that leaves remainder
// 90 when divided by 100.

#include <bits/stdc++.h>

using namespace std;

int test_cases;

int get_luckiest(int n)
{
    vector<int> digits;

    int k = n;
    while (k > 0)
    {
        digits.push_back(k % 10);
        k /= 10;
    }
    const auto [min, max] = minmax_element(begin(digits), end(digits));
    return *max - *min;
}

void Solve()
{
    int l;
    int r;
    cin >> l;
    cin >> r;
    if (r - l >= 101)
    {
        if (l <= 90)
        {
            cout << 90 << '\n';
        }
        else
        {

            l = max(100, l);
            if (l % 100 < 90)
            {
                cout << (l / 100) * 100 + 90 << '\n';
            }
            else
            {
                cout << ((l / 100) + 1) * 100 + 9 << '\n';
            }
        }
    }
    else
    {
        int index = l;
        int answer = get_luckiest(l);
        for (int i = l + 1; i <= r; i++)
        {
            int temp = get_luckiest(i);
            if (temp > answer)
            {
                answer = temp;
                index = i;
            }
        }
        cout << index << '\n';
    }
    return;
}

int main()
{
    cin >> test_cases;
    while (test_cases > 0)
    {
        Solve();
        test_cases--;
    }
    return 0;
}