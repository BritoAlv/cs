// Problem: B. Gardener and the Array
// Contest: Codeforces - Codeforces Round 843 (Div. 2)
// URL: https://codeforces.com/problemset/problem/1775/B
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

void Solve()
{
    int n;
    cin >> n;
    map<int, int> count;
    vector<vector<int>> numbers;
    forn
    {
        int k;
        cin >> k;
        numbers.pb(vector<int>());
        for (int j = 0; j < k; j++)
        {
            int a;
            cin >> a;
            if (count.find(a) == count.end())
            {
                count[a] = 0;
            }
            count[a]++;
            numbers[i].pb(a);
        }
    }
    forn
    {
        int works = 1;
        for (int j = 0; j < numbers[i].size(); j++)
        {
            if (count[numbers[i][j]] < 2)
            {
                works = 0;
                break;
            }
        }
        if (works)
        {
            cout << "Yes" << endl;
            return;
        }
    }
    cout << "No" << endl;
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
