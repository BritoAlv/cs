// Problem: C. 3SUM Closure
// Contest: Codeforces - Codeforces Round 803 (Div. 2)
// URL: https://codeforces.com/problemset/problem/1698/C
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

int n;
int a[200000];

int is_closed()
{
    set<int> v;
    forn
    {
        v.insert(a[i]);
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                int sum = a[i] + a[j] + a[k];
                if (v.find(sum) == v.end())
                {
                    return 0;
                }
            }
        }
    }
    return 1;
}

void Solve()
{
    cin >> n;
    map<int, int> count;
    forn
    {
        int c;
        cin >> c;
        if (count.find(c) == count.end())
        {
            count[c] = 0;
        }
        if (count[c] <= 3)
        {
            count[c]++;
        }
    }
    if (count.size() >= 10)
    {
        cout << "No" << endl;
    }
    else
    {
        int pointer = 0;
        for (auto x : count)
        {
            for (int h = 0; h < x.second; h++)
            {
                a[pointer++] = x.first;
            }
        }
        n = pointer;
        if (is_closed())
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }
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
