// Problem: B. Array Reodering
// Contest: Codeforces - Educational Codeforces Round 110 (Rated for Div. 2)
// URL: https://codeforces.com/problemset/problem/1535/B
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Math Proof: put evens first.
//
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
#define endl '\n'
#define wp ' '
#define forn for (int i = 0; i < n; i++)
using namespace std;

int test_cases;

int gcd(int a, int b)
{
    if (a == b)
    {
        return a;
    }
    else if (a > b)
    {
        if (a % b == 0)
        {
            return b;
        }
        return gcd(a % b, b);
    }
    else
    {
        if (b % a == 0)
        {
            return a;
        }
        return gcd(b % a, a);
    }
}

void Solve()
{
    int n;
    cin >> n;
    int a[n];
    vector<int> odds;
    vector<int> evens;
    forn
    {
        cin >> a[i];
        if (a[i] % 2 == 0)
        {
            evens.push_back(a[i]);
        }
        else
        {
            odds.push_back(a[i]);
        }
    }
    for (int i = 0; i < evens.size(); i++)
    {
        a[i] = evens[i];
    }
    for (int i = evens.size(); i < n; i++)
    {
        a[i] = odds[i - evens.size()];
    }
    int answer = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (gcd(a[i], 2 * a[j]) > 1)
            {
                answer++;
            }
        }
    }
    cout << answer << endl;
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
