// Problem: D. Polycarp and Div 3
// Contest: Codeforces - Codeforces Round 496 (Div. 3)
// URL: https://codeforces.com/contest/1005/problem/D
// Memory Limit: 256 MB
// Time Limit: 3000 ms
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
using namespace std;

void Solve()
{
    string s;
    cin >> s;
    int result = 0;
    int n = s.size();
    forn
    {
        int start = i;
        int end = i;
        set<int> psums;
        int sum = 0;
        psums.insert(0);
        while (end < n)
        {
            sum += (s[end] - '0') % 3;
            sum %= 3;
            if (psums.find(sum) != psums.end())
            {
                result++;
                break;
            }
            else
            {
                psums.insert(sum);
            }
            end++;
        }
        i = end;
    }
    cout << result << endl;
    return;
}

int main()
{
    int test_cases = 1;
    while (test_cases > 0)
    {
        Solve();
        test_cases--;
    }
    return 0;
}