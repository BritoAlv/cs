// Problem: B. Social Distance
// Contest: Codeforces - Codeforces Round 783 (Div. 2)
// URL: https://codeforces.com/problemset/problem/1668/B
// Memory Limit: 256 MB
// Time Limit: 1500 ms
// Math Proof: well indeed, there is one, first there
// is to find the minimal value of:
// max(p0, p1) + max(p1, p2) + ... + max(pn, p0) where pi is a permutation of array A.
// notice that whenever we put the maximal value of the array its counted twice
/*
but we can avoid counting (n-1) twice by comparing it to n, and by this way it will be counted only
once, this argument leds to the array sorted for getting the minimal.
*/
^

// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
#define endl '\n'
#define forn for (int i = 0; i < n; i++)
    using namespace std;

int test_cases;

int max(int a, int b)
{
    return a > b ? a : b;
}

void Solve()
{
    int n, m;
    cin >> n >> m;
    int a[n];
    forn
    {
        cin >> a[i];
    }
    sort(a, a + n);
    long long sits = 0;
    for (int i = 0; i < n - 1; i++)
    {
        sits++;                      // sit person i
        sits += max(a[i], a[i + 1]); // leave spaces.
        if (sits > m)
        {
            cout << "NO" << endl;
            return;
        }
    }
    sits++;                      // sit person n
    sits += max(a[n - 1], a[0]); // leave spaces.
    if (sits <= m)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
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