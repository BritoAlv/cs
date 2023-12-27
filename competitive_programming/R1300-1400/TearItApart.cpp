// Problem: C. Tear It Apart
// Contest: Codeforces - Educational Codeforces Round 147 (Rated for Div. 2)
// URL: https://codeforces.com/problemset/problem/1821/C
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

int rec(int x)
{
    if (x == 0)
    {
        return 0;
    }
    else if (x == 1)
    {
        return 1;
    }
    else if (x == 2)
    {
        return 2;
    }
    else if (x % 2 == 0)
    {
        return 1 + rec(x / 2);
    }
    else
    {
        return 1 + rec(x - x / 2 - 1);
    }
}

void Solve()
{
    string S;
    cin >> S;
    int answer = S.size();
    for (int i = 0; i < 26; i++)
    {
        char s = 'a' + i;
        vector<int> parts;
        for (int j = 0; j < S.size(); j++)
        {
            if (S[j] != s)
            {
                int start = j;
                int end = j;
                while (end + 1 < S.size() && S[end + 1] != s)
                {
                    end++;
                }
                j = end;
                parts.pb(end - start + 1);
            }
        }
        int ans = 0;
        for (auto x : parts)
        {
            ans = max(ans, rec(x));
        }
        answer = min(answer, ans);
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
