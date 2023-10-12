// Problem: B. Elimination of a Ring
// Contest: Codeforces - Pinely Round 1 (Div. 1 + Div. 2)
// URL: https://codeforces.com/contest/1761/problem/B
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
    unordered_map<int, int> count;
    vector<int> a(n);
    int op = 0;
    forn
    {
        cin >> a[i];
        if (count.find(a[i]) == count.end())
        {
            count[a[i]] = 0;
        }
        count[a[i]]++;
    }
    while (a.size() > 2)
    {
        for (int i = 0; i <= a.size(); i++)
        {
            if (i == a.size())
            {
                a.erase(a.end() - 1);
                a.erase(a.begin());
                op++;
            }
            if (a[(i - 1) % a.size()] != a[(i + 1) % a.size()])
            {
                if (count[a[i]] == 1)
                {
                    cout << n << endl;
                    return;
                }
                count[a[i]]--;
                a.erase(a.begin() + i);
                op++;
                break;
            }
        }
    }
    cout << op + a.size() << endl;
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