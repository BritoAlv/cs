// Problem: B. Nene and the Card Game
// Contest: Codeforces - Codeforces Round 939 (Div. 2)
// URL: https://codeforces.com/contest/1956/problem/B
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
#define fork for (int i = 0; i < k; i++)
#define pb push_back
#define ull unsigned long long
#define pi pair<int, int>
#define sz size()
// je m appelle Alvaro j ai 21 ans.

using namespace std;

void Solve()
{
    int n;
    cin >> n;
    vector<int> count(n, 0);
    forn
    {
        int t;
        cin >> t;
        count[t - 1]++;
    }
    int count0 = 0;
    int count1 = 0;
    int count2 = 0;
    forn
    {
        if (count[i] == 2)
        {
            count2++;
        }
        else if (count[i] == 1)
        {
            count1++;
        }
        else
        {
            count0++;
        }
    }
    if (count2 > count0)
    {
        cout << count2 + count1 << endl;
    }
    else
    {
        cout << count2 << endl;
    }
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int test_cases;
    cin >> test_cases;
    while (test_cases-- > 0)
    {
        Solve();
    }
    return 0;
}