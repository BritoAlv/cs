// Problem: A. Bestie
// Contest: Codeforces - Codeforces Round 830 (Div. 2)
// URL: https://codeforces.com/contest/1732/problem/A
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

int mcd(int a, int b)
{
    if (a <= b)
    {
        if (b % a == 0)
        {
            return a;
        }
        return mcd(a, b % a);
    }
    return mcd(b, a);
}

int mcd(int a[], int start, int end)
{
    int mcd_s = a[start];
    for (int i = start + 1; i <= end; i++)
    {
        mcd_s = mcd(mcd_s, a[i]);
    }
    return mcd_s;
}

int test_cases;

void Solve()
{
    int n;
    cin >> n;
    int a[n];
    forn
    {
        cin >> a[i];
    }
    int R = mcd(a, 0, n - 1);
    if (R == 1)
    {
        cout << 0 << endl;
    }
    else if (n == 1)
    {
        cout << 1 << endl;
    }
    else
    {
        int temp = a[n - 1];
        a[n - 1] = mcd(a[n - 1], n);
        if (mcd(a, 0, n - 1) == 1)
        {
            cout << 1 << endl;
            return;
        }
        a[n - 1] = temp;
        temp = a[n - 2];
        a[n - 2] = mcd(a[n - 2], n - 1);
        if (mcd(a, 0, n - 1) == 1)
        {
            cout << 2 << endl;
            return;
        }
        cout << 3 << endl;
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
