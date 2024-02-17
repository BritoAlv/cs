// Problem: C. Physical Education Lesson
// Contest: Codeforces - Codeforces Round 924 (Div. 2)
// URL: https://codeforces.com/contest/1928/problem/C
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
#define pb push_back
#define ull unsigned long long

// je m appelle Alvaro j ai 21 ans.

using namespace std;

int n, x;
set<int> wor;
void work(int k)
{
    if (k < 2)
    {
        return;
    }
    int copy_n = n;
    if (copy_n % (2 * k - 2) != 0)
    {
        copy_n = copy_n % (2 * k - 2);
    }
    else
    {
        copy_n = 2 * k - 2;
    }
    if (copy_n <= k && copy_n == x)
    {
        wor.insert(k);
    }
    else if (copy_n > k && copy_n + x == 2 * k)
    {
        wor.insert(k);
    }
}

void Solve()
{
    cin >> n >> x;
    wor.clear();
    work(2);
    work((x + 2) / 2);
    work((n + x) / 2);
    work(x);
    int number1 = n + x - 2;
    for (int i = 1; i * i <= number1; i++)
    {
        if (number1 % i == 0)
        {
            work((i + 2) / 2);
            work((number1 / i + 2) / 2);
        }
    }
    int number2 = n - x;
    for (int i = 1; i * i <= number2; i++)
    {
        if (number2 % i == 0)
        {
            work((i + 2) / 2);
            work((number2 / i + 2) / 2);
        }
    }
    cout << wor.size() << endl;
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