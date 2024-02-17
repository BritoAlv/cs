// Problem: A. Directional Increase
// Contest: Codeforces - Codeforces Round 800 (Div. 1)
// URL: https://codeforces.com/problemset/problem/1693/A
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

void Solve()
{
    int n;
    cin >> n;
    long long a[n];
    forn
    {
        cin >> a[i];
    }
    int all_zero = 1;
    forn
    {
        if (a[i] != 0)
        {
            all_zero = 0;
            break;
        }
    }
    if (all_zero)
    {
        cout << "Yes" << endl;
        return;
    }
    int first = -1;
    for (int i = n - 1; i >= 0; i--)
    {
        if (a[i] < 0)
        {
            first = i;
            break;
        }
        if (a[i] > 0)
        {
            break;
        }
    }
    if (first == -1)
    {
        cout << "No" << endl;
        return;
    }
    vector<long long> aa(n, 0);
    for (int i = 0; i < first; i++)
    {
        aa[i]++;
    }
    int pointer = first;
    while (pointer > 0)
    {
        // should have a[pointer]
        // has aa[pointer]
        //
        if (aa[pointer] <= a[pointer])
        {
            cout << "No" << endl;
            return;
        }
        else
        {
            aa[pointer - 1] += aa[pointer] - a[pointer] - 1;
        }
        pointer--;
    }
    if (a[0] == aa[0])
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }

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