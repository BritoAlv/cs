// Problem: B. Doremy's Perfect Math Class
// Contest: Codeforces - Codeforces Global Round 24
// URL: https://codeforces.com/problemset/problem/1764/B
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Math Proof: if x, y are also any positive number
// of the form x - ky, the mcd(x,y) is there also.
// from that observation the smallest number will be the
// mcd of all numbers.
//
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>

using namespace std;

int test_cases;

int mcd(int a, int b)
{
    if (a == 0)
    {
        return b;
    }
    if (b == 0)
    {
        return a;
    }
    if (a == b)
    {
        return a;
    }
    else if (a < b)
    {
        if (b % a == 0)
        {
            return a;
        }
        return mcd(a, b % a);
    }
    else
    {
        if (a % b == 0)
        {
            return b;
        }
        return mcd(b, a % b);
    }
}

void Solve()
{
    int n;
    cin >> n;
    vector<int> numbers;
    int max = -1;
    int mcdd = 0;
    while (n > 0)
    {
        int t;
        cin >> t;
        if (t > max)
        {
            max = t;
        }
        mcdd = mcd(t, mcdd);
        n--;
    }

    cout << max / mcdd << '\n';
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
