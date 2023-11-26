// Problem: B. Lamps
// Contest: Codeforces - Codeforces Round 876 (Div. 2)
// URL: https://codeforces.com/contest/1839/problem/B
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Math Proof:
//
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
#define endl '\n'
#define wp ' '
#define forn for (int i = 0; i < n; i++)
#define pb push_back

using namespace std;

int comparer(pair<int, int> A, pair<int, int> B)
{
    if (A.first < B.first)
    {
        return 1;
    }
    else if (A.first > B.first)
    {
        return 0;
    }
    else
    {
        if (A.second > B.second)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
}

void Solve()
{
    int n;
    cin >> n;
    vector<pair<int, int>> lamps;
    forn
    {
        int a, b;
        cin >> a >> b;
        lamps.pb({a, b});
    }
    sort(lamps.begin(), lamps.end(), comparer);
    long long points = 0;
    queue<pair<int, int>> arr;
    int index = 0;
    while (index < n)
    {
        arr.push(lamps[index]);
        points += lamps[index].second;
        index++;
        if (arr.front().first == arr.size())
        {
            if (index < n && lamps[index].first <= arr.front().first)
            {
                while (index < n && lamps[index].first <= arr.front().first)
                {
                    index++;
                }
            }
            arr.pop();
        }
    }
    cout << points << endl;
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
