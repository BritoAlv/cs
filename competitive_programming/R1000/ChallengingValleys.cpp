// Problem: D. Challenging Valleys
// Contest: Codeforces - Codeforces Round 835 (Div. 4)
// URL: https://codeforces.com/contest/1760/problem/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Math Proof:
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
    forn
    {
        cin >> a[i];
    }
    if (n == 1)
    {
        cout << "YES" << endl;
        return;
    }
    unordered_set<int> size1;
    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            if (a[1] > a[0])
            {
                size1.insert(0);
            }
        }
        else if (i == n - 1)
        {
            if (a[n - 2] > a[n - 1])
            {
                size1.insert(n - 1);
            }
        }
        else
        {
            if (a[i - 1] > a[i] && a[i + 1] > a[i])
            {
                size1.insert(i);
            }
        }
    }
    unordered_set<int> size2;
    for (int i = 0; i < n - 1; i++)
    {
        if (i == 0 || a[i - 1] > a[i])
        {
            int start = i;
            int end = i;
            while (end < n && a[start] == a[end + 1])
            {
                end++;
                if (end == n - 1)
                {
                    break;
                }
            }
            if (end != start && (end == n - 1 || a[end + 1] > a[end]))
            {
                size2.insert(start);
            }
            i = end;
        }
    }
    cout << (((size1.size() + size2.size()) == 1) ? "YES" : "NO") << endl;
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
