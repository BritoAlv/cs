// Problem: C. Qingshan Loves Strings 2
// Contest: Codeforces - Codeforces Round 906 (Div. 2)
// URL: https://codeforces.com/contest/1890/problem/C
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

void Solve()
{
    int n;
    cin >> n;
    string S;
    cin >> S;
    if (n % 2 == 1)
    {
        cout << -1 << endl;
    }
    else
    {
        int ops = 0;
        vector<int> positions;
        while (ops < 300)
        {
            for (int i = 0; i < S.size(); i++)
            {
                if (S[i] == S[S.size() - i - 1])
                {
                    if (S[i] == '1')
                    {
                        positions.push_back(i);
                        string new_S = "";
                        for (int j = 0; j < i; j++)
                        {
                            new_S += S[j];
                        }
                        new_S += "01";
                        for (int j = i; j < S.size(); j++)
                        {
                            new_S += S[j];
                        }
                        S = new_S;
                        break;
                    }
                    if (S[i] == '0')
                    {
                        positions.push_back(S.size() - i);
                        string new_S = "";
                        for (int j = 0; j <= S.size() - i - 1; j++)
                        {
                            new_S += S[j];
                        }
                        new_S += "01";
                        for (int j = S.size() - i; j < S.size(); j++)
                        {
                            new_S += S[j];
                        }
                        S = new_S;
                        break;
                    }
                }
            }
            ops++;
        }
        for (int i = 0; i < S.size(); i++)
        {
            if (S[i] == S[S.size() - i - 1])
            {
                cout << -1 << endl;
                return;
            }
        }
        cout << positions.size() << endl;
        for (auto z : positions)
        {
            cout << z << wp;
        }
        cout << endl;
    }
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
