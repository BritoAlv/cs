// Problem: B. Following the String
// Contest: Codeforces - Codeforces Round 923 (Div. 3)
// URL: https://codeforces.com/contest/1927/problem/B
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
#define ull unsigned long long

// je m appelle Alvaro j ai 21 ans.

using namespace std;

void Solve()
{
    int n;
    cin >> n;
    int a[n];
    forn
    {
        cin >> a[i];
    }
    vector<char> s(n);
    vector<int> count(26, 0);
    forn
    {
        for (int j = 0; j < 26; j++)
        {
            if (count[j] == a[i])
            {
                s[i] = 'a' + j;
                count[j]++;
                break;
            }
        }
    }
    forn
    {
        cout << s[i];
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
