// Problem: E. Look Back
// Contest: Codeforces - Codeforces Round 905 (Div. 3)
// URL: https://codeforces.com/problemset/problem/1883/E
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

int get_smallest_pow_two(int a, int b)
{
    if (a <= b)
    {
        return 0;
    }
    int ceil = a / b + (a % b != 0);
    int pow = 0;
    while (true)
    {
        if (ceil <= (1 << (pow)))
        {
            break;
        }
        pow++;
    }
    return pow;
}

void Solve()
{

    int n;
    cin >> n;
    long long a[n];
    long long op[n];
    forn
    {
        cin >> a[i];
        op[i] = 0;
    }
    long long sum = 0;
    for (int i = 1; i < n; i++)
    {
        if (a[i] == a[i - 1])
        {
            op[i] = op[i - 1];
        }
        if (a[i] < a[i - 1])
        {
            op[i] = op[i - 1] + get_smallest_pow_two(a[i - 1], a[i]);
        }
        else
        {
            int exp = get_smallest_pow_two(a[i], a[i - 1]);
            if (op[i - 1] < exp)
            {
                op[i] = 0;
            }
            else if (op[i - 1] == exp)
            {
                if (a[i] % a[i - 1] == 0 && (1 << exp) == a[i] / a[i - 1])
                {
                    op[i] = 0;
                }
                else
                {
                    op[i] = 1;
                }
            }
            else
            {
                if (a[i] % a[i - 1] == 0 && (1 << exp) == a[i] / a[i - 1])
                {
                    op[i] = op[i - 1] - exp;
                }
                else
                {
                    op[i] = op[i - 1] - (exp - 1);
                }
            }
        }
        sum += op[i];
    }
    cout << sum << endl;

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