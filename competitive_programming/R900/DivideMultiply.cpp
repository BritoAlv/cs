// Problem: A. Divide and Multiply
// Contest: Codeforces - Deltix Round, Autumn 2021 (open for everyone, rated, Div. 1 + Div. 2)
// URL: https://codeforces.com/problemset/problem/1609/A
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Math Proof: implementing it got me two wrong submissions, seems a little bit tricky.
//
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
#define endl '\n'
#define wp ' '
#define forn for (int i = 0; i < n; i++)
using namespace std;

int test_cases;

void Solve()
{
    int n;
    cin >> n;

    int a[n];
    int max = 0;
    int index = -1;
    int op_count = 0;
    forn
    {
        cin >> a[i];
        int t = a[i];
        while (t % 2 == 0)
        {
            t = t / 2;
            op_count++;
        }
        if (t > max)
        {
            max = t;
            index = i;
        }
        a[i] = t;
    }

    long long sum = 0;
    forn
    {
        if (i == index)
        {
            sum += max * pow(2, op_count);
        }
        else
        {
            sum += a[i];
        }
    }
    cout << sum << endl;
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
