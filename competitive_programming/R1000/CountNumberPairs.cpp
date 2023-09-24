// Problem: B. Count the Number of Pairs
// Contest: Codeforces - Codeforces Round 855 (Div. 3)
// URL: https://codeforces.com/problemset/problem/1800/B
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Math Proof: min arguments.
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
    int n, k;
    cin >> n >> k;
    string S;
    cin >> S;
    map<char, pair<int, int>> let;
    forn
    {
        char low = tolower(S[i]);
        if (let.find(low) == let.end())
        {
            if (S[i] == low)
            {
                let[low] = make_pair(1, 0);
            }
            else
            {
                let[low] = make_pair(0, 1);
            }
        }
        else
        {
            if (S[i] == low)
            {
                let[low].first++;
            }
            else
            {
                let[low].second++;
            }
        }
    }

    int answer = 0;
    for (auto x : let)
    {
        answer += min(x.second.first, x.second.second);
        if (abs(x.second.first - x.second.second) >= 2)
        {
            answer += min(k, abs(x.second.first - x.second.second) / 2);
            k -= min(k, abs(x.second.first - x.second.second) / 2);
        }
    }
    cout << answer << endl;

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
