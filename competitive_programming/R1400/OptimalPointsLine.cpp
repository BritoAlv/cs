// Problem: B. Optimal Point on a Line
// Contest: Codeforces - Educational Codeforces Round 16
// URL: https://codeforces.com/contest/710/problem/B
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
    sort(a, a + n);
    vector<pair<long long, int>> distances;
    forn
    {
        distances.pb({0, a[i]});
    }
    for (int j = 0; j < distances.size(); j++)
    {
        if (j == 0)
        {
            forn
            {
                distances[j].first += abs(distances[j].second - a[i]);
            }
        }
        else
        {
            ull dif = abs(a[j] - a[j - 1]);
            distances[j].first = distances[j - 1].first - dif * ((n - 1) - j) + dif * (j - 1);
        }
    }
    sort(distances.begin(), distances.end());
    cout << distances[0].second << endl;
    return;
}

int main()
{
    int test_cases = 1;
    while (test_cases > 0)
    {
        Solve();
        test_cases--;
    }
    return 0;
}
