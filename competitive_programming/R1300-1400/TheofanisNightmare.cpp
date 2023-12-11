// Problem: C. Theofanis' Nightmare
// Contest: Codeforces - Codeforces Round 912 (Div. 2)
// URL: https://codeforces.com/contest/1903/problem/C
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Math Proof:
//
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
#define endl '\n'
#define wp ' '
#define forn for (int i = 0; i < n; i++)
#define form for (int j = 0; j < n; j++)
#define pb push_back

using namespace std;

void Solve()
{
    int n;
    cin >> n;
    int a[n];
    forn
    {
        cin >> a[i];
    }
    long long psums[n];
    psums[n - 1] = a[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        psums[i] = a[i] + psums[i + 1];
    }
    long long summ = 0;
    int segmenet_index = 1;
    forn
    {
        long long seg_sum = a[i];
        while (i + 1 < n && psums[i + 1] < 0)
        {
            i++;
            seg_sum += a[i];
        }
        summ += (segmenet_index++) * seg_sum;
    }
    cout << summ << endl;
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