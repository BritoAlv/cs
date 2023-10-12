// Problem: C. Traffic Light
// Contest: Codeforces - Codeforces Round  828 (Div. 3)
// URL: https://codeforces.com/contest/1744/problem/C
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
    char c;
    cin >> c;
    vector<char> s(n);
    forn
    {
        cin >> s[i];
    }
    int index = 0;
    while (s[index] != 'g')
    {
        index++;
    }

    int answer[n];
    answer[index] = 0;
    for (int i = index - 1; i >= 0; i--)
    {
        answer[i] = answer[i + 1] + 1;
    }
    for (int i = n - 1; i >= index + 1; i--)
    {
        if (s[i] == 'g')
        {
            answer[i] = 0;
        }
        else
        {
            answer[i] = answer[(i + 1) % (n)] + 1;
        }
    }
    unordered_map<char, int> ans;
    forn
    {
        if (ans.find(s[i]) == ans.end())
        {
            ans[s[i]] = answer[i];
        }
        else
        {
            ans[s[i]] = max(ans[s[i]], answer[i]);
        }
    }
    cout << ans[c] << endl;
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
