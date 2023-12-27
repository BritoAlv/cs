// Problem: E. Interview
// Contest: Codeforces - Codeforces Round 859 (Div. 4)
// URL: https://codeforces.com/problemset/problem/1807/E
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Math Proof:
//
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
#define endl '\n'
#define wp ' '
#define forn for (int i = 0; i < n; i++)
#define form for (int j = 0; j < m; j++)
#define pb push_back

using namespace std;

long long psums[200000];

long long get_sum(int start, int end)
{
    start--, end--;
    return psums[end] - (start == 0 ? 0 : psums[start - 1]);
}

void Solve()
{
    int n;
    cin >> n;
    int a[n];
    forn
    {
        cin >> a[i];
    }
    psums[0] = a[0];
    for (int i = 1; i < n; i++)
    {
        psums[i] = a[i] + psums[i - 1];
    }
    int start = 1;
    int end = n;
    while (end - start > 1)
    {
        int middle = (start + end) / 2;
        cout << '?' << wp << (middle - start + 1) << wp;
        for (int i = start; i <= middle; i++)
        {
            cout << i << wp;
        }
        cout << endl;
        cout.flush();
        long long p1;
        cin >> p1;
        if (p1 != get_sum(start, middle))
        {
            end = middle;
        }
        else
        {
            start = middle + 1;
        }
    }
    cout << '?' << wp << 1 << wp << start << endl;
    cout.flush();
    long long ans;
    cin >> ans;
    if (ans != get_sum(start, start))
    {
        cout << "!" << wp << start << endl;
    }
    else
    {
        cout << "!" << wp << start + 1 << endl;
    }
    cout.flush();
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