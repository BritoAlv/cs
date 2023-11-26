// Problem: D. Yarik and Musical Notes
// Contest: Codeforces - Codeforces Round 909 (Div. 3)
// URL: https://codeforces.com/contest/1899/problem/D
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

void Solve()
{
    int n;
    cin >> n;
    unordered_map<int, int> count;
    forn
    {
        int a;
        cin >> a;
        if (count.find(a) == count.end())
        {
            count[a] = 0;
        }
        count[a]++;
    }
    long long answer = 0;
    for (auto x : count)
    {
        long long s = x.second;
        s *= (s - 1);
        s /= 2;
        answer += s;
    }
    if (count.find(1) != count.end() && count.find(2) != count.end())
    {
        long long s = count[1];
        s *= count[2];
        answer += s;
    }
    cout << answer << endl;
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
