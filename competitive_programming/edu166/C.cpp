// Problem: C. Job Interview
// Contest: Codeforces - Educational Codeforces Round 166 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1976/problem/C
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
#define fork for (int i = 0; i < k; i++)
#define pb push_back
#define ull unsigned long long
#define pi pair<int, int>
#define sz size()
// je m appelle Alvaro j ai 21 ans.

using namespace std;

void BruteSolve()
{
    return;
}

void Solve()
{
    int n, m;
    cin >> n >> m;
    vector<pi> sk(n + m + 1);
    for (int i = 0; i < n + m + 1; i++)
    {
        cin >> sk[i].first;
    }
    for (int i = 0; i < n + m + 1; i++)
    {
        cin >> sk[i].second;
    }
    vector<long long> programmer = {-1, -1, n + m + 1};
    vector<long long> tester = {-1, -1, n + m + 1};
    for (int i = 0; i < n + m + 1; i++)
    {
        if (sk[i].first > sk[i].second)
        {
            programmer[0] = i;
            break;
        }
    }
    for (int i = 0; i < n + m + 1; i++)
    {
        if (sk[i].first < sk[i].second)
        {
            tester[0] = i;
            break;
        }
    }
    if (programmer[0] != -1)
    {
        int i = programmer[0];
        long long scores = 0;
        int p = 0;
        int t = 0;
        for (int j = 0; j < n + m + 1; j++)
        {
            if (j != i)
            {
                if ((sk[j].first > sk[j].second && p < n) || t == m)
                {
                    p++;
                    scores += sk[j].first;
                }
                else
                {
                    t++;
                    if (sk[j].first > sk[j].second && programmer[2] == n + m + 1)
                    {
                        programmer[2] = j;
                    }
                    scores += sk[j].second;
                }
            }
        }
        programmer[1] = scores;
    }
    if (tester[0] != -1)
    {
        int i = tester[0];
        long long scores = 0;
        int p = 0;
        int t = 0;
        for (int j = 0; j < n + m + 1; j++)
        {
            if (j != i)
            {
                if ((sk[j].first > sk[j].second && p < n) || t == m)
                {
                    p++;
                    if (sk[j].first < sk[j].second && tester[2] == n + m + 1)
                    {
                        tester[2] = j;
                    }
                    scores += sk[j].first;
                }
                else
                {
                    t++;
                    scores += sk[j].second;
                }
            }
        }
        tester[1] = scores;
    }
    for (int i = 0; i < n + m + 1; i++)
    {
        if (sk[i].first > sk[i].second)
        {
            if (i < programmer[2])
            {
                programmer[1] = programmer[1] + sk[programmer[0]].first - sk[i].first;
            }
            else
            {
                programmer[1] = programmer[1] + sk[programmer[0]].second - sk[i].second;
            }
            programmer[0] = i;
            cout << programmer[1] << wp;
        }
        else
        {
            if (i < tester[2])
            {
                tester[1] = tester[1] + sk[tester[0]].second - sk[i].second;
            }
            else
            {
                tester[1] = tester[1] + sk[tester[0]].first - sk[i].first;
            }
            tester[0] = i;
            cout << tester[1] << wp;
        }
    }
    cout << endl;
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