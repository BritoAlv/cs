// Problem: D2. Prefix-Suffix Palindrome (Hard version)
// Contest: Codeforces - Codeforces Global Round 7
// URL: https://codeforces.com/contest/1326/problem/D2
// Memory Limit: 256 MB
// Time Limit: 2000 ms
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
    string s;
    cin >> s;
    if (s.size() == 1)
    {
        cout << s << endl;
        return;
    }
    int max_length = 0;
    while (max_length < s.size() && (s[max_length] == s[s.size() - 1 - max_length]))
    {
        max_length++;
    }
    if (max_length == s.size())
    {
        cout << s << endl;
        return;
    }
    vector<char> candidate;
    if (s.size() - max_length >= max_length)
    {
        int part1 = 1;
        int part2 = 1;
        if (s.size() - 2 * max_length > 1)
        {
            vector<char> ss;
            vector<char> tt;
            for (int i = max_length; i < s.size() - max_length; i++)
            {
                ss.push_back(s[i]);
            }
            ss.push_back('$');
            for (int i = s.size() - max_length - 1; i >= max_length; i--)
            {
                ss.push_back(s[i]);
                tt.push_back(s[i]);
            }
            tt.push_back('$');
            for (int i = max_length; i < s.size() - max_length; i++)
            {
                tt.push_back(s[i]);
            }

            int pi1[ss.size()];
            int pi2[tt.size()];
            for (int i = 0; i < ss.size(); i++)
            {
                pi1[i] = 0;
                pi2[i] = 0;
            }

            for (int i = 1; i < ss.size(); i++)
            {
                int k = pi1[i - 1];
                while (k > 0)
                {
                    if (ss[i] == ss[k])
                    {
                        break;
                    }
                    else
                    {
                        k = pi1[k - 1];
                    }
                }
                if (ss[i] == ss[k])
                {
                    pi1[i] = k + 1;
                }
            }
            part1 = pi1[ss.size() - 1];
            for (int i = 1; i < tt.size(); i++)
            {
                int k = pi2[i - 1];
                while (k > 0)
                {
                    if (tt[i] == tt[k])
                    {
                        break;
                    }
                    else
                    {
                        k = pi2[k - 1];
                    }
                }
                if (tt[i] == tt[k])
                {
                    pi2[i] = k + 1;
                }
            }
            part2 = pi2[tt.size() - 1];
        }

        if (part1 >= part2)
        {
            for (int i = 0; i < max_length + part1; i++)
            {
                candidate.push_back(s[i]);
            }
            for (int i = s.size() - max_length; i < s.size(); i++)
            {
                candidate.push_back(s[i]);
            }
        }
        else
        {
            for (int i = 0; i < max_length; i++)
            {
                candidate.push_back(s[i]);
            }
            for (int i = s.size() - max_length - part2; i < s.size(); i++)
            {
                candidate.push_back(s[i]);
            }
        }
    }
    for (auto x : candidate)
    {
        cout << x;
    }
    cout << endl;
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
