// Problem: B. Shoe Shuffling
// Contest: Codeforces - CodeCraft-22 and Codeforces Round 795 (Div. 2)
// URL: https://codeforces.com/contest/1691/problem/B
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
    vector<int> answer;
    for (int i = 0; i < n; i++)
    {
        int start = i;
        int end = i;
        while (end + 1 < n && a[end + 1] == a[start])
        {
            end++;
        }
        if (end == start)
        {
            cout << -1 << endl;
            return;
        }
        else
        {
            for (int j = start; j < end; j++)
            {
                answer.push_back(j + 2);
            }
            answer.push_back(start + 1);
        }
        i = end;
    }
    for (auto x : answer)
    {
        cout << x << wp;
    }
    cout << endl;
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
