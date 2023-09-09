// Problem: D. Deletive Editing
// Contest: Codeforces - 2021-2022 ICPC, NERC, Northern Eurasia Onsite (Unrated, Online Mirror, ICPC Rules, Teams
// Preferred) URL: https://codeforces.com/problemset/problem/1666/D Memory Limit: 512 MB Time Limit: 3000 ms Math Proof:
//
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
#define endl '\n'
#define forn for (int i = 0; i < n; i++)
using namespace std;

int test_cases;

void Solve()
{
    int count[26];
    for (int i = 0; i < 26; i++)
    {
        count[i] = 0;
    }

    string B, s;
    cin >> B >> s;
    for (int i = 0; i < (int)s.size(); i++)
    {
        count[s[i] - 'A']++;
    }

    map<char, stack<int>> to_check;

    for (int i = (int)B.size() - 1; i >= 0; i--)
    {

        if (count[B[i] - 'A'] > 0)
        {
            to_check[B[i]].push(i);
            count[B[i] - 'A']--;
        }
    }

    for (int i = 0; i < 26; i++)
    {
        if (count[i] > 0)
        {
            cout << "NO" << endl;
            return;
        }
    }

    int start = -1;
    for (int i = 0; i < (int)s.size(); i++)
    {
        int neww = to_check[s[i]].top();
        to_check[s[i]].pop();
        if (neww <= start)
        {
            cout << "NO" << endl;
            return;
        }
        else
        {
            start = neww;
        }
    }
    cout << "YES" << endl;

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
