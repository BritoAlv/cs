// Problem: B. Collecting Game
// Contest: Codeforces - Codeforces Round 914 (Div. 2)
// URL: https://codeforces.com/contest/1904/problem/B
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

using namespace std;

void Solve()
{
    int n;
    cin >> n;
    vector<pair<int, int>> a;
    forn
    {
        int b;
        cin >> b;
        a.pb({b, i});
    }
    sort(a.begin(), a.end());
    bool vl[n + 1];
    long long sum = 0;
    vl[0] = false;
    for (int i = 1; i < n; i++)
    {
        sum += a[i - 1].first;
        vl[i] = a[i].first <= sum;
    }
    int b[n];
    int left_most_false = 0;
    vl[n] = false;
    for (int i = 1; i <= n; i++)
    {
        if (!vl[i])
        {
            left_most_false = i;
            break;
        }
    }
    forn
    {
        if (left_most_false == i)
        {
            for (int j = i + 1; j <= n; j++)
            {
                if (!vl[j])
                {
                    left_most_false = j;
                    break;
                }
            }
        }
        b[a[i].second] = left_most_false - 1;
    }
    forn
    {
        cout << b[i] << wp;
    }
    cout << endl;
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
