// Problem: C2. Подкрутка II
// Contest: Codeforces - VK Cup 2022 - Квалификация (Engine)
// URL: https://codeforces.com/contest/1769/problem/C2
// Memory Limit: 512 MB
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
#define ull unsigned long long
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
    vector<bool> A(n, false);
    forn
    {
        int start = i;
        int end = i;
        while (end + 1 < n && a[end + 1] == a[end])
        {
            a[end + 1]++;
            A[end + 1] = true;
            end++;
            while (end + 1 < n && a[end + 1] < a[end])
            {
                a[end + 1] = a[end];
                A[end + 1] = true;
                end++;
            }
        }
        i = end;
    }
    int racha = 0;
    int start = 0;
    int end = 0;
    while (true)
    {
        while (end + 1 < n && a[end + 1] - a[end] <= 1)
        {
            end++;
        }
        set<int> difs;
        for (int i = start; i <= end; i++)
        {
            difs.insert(a[i]);
        }
        racha = max(racha, (int)difs.size());
        if (end == n - 1)
        {
            break;
        }
        else
        {
            int next_start = end + 1;
            end = next_start;
            while (next_start - 1 >= 0 && !A[next_start - 1] && a[next_start] - a[next_start - 1] <= 2)
            {
                next_start--;
                a[next_start]++;
                A[next_start] = true;
            }
            start = next_start;
        }
    }
    cout << racha << endl;
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