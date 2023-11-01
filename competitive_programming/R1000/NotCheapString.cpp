// Problem: D. Not a Cheap String
// Contest: Codeforces - Codeforces Round 805 (Div. 3)
// URL: https://codeforces.com/contest/1702/problem/D
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

int comparer1(pair<char, int> A, pair<char, int> B)
{
    if (A.first > B.first)
    {
        return 1;
    }
    return 0;
}

int comparer2(pair<char, int> A, pair<char, int> B)
{
    if (A.second < B.second)
    {
        return 1;
    }
    return 0;
}

void Solve()
{
    string S;
    int p;
    cin >> S >> p;
    int n = S.size();
    int sum = 0;
    pair<char, int> the_string[n];
    forn
    {
        char t = S[i];
        the_string[i] = make_pair(t, i);
        sum += (the_string[i].first - 'a' + 1);
    }
    sort(the_string, the_string + n, comparer1);
    int i = 0;
    for (; i < n; i++)
    {
        if (sum <= p)
        {
            break;
        }
        else
        {
            sum -= (the_string[i].first - 'a' + 1);
        }
    }
    if (n - i == 0)
    {
        cout << endl;
        return;
    }
    pair<char, int> the_string2[n - i];
    for (int j = i; j < n; j++)
    {
        the_string2[j - i] = the_string[j];
    }

    sort(the_string2, the_string2 + (n - i), comparer2);
    for (auto x : the_string2)
    {
        cout << x.first;
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