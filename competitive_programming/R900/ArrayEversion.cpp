// Problem: B. Array Eversion
// Contest: Codeforces - Technocup 2022 - Elimination Round 3
// URL: https://codeforces.com/problemset/problem/1585/B
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Math Proof: count largest increasing sequence from right to left
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
    int max = -1;
    int index = -1;
    int a[n];
    forn
    {
        cin >> a[i];
        if (a[i] >= max)
        {
            index = i;
            max = a[i];
        }
    }

    if (index == n - 1)
    {
        cout << 0 << endl;
    }

    else
    {
        int op = 1;
        int largest = a[n - 1];
        for (int i = n - 2; i > index; i--)
        {
            if (a[i] > largest)
            {
                largest = a[i];
                op++;
            }
        }
        cout << op << endl;
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
